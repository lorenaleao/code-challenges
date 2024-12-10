from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

# class Node:
#     def __hash__(self):
#       return hash((self.val, self.next, self.random))

class Solution:
    def __init__(self):
        self.visited = {}

    def initialize_nodes_map(self, head: 'Optional[Node]') -> 'dict[Node]':
        nodes_map = {}
        it = head
        while it is not None:
            nodes_map[it] = it
            it = it.next
        return nodes_map

    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None

        original_list = head
        list_copy_head = Node(head.val)
        self.visited[head] = list_copy_head

        original_list = original_list.next
        list_copy_it = list_copy_head 

        while original_list is not None:
            next_node = Node(original_list.val)
            list_copy_it.next = next_node 
            self.visited[original_list] = list_copy_it.next
            original_list = original_list.next
            list_copy_it = list_copy_it.next
    
        original_list = head
        list_copy_it = list_copy_head
        while original_list is not None:
            if original_list.random is not None:
                new_node = self.visited[original_list.random]
                list_copy_it.random = new_node
            original_list = original_list.next
            list_copy_it = list_copy_it.next

        return list_copy_head


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
