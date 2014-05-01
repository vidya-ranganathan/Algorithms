#include<stdio.h>
#include "listHelper.h"

void makeNode(struct linkList **head, struct linkList **tail, int dat)
{
                struct linkList *curr;
                curr = (struct linkList*)malloc(sizeof(struct linkList));
                curr->data = dat;
                curr->next = NULL;

                if(*head == NULL) {
                        *head = *tail = curr;
		            }
                else {
			                  curr->next = *head;
			                  *head = curr;
                }

}

void
main() {

        int dat;
        struct linkList *head, *tail;

        tail = head = NULL;

        for (dat = 1; dat <= 21; dat++)
                makeNode(&head, &tail, dat);

        displayList(head);
        displayList(head);
        free(head);
}
