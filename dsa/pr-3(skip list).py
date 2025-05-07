# Problem Statement : For given set of elements create skip list. Find the element in the set that is closest to
# some given value. (note: Decide the level of element in the list Randomly with some

# upper limit)
# Code : 

import random
class Node:
    def __init__(self, height, value):
        self.value = value
        self.next = [None]*height

class SkipList:
    def __init__(self, max_height=16, p=0.5):
        self.max_height = max_height
        self.p = p
        self.head = Node(max_height, float('-inf'))

    def _random_height(self):
        height = 1
        while height < self.max_height and random.random() < self.p:
            height += 1
        return height

    def insert(self, value):
        height = self._random_height()
        node = Node(height, value)
        update = [self.head]*height
        current = self.head

        for i in range(height-1, -1, -1):
            while current.next[i] and current.next[i].value < value:
                current = current.next[i]
            update[i] = current

        for i in range(height):
            node.next[i] = update[i].next[i]
            update[i].next[i] = node

    def find_closest(self, value):
        current = self.head
        closest = float('inf')

        for i in range(self.max_height-1, -1, -1):
            while current.next[i] and current.next[i].value <= value:
                current = current.next[i]
            if abs(current.value - value) < abs(closest - value):
                closest = current.value

        return closest
    def print_skip_list(self):
        for i in range(self.max_height-1, -1, -1):
            node = self.head
            print(f"Level {i}: ", end="")
            while node.next[i]:
                print(node.next[i].value, end=" ")
                node = node.next[i]
            print()
skip_list = SkipList()
elements = [3, 6, 7, 9, 12, 19, 17, 26, 21, 25]
for element in elements:
    skip_list.insert(element)
skip_list.print_skip_list()
value = 20
closest_element = skip_list.find_closest(value)
print(f"The element closest to {value} is {closest_element}")