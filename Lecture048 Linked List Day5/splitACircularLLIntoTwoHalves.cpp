// Split a Circular Linked List into two halves
// Problem Link :- https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1

// Solution Below 

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    //if list is empty or single Node
    if(head == NULL || head -> next == NULL)
    {
        return;
    }
    
    Node* fast = head;
    Node* slow = head;
    
    while(fast->next != head && fast -> next -> next != head)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
        
    if(fast -> next == head)
    {
        fast -> next = slow -> next;
    }
    else
    {
        fast -> next -> next = slow -> next;
    }   
    
    *head1_ref = head;
    *head2_ref = slow -> next;
    slow->next = head;
}
