#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "print.h"

void print_node (struct node* ptr)
{
	if (ptr == NULL)
		printf ("NULL") ;
	else
		printf ("%s" , ptr->str) ;
}


void print_space (int count) 
{
	int i ;

	for (i = 1 ; i <= count ; i++)
		printf (" ") ;
}

void print_space_node (struct node *ptr)
{
	if (ptr == NULL)
		print_space (4) ;
	else
		print_space (strlen(ptr->str)) ;
}

void print_tree_vertical (struct tree *t)
{
	int i , maxlevel ;
	maxlevel = max (t->root->lh , t->root->rh) ;

	create_all_simple_levellists (t) ;
	create_all_space_levellists_edgewise (t , t->root , 'x' , 0 , 0) ;

	print_space (t->levellists->front->space) ;
	print_node (t->levellists->front->nodeptr) ;
	printf ("\n") ;
	
	for (i = 1 ; i <= maxlevel ; i++)
	{
		print_all_dll_space_edgewise (t->levellists + i , t->levellists + i - 1) ;
		printf ("\n") ;
		print_all_dll_node_edgewise (t->levellists + i) ;
		printf ("\n") ;
	}
}

void print_random_message ()
{
	//printf ("Y U NO OBEY INSTRUCTION!?\n") ;

	int i ;
	char *random[16] ;
	random[0] = "KYA KAR RAHA HAIN?" ;
	random[1] = "CRATE MAT TOR! HOW WILL YOU GET UP?" ;
	random[2] = "YOU ARE A VERY TASTY SNACC" ;
	random[3] = "EVEN IF YOU ARE SWEATY, I WOULD LICK YOU CLEAN. YUMMM!!!!" ;
	random[4] = "MY RELATIONSHIP IS DRIVING ME INSANE" ;
	random[5] = "NOOOO PANWESH!! DON'T GOOOOO" ;
	random[6] = "SENSITIVE LITTLE BABY BUNNY" ;
	random[7] = "I'LL GIVE YOU WONG HUNDRED MILLION THOUSAND DOLLAH" ;
	random[8] = "ANWESH JAAKE DSA PADH. ITNI TENSION KYU LETA HAIN?" ;
	random[9] = "YOUR GOATEE IS LOOKING VERY SEXY TODAY" ;
	random[10] = "YOUR BUTT IS THE BEST AND SOFTEST IN THE WORLD!" ;
	random[11] = "I MISS MY HOME (YOUR SNACCY BOOBS)" ;
	random[12] = "SPEED ME DOSO BEES DI CHAALAN" ;
	random[13] = "I FUCKING HATE NITIN CHATURVEDI" ;
	random[14] = "ANWESH TU KYA BOL RAHA HAIN?" ;
	random[15] = "SNAC, SNACC, SNACCK, SNACCKSHI" ;

	srand(time(0)) ;
	i = rand() % 16 ;

	printf ("%s", random[i]) ;
}

void inorder (struct node* ptr)
{
	if (ptr == NULL)
		return ;

	inorder (ptr->left) ;
	printf ("%s " , ptr->str) ;
	inorder (ptr->right) ;
}

