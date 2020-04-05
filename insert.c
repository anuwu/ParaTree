#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "util.h"
#include "insert.h"


void tokenize_add (struct tree *t)
{
	char str[] = "If you've decoded this, you're good at reading trees. Why don't you try a longer sentence?" ;

	char *tok, *word ;
	int i = 1 ;


	tok = strtok (str , " ") ;
	while (tok != NULL)
	{
		add_bal (t , i , tok) ;
		//printf ("%s\n" , tok) ;
		tok = strtok (NULL , " ") ;
		i++ ;
	}
}


struct node* find_y_add (struct node *ptr , struct node *z)
{
	while (ptr->parent != z)
		ptr = ptr->parent ;

	return ptr ;
}

struct node* find_x_add (struct node *ptr , struct node *y)
{
	while (ptr->parent != y)
		ptr = ptr->parent ;

	return ptr ;
}

void add_bal (struct tree *t , int val , char* str)
{
	if (t->root == NULL)
	{
		t->root = (struct node*) malloc (sizeof(struct node)) ;

		t->root->val = val ;
		t->root->str = (char *) malloc (sizeof(char) * (strlen(str)+1)) ;
		strcpy (t->root->str , str) ;
		t->root->lh = 0 ;
		t->root->rh = 0 ;
		t->root->hb = 0 ;

		t->root->left = NULL ;
		t->root->right = NULL ;
		t->root->parent = NULL ;

		//printf ("Root created!\n") ;
	}
	else
	{
		struct node *ptr , *prnt ;
		ptr = t->root ;
		prnt = ptr ;

		while (ptr != NULL)
		{
			prnt = ptr ;
			if (val < ptr->val)
				ptr = ptr->left ;
			else
				ptr = ptr->right ;
		}

		if (ptr == NULL)
		{
			//Value has not been encountered before. Need to insert a new node as ptr is null.
			struct node *z ,*y , *x ;
			ptr = (struct node*) malloc (sizeof(struct node)) ;
			ptr->str = (char *) malloc (sizeof(char) * (strlen(str)+1)) ;
			strcpy (ptr->str , str) ;
			ptr->val = val ;
			ptr->lh = 0 ;
			ptr->rh = 0 ;
			ptr->hb = 0 ;

			ptr->left = NULL ;
			ptr->right = NULL ;
			ptr->parent = prnt ;

			if (val < prnt->val)
			{
				prnt->left = ptr ;
				prnt->lh = 1 ;
			}
			else
			{
				prnt->right = ptr ;
				prnt->rh = 1 ;
			}

			prnt->hb = prnt->rh - prnt->lh ;
			//printf ("New node added!\n") ;
			update_balance (prnt) ;

			

			/********************
			Maintaining balanced property here
			*********************/


			z = find_z(ptr) ;
			if (z != NULL)
			{
				//printf ("There is imbalance!\n") ;
				//just_enter () ;

				y = find_y_add(ptr , z) ;
				x = find_x_add(ptr , y) ;
				//printf ("x = %d , y = %d , z = %d\n" , x->) ;
				//just_enter () ;

				int cas ;	//1 - LL, 2 - LR, 3 - RR, 4 - RL
				if (z->left == y && y->left == x)
					cas = 1 ;
				if (z->left == y && y->right == x)
					cas = 2 ;
				if (z->right == y && y->right == x)
					cas = 3 ;
				if (z->right == y && y->left == x)
					cas = 4 ;

				switch (cas)
				{
					case 1 :
						right_rotate (t , z) ;
						break ;

					case 2 :
						left_rotate (t , y) ;
						right_rotate (t , z) ;
						break ;

					case 3 :
						left_rotate (t , z) ;
						break ;

					case 4 :
						right_rotate (t , y) ;
						left_rotate (t , z) ;
						break ;
				}
			}
		}
	}

	t->no += 1 ;
}

