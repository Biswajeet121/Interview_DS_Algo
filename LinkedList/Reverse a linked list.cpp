
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/reverse-a-linked-list

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        if(!head || !head -> next)  return head;;
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr != NULL){
            Node* forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
};
