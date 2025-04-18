
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tries-gfg-160/problem/trie-insert-and-search0651

class TrieNode{
  public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
    
};

class Trie {
  public:
    TrieNode* root;
    
    Trie() {
        // implement Trie
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string w){
        if(w.size() == 0){
            root -> isTerminal = true;
            return;
        }
        int index = w[0] - 'a';
        TrieNode* child;
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            child = new TrieNode(w[0]);
            root -> children[index] = child;
        }
        insertUtil(child, w.substr(1));
    }
    
    bool searchUtil(TrieNode* root, string w){
        if(w.size() == 0){
            return root -> isTerminal;
        }
        int index = w[0] - 'a';
        TrieNode* child;
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            return false;
        }
        return searchUtil(child, w.substr(1));
    }
    
    bool isPrefixUtil(TrieNode* root, string w){
        if(w.size() == 0){
            return true;
        }
        int index = w[0] - 'a';
        TrieNode* child;
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            return false;
        }
        return isPrefixUtil(child, w.substr(1));
    }

    void insert(string &word) {
        // insert word into Trie
        insertUtil(root, word);
    }

    bool search(string &word) {
        // search word in the Trie
        return searchUtil(root, word);
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        return isPrefixUtil(root, word);
    }
};
