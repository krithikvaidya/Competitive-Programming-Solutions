

// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
vector<SinglyLinkedListNode*> visited;
bool has_cycle(SinglyLinkedListNode* head) {
    if(head == NULL)
        return false;
    
    for(SinglyLinkedListNode* ptr: visited)
        if(ptr == head)
            return true;
    
    visited.push_back(head);
    return has_cycle(head -> next);
}


