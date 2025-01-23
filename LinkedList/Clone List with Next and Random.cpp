

    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/clone-a-linked-list-with-next-and-random-pointer

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        Node* curr = head;
        while(curr != NULL){
            Node* forward = curr -> next;
            Node* newNode = new Node(curr -> data);
            newNode -> next = forward;
            curr -> next = newNode;
            curr = forward;
        }
        
        curr = head;
        while(curr != NULL){
            if(curr -> random == NULL){
                curr -> next -> random = NULL;
            }
            else{
                curr -> next -> random = curr -> random -> next;
            }
            curr = curr -> next -> next;
        }
        
        Node* copy = head -> next;
        Node* temp1 = head;
        Node* temp2 = head -> next;
        
        while(temp1 != NULL){
            temp1 -> next = temp2 -> next;
            temp1 = temp1 -> next;
            if(temp1 != NULL){
                temp2 -> next = temp1 -> next;
                temp2 = temp2 -> next;
            }
        }
        
        return copy;
    }
};
