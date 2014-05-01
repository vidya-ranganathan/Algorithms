#include<stdio.h>
#include<malloc.h>

        struct linkList
        {
                int data;
                struct linkList *next;
        };

void displayList(struct linkList *node){
	if(node == NULL)
        {
                printf("list is empty\n");
                return;
        }


        while(node->next != NULL){
                printf("%d..", node->data);
                node = node->next;
        }
                printf("%d..", node->data);
		puts("\n");
}

void InsertLinkedList(struct linkList **head, int data, int pos) {
	struct linkList *locHead, *locTail, *newNode;
	int currPos = 1;
	locHead = locTail = *head;

	newNode = (struct linkList *)malloc(sizeof(struct linkList));
	if(newNode == NULL) {
		printf("NOMEM\n");
		return;
	}

	newNode->data = data;
	newNode->next = NULL;

	if(pos == 1 && *head == NULL)
		locHead = locTail = newNode;
	else if(pos == 1) 
	{
		newNode->next = locHead;
		locHead = newNode;
	}
	else {
		while((locTail != NULL) && (currPos <= pos - 1))
		{
			currPos++;
			if(locTail->next == NULL) {
				locTail->next = newNode;
			}
			else if(currPos == pos) {
				struct linkList *tempHead;
				tempHead = locTail->next;
				locTail->next = newNode;
				newNode->next = tempHead;
			}
			locTail = locTail->next;
		}
	}
	*head = locHead;
}
