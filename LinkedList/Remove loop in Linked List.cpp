
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/remove-loop-in-linked-list

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow)    break;
        }
        
        if(slow != fast)    return;
        
        slow = head;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        
        while(slow != NULL){
            if(slow -> next == fast){
                slow -> next = NULL;
            }
            slow = slow -> next;
        }
    }
};
