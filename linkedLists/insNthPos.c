#include <stdio.h>
#include "listHelper.h"

void
main() {

        int dat;
        struct linkList *head = NULL; 

	InsertLinkedList(&head, 21, 1);		/*Insert node in Beginning */
	InsertLinkedList(&head, 31, 2);		/*Insert at position 2 */
	InsertLinkedList(&head, 41, 3);
	InsertLinkedList(&head, 51, 4);
	InsertLinkedList(&head, 61, 5);
	InsertLinkedList(&head, 72, 6);
	InsertLinkedList(&head, 99, 1);
        displayList(head);
	
	InsertLinkedList(&head, 199, 3);
        displayList(head);
}
