/* sum of the distances tiles are out of place */

/*       Program for solving the 8-puzzle (Improved version).
    (Heuristic used is sum of the distances tiles are out of place.)

The user first enters the initial state of the puzzle by typing
its rows (the hole is represented by 0).  The program then
searches for the solution and reports a sequence of steps
describing the solution found.

Nodes in the search tree contain the following fields:

  state:     A 3 X 3 array representing the position of the
             tiles for that state.
  hole:      An array containing the coordinates of the hole
             in that state.
  move:      Indicates the hole motion used to reach this
	     state from the node's parent.
  depth:     The number of moves required to reach the node along
             the path on which it was found.
  heuristic: A heuristic estimate of the number of moves
	     still necessary to reach the goal.
  proj_cost: heuristic + depth.
  parent:    A pointer to the node's parent.  The root node's
             parent pointer is NULL.
  next_in_leaf_list:  A pointer to the next leaf in the leaf list.

The leaves in the search tree are linked to form the leaf list.
This list is accessed through the pointer head_leaf_list.  The leaf
list is always sorted by the nodes' proj_cost.  Thus the
first entry in the list is always the next node to be expanded. */

#include <stdio.h>
#include <stddef.h>

enum move_type {up, down, left, right};
enum Bool_type {true, false};

struct node_struct
 {
  int                  state[3][3];
  int                  hole[2];
  enum move_type       move;
  int                  depth;
  int                  heuristic;
  int                  proj_cost;
  struct node_struct  *parent;
  struct node_struct  *next_in_leaf_list;
 };

typedef struct node_struct node_type;
typedef enum Bool_type     Boolean;

char       buf[80];
node_type *head_leaf_list;
Boolean    solved;
int        goal_state[3][3] = {1, 2, 3, 8, 0, 1, 7, 6, 5};

    /*  Heuristic returns an estimate of the cost of reaching */
    /*  the goal_state from the node pointed to by node.      */

int heuristic (node_type *node)
{
 int i, j, z = 0;

 for(i = 0; i < 3; i++)
   for(j = 0; j < 3; j++)
     {if (node->state[i][j] != goal_state[i][j] &&
	 (node->state[i][j] != 0))
	   z = z + abs(i - ((node->state[i][j] - 1) / 3))
	         + abs(j - ((node->state[i][j] - 1) % 3));
     }
 return(z);
}

    /* get_start_state gets the start state from the user, */
    /* establishes this state as the root node in the      */
    /* search tree and fills in the fields of this node.   */

node_type * get_start_state ()
{
 int  i, j;
 char c;
 node_type *node;

 node = (node_type *) malloc(sizeof(node_type));
 printf("\n     Improved 8-Puzzle Solver    \n");
 do {
    printf("Enter the configuration of the puzzle that \n");
    printf("you wish to have solved one row at a time \n");
    printf("with at least one blank between each tile \n");
    printf("number.  Use a zero to represent the hole. \n");
    printf("Example:  1 2 3\n");
    printf("          8 0 4\n");
    printf("          7 6 5\n\n");
    for (i = 0; i < 3; i++)
     {
      scanf("%d %d %d%c", &(node->state[i][0]), &(node->state[i][1]),
			&(node->state[i][2]), &c);
      printf("\n");
      for (j = 0; j < 3; j++)
	if (node->state[i][j] == 0)
	  {
	   node->hole[0] = i;
	   node->hole[1] = j;
	  }
     } /* for i */
    printf("\nStarting configuration is: \n");
    for (i = 0; i < 3; i++)
     {
      printf("     ");
      for (j = 0; j < 3; j++)
	 printf("%d ", node->state[i][j]);
      printf("\n");
     }
    printf("\nIs that correct? (Y/N): ");
    gets(buf);
  } while((buf[0] != 'Y') && (buf[0] != 'y'));
 node->parent = NULL;
 node->heuristic = heuristic(node);
 node->depth = 0;
 node->proj_cost = node->heuristic;
 return(node);
} 

    /*  at_goal returns true if the state pointed to by */
    /*  node matches the goal_state.                    */

Boolean at_goal(node_type *node)
{
 int i, j;
 Boolean at_goal = true;

 for (i = 0; i < 3; i++)
   for (j = 0; j < 3; j++)
     if ((node->state[i][j]) != goal_state[i][j])
	    at_goal = false;
 return(at_goal);
} 

    /* Insert places NewNode into the leaf list.  The list   */
    /* is kept in ascending order according to the proj_cost */
    /* field of each node.                                   */

