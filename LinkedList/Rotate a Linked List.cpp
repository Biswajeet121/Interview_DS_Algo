

    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/rotate-a-linked-list

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        if(!head || !head -> next)
            return head;
            
        int cnt = 0;
        Node* curr = head;
        Node* tail = NULL;
        while(curr != NULL){
            cnt++;
            tail = curr;
            curr = curr -> next;
        }
        
        k = k % cnt;
        curr = head;
        while(k--){
            tail -> next = head;
            head = head -> next;
            tail = tail -> next;
            tail -> next = NULL;
        }
        
        return head;
    }
};
