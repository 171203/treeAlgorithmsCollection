                                                              //Written by: N Mohan Teja
                                                              //Date: 18th March 2020
                                                              //Contents: Implicit Declarations of the Functions

#include<stdio.h>


#include<stdlib.h>
/******************************BINARY SEARCH TREE STRUCTURE ***********************************************************/
typedef struct bst
{
 char number;
 struct bst *leftChild;
 struct bst *rightChild;
}node;
node *root=NULL;
node *Insert_node_BST(node *root,char number);
void preOrderPrint_BST(node *root);
node *findMinimum_BST(node *root);
node *deleteNode_BST(node *root,char value);
void post_Order_BST(node *root);
void print_Tree_Triangle_BST(node *root,int level);
void print_Tree_Diagonal_BST(node *root,int level);
void smallest_node_BST(node *root);
void largest_node_BST(node *root); 
int leaf_nodes_BST(node *root);
int countNodes_BST(node *root);
int Depth_BST(node *root);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



typedef struct nodee
{
	char data;
	struct nodee *left,*right;
	int ht;
}nodee;
 
nodee *_insert(nodee *,char);
nodee *Delete(nodee *,char);
void preorder(nodee *);
void inorder(nodee *);
int height( nodee *);
nodee *rotateright(nodee *);
nodee *rotateleft(nodee *);
nodee *RR(nodee *);
nodee *LL(nodee *);
nodee *LR(nodee *);
nodee *RL(nodee *);
int BalanceFactor(nodee *);
int search_AVL(nodee *,char);
void postorder(nodee *);
int Depth_AVL(nodee *);
void smallest_AVL(nodee *);
void largest_AVL(nodee *);



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#define MAX 7
#define MIN 4

struct btnode
{
    int count ;
    char value[MAX + 1] ;
    struct btnode *child[MAX + 1] ;
} ;

struct btnode * insert ( char, struct btnode * ) ;
int setval ( char, struct btnode *, char *, struct btnode ** ) ;
struct btnode * search ( char, struct btnode *, int * ) ;
int searchnode ( char, struct btnode *, int * ) ;
void fillnode ( char, struct btnode *, struct btnode *, int ) ;
void split ( char, struct btnode *, struct btnode *,
                int, char *, struct btnode ** ) ;
struct btnode * delete_ ( char, struct btnode * ) ;
int delete_leaf ( char, struct btnode * ) ;
void clear ( struct btnode *, int ) ;
void copysucc ( struct btnode *, int ) ;
void restore ( struct btnode *, int ) ;
void rightshift ( struct btnode *, int ) ;
void leftshift ( struct btnode *, int ) ;
void merge ( struct btnode *, int ) ;
void display ( struct btnode * ) ;
int max_btree(char,char,char);
int maxlevel(struct btnode *);
void printMaxLevel(struct btnode*);
void getMinMax(struct btnode *);
int getMax(struct btnode *);
int getMin(struct btnode *);
void printTotal(struct btnode*);
int totalKeys(struct btnode*);
void inorder_btree(struct btnode*);
void print_btree(struct btnode*,int );




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





