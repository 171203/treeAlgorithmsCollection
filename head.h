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
int nonLeafNodes_BST(node *root);
int Depth_BST(node *root);
node longesrPath_BST(node *temp);
/****************************AVL TREE STRUCTURE*******************************************/
typedef struct node
{
    char data;
    struct node *left,*right;
    int bal;
}AVL;
#define TRUE 1
#define FALSE 0
AVL *insert_AVL(AVL *,char,int*);
AVL *Delete_AVL(AVL *,int);
void preorder_AVL(AVL *);
void inorder_AVL(AVL *);
void postorder_AVL(AVL *);
int Balance_factor(AVL *);
void print_Tree_AVL(AVL *,int);
AVL *balance_left(AVL *,int *);
AVL *balance_right(AVL *,int *);
AVL *del(AVL *,AVL *,int *h);
AVL *delete_AVL(AVL *,char,int *h);
int height(AVL*);
AVL *newNode(char);
AVL *rightRotate(AVL*);
AVL *leftRotate(AVL*);
int getBalanceFactor(AVL*);
AVL *insertNode(AVL*,char);
AVL *minValueNode(AVL*);
AVL *deleteNode(AVL*,char);
void printPreOrder(AVL*);
/*******************B TREE STRUCTURE **************************/
/*
struct node
{
int n; / n < M No. of keys in noe will always less than order of B tree /
int keys[M-1]; /array of keys
struct node *p[M]; / (n+1 pointers will be in use ) /
}*root=NULL;

enum KeyStatus { Duplicate,SearchFailure,Success,InsertIt,LessKeys };

void insert(int key);
void display(struct node *root,int);
void DelNode(char x);
void search(char x);
enum KeyStatus ins(struct node *r, char x, char* y, struct node** u);
int searchPos(char x,char *key_arr, int n);
enum KeyStatus del(struct node *r, char x);
void eatline(void);
void inorder(struct node *ptr);
int totalKeys(struct node *ptr);
void printTotal(struct node *ptr);
int getMin(struct node *ptr);
int getMax(struct node *ptr);
void getMinMax(struct node *ptr);
int max(char first, char second, char third);
int maxLevel(struct node *ptr);
void printMaxLevel(struct node *ptr);*/

