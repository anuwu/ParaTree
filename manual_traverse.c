#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "data.h"
#include "print.h"
#include "manual_traverse.h"

void print_manual_traverse_menu ()
{
	printf ("Enter your choice. (Wrong input surprise applies here also)\n") ;
	printf ("1. Visit left node\n") ;
	printf ("2. Visit right node\n") ;
	printf ("3. Visit parent\n") ;
	printf ("4. Back to root\n") ;
	printf ("5. Back to main menu\n") ;
}

void print_manual_traverse_node (struct tree *t , struct node *ptr)
{
	int maxspace , lenp , lenlc ;

	if (ptr == t->root)
		{
			print_space (10) ;
			print_space_node (ptr->left) ;				//length of ptr->left
			print_space (1) ;							//one for forward slash
			print_space (strlen(ptr->str)/2 - 1) ;		//half of length of ptr
			print_node (ptr->parent) ;					//printing NULL
			printf("\n") ;								//newline

			print_space (10) ;
			print_space_node (ptr->left) ;				//length of ptr->left
			print_space (1) ;							//one for forward slash
			print_space (strlen(ptr->str)/2) ;			//half of length of ptr
			printf ("|") ;								//printing |
			printf ("\n") ;								//newline

			print_space (10) ;
			print_space_node (ptr->left) ;				//length of ptr->left
			print_space (1) ;							//one for forward slash
			print_node (ptr) ;							//printing ptr
			printf("\n") ;								//newline

			print_space (10) ;
			print_space_node (ptr->left) ;				//length of ptr->left
			printf ("/") ;								//printing foward slash
			print_space_node (ptr) ;					//length of ptr
			printf ("\\") ;								//printing backslash
			printf ("\n") ;								//newline

			print_space (10) ;
			print_node (ptr->left) ;					//printing ptr->left
			print_space(1) ;							//for forward slash
			print_space_node (ptr) ;					//length of ptr
			print_space (1) ;							//for back slash
			print_node (ptr->right) ;					//printing ptr->right
			printf ("\n") ;								//newline
		}
		else 
		{
			if (ptr == ptr->parent->left) 
			{
				print_space (10) ;
				print_space_node (ptr->left) ;				//length of ptr->left
				print_space (1) ;							//one for forward slash
				print_space_node (ptr) ;					//length of ptr
				print_space (1) ;							//one for forward slash
				print_node (ptr->parent) ;					//printing parent
				printf("\n") ;								//newline

				print_space (10) ;
				print_space_node (ptr->left) ;				//length of ptr->left
				print_space (1) ;							//one for forward slash
				print_space_node (ptr) ;					//length of ptr
				printf ("/") ;								//printing |
				printf ("\n") ;								//newline

				print_space (10) ;
				print_space_node (ptr->left) ;				//length of ptr->left
				print_space (1) ;							//one for forward slash
				print_node (ptr) ;							//printing ptr
				printf("\n") ;								//newline

				print_space (10) ;
				print_space_node (ptr->left) ;				//length of ptr->left
				printf ("/") ;								//printing foward slash
				print_space_node (ptr) ;					//length of ptr
				printf ("\\") ;								//printing backslash
				printf ("\n") ;								//newline

				print_space (10) ;
				print_node (ptr->left) ;					//printing ptr->left
				print_space(1) ;							//for forward slash
				print_space_node (ptr) ;					//length of ptr
				print_space (1) ;							//for back slash
				print_node (ptr->right) ;					//printing ptr->right
				printf ("\n") ;								//newline
			}
			else
			{
				lenp = ret_strlen(ptr->parent) ;
				lenlc = ret_strlen(ptr->left) ;
				maxspace = max (lenp, lenlc) ;

				print_space (10) ;
				if (maxspace == lenp)						//when parent length is greater
					print_node (ptr->parent) ;				//no need to print any space
				else										//when left child length is greater
				{
					print_space (lenlc - lenp) ;			//printing space difference of length
					print_node (ptr->parent) ;
				}
				printf ("\n") ;

				print_space (10) ;
				print_space (maxspace) ;					//fpr maxspace
				printf ("\\") ;								//printing backslash
				printf ("\n") ;								//newline

				print_space (10) ;
				print_space (maxspace) ;					//for maxspace
				print_space (1) ;							//one for forward slash
				print_node (ptr) ;							//printing ptr
				printf("\n") ;								//newline

				print_space (10) ;
				print_space (maxspace) ;					//for maxspace
				printf ("/") ;								//printing forward slash
				print_space_node (ptr) ;					//length of ptr
				printf("\\") ;								//printing backslash
				printf("\n") ;								//newline

				print_space (10) ;
				if (maxspace == lenp)						//when parent length is greater
				{
					print_space (lenp - lenlc) ;			//printing space difference of length	
					print_node (ptr->left) ;
				}
				else
					print_node (ptr->left) ;				//no need to print any space
				print_space (1) ;							//for forward slash
				print_space_node (ptr) ;					//length of ptr
				print_space (1) ;							//for backslash
				print_node (ptr->right) ;

			}
		}
}

void manual_traverse (struct tree *t)
{
	int cont = 1 , option ;
	char dummy ;
	char buf[10] ;

	struct node *ptr = t->root ;

	do
	{
		printf ("\n") ;
		print_manual_traverse_node (t , ptr) ;

		printf ("\n\n") ;
		printf ("---------------------------------------------------\n\n") ;

		print_manual_traverse_menu () ;
		fgets (buf , 10 , stdin) ;
		if (strlen(buf) > 0 && (buf[strlen(buf) - 1] == '\n'))
					buf[strlen(buf) - 1] = '\0' ;

		if (!(isdigit(buf[0])))
			option = 99 ;
		else
			option = atoi(buf) ;

		switch (option)
		{
			case 1 :
				if (ptr->left == NULL)
					printf ("\nLeft child is empty. Cannot visit. Choose another option\n\n") ;
				else
					ptr = ptr->left ;
				break ;

			case 2 :
				if (ptr->right == NULL)
					printf ("\nRight child is empty. Cannot visit. Choose another option\n\n") ;
				else
					ptr = ptr->right ;
				break ;

			case 3 :
				if (ptr->parent == NULL)
					printf ("\nAt root. Cannot go upward. Choose another option\n\n") ;
				else
					ptr = ptr->parent ;
				break ;

			case 4 :
				ptr = t->root ;
				break ;

			case 5 :
				cont = 0 ;
				break ;

			default : 
				printf ("\n---------------------------------------------\n") ;
				print_random_message () ;
				printf ("\n---------------------------------------------\n") ;
		}


	} while (cont) ;
}
