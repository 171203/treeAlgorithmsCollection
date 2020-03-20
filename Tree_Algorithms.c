                                    //Written by: N Mohan Teja 
                                    //Date:    18th March 2020
                                    //Content: Functions of Binary Search Tree, Adelson Velski Landis Tree and B -Tree.

#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*****************************************************************************************************/
        /*****************************************************************************************************/
        /*                   BINARY SEARCH TREE FUNCTIONS THAT ARE USED IN THE MAIN FUNCTION                 */                                                                           
        /*                                                                                                  **/
        /*****************************************************************************************************/
        /*****************************************************************************************************/       
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*******************************************************DELETES THE ROOT  NODE**************************************************************************/
node *deleteNode_BST(node *currentNode, char value)
{
if(currentNode==NULL) // empty tree
return NULL;
else if(value < currentNode->number) // value is less than node's number. so go to left subtree
currentNode->leftChild = deleteNode_BST(currentNode->leftChild, value);
else if(value > currentNode->number) // value is greater than node's number. so go to right subtree
currentNode->rightChild = deleteNode_BST(currentNode->rightChild, value);
else // node found. Let's delete it!
{
//node has no child
if(currentNode->leftChild == NULL && currentNode->rightChild == NULL)
{
currentNode = NULL;
}
else if(currentNode->leftChild == NULL) // node has only right child
{
currentNode = currentNode->rightChild;
}
else if(currentNode->rightChild == NULL) // node has only left child
{
currentNode = currentNode->leftChild;
}
else // node has two children
{
node *tempNode = findMinimum_BST(currentNode->rightChild);
currentNode->number = tempNode->number;
currentNode->rightChild = deleteNode_BST(currentNode->rightChild, tempNode->number);
}
}
return currentNode;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  /*************************************************FINDS THE MINIMUM NODE IN THE BINARY SEARCH TREE*******************************************************************/
node * findMinimum_BST(node *currentNode)
{
if(currentNode->leftChild==NULL)
return currentNode;
return findMinimum_BST(currentNode->leftChild);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**************************************************************************INSERTS THE NODE INTO THE BINARY SEARCH TREE************************************************/
node *Insert_node_BST(node *root,char value)
{
    if(root==NULL)
    {
	root=(node*)malloc(sizeof(node));
	root->number=value;
	root->leftChild=root->rightChild=NULL;
	return root;
    }
    if(value < root->number)
	root->leftChild=Insert_node_BST(root->leftChild,value);
     else
     { if(value > root->number)
	     root->rightChild=Insert_node_BST(root->rightChild,value);
     }
      return root;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /******************** DISPLAYS THE CHARACTERS IN THE BINARY SEARCH TREE TREE IN PREORDER TRAVERSAL********************************************************************/
void preOrderPrint_BST(node *root)
{
if(root==NULL)
return;
printf("%c-> ", root->number);
preOrderPrint_BST(root->leftChild);
preOrderPrint_BST(root->rightChild);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************DISPLAYS THE NODE IN IN_ORDER TRAVERSAL IN BINARY SEARCH TREE***************************************************************************/

void in_Order_BST(node *root)
{
   if(root==NULL)
       return;
   in_Order_BST(root->leftChild);
   printf("%c->",root->number);
   in_Order_BST(root->rightChild);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*************************************************DISPLAYS THE BINARY SEARCH TREE IN THE POST_ ORDER TRAVERSAL*********************************************************/

void post_Order_BST(node *root)
{
    if(root==NULL)
	return;
    post_Order_BST(root->leftChild);
    post_Order_BST(root->rightChild);
    printf("%c->",root->number);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**************************************************PRINTS THE BINARY SEARCH TREE IN THE TRIANGULAR FORM****************************************************************/
void print_Tree_Triangle_BST(node *root,int level)
{
    int i;
    if(root==NULL)
	return;
    print_Tree_Triangle_BST(root->rightChild,level+1);
    printf("\n");
    for(i=0;i<level;i++)
	printf("      ");
    printf("%c",root->number);
    print_Tree_Triangle_BST(root->leftChild,level+1);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/***********************************************************PRINTS THE BINARY SEARCH TREE IN DIAGONAL FORM********************************************************/
void print_Tree_Diagonal_BST(node *root,int level)
{
    int i;
    if(root==NULL)
	return;
    printf("\n");
    for(i=0;i<level;i++)
	printf("     ");
    printf("%c",root->number);
    print_Tree_Diagonal_BST(root->leftChild,level+1);
    print_Tree_Diagonal_BST(root->rightChild,level+1);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void smallest_node_BST(node *root)
{
    while(root!=NULL&&root->leftChild!=NULL)
    {
	root=root->leftChild;
    }
    printf("\n Smallest Character in the Binary Search Tree is  %c\n",root->number);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void largest_node_BST(node *root)
{
    while(root!=NULL && root->rightChild!=NULL)
    {
	root=root->rightChild;
    }
    printf("\n Largest character in the Binary Search Tree is  %c\n",root->number);
}
int count=0;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int leaf_nodes_BST(node *root)
{
  
    if(root!=NULL)
    {
	
	if((root->leftChild==NULL) && (root->rightChild==NULL))
	
	    count++;
	leaf_nodes_BST(root->leftChild);
	leaf_nodes_BST(root->rightChild);
    }
    return count;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int countNodes_BST(node *root)
{
   if(root!=NULL)
   {
       count++;
       countNodes_BST(root->leftChild);
       countNodes_BST(root->rightChild);
   }
   return count;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Height_BST(node *root)
{
    int lheight,rheight;
    if(root!=NULL)
    {
	lheight=Height_BST(root->leftChild);
	rheight=Height_BST(root->rightChild);
	if(lheight > rheight)
	    return(lheight+1);
	else
	    return(rheight+1);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Depth_BST(node *root)
{
    int ldepth,rdepth;
    if(root==NULL)
	return 0;
    else
    {
	ldepth=Depth_BST(root->leftChild);
	rdepth=Depth_BST(root->rightChild);
	if(ldepth > rdepth)
	    return (ldepth+1);
          else
	      return (rdepth+1);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int search_BST(node *root,char key)
{
    while(root!=NULL)
    {
	if(key > root->number)
	{
	    return search_BST(root->rightChild,key);
	}
	else
	    if(key < root->number)
	    {
		return search_BST(root->leftChild,key);
	    }
	    else
             {
		return 1;
                }
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


   /*******************************************************************************************************************/
   //                            ADELSON VELSKI LANDIS TREE FUNCTIONS                                                  
   //
   //*******************************************************************************************************************//

  //           Inserting The Characters into the AVL Tree
nodee * _insert(nodee *T,char x)// nodeee is a AVL TREE structure definition
{
	if(T==NULL)// check for the Null tree
	{
		T=(nodee*)malloc(sizeof(nodee));// if the tree is empty then insert the characters
		T->data=x;
		T->left=NULL;
		T->right=NULL;
	}
	else
		if(x > T->data)		// insert in right subtree
		{
			T->right=_insert(T->right,x);
			if(BalanceFactor(T)==-2)// checking for the balance factor
				if(x>T->right->data)
					T=RR(T);
				else
					T=RL(T);
		}
		else
			if(x<T->data) // insert in the left sub tree
			{
				T->left=_insert(T->left,x);
				if(BalanceFactor(T)==2)// checking for the balance factor
					if(x < T->left->data)
						T=LL(T);// left left rotation
					else
						T=LR(T);// left right rotation
			}
		
		T->ht=height(T);// updating the height
		
		return(T);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
/// Deletion of the particular node in the AVL tree
nodee * Delete(nodee *T,char x)// nodee is a avl tree data structure definition
{
	nodee *p;
	
	if(T==NULL)// check for empty tree
	{
		return NULL;// nothing to do
	}
	else
		if(x > T->data)		// delete in right subtree
		{
			T->right=Delete(T->right,x);
			if(BalanceFactor(T)==2)
				if(BalanceFactor(T->left)>=0)
					T=LL(T);
				else
					T=LR(T);
		}
		else
			if(x<T->data) // delete in the left subtree
			{
				T->left=Delete(T->left,x);
				if(BalanceFactor(T)==-2)	//Rebalance during windup
					if(BalanceFactor(T->right)<=0)
						T=RR(T);// right right rotation
					else
						T=RL(T);// right left rotation
			}
			else
			{
				//data to be deleted is found
				if(T->right!=NULL)
				{	//delete its inorder succesor
					p=T->right;
					
					while(p->left!= NULL)
						p=p->left;
					
					T->data=p->data;
					T->right=Delete(T->right,p->data);
					
					if(BalanceFactor(T)==2)//Rebalance during windup
						if(BalanceFactor(T->left)>=0)
							T=LL(T);// left left roptation
						else
							T=LR(T);// left right rotation
				}
				else
					return(T->left);
			}
	T->ht=height(T);// updating the height
	return(T);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
 
// height of the AVL tree
int height(nodee *T)
{
	int lh,rh;
	if(T==NULL)//check for empty tree
		return(0);
	
	if(T->left==NULL)// check for empty left suntree
		lh=0;
	else
		lh=1+T->left->ht;
		
	if(T->right==NULL)// check for empty right suntree
		rh=0;
	else
		rh=1+T->right->ht;
	
	if(lh>rh)
		return(lh);
	
	return(rh);
}
   /////////////////// /////////////////////////////////////////////////////////////////////////////////////////////////
  // Rotate right//
nodee * rotateright(nodee *x)
{
	nodee *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     //                 ROTATE LEFT

 
nodee * rotateleft(nodee *x)
{
	nodee *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	
	return(y);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Rotate right and then right again
 
nodee * RR(nodee *t)
{
	t=rotateleft(t);
	return(t);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Rotate Left and then lef again
 
nodee * LL(nodee *t)
{
	t=rotateright(t);
	return(t);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// rotate Left and then right again 
nodee * LR(nodee *t)
{
	t->left=rotateleft(t->left);
	t=rotateright(t);
	
	return(t);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
nodee * RL(nodee *t)
{
	t->right=rotateright(t->right);
	t=rotateleft(t);
	return(t);
}
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int BalanceFactor(nodee *T)
{
	int lh,rh;
	if(T==NULL)
		return(0);
 
	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->ht;
 
	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->ht;
 
	return(lh-rh);
}
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void preorder(nodee *T)
{
	if(T!=NULL)
	{
		printf("%c|(Balancefactor=%d)|->",T->data,BalanceFactor(T));
		preorder(T->left);
		preorder(T->right);
	}
}
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void inorder(nodee *T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		printf("%c|(Balanefactor=%d)|->",T->data,BalanceFactor(T));
		inorder(T->right);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 int search_AVL(nodee *head,char info)
{
    while(head!=NULL)
    {
	if(info > head->data)
	{
	    return search_AVL(head->right,info);
	}
	else
	    if(info < head->data)
	    {
		return search_AVL(head->left,info);
	    }
	    else
	    {
		return 1;
	    }
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void postorder(nodee *T)
{
    if(T!=NULL)
    {
	postorder(T->left);
	postorder(T->right);
	printf(" %c(Balancefactor=%d)->   ",T->data,BalanceFactor(T));
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int maximum_AVL(char a,char b)
{
    return (a > b)? a: b;
}
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void  print_AVL(nodee *avl,int level)
{
    int i;
    if(avl)
    {
	print_AVL(avl->right,level+1);
	printf("\n");
	for(i=0;i<level;i++)
	    printf("      ");
	printf("%c",avl->data);
	print_AVL(avl->left,level+1);
    }
}
  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Depth_AVL(nodee *head)
{
    int ldepth,rdepth;
    if(head==NULL)
	return 0;
    else
    {
	ldepth=Depth_AVL(head->left);
	rdepth=Depth_AVL(head->right);
	if(ldepth > rdepth)
	    return (ldepth+1);
	else
	    return (rdepth+1);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void smallest_AVL(nodee *head)
{
    while(head!=NULL && head->left!=NULL)
    {
	head=head->left;
    }
    printf("\n Smallest node in the Adelson Velski Landis tree is %c\n",head->data);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void largest_AVL(nodee *head)
{
    while(head!=NULL && head->right!=NULL)
    {
	head=head->right;
    }
    printf("\n Largest Node in the Adelson Velski Landis Tree is %c\n",head->data);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**********************************************************************************************************************/
//                                 B Tree FUNCTIONS                                                                   
//
//
/*********************************************************************************************************************/

/* inserts a value in the B-tree*/
struct btnode * insert ( char val, struct btnode *root )
{
    char i ;
    struct btnode *c, *n ;
    int flag ;

    flag = setval ( val, root, &i, &c ) ;
    if ( flag )
    {
        n = ( struct btnode * ) malloc ( sizeof ( struct btnode ) ) ;
        n -> count = 1 ;
        n -> value [1] = i ;
        n -> child [0] = root ;
        n -> child [1] = c ;
        return n ;
    }
    return root ;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* sets the value in the node */
int setval ( char val, struct btnode *n, char *p, struct btnode **c )
{
    int k ;
    if ( n == NULL )
    {
        *p = val ;
        *c = NULL ;
        return 1 ;
    }
    else
    {
      if(searchnode(val,n,&k))
	  printf("\nKey already exists \n");
	
        if ( setval ( val, n -> child [k], p, c ) )
        {
            if ( n -> count < MAX )
            {
                fillnode ( *p, *c, n, k ) ;
                return 0 ;
            }
            else
            {
                split ( *p, *c, n, k, p, c ) ;
                return 1 ;
            }
        }
        return 0 ;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* searches value in the node */
struct btnode * search ( char val, struct btnode *root, int *pos )
{
    if ( root == NULL )
        return NULL ;
    else
    {
        if ( searchnode ( val, root, pos ) )
            return root ;
        else
	    return search ( val, root -> child [*pos], pos ) ;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* searches for the node */
int searchnode ( char val, struct btnode *n, int *pos )
{
    if ( val < n -> value [1] )
    {
        *pos = 0 ;
        return 0 ;
    }
    else
    {
        *pos = n -> count ;
        while ( ( val < n -> value [*pos] ) && *pos > 1 )
            ( *pos )-- ;
        if ( val == n -> value [*pos] )
            return 1 ;
        else
	    return 0 ;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* adjusts the value of the node */
void fillnode ( char val, struct btnode *c, struct btnode *n, int k )
{
    int i ;
    for ( i = n -> count ; i > k ; i-- )
    {
        n -> value [i + 1] = n -> value [i] ;
        n -> child [i + 1] = n -> child [i] ;
    }
    n -> value [k + 1] = val ;
    n -> child [k + 1] = c ;
    n -> count++ ;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* splits the node */
void split ( char val, struct btnode *c, struct btnode *n,
                int k, char *y, struct btnode **newnode )
{
    int i, mid ;

    if ( k <= MIN )
        mid = MIN ;
    else
        mid = MIN + 1 ;

    *newnode = ( struct btnode * ) malloc ( sizeof ( struct btnode ) ) ;

    for ( i = mid + 1 ; i <= MAX ; i++ )
    {
        ( *newnode ) -> value [i - mid] = n -> value [i] ;
        ( *newnode ) -> child [i - mid] = n -> child [i] ;
    }

    ( *newnode ) -> count = MAX - mid ;
    n -> count = mid ;

    if ( k <= MIN )
        fillnode ( val, c, n, k ) ;
    else
        fillnode ( val, c, *newnode, k - mid ) ;

    *y = n -> value [n -> count] ;
    ( *newnode ) -> child [0] = n -> child [n -> count] ;
    n -> count-- ;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* deletes value from the node */
struct btnode * delete_ ( char val, struct btnode *root )
{
    struct btnode * temp ;
    if ( ! delete_leaf ( val, root ) )
        printf ( "\nValue |%c| not found.", val ) ;
    else
    {
	printf("\n Value |%c| found in the tree\n",val);
        if ( root -> count == 0 )
        {
            temp = root ;
            root = root -> child [0] ;
            free ( temp ) ;
        }
    }
    return root ;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* helper function for delete( ) */
int delete_leaf ( char val, struct btnode *root )
{
    int i ;
    int flag ;
    if ( root == NULL )
        return 0 ;
    else
    {
        flag = searchnode ( val, root, &i ) ;
        if ( flag )
        {
            if ( root -> child [i - 1] )
            {
                copysucc ( root, i ) ;
                flag = delete_leaf ( root -> value [i], root -> child [i] ) ;
                if ( !flag )
                    printf ( "\nValue |%c| not found.", val ) ;
            }
            else
                clear ( root, i ) ;
        }
        else
            flag = delete_leaf ( val, root -> child [i] ) ;

        if ( root -> child [i] != NULL )
        {
            if ( root -> child [i] -> count < MIN )
                restore ( root, i ) ;
        }
        return flag ;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* removes the value from the node and adjusts the values */
void clear ( struct btnode *node, int k )
{
    int i ;
    for ( i = k + 1 ; i <= node -> count ; i++ )
    {
        node -> value [i - 1] = node -> value [i] ;
        node -> child [i - 1] = node -> child [i] ;
    }
    node -> count-- ;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* copies the successor of the value that is to be deleted */
void copysucc ( struct btnode *node, int i )
{
    struct btnode *temp ;

    temp = node -> child [i] ;

    while ( temp -> child[0] )
        temp = temp -> child [0] ;

    node -> value [i] = temp -> value [1] ;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* adjusts the node */
void restore ( struct btnode *node, int i )
{
    if ( i == 0 )
    {
        if ( node -> child [1] -> count > MIN )
            leftshift ( node, 1 ) ;
        else
            merge ( node, 1 ) ;
    }
    else
    {
        if ( i == node -> count )
        {
            if ( node -> child [i - 1] -> count > MIN )
                rightshift ( node, i ) ;
            else
                merge ( node, i ) ;
        }
        else
        {
            if ( node -> child [i - 1] -> count > MIN )
                rightshift ( node, i ) ;
            else
            {
                if ( node -> child [i + 1] -> count > MIN )
                    leftshift ( node, i + 1 ) ;
                else
                    merge ( node, i ) ;
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* adjusts the values and children while shifting the value from parent to right 
    child */
void rightshift ( struct btnode *node, int k )
{
    int i ;
    struct btnode *temp ;

    temp = node -> child [k] ;

    for ( i = temp -> count ; i > 0 ; i-- )
    {
        temp -> value [i + 1] = temp -> value [i] ;
        temp -> child [i + 1] = temp -> child [i] ;
    }

    temp -> child [1] = temp -> child [0] ;
    temp -> count++ ;
    temp -> value [1] = node -> value [k] ;

    temp = node -> child [k - 1] ;
    node -> value [k] = temp -> value [temp -> count] ;
    node -> child [k] -> child [0] = temp -> child [temp -> count] ;
    temp -> count-- ;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* adjusts the values and children while shifting the value from parent to left 
    child */
void leftshift ( struct btnode *node, int k )
{
    int i ;
    struct btnode *temp ;

    temp = node -> child [k - 1] ;
    temp -> count++ ;
    temp -> value [temp -> count] = node -> value [k] ;
    temp -> child [temp -> count] = node -> child [k] -> child [0] ;

    temp = node -> child [k] ;
    node -> value [k] = temp -> value [1] ;
    temp -> child [0] = temp -> child [1] ;
    temp -> count-- ;

    for ( i = 1 ; i <= temp -> count ; i++ )
    {
        temp -> value [i] = temp -> value [i + 1] ;
        temp -> child [i] = temp -> child [i + 1] ;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* merges two nodes */
void merge ( struct btnode *node, int k )
{
    int i ;
    struct btnode *temp1, *temp2 ;

    temp1 = node -> child [k] ;
    temp2 = node -> child [k - 1] ;
    temp2 -> count++ ;
    temp2 -> value [temp2 -> count] = node -> value [k] ;
    temp2 -> child [temp2 -> count] = node -> child [0] ;

    for ( i = 1 ; i <= temp1 -> count ; i++ )
    {
        temp2 -> count++ ;
        temp2 -> value [temp2 -> count] = temp1 -> value [i] ;
        temp2 -> child [temp2 -> count] = temp1 -> child [i] ;
    }
    for ( i = k ; i < node -> count ; i++ )
    {
        node -> value [i] = node -> value [i + 1] ;
        node -> child [i] = node -> child [i + 1] ;
    }
    node -> count-- ;
    free ( temp1 ) ;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* displays the B-tree */
void display ( struct btnode *root )
{
    int i ;

    if ( root != NULL )
    {
        for ( i = 0 ; i < root -> count ; i++ )
        {
            display ( root -> child [i] ) ;
            printf ( "|%c|->\t", root -> value [i + 1] ) ;
        }
        display ( root -> child [i] ) ;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Maximum in the b tree//

int max_btree(char first, char second, char third) {
int max = first;
if (second > max) max = second;
if (third > max) max = third;
return max;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Maximum level in the B tree//
int maxLevel(struct btnode *head) {
if (head) 
{
int l = 0, mr = 0, r = 0, max_depth;
if (head->child[0] != NULL) l = maxLevel(head->child[0]);
if (head->child[1] != NULL) mr = maxLevel(head->child[1]); 
if (head->count == 2) {
if (head->child[2] != NULL) r = maxLevel(head->child[2]);
}
max_depth = max_btree(l, mr, r) + 1;
return max_depth;
}
return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_btree(struct btnode *head, int blanks)
{
if (head)
{
int i;
for(i=1; i<=blanks; i++)
printf(" ");
for (i=0; i < head->count; i++)
printf("%c ",head->value[i]);
printf("\n");
for (i=0; i <= head->count; i++)
print_btree(head->child[i], blanks+10);
}/*End of if*/
}/*End of display()*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int totalKeys(struct btnode *head) {
if (head) {
int inc = 1;
if (head->count >= 1) {
inc += totalKeys(head->child[0]);
inc += totalKeys(head->child[1]);
if (head->count== 2) inc += totalKeys(head->child[2]) + 1;
}
return count;
}
return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void printTotal(struct btnode *head) {
printf("%d\n",totalKeys(head));
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int getMin(struct btnode *head) {
if (head) {
int min;
if (head->child[0] != NULL) min = getMin(head->child[0]);
else min = head->value[0];
return min;
}
return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int getMax(struct btnode *head) {
if (head) {
int max;
if (head->count == 1) {
if (head->child[1] != NULL) max = getMax(head->child[1]);
else max = head->value[0];
}
if (head->count == 2) {
if (head->child[2] != NULL) max = getMax(head->child[2]);
else max = head->value[1];
}
return max;
}
return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void getMinMax(struct btnode *head) {
printf("%c %c\n", getMin(head), getMax(head));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






