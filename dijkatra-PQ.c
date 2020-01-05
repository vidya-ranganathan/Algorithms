
// C / C++ program for Dijkstra's shortest path algorithm for adjacency 
// list representation of &grp 

#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

#define SIZE 9

#define bool int
#define true 1
#define false 0

// A structure to represent a node in adjacency list 
struct adjlist 
{ 
	int dest; 
	int weight; 
	struct adjlist* next; 
}; 


// A structure to represent a &grp. A &grp is an adjList of adjacency lists. 
// Size of adjList will be V (number of vertices in &grp) 
struct graph 
{ 
	int V; 
	struct adjlist **adjList; 
}; 

// A utility function to create a new adjacency list node 
struct adjlist* newadjlist(int dest, int weight) 
{ 
	struct adjlist* curr = 
			(struct adjlist*) malloc(sizeof(struct adjlist)); 
	curr->dest = dest; 
	curr->weight = weight; 
	curr->next = NULL; 
	return curr; 
} 

// A utility function that creates a &grp of V vertices 
struct graph* creategraph(int V) 
{ 
	struct graph* grp = (struct graph*) malloc(sizeof(struct graph)); 
	grp->V = V; 

	// Create an adjList of adjacency lists. Size of adjList will be V 
	grp->adjList = (struct adjlist **) malloc(V * sizeof(struct adjlist)); 

	int i;
	for (i = 0; i < V; ++i) 
		grp->adjList[i]= NULL; 

	return grp; 
} 

// Adds an edge to an undirected &grp 
void addEdge(struct graph *grp, int src, int dest, int weight) 
{ 
	// Add an edge from src to dest. A new node is added to the adjacency 
	// list of src. The node is added at the begining 
	struct adjlist* curr = newadjlist(dest, weight); 
	curr->next = grp->adjList[src]; 
	grp->adjList[src]= curr; 

	// Since &grp is undirected, add an edge from dest to src also 

	curr = newadjlist(src, weight); 
	curr->next = grp->adjList[dest]; 
	grp->adjList[dest]= curr; 
} 

struct graph *transpose(struct graph *grp)
{
        struct graph *trp = NULL;
        struct adjlist *walker = NULL;

        trp = creategraph(SIZE);

        int v;
        for(v=0; v<SIZE; v++)
        {
                walker = grp->adjList[v];
                while(walker != NULL)
                {
                        addEdge(trp, walker->dest, v, walker->weight);
                        walker = walker->next;
                }
        }
        return trp;
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
      printf("%d->", curr->dest);
      curr = curr->next;
    }
    printf("\n");
  }
  return;
}

// Driver program to test above functions 
struct graph *buildGraph() 
{ 
	// create the &grp given in above fugure 
	int V = SIZE; 
	struct graph *grp = creategraph(V); 

        addEdge(grp, 0, 1, 4);
        addEdge(grp, 0, 7, 8);
        addEdge(grp, 1, 2, 8);
        addEdge(grp, 1, 7, 11);
        addEdge(grp, 2, 3, 7);
        addEdge(grp, 2, 8, 2);
        addEdge(grp, 2, 5, 4);
        addEdge(grp, 3, 4, 9);
        addEdge(grp, 3, 5, 14);
        addEdge(grp, 4, 5, 10);
        addEdge(grp, 5, 6, 2);
        addEdge(grp, 6, 7, 1);
        addEdge(grp, 6, 8, 6);
        addEdge(grp, 7, 8, 7);


/*
	addEdge(grp, 0, 5, 0 );
	addEdge(grp, 0, 2, 1 );
	addEdge(grp, 1, 0, 2 );
	addEdge(grp, 2, 5, 3 );
	addEdge(grp, 3, 1, 4 );
	addEdge(grp, 3, 4, 5 );
	addEdge(grp, 4, 2, 6 );
	addEdge(grp, 5, 4, 7 );
*/

	return grp; 
} 
/****************************************************************************************/


struct pqNode
{
	int data;
	int priority;
	struct pqNode *next;
};

struct pqNode *makeNode(int data, int priority)
{
	struct pqNode *curr;
	curr = (struct pqNode *)malloc(sizeof(struct pqNode));
	if(curr == NULL)
		return NULL;

	curr->data = data;
	curr->priority = priority;
	curr->next = NULL;

	return curr;
}

