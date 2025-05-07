# Problem Statement : Implement all the functions of a dictionary (ADT) using hashing and handle collisions
# using chaining with / without replacement.
# Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys
# must be unique
# Standard Operations: Insert(key, value), Find(key), Delete(key)   
# Solution :
class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size  # List for buckets

    def hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        if self.table[index] is None:
            # If bucket is empty, create a new list and insert the key-value pair
            self.table[index] = [(key, value)]
        else:
            # Check if the key already exists
            for i, (k, v) in enumerate(self.table[index]):
                if k == key:
                    # Replace the existing key-value pair
                    self.table[index][i] = (key, value)
                    return
            # If key does not exist, append the new key-value pair
            self.table[index].append((key, value))

    def find(self, key):
        index = self.hash_function(key)
        bucket = self.table[index]

        if bucket is not None:
            # Search for the key in the bucket
            for k, v in bucket:
                if k == key:
                    return v

        return None  # Key not found

    def delete(self, key):
        index = self.hash_function(key)
        bucket = self.table[index]

        if bucket is not None:
            # Search for the key in the bucket
            for i, (k, v) in enumerate(bucket):
                if k == key:
                    # Remove the key-value pair
                    del bucket[i]
                    # Remove the bucket if it is now empty
                    if not bucket:
                        self.table[index] = None
                    return True

        return False  # Key not found

    def display(self):
        print("\nHash Table:")
        for i, bucket in enumerate(self.table):
            print(f"Bucket {i}: {bucket}")

# Example usage
if __name__ == "__main__":
    hash_table = HashTable(size=10)

    # Insert operations
    hash_table.insert("Alice", 25)
    hash_table.insert("Bob", 30)
    hash_table.insert("Charlie", 35)
    hash_table.insert("Alice", 40)  # Replace value for "Alice"

    # Display the hash table
    hash_table.display()

    # Find operations
    print("\nFind Alice:", hash_table.find("Alice"))
    print("Find Bob:", hash_table.find("Bob"))
    print("Find NonExistent:", hash_table.find("NonExistent"))

    # Delete operations
    print("\nDelete Bob:", hash_table.delete("Bob"))
    print("Delete NonExistent:", hash_table.delete("NonExistent"))

    # Display after deletions
    hash_table.display()