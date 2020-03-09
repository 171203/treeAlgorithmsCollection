#include<stdio.h>
#include<stdlib.h>
#include"head.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*****************************************************************************************************/
        /*****************************************************************************************************/
        /*                   BINARY SEARCH TREE FUNCTIONS THAT ARE USED IN THE MAIN FUNCTION                 */                                                                           
        /*                                                                                                  **/
        /*****************************************************************************************************/
        /*****************************************************************************************************/       
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*******************************************************DELETES THE ROOT  NODE**************************************************************************/
node * deleteNode_BST(node *currentNode, char value)
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
/* 
node *CreateNode(char number)
  {
   node *temp=malloc(sizeof(node));
   if(temp==NULL)
     {
      printf("\tSorry,there is no space in the storage.\n");
      exit(-1);
     }
   else
     {
      temp->number=number;
      temp->leftChild=NULL;
      temp->rightChild=NULL;
      return temp;
      }
 }
*/
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
	leaf_nodes_BST(root->leftChild);
	if((root->leftChild==NULL) && (root->rightChild==NULL))
	{
	    count++;
	}
	leaf_nodes_BST(root->rightChild);
    }
    return count;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int countNodes_BST(node *root)
{
   if(root!=NULL)
   {
       countNodes_BST(root->leftChild);
       count++;
       countNodes_BST(root->rightChild);
   }
   return count;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int nonLeafNodes_BST(node *root)
{
    if(root!=NULL)
    {
	nonLeafNodes_BST(root->leftChild);
	if((root->leftChild!=NULL)|| (root->rightChild!=NULL))
	{
	    count++;
	}
	nonLeafNodes_BST(root->rightChild);
    }
    return count;
}
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*AVL *insert_AVL(AVL *root,char data,int *h)
{
    AVL *node1,*node2;
    if(!root)
    {
	root=(AVL*)malloc(sizeof(AVL));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	root->bal=0;
	*h=TRUE;
	return(root);
    }
    if(data < root->data)
    {
	root->left=insert_AVL(root->left,data,h);
	// if left subtree is higher*/
/*	if(*h)
	{
	    switch(root->bal)
	    {
		case 1:
		    node1=root->left;
		    if(node1->bal==1)
		    {
			printf("Right rotation along %c\n",root->data);
			root->left=node1->right;
			node1->right=root;
			root->bal=0;
			root=node1;
			print_Tree_AVL(root,1);
		    }
		    else
		    {
			printf("Double Rotation , left along %c",node1->data);
			node2=node1->right;
			node1->right=node2->left;
			printf("Then right rotation along %c\n",root->data);
			node2->left=node1;
			root->left=node2->right;
			node2->right=root;
			if(node2->bal==1)
			    root->bal=-1;
			else
                           root->bal=0;
			if(node2->bal==-1)
			    node1->bal=1;
			else
			    node1->bal=0;
			root=node2;
		    }
		    root->bal=0;
		    *h=FALSE;
		    break;
		case 0:
		    root->bal=1;
		    break;
		case -1:
		    root->bal=0;
		    *h=FALSE;
	    }
	}
    }
    if(data > root->data)
    {
	root->right=insert_AVL(root->right,data,h);
  // if the right subtree is high*/
/*	if(*h)
	{
	    switch(root->bal)
	    {
		case 1:
		    root->bal=0;
		    *h=FALSE;
		    break;
		case 0:
		    root->bal=-1;
		    break;
		case -1:
		    node1=root->right;
		    if(node1->bal==-1)
		    {
			printf("Left Rotation along %c\n",root->data);
			root->right=node1->left;
			node1->left=root;
			root->bal=0;
			root=node1;
		    }
		    else
		    {
			printf("Double Rotation along %c\n",node1->data);
			node2=node1->left;
			node1->left=node2->right;
			node2->right=node1;
                        printf("Then left Rotation a;ong %c\n",root->data);
		       root->right=node2->right;
		       node2->right=root;
		       if(node2->bal==-1)
			   root->bal=1;
		       else
			   root->bal=0;
		       if(node2->bal==1)
			   node1->bal=-1;
		       else
			   node1->bal=0;
		       root=node2;
                        }
		    root->bal=0;
                      *h=FALSE;
	    }
	}
    }
    return(root);
}
    */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*int Balance_factor(AVL *T)
{
    int left_height,right_height;
    if(T==NULL)
	return(0);
    if(T->left==NULL)
	left_height=0;
    else
	left_height=1+T->left->ht;
    if(T->right==NULL)
	right_height=0;
    else
	right_height=1+T->right->ht;
    return(left_height-right_height);
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*************************************DISPLAY OF THE AVL TREE IN PREORDER*************************************************************/
void preorder_AVL(AVL *root)
{
    if(root!=NULL)
    {
	printf("%c->",root->data);
	preorder_AVL(root->left);
	preorder_AVL(root->right);
    }
} 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
/******************************************************DISPLAY OF AVL TREE IN INORDER WAY************************************************************/
    void inorder_AVL(AVL *root)
    {
	if(root!=NULL)
	{
	    inorder_AVL(root->left);
	    printf("%c->",root->data);
	    inorder_AVL(root->right);
	}
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/***************************************************DISPLAY OF AVL TREE IN POST ORDER **************************************************************/
    void postorder_AVL(AVL *root)
    {
	if(root!=NULL)
	{
	    postorder_AVL(root->left);
	    postorder_AVL(root->right);
	    printf("%c->",root->data);
	}
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_Tree_AVL(AVL *avl,int level)
{
   int i;
   if(avl)
   {
       print_Tree_AVL(avl->right,level+1);
       printf("\n");
       for(i=0;i<level;i++)
	   printf("    ");
       printf("%c",avl->data);
       print_Tree_AVL(avl->left,level+1);
   }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*AVL *delete_AVL(AVL *root,char data,int *h)
{
    AVL *node;
    if(!root)
    {
	printf("No such data\n");
	return(root);
    }
    else
    {
	if(data < root->data)
	{
	    root->left=delete_AVL(root->left,data,h);
	    if(*h)
		root=balance_right(root,h);
	}
	else
	{
	    if(data > root->data)
	    {
		root->right=delete_AVL(root->right,data,h);
		if(*h)
		    root=balance_left(root,h);
	    }
	    else
	    {
		node=root;
                if(node->right==NULL)
		{
		    root=node->left;
		    *h=TRUE;
		    free(node);
		}
		else
		{
		    if(node->left==NULL)
		    {
			root=node->right;
			*h=TRUE;
			free(node);
		    }
		    else
		    {
			node->right=del(node->right,node,h);
			if(*h)
			    root=balance_left(root,h);
		    }
		}
	    }
	}
    }
    return(root);
}
 AVL *del(AVL *succ,AVL *node,int *h)
{
    AVL *temp=succ;
    if(succ->left!=NULL)
    {
	succ->left=del(succ->left,node,h);
	if(*h)
	    succ=balance_right(succ,h);
    }
    else
    {
	temp=succ;
	node->data=succ->data;
	succ=succ->right;
	free(temp);
	*h=TRUE;
    }
    return(succ);
}
 

// balances the tree if the right subtree is higher*/
/*AVL *balance_right(AVL *root,int *h)
{
    AVL *node1,*node2;
    switch(root->bal)
    {
	case 1:
	    root->bal=0;
	    break;
	case 0:
	    root->bal=-1;
	    *h=FALSE;
	    break;
	case -1:
           node1=root->right;
	   if(node1->bal <=0)
	   {
	       printf("Left Rotation along %c\n",root->data);
	       root->right=node1->left;
	       node1->left=root;
	       if(node1->bal==0)
	       {
		   root->bal=-1;
		   node1->bal=1;
		   *h=FALSE;
	       }
	       else
	       {
		   root->bal=node1->bal=0;
	       }
	       root=node1;
	   }
	   else
	   {
	       printf("Double Rotation,right along %c\n",node1->data);
	       node2=node1->left;
	       node1->left=node2->right;
	       node2->right=node1;
	       printf("Then Left rotation along %c\n",root->data);
	       root->right=node2->left;
	       node2->left=root;
	       if(node2->bal==-1)
		   root->bal=1;
	       else
		   root->bal=0;
	       if(node2->bal==1)
                  node1->bal=-1;
	       else
		   node1->bal=0;
	       root=node2;
	       node2->bal=0;
	   }
    }
    return(root);
}
// balances the tree if left tree is higher*/
/*AVL *balance_left(AVL *root,int *h)
  {
      AVL *node1,*node2;
      switch(root->bal)
      {
        case -1:
         root->bal=0;
	 break;
	case 0:
	 root->bal=1;
	 *h=TRUE;
	 break;
	case 1:
	 node1=root->left;
	 if(node1->bal >=0)
	 {
	     printf("Right Rotation along %c\n",root->data);
	     root->left=node1->right;
	     node1->right=root;
	     if(node1->bal==0)
	     {
		 root->bal=1;
		 node1->bal=-1;
		 *h=FALSE;
	     }
	     else
	     {
		 root->bal=node1->bal=0;
	     }
	     root=node1;
	 }
	 else
	 {
	     printf("Double Rotation,Left Rotation along %c\n",node1->data);
	     node2=node1->right;
	     node1->right=node2->left;
	     node2->left=node1;
	     printf("Then righr along %c\n",root->data);
	     root->left=node2->right;
	     node2->right=root;
	     if(node2->bal==1)
		 root->bal=-1;
	     else
		 root->bal=0;
	     if(node2->bal==-1)
		 node1->bal=1;
	     else
		 node1->bal=0;
	     root=node2;
	     node2->bal=0;
	 }
      }
      return(root);
  }*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    

 

                                 /****************************************************************************************************************/
                                 /*                                     AVL TREE FUNCTIONS                                                                                                */
                                 /*                                                                                                              */
                                 /*                                                                                                              */
                                 /****************************************************************************************************************/
    int max(char a, char b); 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int height(AVL *N) 
{ 
  if (N == NULL) 
    return 0; 
  return N->bal; 
} 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int max(char a, char b) 
{ 
  return (a > b)? a : b; 
} 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AVL* newNode(char data) 
{ 
  AVL *root = (AVL*) 
            malloc(sizeof(AVL)); 
  root->data = data; 
  root->left = NULL; 
  root->right = NULL; 
  root->bal = 1;
  return(root); 
} 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AVL *rightRotate(AVL *y) 
{ 
  AVL *x = y->left; 
  AVL *T2 = x->right; 

  x->right = y; 
  y->left = T2; 

  y->bal = max(height(y->left), height(y->right))+1; 
  x->bal = max(height(x->left), height(x->right))+1; 

  return x; 
} 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AVL *leftRotate(AVL *x) 
{ 
 AVL *y = x->right; 
  AVL *T2 = y->left; 

  y->left = x; 
  x->right = T2; 

  x->bal = max(height(x->left), height(x->right))+1; 
  y->bal = max(height(y->left), height(y->right))+1; 

  return y; 
} 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int getBalanceFactor(AVL *N) 
{ 
  if (N == NULL) 
    return 0; 
  return height(N->left) - height(N->right); 
} 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AVL *insertNode(AVL* root, char data) 
{ 
  if (root == NULL) 
    return(newNode(data)); 

  if (data < root->data) 
    root->left = insertNode(root->left, data); 
  else if (data > root->data) 
    root->right = insertNode(root->right, data); 
  else
    return root; 

  root->bal = 1 + max(height(root->left), 
            height(root->right)); 

  int balanceFactor = getBalanceFactor(root); 

  if (balanceFactor > 1)
  {
    if (data < root->left->data)
    {
      return rightRotate(root);
    }
    else if (data > root->left->data)
    {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1)
  {
    if (data > root->right->data)
    {
      return leftRotate(root);
    }
    else if (data < root->right->data)
    {
      root->left = rightRotate(root->left);
      return leftRotate(root);
    }
  }

  // if (balance > 1 && key < node->left->key) 
  //   return rightRotate(node); 

  // if (balance < -1 && key > node->right->key) 
  //   return leftRotate(node); 

  // if (balance > 1 && key > node->left->key) 
  // { 
  //   node->left = leftRotate(node->left); 
  //   return rightRotate(node); 
  // } 

  // if (balance < -1 && key < node->right->key) 
  // { 
  //   node->right = rightRotate(node->right); 
  //   return leftRotate(node); 
  // } 

  return root; 
} 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AVL * minValueNode(AVL* node) 
{ 
  AVL* current = node; 

  while (current->left != NULL) 
    current = current->left; 

  return current; 
} 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AVL* deleteNode(AVL* root, char data) 
{ 

  if (root == NULL) 
    return root; 

  if ( data < root->data ) 
    root->left = deleteNode(root->left, data); 

  else if( data > root->data ) 
    root->right = deleteNode(root->right, data); 

  else
  { 
    if( (root->left == NULL) || (root->right == NULL) ) 
    { 
      AVL *temp = root->left ? root->left : 
                      root->right; 

      if (temp == NULL) 
      { 
        temp = root; 
        root = NULL; 
      } 
      else
      *root = *temp;
 
      free(temp); 
    } 
    else
    { 
      AVL* temp = minValueNode(root->right); 

      root->data = temp->data; 

      root->right = deleteNode(root->right, temp->data); 
    } 
  } 

  if (root == NULL) 
  return root; 

  root->bal = 1 + max(height(root->left), 
            height(root->right)); 


  int balanceFactor = getBalanceFactor(root); 

  if (balanceFactor > 1)
  {
    if (getBalanceFactor(root->left) >= 0)
    {
      return rightRotate(root);
    }
    else
    {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }

  if (balanceFactor < -1)
  {
    if (getBalanceFactor(root->right) <= 0)
    {
      return leftRotate(root);
    }
    else
    {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }

  // if (balance > 1 && getBalance(root->left) >= 0) 
  //   return rightRotate(root); 

  // if (balance > 1 && getBalance(root->left) < 0) 
  // { 
  //   root->left = leftRotate(root->left); 
  //   return rightRotate(root); 
  // } 

  // if (balance < -1 && getBalance(root->right) <= 0) 
  //   return leftRotate(root); 

  // // Right Left Case 
  // if (balance < -1 && getBalance(root->right) > 0) 
  // { 
  //   root->right = rightRotate(root->right); 
  //   return leftRotate(root); 
  // } 
  return(root);
  }
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   	        
void printPreOrder(AVL *root) 
{ 
      if(root != NULL) 
	    { 
		    printf("%c ", root->data); 
		        printPreOrder(root->left); 
			    printPreOrder(root->right); 
			      } 
} 


/*==//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





                                /**********************************************************************************/
                                /*         B TREE FUNCTIONS                                                                       */
                               /*                                                                                 */
                               /*==================================================================================*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
void insert(char key)
{
struct node *newnode;
char upKey;
enum KeyStatus value;
value = ins(root, key, &upKey, &newnode);
if (value == Duplicate)
printf("Key already available\n");
if (value == InsertIt)
{
struct node *uproot = root;
root=malloc(sizeof(struct node));
root->n = 1;
root->keys[0] = upKey;
root->p[0] = uproot;
root->p[1] = newnode;
}End of if /
}End of insert()/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum KeyStatus ins(struct node *ptr, char key, char *upKey,struct node **newnode)
{
struct node *newPtr, *lastPtr;
int pos, i, n,splitPos;
int newKey, lastKey;
enum KeyStatus value;
if (ptr == NULL)
{
*newnode = NULL;
*upKey = key;
return InsertIt;
}
n = ptr->n;
pos = searchPos(key, ptr->keys, n);
if (pos < n && key == ptr->keys[pos])
return Duplicate;
value = ins(ptr->p[pos], key, &newKey, &newPtr);
if (value != InsertIt)
return value;
If keys in node is less than M-1 where M is order of B tree//
if (n < M - 1)
{
pos = searchPos(newKey, ptr->keys, n);
//Shifting the key and pointer right for inserting the new key/
for (i=n; i>pos; i--)
{
ptr->keys[i] = ptr->keys[i-1];
ptr->p[i+1] = ptr->p[i];
}
/Key is inserted at exact location/
ptr->keys[pos] = newKey;
ptr->p[pos+1] = newPtr;
++ptr->n; /incrementing the number of keys in node/
return Success;
}/End of if /
/If keys in nodes are maximum and position of node to be inserted is last/
if (pos == M - 1)
{
lastKey = newKey;
lastPtr = newPtr;
}
else /If keys in node are maximum and position of node to be inserted is not last/
{
lastKey = ptr->keys[M-2];
lastPtr = ptr->p[M-1];
for (i=M-2; i>pos; i--)
{
ptr->keys[i] = ptr->keys[i-1];
ptr->p[i+1] = ptr->p[i];
}
ptr->keys[pos] = newKey;
ptr->p[pos+1] = newPtr;
}
splitPos = (M - 1)/2;
(*upKey) = ptr->keys[splitPos];

(*newnode)=malloc(sizeof(struct node));/Right node after split/
ptr->n = splitPos; /No. of keys for left splitted node/
(*newnode)->n = M-1-splitPos;/No. of keys for right splitted node/
for (i=0; i < (*newnode)->n; i++)
{
(*newnode)->p[i] = ptr->p[i + splitPos + 1];
if(i < (*newnode)->n - 1)
(*newnode)->keys[i] = ptr->keys[i + splitPos + 1];
else
(*newnode)->keys[i] = lastKey;
}
(*newnode)->p[(*newnode)->n] = lastPtr;
return InsertIt;
}//End of ins()/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void display(struct node *ptr, int blanks)
{
if (ptr)
{
int i;
for(i=1; i<=blanks; i++)
printf(" ");
for (i=0; i < ptr->n; i++)
printf("%c ",ptr->keys[i]);
printf("\n");
for (i=0; i <= ptr->n; i++)
display(ptr->p[i], blanks+10);
}/End of if/
}/End of display()/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void search(char key)
{
int pos, i, n;
struct node *ptr = root;
printf("Search path:\n");
while (ptr)
{
n = ptr->n;
for (i=0; i < ptr->n; i++)
printf(" %c",ptr->keys[i]);
printf("\n");
pos = searchPos(key, ptr->keys, n);
if (pos < n && key == ptr->keys[pos])
{
printf("Key %c found in position %d of last dispalyed node\n",key,i);
return;
}
ptr = ptr->p[pos];
}
printf("Key %c is not available\n",key);
}/End of search()/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int searchPos(char key, char *key_arr, int n)
{
int pos=0;
while (pos < n && key > key_arr[pos])
pos++;
return pos;
}/End of searchPos()/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DelNode(char key)
{
struct node *uproot;
enum KeyStatus value;
value = del(root,key);
switch (value)
{
case SearchFailure:
printf("Key %c is not available\n",key);
break;
case LessKeys:
uproot = root;
root = root->p[0];
free(uproot);
break;
}/End of switch/
}/End of delnode()/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum KeyStatus del(struct node *ptr, char key)
{
int pos, i, pivot, n ,min;
char *key_arr;
enum KeyStatus value;
struct node **p,*lptr,*rptr;

if (ptr == NULL)
return SearchFailure;
/Assigns values of node/
n=ptr->n;
key_arr = ptr->keys;
p = ptr->p;
min = (M - 1)/2;/Minimum number of keys/

//Search for key to delete
pos = searchPos(key, key_arr, n);
// p is a leaf
if (p[0] == NULL)
{
if (pos == n || key < key_arr[pos])
return SearchFailure;
/Shift keys and pointers left/
for (i=pos+1; i < n; i++)
{
key_arr[i-1] = key_arr[i];
p[i] = p[i+1];
}
return --ptr->n >= (ptr==root ? 1 : min) ? Success : LessKeys;
}/End of if /

//if found key but p is not a leaf
if (pos < n && key == key_arr[pos])
{
struct node *qp = p[pos], *qp1;
char nkey;
while(1)
{
nkey = qp->n;
qp1 = qp->p[nkey];
if (qp1 == NULL)
break;
qp = qp1;
}/End of while/
key_arr[pos] = qp->keys[nkey-1];
qp->keys[nkey - 1] = key;
}/End of if /
value = del(p[pos], key);
if (value != LessKeys)
return value;

if (pos > 0 && p[pos-1]->n > min)
{
pivot = pos - 1; /pivot for left and right node/
lptr = p[pivot];
rptr = p[pos];
/Assigns values for right node/
rptr->p[rptr->n + 1] = rptr->p[rptr->n];
for (i=rptr->n; i>0; i--)
{
rptr->keys[i] = rptr->keys[i-1];
rptr->p[i] = rptr->p[i-1];
}
rptr->n++;
rptr->keys[0] = key_arr[pivot];
rptr->p[0] = lptr->p[lptr->n];
key_arr[pivot] = lptr->keys[--lptr->n];
return Success;
}/End of if /
//if (posn > min)
if (pos < n && p[pos + 1]->n > min)
{
pivot = pos; /pivot for left and right node/
lptr = p[pivot];
rptr = p[pivot+1];
/Assigns values for left node/
lptr->keys[lptr->n] = key_arr[pivot];
lptr->p[lptr->n + 1] = rptr->p[0];
key_arr[pivot] = rptr->keys[0];
lptr->n++;
rptr->n--;
for (i=0; i < rptr->n; i++)
{
rptr->keys[i] = rptr->keys[i+1];
rptr->p[i] = rptr->p[i+1];
}/End of for/
rptr->p[rptr->n] = rptr->p[rptr->n + 1];
return Success;
}/End of if /

if(pos == n)
pivot = pos-1;
else
pivot = pos;

lptr = p[pivot];
rptr = p[pivot+1];
/merge right node with left node/
lptr->keys[lptr->n] = key_arr[pivot];
lptr->p[lptr->n + 1] = rptr->p[0];
for (i=0; i < rptr->n; i++)
{
lptr->keys[lptr->n + 1 + i] = rptr->keys[i];
lptr->p[lptr->n + 2 + i] = rptr->p[i+1];
}
lptr->n = lptr->n + rptr->n +1;
free(rptr); /Remove right node/
for (i=pos+1; i < n; i++)
{
key_arr[i-1] = key_arr[i];
p[i] = p[i+1];
}
return --ptr->n >= (ptr == root ? 1 : min) ? Success : LessKeys;
}/End of del()/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void eatline(void) {
char c;
puts("");
while (c=getchar()!='\n') ;
}

/ Function to display each key in the tree in sorted order (in-order traversal)
@param struct node *ptr, the pointer to the node you are currently working with
/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void inorder(struct node *ptr) {
if (ptr) {
if (ptr->n >= 1) {
inorder(ptr->p[0]);
printf("%d ", ptr->keys[0]);
inorder(ptr->p[1]);
if (ptr->n == 2) {
printf("%d ", ptr->keys[1]);
inorder(ptr->p[2]);
}
}
}
}

/ Function that returns the total number of keys in the tree.
@param struct node *ptr, the pointer to the node you are currently working with
/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int totalKeys(struct node *ptr) {
if (ptr) {
int count = 1;
if (ptr->n >= 1) {
count += totalKeys(ptr->p[0]);
count += totalKeys(ptr->p[1]);
if (ptr->n == 2) count += totalKeys(ptr->p[2]) + 1;
}
return count;
}
return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
* Function that prints the total number of keys in the tree.
@param struct node *ptr, the pointer to the node you are currently working with
/
///////////////////////////////////////
void printTotal(struct node *ptr) {
printf("%d\n",totalKeys(ptr));
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/ Function that returns the smallest key found in the tree.
@param struct node *ptr, the pointer to the node you are currently working with
/
int getMin(struct node *ptr) {
if (ptr) {
int min;
if (ptr->p[0] != NULL) min = getMin(ptr->p[0]);
else min = ptr->keys[0];
return min;
}
return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/ Function that returns the largest key found in the tree.
@param struct node *ptr, the pointer to the node you are currently working with
/
int getMax(struct node *ptr) {
if (ptr) {
int max;
if (ptr->n == 1) {
if (ptr->p[1] != NULL) max = getMax(ptr->p[1]);
else max = ptr->keys[0];
}
if (ptr->n == 2) {
if (ptr->p[2] != NULL) max = getMax(ptr->p[2]);
else max = ptr->keys[1];
}
return max;
}
return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/ Function that prints the smallest and largest keys found in the tree.
@param struct node *ptr, the pointer to the node you are currently working with
/
void getMinMax(struct node *ptr) {
printf("%c %c\n", getMin(ptr), getMax(ptr));
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/ Function that determines the largest number.
@param int, integer to compare.
@param int, integer to compare.
@param int, integer to compare.
/
int max(int first, int second, int third) {
int max = first;
if (second > max) max = second;
if (third > max) max = third;
return max;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/Function that finds the maximum level in the node and returns it as an integer.
@param struct node *ptr, the node to find the maximum level for.
/
int maxLevel(struct node *ptr) {
if (ptr) {
int l = 0, mr = 0, r = 0, max_depth;
if (ptr->p[0] != NULL) l = maxLevel(ptr->p[0]);
if (ptr->p[1] != NULL) mr = maxLevel(ptr->p[1]); 
if (ptr->n == 2) {
if (ptr->p[2] != NULL) r = maxLevel(ptr->p[2]);
}
max_depth = max(l, mr, r) + 1;
return max_depth;
}
return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/Function that prints the maximum level in the tree.
struct node *ptr, the tree to find the maximum level for.
/
void printMaxLevel(struct node *ptr) {
int max = maxLevel(ptr) - 1;
if (max == -1) printf("tree is empty\n");
else printf("%c\n", max);

}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






