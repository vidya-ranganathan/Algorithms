#include "listHelper.h"

/* Function to delete the entire linked list */
void delList(struct linkList** head)
{
   struct linkList* current = *head, *next;
 
   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }

   *head = NULL;
 
}

void
main() {

        int dat;
        struct linkList *list1 = NULL;

        InsertLinkedList(&list1, 21, 1);         /*Insert linkList in Beginning */
        InsertLinkedList(&list1, 31, 2);         /*Insert at position 2 */
        InsertLinkedList(&list1, 41, 3);
        InsertLinkedList(&list1, 51, 4);
        InsertLinkedList(&list1, 61, 5);
        InsertLinkedList(&list1, 72, 6);
        InsertLinkedList(&list1, 87, 7);
        InsertLinkedList(&list1, 98, 8);

	displayList(list1);
	delList(&list1);
	displayList(list1);
}
