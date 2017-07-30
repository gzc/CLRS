struct TrieNode {
    TrieNode *nodes[26];
    bool word;
    // Initialize your data structure here.
    TrieNode(): word(false) {
        memset(nodes, 0, sizeof(nodes));
    }
};

class Trie {
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(const string& s) {
        TrieNode *tmp = root;
        for(char ch : s) {
            int index = ch - 'a';
            if(tmp->nodes[index] == nullptr) {
                tmp->nodes[index] = new TrieNode();
            }
            tmp = tmp->nodes[index];
        }
        tmp->word = true;
    }
    
    // Returns if the word is in the trie.
    bool search(const string& key) const {
        TrieNode *tmp = root;
        for(char ch : key) {
            int index = ch - 'a';
            if(tmp->nodes[index] == nullptr) {
                return false;
            }
            tmp = tmp->nodes[index];
        }
        return tmp->word;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(const string& prefix) const {
        TrieNode *tmp = root;
        for(char ch : prefix) {
            int index = ch - 'a';
            if(tmp->nodes[index] == nullptr) {
                return false;
            }
            tmp = tmp->nodes[index];
        }
        return true;
    }
    
private:
    TrieNode* root;
};