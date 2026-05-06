#include <iostream>
#include <vector>
#include <optional>

// Define the HashMap with Open Addressing and Linear Probing
template<typename K, typename V>
class OpenAddressingHashMap {
private:
    struct Entry {
        K key;
        V value;
        bool isOccupied;
        bool isDeleted;

        Entry() : isOccupied(false), isDeleted(false) {}
    };

    std::vector<Entry> table;
    int capacity;
    int size;

    int hash(const K& key) const {
        return std::hash<K>{}(key) % capacity;
    }

public:
    OpenAddressingHashMap(int cap = 8) : capacity(cap), size(0) {
        table.resize(capacity);
    }

    void insert(const K& key, const V& value) {
        if (size >= capacity / 2) resize();

        int idx = hash(key);
        while (table[idx].isOccupied && !table[idx].isDeleted && table[idx].key != key) {
            idx = (idx + 1) % capacity; // Linear probing
        }

        if (!table[idx].isOccupied || table[idx].isDeleted) {
            table[idx].key = key;
            table[idx].value = value;
            table[idx].isOccupied = true;
            table[idx].isDeleted = false;
            ++size;
        } else {
            table[idx].value = value; // Update existing value
        }
    }

    std::optional<V> get(const K& key) const {
        int idx = hash(key);
        while (table[idx].isOccupied) {
            if (!table[idx].isDeleted && table[idx].key == key) {
                return table[idx].value;
            }
            idx = (idx + 1) % capacity; // Linear probing
        }
        return std::nullopt;
    }

    void remove(const K& key) {
        int idx = hash(key);
        while (table[idx].isOccupied) {
            if (!table[idx].isDeleted && table[idx].key == key) {
                table[idx].isDeleted = true;
                --size;
                return;
            }
            idx = (idx + 1) % capacity; // Linear probing
        }
    }

private:
    void resize() {
        int newCapacity = capacity * 2;
        std::vector<Entry> newTable(newCapacity);

        for (const auto& entry : table) {
            if (entry.isOccupied && !entry.isDeleted) {
                int idx = std::hash<K>{}(entry.key) % newCapacity;
                while (newTable[idx].isOccupied) {
                    idx = (idx + 1) % newCapacity;
                }
                newTable[idx] = entry;
            }
        }

        table = std::move(newTable);
        capacity = newCapacity;
    }
};

// Usage example
int main() {
    OpenAddressingHashMap<int, std::string> map;
    map.insert(1, "One");
    map.insert(2, "Two");
    map.insert(3, "Three");

    auto result = map.get(2);
    if (result.has_value()) {
        std::cout << "Key 2 has value: " << result.value() << std::endl;
    }

    map.remove(2);
    result = map.get(2);
    if (!result.has_value()) {
        std::cout << "Key 2 has been removed." << std::endl;
    }

    return 0;
}