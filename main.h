//intrinsic to main.h
void display_menu () ;

//functions needed from insert.h
void tokenize_add (struct tree *t) ;

//Only function needed from print.h
void print_tree_horizontal (struct node *ptr , int space) ;
void print_tree_vertical (struct tree *t) ;
void inorder (struct node* ptr) ;

//function needed from dll.h
void del_all_dll (struct dll *list) ;

//function needed from util.h
void all_bal (struct tree *t , struct node *ptr) ;
void just_enter () ;

//function needed from breadth.h
void create_all_simple_levellists (struct tree *t) ;
int create_all_space_levellists_edgewise (struct tree *t, struct node *ptr , char c , int level , int init_space) ;
int create_all_space_levellists_centred (struct tree *t, struct node *ptr , char c , int level , int init_space) ;
void print_all_levellists (struct tree *t) ;
void del_all_levellists (struct tree *t) ;
