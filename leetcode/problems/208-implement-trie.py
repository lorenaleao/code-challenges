class TrieNode:
    def __init__(self):
        self.children = {}
        self.eow = False

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.eow = True
    
    def search(self, word: str) -> bool:
        curr = self.root
        for c in word:
            if c not in curr.children:
                return False
            curr = curr.children[c]
        if curr.eow:
            return True
        return False

    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        for c in prefix:
            if c not in curr.children:
                return False
            curr = curr.children[c]
        return True
        

["Trie","insert","search","search","startsWith","insert","search"]
[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]

# Your Trie object will be instantiated and called as such:
obj = Trie()
obj.insert("apple")
assert(obj.search("apple")) == True, "Oh no!"
assert(obj.search("app")) == False, "Oh no!"
assert(obj.startsWith("app")) == True, "Oh no!"
obj.insert("app")
assert(obj.search("app")) == True, "Oh no!"
