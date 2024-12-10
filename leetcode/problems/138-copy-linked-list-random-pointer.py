from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

# There is no need to implement a hash function, the type is already hashable
# class Node:
#     def __hash__(self):
#       return hash((self.val, self.next, self.random))

class Solution:
    def __init__(self):
        self.visited = {}

    def get_cloned_node(self, node: 'Optional[Node]') -> 'Optional[Node]':
        if node is None:
            return None
        if node in self.visited:
            return self.visited[node]
        self.visited[node] = Node(node.val)
        return self.visited[node]

    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None

        old_node = head
        new_node = Node(head.val)
        self.visited[old_node] = new_node

        while old_node is not None:
            new_node.random = self.get_cloned_node(old_node.random)
            new_node.next = self.get_cloned_node(old_node.next)

            old_node = old_node.next
            new_node = new_node.next

        return self.visited[head]


def create_linked_list(head_list):
    # Create all nodes and store them in a list for easy access
    nodes = [Node(val) for val, _ in head_list]
    
    # Set up the next pointers
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
    
    # Set up the random pointers
    for i, (_, random_index) in enumerate(head_list):
        if random_index is not None:
            nodes[i].random = nodes[random_index]
    
    # Return the head of the list
    return nodes[0] if nodes else None

# Example input
head_list = [[7, None], [13, 0], [11, 4], [10, 2], [1, 0]]
head = create_linked_list(head_list)

# To print the linked list (values of nodes), you can iterate over it:
def print_list(head):
    current = head
    while current:
        print(f"Node val: {current.val}, Random val: {current.random.val if current.random else None}")
        current = current.next

        
s = Solution()
print_list(head)
copy = s.copyRandomList(head)
print("--------------------------------------")
print_list(copy)
