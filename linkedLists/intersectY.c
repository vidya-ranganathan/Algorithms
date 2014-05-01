#include "listHelper.h"

int intersectNode(struct linkList *l1,  struct linkList *l2, int m, int n) {

	/*     l1
		\    l2
		 \  /
		  \/
		   |
		   |
	l1 is list1 with length m
	l2 is list2 with length n
	here, m is 5 and n is 4
	so diff = abs(m-n) = 1
	we need to hop 1 step on l1 to reach l2's length.
	from here on, we loop till end of list and verify id l1 == l2
	if l1 == l2 somewhere, we have a Y list
	*/

	int diff = abs (m -n );
	if ( m > n) {
		while ( diff ) {
			diff--;
			l1 = l1->next;
		}
	}
	if ( n > m ) {
		while ( diff ) {
			diff--;
			l2 = l2->next;
		}
	}

	while (l1 != NULL || l2 != NULL ) {
		if ( l1 == l2) 
			return l1->data;
		else {
			l1 = l1->next;
			l2 = l2->next;
		}
	}
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

        InsertLinkedList(&list2, 91, 1);
        InsertLinkedList(&list2, 92, 2);
        InsertLinkedList(&list2, 93, 3);
        InsertLinkedList(&list2, 94, 4);
        displayList(list1);
        displayList(list2);

	/* build a Y list */
	list2->next->next->next->next = list1->next->next->next;
        displayList(list1);
        displayList(list2);

	printf ( "Intersecting node is %d\n", intersectNode(list1, list2, 7, 8));
}
