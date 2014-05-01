#include "listHelper.h"

int countSameVals(struct linkList *node_ptr, int val)
{
	int count = 0;

	while(node_ptr != NULL) {
		if(node_ptr->data == val)
			count ++;
		node_ptr = node_ptr->next;
	}
	
	return count;
}

void
main() {

        int dat;
        struct linkList *list1 = NULL;

        InsertLinkedList(&list1, 21, 1);         /*Insert node in Beginning */
        InsertLinkedList(&list1, 31, 2);         /*Insert at position 2 */
        InsertLinkedList(&list1, 41, 3);
        InsertLinkedList(&list1, 51, 4);
        InsertLinkedList(&list1, 61, 5);
        InsertLinkedList(&list1, 72, 6);
        InsertLinkedList(&list1, 87, 7);
        InsertLinkedList(&list1, 98, 8);
        InsertLinkedList(&list1, 99, 9);
        InsertLinkedList(&list1, 99, 10);
        InsertLinkedList(&list1, 99, 11);

	displayList(list1);
	printf("Count of nodes with value 99 is %d\n", countSameVals(list1, 99));

}
