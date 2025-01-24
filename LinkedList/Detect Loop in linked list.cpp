

    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/detect-loop-in-linked-list

class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        if(head -> next == NULL)
            return false;
        if(head -> next == head)
            return true;
        Node* slow = head;
        Node* fast = head -> next;
        while(fast != NULL){
            slow = slow -> next;
            fast = fast -> next;
            if(fast == NULL)    return false;
            if(fast == slow)    return true;
            
            if(fast -> next)
                fast = fast -> next;
            if(fast == NULL)    return false;
            if(fast == slow)    return true;
        }
        return true;
    }
};
