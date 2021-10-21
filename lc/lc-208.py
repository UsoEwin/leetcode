# lc-208-prefix tree
class TrieNode:
    def __init__(self, char):
        self.char = char
        self.is_end = False
        self.counter = 0
        self.children = {}

class Trie:

    def __init__(self):
        self.root = TrieNode("")

    def insert(self, word: str) -> None:
        '''
        insert a word 
        '''
        node = self.root
        for char in word:
            if char in node.children:
                node = node.children[char]
            else:
                new_node = TrieNode(char)
                node.children[char] = new_node
                node = new_node
        node.is_end = True

    def search(self, word: str) -> bool:
        '''
        starting at the root
        '''
        node = self.root
        for char in word:
            if char in node.children:
                node = node.children[char]
            else:
                return False
        if node.is_end == True:
            return True
        return False

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for char in prefix:
            if char in node.children:
                node = node.children[char]
            else:
                return False
        return True