/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {

    int counter = 1;
    SinglyLinkedListNode* head = llist;
    SinglyLinkedListNode* toAdd = new SinglyLinkedListNode(data);

    while(llist != nullptr) {
        if (counter == position) {
            toAdd->next = llist->next;
            llist->next = toAdd;
            
            break;
        } else{
            llist = llist->next;
        }
        counter++;
    }

    return head;
}