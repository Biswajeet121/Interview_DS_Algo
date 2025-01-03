/*

    Problem Link : https://www.naukri.com/code360/problems/middle-of-linked-list_8230764?topList=ninjas-sde-sheet&problemListRedirection=true&leftPanelTabValue=PROBLEM
    
    Problem statement
    Given a singly linked list of 'N' nodes. The objective is to determine the middle node of a singly linked list. However, if the list has an even number of nodes, we return the second middle node.
    
    Note:
    1. If the list is empty, the function immediately returns None because there is no middle node to find.
    2. If the list has only one node, then the only node in the list is trivially the middle node, and the function returns that node.
    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1 :
    5
    1 2 3 4 5
    Sample Output 1 :
    3 4 5
    Explanation Of Sample Input 1 :
    
    We can clearly see that there are 5 elements in the linked list therefore the middle node is the node with value '3'.

  */
    
    Node *findMiddle(Node *head) {
        // Write your code here
        if(head -> next == NULL)
            return head;
        Node* slow = head;
        Node* fast = head -> next;
    
        while(fast != NULL){
            slow = slow -> next;
            fast = fast -> next;
            if(fast != NULL)
                fast = fast -> next;
        }
        return slow;
    }

