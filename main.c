#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "create.h"
#include "main.h"


void display_menu ()
{
	/*
	Either do one of the following -
	1. Never balance the tree in any of the operations.
	2. Always keep the tree balanced.
	*/

	printf ("Choose what you want to do (Enter wrong input just to see what happens. Life is a box of chocolates. Be surprised \"each time\")\n") ;
	printf ("1. Explore the ParaTree\n") ;
	printf ("2. Print the ParaTree\n") ;
	printf ("3. See the hidden message \n") ;
	printf ("4. Exit\n") ;
}

int main ()
{
	int option , cont = 1 ;
	char ch ,  buf[10] , opch[2] ;
	struct tree *t ;

	t = create_tree () ;
	tokenize_add (t) ;

	printf ("\n\n---------------------------------------------\n") ;
	printf ("Welcome to the LOVE TREE!\n") ;
	printf ("Press enter to continue (applies in future stages as well)\n") ;
	just_enter () ;

	printf ("\n\n---------------------------------------------") ;
	printf ("\nThis is a puzzle. In the next section, choose option 1 to solve the puzzle. The controls for the game are simple. It's a slightly long one and I'd advise you to sit down with a pen and paper. Don't worry it's not hard, just a bit long. Refer to the paper I gave you to understand the concept of the puzzle. Don't press option 2 before you solve the puzzle, then it will all be given away! After you've solved it, press option 2 to check your solution. The gift lies there.\n") ;
	just_enter () ;

	printf ("\n---------------------------------------------") ;
	printf ("\nReady? Go!!!\n") ;
	just_enter () ;

	while (cont)
	{
		//system("cls") ;
		printf ("\n\n---------------------------------------------\n") ;
		display_menu () ;

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
				manual_traverse (t) ;
				break ;

			case 2 :
				printf ("\n\n---------------------------------------------\n\n") ;
				print_tree_vertical (t) ;
				printf ("\n\n---------------------------------------------\n\n") ;
				break ;

			case 3 :
				printf ("\n\n---------------------------------------------\n\n") ;
				inorder (t->root) ;
				printf ("\n\n---------------------------------------------\n\n") ;
				break ;

			case 4 :
				cont = 0 ; 
				printf ("\n\n---------------------------------------------\n\n") ;
				printf ("\nBye Bye! See you soon!\n") ;
				printf ("\n\n---------------------------------------------\n\n") ;
				break ;

			default :
				printf ("\n---------------------------------------------\n") ;
				print_random_message () ;			
				printf ("\n---------------------------------------------\n") ;

		}
	}

	return 0 ;
}
