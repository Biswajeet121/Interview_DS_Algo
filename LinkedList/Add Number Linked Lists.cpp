

    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/add-two-numbers-represented-by-linked-lists

class Solution {
  public:
    Node* reverseList(Node* head){
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
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        while(num1 != NULL && num1 -> data == 0){
            num1 = num1 -> next;
        }
        while(num2 != NULL && num2 -> data == 0){
            num2 = num2 -> next;
        }
        if(num1 == NULL)    return num2;
        if(num2 == NULL)    return num1;
        
        num1 = reverseList(num1);
        num2 = reverseList(num2);
        
        Node* head = num1;
        Node* prev = NULL;
        int carry = 0;
        while(num1 != NULL && num2 != NULL){
            int sum = num1 -> data + num2 -> data + carry;
            num1 -> data = sum % 10;
            carry = sum / 10;
            prev = num1;
            num1 = num1 -> next;
            num2 = num2 -> next;
        }
        if(num1 == NULL){
            prev -> next = num2;
            num1 = prev -> next;
        }
        while(num1){
            int sum = num1 -> data + carry;
            num1 -> data = sum % 10;
            carry = sum / 10;
            prev = num1;
            num1 = num1 -> next;
        }
        
        if(carry){
            Node* newNode = new Node(carry);
            prev -> next = newNode;
        }
        
        head = reverseList(head);
        return head;
    }
};
