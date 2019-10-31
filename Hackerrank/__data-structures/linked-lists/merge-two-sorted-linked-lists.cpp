

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* createNewNode(int val)
{
    SinglyLinkedListNode* node = new SinglyLinkedListNode(val);
    node -> next = NULL;
    return node;
}
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* ptr;

    SinglyLinkedListNode* fptr = head1;
    SinglyLinkedListNode* sptr = head2;

    if(fptr -> data < sptr -> data)
    {
        head = createNewNode(fptr -> data);
        ptr = head;
        fptr = fptr -> next;
    }
    else
    {
        head = createNewNode(sptr -> data);
        ptr = head;
        sptr = sptr -> next;
    }

    SinglyLinkedListNode* temp;

    while(fptr != NULL && sptr != NULL)
    {
        if(fptr -> data < sptr -> data)
        {
            temp = createNewNode(fptr -> data);
            fptr = fptr -> next;
        }
        else
        {
            temp = createNewNode(sptr -> data);
            sptr = sptr -> next;
        }
        ptr -> next = temp;
        ptr = temp;
    }

    while(fptr != NULL)
    {  
        temp = createNewNode(fptr -> data);
        fptr = fptr -> next;

        ptr -> next = temp;
        ptr = temp;
    }

    while(sptr != NULL)
    {
        temp = createNewNode(sptr -> data);
        sptr = sptr -> next;

        ptr -> next = temp;
        ptr = temp;
    }
    return head;
}


