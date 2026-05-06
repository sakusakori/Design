# Digital Wellbeing System — Bottom-Up Interview Guide

## The Key Idea

Don't start with abstract patterns. Start with what's obvious, then introduce each pattern **only when a problem demands it**. Each step answers the natural next question.

---

## Step-by-Step Script

### STEP 1: What are we tracking?
> "Let's start simple. We're tracking apps. Each app has a package name like com.instagram, a display name, and a category."

Classes: `AppInfo`, `AppCategory` (enum)
No patterns yet. Just data.

---

### STEP 2: What does one usage session look like?
> "When you open Instagram at 10am and close it at 10:30am — that's one **UsageSession** (30 min). All sessions of one app on one day get aggregated into a **DailyUsageSummary**."

Classes: `UsageSession`, `DailyUsageSummary`
**SOLID: SRP** — these are pure data holders, no business logic.

---

### STEP 3: Who creates and manages sessions?
> "We need something that listens for app open/close events and creates sessions. That's the **ScreenTimeTracker**."

> "**Why Singleton?** If we have two tracker instances, sessions get double-counted. One device = one tracker = one source of truth."

Classes: `ScreenTimeTracker`
**Pattern: Singleton**

---

### STEP 4: App closed — now what? Multiple things must happen!
> "When a session ends, three things must happen: save data to disk, refresh the stats UI, check if the daily limit is hit."

> "**Problem:** If the tracker directly calls persistence, stats, and limits — that's tight coupling. Adding a new reaction means modifying the tracker."

> "**Solution: Observer Pattern.** The tracker just says 'something happened' by calling notifyObservers(). Each observer reacts independently."

> "Want to add SMS alerts later? Add one observer class. Tracker code never changes."

Classes: `UsageEventObserver` (interface), `PersistenceObserver`, `StatisticsUpdateObserver`, `UsageLimitObserver`
**Pattern: Observer** | **SOLID: OCP, SRP**

---

### STEP 5: Observer saves data... but where? (must survive reboots)
> "The PersistenceObserver needs to save data somewhere durable."

> "**Problem:** If we hardcode SQLite everywhere, we can't swap to file storage for tests."

> "**Solution: Two patterns together.**"
> "**Repository Pattern** — business logic calls saveSession(). It never knows if it's SQLite, file, or cloud."
> "**Strategy Pattern** — the actual storage backend is pluggable. SQLite for production, InMemory for unit tests."

> "New backend like cloud sync? One new strategy class. Nothing else changes."

Classes: `UsageRepository` (interface), `UsageRepositoryImpl`, `PersistenceStrategy` (interface), `SQLitePersistence`, `FilePersistence`, `SharedPrefsPersistence`
**Patterns: Repository + Strategy** | **SOLID: DIP, OCP, LSP**

---

### STEP 6: Data is stored. How do we show it to the user?
> "The stats service reads from the repository and builds a report."

> "**Problem:** UsageReport has 5+ fields — date range, daily summaries, total hours, per-app breakdown. A constructor with 6 parameters is unreadable."

> "**Solution: Builder Pattern.** `builder.setDateRange(mon, sun).addDailySummary(mon).addDailySummary(tue).build()` — clean, readable, validated."

Classes: `UsageStatisticsService`, `UsageReportBuilder`, `UsageReport`
**Pattern: Builder** | **SOLID: SRP**

---

### STEP 7: Stats work. How to keep only 7 days?
> "Simple. On every app startup, DataRetentionManager calls `repository.deleteOlderThan(today - 7)`. Storage stays bounded. Change to 30 days? One field change."

Classes: `DataRetentionManager`, `DateRange`
**SOLID: SRP**

---

### STEP 8: Everything works. How to expose it cleanly?
> "The client shouldn't know about trackers, observers, or repositories. **Facade Pattern** — one class, one API. Client calls `onAppOpened()`. Done. All wiring is hidden inside `DigitalWellbeingSystem`."

Classes: `DigitalWellbeingSystem`
**Pattern: Facade** | **SOLID: SRP, DIP**

---

### WRAP UP
> "We started with concrete models, built tracking on top, used **Observer** to decouple reactions, **Repository + Strategy** for durable and swappable persistence, **Builder** for clean reports, and **Facade** to hide it all behind one API. Six patterns, each solving a specific problem. All three requirements met."

---

## Patterns Summary

| Pattern | Step | Problem It Solves |
|---------|------|-------------------|
| Singleton | 3 | One tracker per device, no double counting |
| Observer | 4 | Decouple tracker from persistence/stats/limits |
| Repository | 5 | Business logic doesn't know how data is stored |
| Strategy | 5 | Swap storage backends without code changes |
| Builder | 6 | Construct complex report without monster constructor |
| Facade | 8 | One clean API, hide internal complexity |

## SOLID at Every Step

| Principle | Where |
|-----------|-------|
| **SRP** | Every step — each class does one thing |
| **OCP** | Steps 4, 5 — new observer or storage = new class only |
| **LSP** | Step 5 — all strategies are interchangeable |
| **ISP** | Steps 4, 5 — observer has 1 method, strategy has 3 |
| **DIP** | Steps 5, 8 — depend on interfaces, not concrete classes |

## Requirements Traceability

| Requirement | Steps |
|-------------|-------|
| Track screen time of apps | Steps 1-4 (Models + Tracker + Observers) |
| Display usage statistics | Step 6 (StatsService + Builder) |
| Persist for 7 days across reboots | Step 5 (Repository + Strategy) + Step 7 (Retention) |

## Common Follow-Up Q&A

**Q: What if the device reboots mid-session?**
> On startup, check for sessions with no endTime. Either set endTime to last checkpoint or discard. Handled in initialize().

**Q: How to add parental controls?**
> New ParentalControlObserver implementing UsageEventObserver. Register with tracker. Zero changes to existing code.

**Q: Why not just use SQLite directly?**
> Can't unit test without a database. Repository + Strategy lets us use InMemoryStrategy in tests. Fast, no disk I/O.

**Q: How does this scale to 100+ apps?**
> DailyUsageSummary aggregates per app per day. Max records = 100 apps x 7 days = 700. SQLite indexes on (date, packageName) for fast lookups.
