#include "treeHelper.h"
#include <stdlib.h>

/* prints cousin of a given node in a binary tree,
 * for this compute level of the node and then, 
 * grab the parent of the node as well.
 * Now, print the nodes at same level whose parent
 * is not node's parent.
 */


int level4me;
struct	binNode *parent;

void cousin(struct binNode* node, int me, int mylevel)
{
  if (node==NULL)
        return;

  if (mylevel == 0 && parent->left != node && parent->right != node)
  {
	printf("my [%d] cousins are .. [%d]\n", me, node->data);
  }

  cousin(node->left, me, mylevel - 1);
  cousin(node->right, me, mylevel - 1);
}

 
void mylevel(struct binNode* node, int me, int level) 
{
  if (node==NULL) 
	return;
 
  /* append this node to the path array */
  if (node->left != NULL && node->left->data == me )
  {
	level4me = level + 1;
	parent = node;
	return;
  }
  else if (node->right != NULL && node->right->data == me )
  {
	level4me = level + 1;
	parent = node;
	return;
  }
  else
 	level++;
 
    mylevel(node->left, me, level);
    mylevel(node->right, me, level);
}


main(int argc, char **argv) {
	if(argc < 2)
		printf("usage : cousin <node>\n");
	int level  = 0;
	int me = atoi(argv[1]);
        struct binNode *tree;
        tree = buildtree();
	mylevel(tree, me, level);
	printf("i am at level - %d\n", level4me);
	cousin(tree, me, level4me);
}
