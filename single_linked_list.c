

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
typedef struct Node
{
  int data;
  struct Node *next;
} Node;
////////////////////////Add_ENd/////////////////////////////////////////////
void
add_end (Node ** Head)
{
  Node *temp = *Head;
  Node *new = malloc (sizeof (struct Node));
  printf ("Enter Data:- ");
  scanf ("%d", &new->data);

  if (*Head == 0)
	{
	  new->next = 0;
	  *Head = new;
	}
  else
	{
	  while (temp->next != 0)
		temp = temp->next;

	  new->next = 0;
	  temp->next = new;
	}
}

//////////////////////////Add_Begin///////////////////////////////////////////////////
void
add_begin (Node ** Head)
{
  Node *new = malloc (sizeof (struct Node));
  printf ("Enter Data:- ");
  scanf ("%d", &new->data);

  if (Head == 0)
	{
	  new->next = 0;
	  *Head = new;
	}
  else
	{
	  new->next = *Head;
	  *Head = new;
	}
}

///////////////////////Add_Middle//////////////////////////////////////////////
void
add_middle (Node ** Head, int pos)
{
  int k = 0;
  Node *p = *Head, *q;
  Node *new = malloc (sizeof (struct Node));
  printf ("Enter Data:- ");
  scanf ("%d", &new->data);

  if (pos == 1)
	{
	  new->next = p;
	  *Head = new;
	}
  else
	{

	  while (p != NULL && (k < pos - 1))
		{
		  k++;
		  q = p;
		  p = p->next;

		}
	  q->next = new;
	  new->next = p;
	}
}

/////////////////////////Print//////////////////////////////////////////////////////
void
print (Node * Head)
{
  while (Head)
	{
	  printf ("%d ", Head->data);
	  Head = Head->next;
	}
  printf ("\n");
}

/////////////////////Count///////////////////////////////////////////////////////////
int
countnode (Node * Head)
{
  int count = 0;
  while (Head)
	{
	  count++;
	  Head = Head->next;
	}

  return count;
}

////////////////////////Rec_print//////////////////////////////////////////////////////
void
recprint (Node * Head)
{
  if (Head == NULL)
	return;
  printf ("%d ", Head->data);
  recprint (Head->next);

}

//////////////////////REV_print->Recursion/////////////////////////////////////////////
void
revprint (Node * Head)
{
  if (Head == NULL)
	return;
  revprint (Head->next);
  printf ("%d ", Head->data);
}

///////////////////////////Delete_Node //////////////////////////////////////////////
void
delete_node (Node ** Head, int pos)
{
  int k = 0;

  Node *p = *Head, *q;

  if (pos == 1)
	{
	  p = *Head;
	  *Head = (*Head)->next;
	  free (p);
	  return;

	}
  else
	{
	  while (p != NULL && k < pos - 1)
		{
		  k++;
		  q = p;
		  p = p->next;
		}
	  q->next = p->next;
	  free (p);
	}
}

///////////////////////////Reverse_Link/////////////////////
void
rev_link (Node ** Head)
{
  static Node *prev = NULL;
  static Node *temp;
  Node *current = *Head;

  if (current)
	{
	  temp = current->next;
	  current->next = prev;
	  prev = current;
	  rev_link (&temp);
	}
  *Head = prev;
}

int
main ()
{
  int count, pos;

  Node *Head = 0;
// add_begin (&Head);
// add_begin (&Head);
// add_begin (&Head);
  add_end (&Head);
  add_end (&Head);
  add_end (&Head);
  add_end (&Head);
  print (Head);
  printf ("\n");


  // printf("Enter Where you want to add:- ");
  // scanf("%d",&pos);
  // add_middle (&Head,pos);

// count = countnode (Head);
// printf ("Count:- %d\n", count);


  // printf ("Enter The Node you want to free:- ");
  // scanf ("%d", &pos);
  // delete_node (&Head, pos);

  rev_link (&Head);

  recprint (Head);
  printf ("\n");


// revprint (Head);
//  printf ("\n");

  return 0;
}
