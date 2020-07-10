#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <strings.h>

#define SIZE 6
#define TRUE 1
#define FALSE 0

struct adjlist
{
  int vertexID;
  struct adjlist *next;
};

struct graph
{
  int vertices;
  struct adjlist **adjList;
};

void initGraph(struct graph **grp, int v)
{
  int i;
  struct graph *curr;
  curr = (struct graph *)malloc(sizeof(struct graph));
    if(curr == NULL)
      return;

  curr->vertices = v;
  curr->adjList = (struct adjlist **)malloc(sizeof(struct adjlist *) * v);
  for(i=0;i<v;i++)
    curr->adjList[i] = (struct adjlist *)malloc(sizeof(struct adjlist) * v);

  for(i=0;i<v;i++)
    curr->adjList[i] = NULL;

  *grp = curr;
}

struct adjlist *makeNode(int dest)
{
  struct adjlist *listnode;
  listnode = (struct adjlist *)malloc(sizeof(struct adjlist));
  if(listnode == NULL)
    return NULL;
  listnode->vertexID = dest;
 listnode->next = NULL;

  return listnode;
}

void addEdge(struct graph **grp, int src, int dest)
{
  struct adjlist *curr;
  curr = makeNode(dest);
  curr->next = (*grp)->adjList[src];
  (*grp)->adjList[src] = curr;

  return;
}


void buildgraph(struct graph *grp)
{
        addEdge(&grp, 0, 5);
        addEdge(&grp, 0, 2);
        addEdge(&grp, 1, 0);
        addEdge(&grp, 2, 5);
        addEdge(&grp, 3, 1);
        addEdge(&grp, 3, 4);
        addEdge(&grp, 4, 2);
        addEdge(&grp, 5, 4);


        /*
        addEdge(&grp, 0, 1);
        addEdge(&grp, 0, 2);
        addEdge(&grp, 1, 2);
        addEdge(&grp, 2, 0);
        addEdge(&grp, 2, 3);
        addEdge(&grp, 3, 3);
        */


}

void displayGraph(struct graph *grp)
{
  struct adjlist *curr;
  int i;

  for(i=0; i<SIZE; i++)
  {
    printf("[%d]==>",i);
    curr = grp->adjList[i];
    while(curr != NULL)
    {
      printf("%d->", curr->vertexID);
      curr = curr->next;
    }
    printf("\n");
  }
  return;
}


/***********************************************************************/
struct stackNode
{
  int data;
  struct stackNode *next;
};

void push(struct stackNode **head, int val)
{
  struct stackNode *curr = NULL;
  curr = (struct stackNode *)malloc(sizeof(struct stackNode));
  if(curr == NULL)
    return;

  curr->data = val;
  curr->next = NULL;

  if(*head == NULL)
    *head = curr;
  else
  {
    curr->next = *head;
    *head = curr;
  }
}

int pop(struct stackNode **head)
{
  int val;
  struct stackNode *del= NULL;
  del = *head;

  val = del->data;
  *head = (*head)->next;

  free(del);
  return val;
}

void displayStack(struct stackNode *head)
{
  while(head != NULL)
  {
    printf(">> %d <<", head->data);
    head = head->next;
  }
  printf("\n");
}

/***********************************************************************/
 /**************************************************************************/

// BFS

void initVisited(int **visit)
{
  int *visited;

  visited = (int *)malloc(sizeof(int) * SIZE);
  if(visited == NULL)
    return;
  // all entries marked FALSE
  memset(visited, '\0', sizeof(int) * SIZE);
  
  *visit = visited;
  return;
}

void markVisited(int **visit, int dest)
{
  int *visited = *visit;
  visited[dest] = TRUE;
}

int foundInStack(struct stackNode *currstk, int vx)
{
  while(currstk != NULL)
  {
    if(currstk->data == vx)
      return 0;
    currstk = currstk->next;
  }
  return 1;
}

int isVisited(int *visited, int vx)
{
    return (visited[vx]);
}


void dfs(struct graph **grp, int start)
{
    int *visited = NULL;
    struct graph *currgrp = NULL;
    struct stackNode *currstk = NULL;
    currgrp = *grp;

    int vx;

    initVisited(&visited);
    printf("\n\nDFS :");

    if(currgrp == NULL)
      return;

    push(&currstk, start);
  
    while(currstk != NULL)
    {
      struct adjlist *walker = NULL;

      vx = pop(&currstk);
      markVisited(&visited, vx);
      printf(": %d-->", vx);
      

      walker = currgrp->adjList[vx];
      while(walker != NULL)
      {
        int vid = walker->vertexID;
#ifdef DEBUG
        printf("\nvidya: start: debugging\n");
        printf("vid  = %d ..\n",vid);
        printf("visited[%d] = %d\n", vid, visited[vid]);
        displayStack(currstk);
        printf("\nvidya: end : debugging\n");

#endif
        // if node not in stack already and not already visited, push to stack
        if((!isVisited(visited,vid)) && (foundInStack(currstk, vid)))
        {
          //puts("vidya: pushing");
          push(&currstk, vid);
        }
        walker = walker->next;
      }

    }

}

int main()
{
    struct graph *grp = NULL;
    initGraph(&grp, SIZE);
    buildgraph(grp);

    displayGraph(grp);

/**************************************************************************/
#if DEBUG
  struct stackNode *stk = NULL;
  push(&stk, 1);
  push(&stk, 2);
  push(&stk, 3);
  push(&stk, 4);
  push(&stk, 5);
  printf("displaying stack ..\n");
  displayStack(stk);
  int rc = pop(&stk);
  displayStack(stk);

  printf("popped value is %d\n", rc);
#endif

   dfs(&grp, 3);



    return 1;
}
