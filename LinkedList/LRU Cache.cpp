
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/lru-cache

class Node{
    public: 
    int key;
    int value;
    Node* prev;
    Node* next;
    
    Node(int k, int v){
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
  private:
    int capacity;
    unordered_map<int, Node*> cacheMap;
    Node* head;
    Node* tail;
    
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(cacheMap.find(key) == cacheMap.end())
            return -1;
        
        Node* node = cacheMap[key];
        remove(node);
        add(node);
        return node -> value;
    }
    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(cacheMap.find(key) != cacheMap.end()){
            Node* removeNode = cacheMap[key];
            remove(removeNode);
            delete removeNode;
        }
        
        Node* newNode = new Node(key, value);
        cacheMap[key] = newNode;
        add(newNode);
        
        if(cacheMap.size() > capacity){
            Node* lastNode = tail -> prev;
            remove(lastNode);
            cacheMap.erase(lastNode -> key);
            delete lastNode;
        }
    }
    void remove(Node *node){
        Node* nextNode = node -> next;
        Node* prevNode = node -> prev;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }
    void add(Node* node){
        Node* nextNode = head -> next;
        head -> next = node;
        node -> prev = head;
        node -> next = nextNode;
        nextNode -> prev = node;
    }
};