void insert (node_type *new_node)
{
 node_type *last, *next;
 Boolean found;

 if (head_leaf_list == NULL)
  {
   head_leaf_list = new_node;
   new_node->next_in_leaf_list = NULL;
  }
 else
  {
   if (new_node->proj_cost < head_leaf_list->proj_cost)
    {
     new_node->next_in_leaf_list = head_leaf_list;
     head_leaf_list = new_node;
    }
   else
    {
     last = head_leaf_list;
     next = head_leaf_list->next_in_leaf_list;
     found = false;
     while ((next != NULL) && (found == false))
       {if (new_node->proj_cost < next->proj_cost)
	  found = true;
	else
	  {
	   last = next;
	   next = next->next_in_leaf_list;
	  }
       }
     new_node->next_in_leaf_list = next;
     last->next_in_leaf_list = new_node;
    }
  }
} 

   /*  Expand considers each of the four states that could be */
   /*  generated from node (by moving the hole up, down,      */
   /*  left, or right), ignores those that are illegal,       */
   /*  or repetitions of node's immediate parent, creates     */
   /*  new nodes for the rest, attaches these to the search   */
   /*  tree and also places them in the leaf list according   */
   /*  to their proj_costs, and reports the occurrence        */
   /*  of the goal.                                           */

void expand (node_type *node, node_type **final_node)
{
 node_type *child;
 enum move_type try;
 int i, j, k, l, x, y, prev1, prev2;

 if (node->parent == NULL)
   {
    prev1 = -1;
    prev2 = -1;
   }
 else
  {
   prev1 = node->parent->hole[0];
   prev2 = node->parent->hole[1];
  }
 i = node->hole[0];
 j = node->hole[1];
 for (try = up; try <= right; try++)
   {
    switch (try)
	   {
	    case up: k = i - 1;
		     l = j;
		     break;
	    case down: k = i + 1;
		       l = j;
		       break;
	    case left: k = i;
		       l = j - 1;
		       break;
	    case right: k = i;
			l = j + 1;
			break;
	  }
    if ((-1 < k) && (k < 3) && (-1 < l) && (l < 3) &&
	  ((prev1 != k) || (prev2 != l)) && solved == false )
      {
       child = (node_type *) malloc(sizeof(node_type));
       child->parent = node;
       for (x = 0; x < 3; x++)
	for (y = 0; y < 3; y++)
	 child->state[x][y] = node->state[x][y];
       child->hole[0] = k;
       child->hole[1] = l;
       child->state[i][j] = child->state[k][l];
       child->state[k][l] = 0;
       child->move = try;
       child->heuristic = heuristic(child);
       child->depth = node->depth + 1;
       child->proj_cost = child->heuristic + child->depth;
       insert(child);
       solved = at_goal(child);
       if (solved == true) *final_node = child;
      } 
   } 
}  

    /* Report_solution recursively moves up the search  */
    /* tree from a goal node to the root, printing out  */
    /* the moves taken to arrive at the goal node in    */
    /* the proper order.                                */

void report_solution (node_type *node)
{
 if (node->parent != NULL)
   {
    report_solution (node->parent);
    switch (node->move)
     {
      case up:    printf("     Move a tile down.\n"); break;
      case down:  printf("     Move a tile up.  \n"); break;
      case left:  printf("     Move a tile right.\n"); break;
      case right: printf("     Move a tile left.\n"); break;
     }
    }
} 

void main(void)
{ int i, j, count, total;
  node_type *current,
	    *final_node;

  current = get_start_state();
  printf("\nSearch has begun.\n");
  solved = at_goal(current);
  head_leaf_list = current;
  current->next_in_leaf_list = NULL;
  count = 0;
  total = 0;
  while ((count < 500) && solved == false)
    {
      current = head_leaf_list;
      head_leaf_list = head_leaf_list->next_in_leaf_list;
      expand (current, &final_node);
      if (solved == true) current = final_node;
      count++;
      if ((count == 500) && solved == false)
	{
	  total = total + count;
	  printf("%d nodes have been expanded ", total);
	  printf("without reaching the goal.\n");
	  printf("Continue searching? (Y/N): ");
	  gets(buf);
	  if ((buf[0] == 'Y') || (buf[0] == 'y'))
	     count = 0;
	}
    }
  if (solved == true)
    {
      printf("\n");
      printf("Solution found.\n");
      printf("Steps are as follows:\n");
      if (current->parent == NULL)
	printf("     No moves required.\n");
      else
	report_solution (current);
    }
  else
    {
      printf("Execution terminated without reaching goal.\n\n");
      printf("Press <Enter> to continue.");
      gets(buf);
    }
}