void pushQ(struct pqNode **head, int data, int priority)
{
	struct pqNode *curr = NULL, *new = NULL;
	curr = *head;

	new = makeNode(data, priority);
	if(curr == NULL)
	{
		curr = new;
	}
	else if(new->priority > curr->priority)
	{
		new->next = curr;
		curr = new;
	}
	else
	{
		struct pqNode *walker = curr;
		if(walker->next == NULL)
		{
			walker->next = new;
		}
		else
		{
			while(walker->next != NULL && walker->next->priority > new->priority)
			{
				new->next = walker->next;
				walker->next = new;
			}
		}
	}

	*head = curr;

	return;
}

int isEmptyPQ(struct pqNode *head)
{
	if(head != NULL)
		return 0;
	else
		return 1;
}

int peekQ(struct pqNode *head)
{
	return(head->data);
}

void popQ(struct pqNode **head)
{
	struct pqNode *curr = NULL;
	curr = *head;

	struct pqNode *del = NULL;
	del = curr;

	free(del);

	curr = curr->next;
	*head = curr;

	return;
}

void displayPQ(struct pqNode *head)
{
	while(head != NULL)
	{
		printf("##%d##::##%d\n", head->priority, head->data);
		head = head->next;
	}
	printf("\n");
	return;
}

int deleteMin(struct pqNode **head)
{
	int data;
	struct pqNode *curr = NULL, *delNode = NULL;
	curr = *head;

	if(curr == NULL)
		return -1;

	if(curr->next == NULL)
	{
		data = curr->data;
		free(curr);
		*head = NULL;
	}
	else
	{
		while(curr->next->next != NULL)
			curr = curr->next;

		delNode = curr->next;
		data = delNode->data;
		curr->next = NULL;

		free(delNode);
	}
	
	return data;

}

/******************************************************************************/
struct infinity
{
	int Distance;
	int Paths;
} inf[SIZE];

void displayInfinity(struct infinity inf[])
{
	int i;
	printf("Vertex\t\tDistance\t\tPath\n");
	for(i=0; i<SIZE; i++)
	{
		printf("%d\t\t%d\t\t%d\n", i, inf[i].Distance, inf[i].Paths);
	}
	return;
}

void dijkstra(struct graph *grp, int start)
{
	int newDistance;
	int vert, wt;
	struct adjlist *walker = NULL;

	struct pqNode *PQ = NULL;

	int i;
	
	pushQ(&PQ,start, 0);
	for(i=0; i< SIZE; i++)
		inf[i].Distance = -1;

	inf[start].Distance = 0;

	while(!isEmptyPQ(PQ))
	{
		vert = deleteMin(&PQ);
		walker = grp->adjList[vert];

		while(walker != NULL)
		{
			newDistance = inf[vert].Distance + walker->weight;
			if( inf[walker->dest].Distance == -1)
			{
				inf[walker->dest].Distance = newDistance;
				pushQ(&PQ, walker->dest, newDistance);
				inf[walker->dest].Paths = vert;
			}

			if(inf[walker->dest].Distance > newDistance)
			{
				inf[walker->dest].Distance = newDistance;
				/* update priority of vertex walker->dest = newDistance */
				struct pqNode *pqCurr = NULL;
				pqCurr = PQ;
				while(pqCurr != NULL)
				{
					if(pqCurr->data == walker->dest)
					{
						pqCurr->priority = newDistance;
						break;
					}
					pqCurr = pqCurr->next;
				}
				inf[walker->dest].Paths = vert;
			}

			walker = walker->next;
		}
	}

	displayInfinity(inf);
	return;
}

/******************************************************************************/

int main()
{
	struct pqNode *head = NULL;
	pushQ(&head, 12, 1);
	pushQ(&head, 22, 2);
	pushQ(&head, 42, 4);
	pushQ(&head, 62, 6);
	pushQ(&head, 72, 7);
	pushQ(&head, 52, 5);
	pushQ(&head, 82, 8);
	pushQ(&head, 92, 9);
	pushQ(&head, 32, 3);

	displayPQ(head);

	if(isEmptyPQ(head) == 0)
		printf("top node is %d\n", peekQ(head));

	popQ(&head);
	popQ(&head);
	popQ(&head);
	popQ(&head);
	displayPQ(head);
	if(isEmptyPQ(head) == 0)
		printf("top node is %d\n", peekQ(head));

	int minVal = deleteMin(&head);
	printf("min node  val is %d\n", minVal);

	displayPQ(head);

	struct graph *grp = NULL;
	grp = buildGraph();

	displayGraph(grp);
	dijkstra(grp, 0);

	return 0;
}
