/*
 * Complete the 'removeDuplicates' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    
    SinglyLinkedListNode* current = llist->next;
    SinglyLinkedListNode* prev = llist;
    while(current != nullptr) {
        if(current->data == prev->data) {
            prev->next = current->next;
            current = prev->next;
            continue;
        }
        prev = current;
        current = current->next;
    }
    return llist;
    
}