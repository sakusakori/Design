# Online Shopping System — LLD Interview Guide

## How to Explain This Diagram (Step-by-Step Script)

### Opening (30 seconds)
> "I'll walk through the Online Shopping System design using a **top-down approach** — starting from the entry point, moving through the core flows, and highlighting the design patterns used at each layer."

---

### Step 1: System Entry Point — Facade Pattern
> "The **OnlineShoppingSystem** is the single entry point. It acts as a **Facade** that coordinates all subsystems — OrderService, PaymentService, SearchService. Clients never interact with internal services directly. This keeps the API surface small and decouples the client from the subsystem complexity."

**Key point:** Mention Singleton if asked — only one instance of the system exists.

---

### Step 2: User Management
> "A **Customer** has an **Account** (with authentication) and an **Address**. The Account holds a **ShoppingCart**. This separation follows **Single Responsibility Principle** — Customer handles identity, Account handles auth, Address is a reusable value object."

---

### Step 3: Product Catalog — Decorator Pattern
> "Products are modeled using the **Decorator Pattern**. There's a **Product interface**, a **BaseProduct** concrete class, and a **ProductDecorator** abstract class. Concrete decorators like **GiftWrapDecorator** add behavior (extra cost, description) at runtime without modifying BaseProduct."

**Why Decorator here?**
> "If we used inheritance, we'd need classes like `GiftWrappedElectronicProduct`, `GiftWrappedGroceryProduct` — a combinatorial explosion. Decorator lets us compose behaviors: `new GiftWrapDecorator(new InsuranceDecorator(baseProduct))`."

**SOLID callout:** Open/Closed Principle — we can add new decorators without changing existing product code.

---

### Step 4: Shopping Cart
> "The ShoppingCart holds **CartItems**, each referencing a Product and quantity. When a customer is ready, the cart contents are converted into **OrderLineItems** during order creation."

---

### Step 5: Order Creation
> "When the customer places an order, **OrderService** creates an **Order** object. It first checks stock via **InventoryService**. The Order contains OrderLineItems, tracks OrderStatus, and holds a reference to the current **OrderState**."

> "This is the **central domain object** — it participates in both the State Pattern and Observer Pattern."

---

### Step 6: Payment Processing — Strategy Pattern
> "Payment is handled via the **Strategy Pattern**. The **PaymentStrategy** interface defines a `pay(amount)` method. Concrete strategies — **CreditCardPaymentStrategy**, **UpiPaymentStrategy** — implement it differently. PaymentService delegates to whichever strategy the customer chose."

**Why Strategy here?**
> "New payment methods (Wallet, NetBanking, PayPal) can be added by implementing the interface — no changes to PaymentService. The algorithm varies, the interface stays the same."

**SOLID callout:** Open/Closed Principle + Dependency Inversion — PaymentService depends on the abstraction (PaymentStrategy), not concrete implementations.

---

### Step 7: Order State Transitions — State Pattern
> "After creation, the Order moves through states: **Placed → Shipped → Delivered** (or **Cancelled** at certain points). Each state is a class implementing the **OrderState** interface. The Order delegates operations like `shipOrder()` or `cancelOrder()` to its current state object."

**State transition rules (encoded in state classes):**
- **PlacedState** → can ship or cancel
- **ShippedState** → can deliver or cancel
- **DeliveredState** → terminal state
- **CancelledState** → terminal state

**Why State here?**
> "Without it, we'd have massive if-else chains in Order: `if (status == PLACED) { ... } else if (status == SHIPPED) { ... }`. The State Pattern eliminates this — each state class knows what transitions are valid from itself."

**SOLID callout:** Single Responsibility — each state class handles only its own transition logic.

---

### Step 8: Notifications — Observer Pattern
> "Order implements the **Subject** interface. When the order state changes, it calls `notifyObservers()`. Registered observers — **EmailNotificationObserver**, **PushNotificationObserver** — receive the update and send notifications via their respective channels."

**Why Observer here?**
> "The Order shouldn't know *how* to send emails or push notifications. It just says 'something changed.' Observers handle the rest. Adding SMS notifications means adding one new observer — no changes to Order."

**SOLID callout:** Open/Closed + Single Responsibility — Order doesn't know about notification channels.

---

### Closing (15 seconds)
> "To summarize: the system uses **Facade** for a clean API, **Strategy** for pluggable payments, **State** for clean order transitions, **Observer** for decoupled notifications, and **Decorator** for composable product features. All of these support the **Open/Closed Principle** — the system is extensible without modifying existing code."

---

## Design Patterns Summary Table

| Pattern | Where Applied | Problem It Solves | Key Classes |
|---------|--------------|-------------------|-------------|
| **Facade** | OnlineShoppingSystem | Hides subsystem complexity from clients | OnlineShoppingSystem → OrderService, PaymentService, SearchService |
| **Strategy** | Payment Processing | Swap payment algorithms at runtime | PaymentStrategy, CreditCardPaymentStrategy, UpiPaymentStrategy |
| **State** | Order Lifecycle | Eliminate state-based conditionals, enforce valid transitions | OrderState, PlacedState, ShippedState, DeliveredState, CancelledState |
| **Observer** | Order Notifications | Decouple order from notification mechanisms | Subject, OrderObserver, EmailNotificationObserver, PushNotificationObserver |
| **Decorator** | Product Features | Add dynamic product features without subclass explosion | Product, ProductDecorator, GiftWrapDecorator |

---

## SOLID Principles Mapping

| Principle | How It's Applied |
|-----------|-----------------|
| **S** — Single Responsibility | Each class has one job: Order manages order data, OrderState handles transitions, PaymentStrategy handles one payment method |
| **O** — Open/Closed | New payment methods, new decorators, new observers, new states — all added via new classes, no existing code modified |
| **L** — Liskov Substitution | All concrete strategies are interchangeable; all states are interchangeable; all observers are interchangeable |
| **I** — Interface Segregation | Small focused interfaces: PaymentStrategy (one method), OrderObserver (one method), Product (only product concerns) |
| **D** — Dependency Inversion | PaymentService depends on PaymentStrategy (abstraction), not CreditCardPaymentStrategy (concrete). Order depends on OrderState interface, not PlacedState. |

---

## Common Interview Follow-Up Questions

**Q: "How would you add a new payment method?"**
> Create a new class implementing PaymentStrategy. No changes to PaymentService or Order. Pass it in at order time.

**Q: "What happens if we need to add a 'Returned' state?"**
> Create ReturnedState implementing OrderState. Add transition from DeliveredState to ReturnedState. Existing states don't change.

**Q: "How would you add SMS notifications?"**
> Create SmsNotificationObserver implementing OrderObserver. Register it on the Order. No changes to Order or existing observers.

**Q: "Why not use inheritance for products?"**
> Combinatorial explosion. With 4 categories and 3 features, you'd need 4 x 2^3 = 32 subclasses. Decorator gives the same power with 4 + 3 classes.

**Q: "Is this thread-safe?"**
> For production, InventoryService.updateStock() needs synchronization. ShoppingCart operations should be atomic. Order state transitions need to be guarded against race conditions (e.g., two threads trying to ship and cancel simultaneously).

**Q: "How does this scale?"**
> Services (OrderService, PaymentService, SearchService, InventoryService) are stateless and can be horizontally scaled. State is in Order/Customer objects which map to database rows. SearchService could be backed by Elasticsearch for large catalogs.
