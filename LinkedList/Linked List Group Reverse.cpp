

    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/reverse-a-linked-list-in-groups-of-given-size

class Solution {
  public:
    Node* reverseList(Node* root){
        Node* curr = root;
        Node* prev = NULL;
        
        while(curr != NULL){
            Node* forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(!head || !head -> next || k == 1)
            return head;
        Node* curr = head;
        Node* start = head;
        Node* end = NULL;
        Node* prev = NULL;
        head = NULL;
        int cnt = 0;
        
        while(curr != NULL){
            cnt++;
            if(cnt == k){
                cnt = 0;
                Node* forward = curr -> next;
                curr -> next = NULL;
                end = reverseList(start);
                if(head == NULL)
                    head = end;
                if(prev == NULL){
                    prev = start;
                }
                else{
                    prev -> next = end;
                    prev = start;
                }
                curr = forward;
                start = curr;
            }
            else    
                curr = curr -> next;
        }
        if(cnt != 0)    
            prev -> next = reverseList(start);
        return head;
    }
};
