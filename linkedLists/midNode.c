#include "listHelper.h"

int midNode(struct linkList *list) {
	struct linkList *snail, *horse;
	snail = horse = list;

	while(horse->next != NULL && horse->next->next != NULL)
	{
			snail = snail->next;
			horse = horse->next->next;
	}
	return(snail->data);
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

        displayList(list1);

	printf ( "Mid node of list is %d\n", midNode(list1));
        displayList(list1);

}
