
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/merge-k-sorted-linked-lists
class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        int n = arr.size();
        vector<int> store;
        
        for(int i=0; i<n; i++){
            Node* temp = arr[i];
            while(temp != NULL){
                store.push_back(temp -> data);
                temp = temp -> next;
            }
        }
        
        sort(begin(store), end(store));
        
        Node* head = new Node(-1);
        Node* temp = head;
        for(int i=0; i<store.size(); i++){
            Node* newNode = new Node(store[i]);
            temp -> next = newNode;
            temp = newNode;
        }
        
        return head -> next;
    }
};
