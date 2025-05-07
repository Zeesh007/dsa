# Consider telephone book database of N clients. Make use of a hash table implementation
# to quickly look up client‘s telephone number. Make use of two collision handling
# techniques and compare them using number of comparisons required to find a set of
# telephone numbers.
# Solution:# Hash table using Separate Chaining
class HashTableChaining:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]  # Each bucket is a list
   
    def hash_function(self, key):
        return hash(key) % self.size
   
    def insert(self, key, value):
        index = self.hash_function(key)
        self.table[index].append((key, value))
   
    def lookup(self, key):
        index = self.hash_function(key)
        comparisons = 0
        for k, v in self.table[index]:
            comparisons += 1
            if k == key:
                return v, comparisons
        return None, comparisons


# Hash table using Open Addressing (Linear Probing)
class HashTableOpenAddressing:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size  # Empty slots are None
   
    def hash_function(self, key):
        return hash(key) % self.size
   
    def insert(self, key, value):
        index = self.hash_function(key)
        original_index = index
        while self.table[index] is not None and self.table[index][0] != key:
            index = (index + 1) % self.size
            if index == original_index:  # Table is full
                raise Exception("Hash Table is full")
        self.table[index] = (key, value)
   
    def lookup(self, key):
        index = self.hash_function(key)
        original_index = index
        comparisons = 0
        while self.table[index] is not None:
            comparisons += 1
            if self.table[index][0] == key:
                return self.table[index][1], comparisons
            index = (index + 1) % self.size
            if index == original_index:  # Full loop
                break
        return None, comparisons

  # Create datasets
telephone_data = {
    "Alice": "123-456-7890",
    "Bob": "234-567-8901",
    "Charlie": "345-678-9012",
    "David": "456-789-0123",
    "Eve": "567-890-1234"
}

# Collision-prone keys for testing
collision_keys = ["John", "Jane", "Jake", "Jill", "Judy"]

# Initialize hash tables
size = 10  # Small size to induce collisions
hash_table_chain = HashTableChaining(size)
hash_table_open = HashTableOpenAddressing(size)

# Populate tables
for name, number in telephone_data.items():
    hash_table_chain.insert(name, number)
    hash_table_open.insert(name, number)

# Lookup test data
lookup_keys = ["Alice", "Charlie", "Eve", "NonExistent"]

# Compare collision handling
print("Separate Chaining Results:")
for key in lookup_keys:
    result, comparisons = hash_table_chain.lookup(key)
    print(f"Key: {key}, Result: {result}, Comparisons: {comparisons}")

print("\nOpen Addressing Results:")
for key in lookup_keys:
    result, comparisons = hash_table_open.lookup(key)
    print(f"Key: {key}, Result: {result}, Comparisons: {comparisons}")