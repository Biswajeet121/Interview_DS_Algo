
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/merge-two-sorted-linked-lists

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        if(!head1 && !head2)    return head1;
        if(!head1 && head2 != NULL) return head2;
        if(head1 != NULL && !head2) return head1;
        
        Node* curr = new Node(-1);
        Node* head = curr;
        
        while(head1 != NULL && head2 != NULL){
            if(head1 -> data <= head2 -> data){
                curr -> next = head1;
                curr = curr -> next;
                if(head1 -> next == NULL){
                    curr -> next = head2;
                    return head -> next;
                }
                head1 = head1 -> next;
            }
            else{
                curr -> next = head2;
                curr = curr -> next;
                if(head2 -> next == NULL){
                    curr -> next = head1;
                    return head -> next;
                }
                head2 = head2 -> next;
            }
        }
        return head -> next;
    }
};
