#include "listHelper.h"

int isIdentical(struct linkList *head1, struct linkList *head2)
{
	/* list1 and list2 has to have same data and length
	 * even if length or data mismatch , we return 
	 * list as non identical.
	 */
	while(head1 != NULL && head2 != NULL) {
		if(head1->data != head2->data)
			return 0;
		head1 = head1->next;
		head2 = head2->next;
	}
	if(head1 == NULL && head2 == NULL)
		return 1;
	else
		return 0;
}

void
main() {

        int dat;
        struct linkList *list1 = NULL, *list2 = NULL;

        InsertLinkedList(&list1, 21, 1);         /*Insert node in Beginning */
        InsertLinkedList(&list1, 31, 2);         /*Insert at position 2 */
        InsertLinkedList(&list1, 41, 3);
        InsertLinkedList(&list1, 51, 4);
        InsertLinkedList(&list1, 61, 5);
        InsertLinkedList(&list1, 72, 6);
        InsertLinkedList(&list1, 87, 7);
        InsertLinkedList(&list1, 98, 8);

        InsertLinkedList(&list2, 21, 1);         /*Insert node in Beginning */
        InsertLinkedList(&list2, 31, 2);         /*Insert at position 2 */
        InsertLinkedList(&list2, 41, 3);
        InsertLinkedList(&list2, 51, 4);
        InsertLinkedList(&list2, 61, 5);
        InsertLinkedList(&list2, 72, 6);
        InsertLinkedList(&list2, 87, 7);
        InsertLinkedList(&list2, 98, 8);

        InsertLinkedList(&list2, 2014, 9);

	if(isIdentical(list1, list2))
		printf("isIdentical\n");
	else
		printf("Not Identical\n");
}
