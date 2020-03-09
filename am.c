#include<stdio.h>
#include<stdlib.h>
#include"funct.c"
int main(int n,char *file[])
{
    int choice;
    char key;
    int flag = 0;
    char indicator='M';
    char ch[1];
    node *root=NULL;
    AVL *avl=NULL;
    int h;
    FILE *fp;
    if(n!=2)
    {
	printf("\n sorry input yoy given is incorrect\n");
	printf("usage:a.out fileneme");
	exit(-1);
    }
    fp=fopen(file[1],"r");
    if(fp==NULL)
    {
	printf("\n the file that you requesed is not available !!! try again\n");
	printf("please give the appropriate file that is available in the current directory\n");
	exit(-1);
    }
    printf("\n");
    fscanf(fp,"%s",ch);
    printf("======================================TREE LIBRARY============================\n");
    printf("\nPress 1 - Binary Search Tree Implementation\n");
    printf("\nPress 2-  Adelson Velskii Landis Tree Implementation\n");
    printf("\n Press 3- B Tree Implementation\n");
    scanf("%d",&choice);
    getchar();
    while(indicator=='M')
    {
	switch(choice)
	{
	    case 1:
		while(!feof(fp)) //scanf through the file
		{
		    root=Insert_node_BST(root,ch[0]);

                 fscanf(fp,"%s",ch);
		}
		if(root==NULL)
		{
		    printf("Tree is empty\n");
		    exit(-1);
		}
		else
		{
		   root=Insert_node_BST(root,ch[0]);
		   fscanf(fp,"%s",ch);
		   printf("Binary Search Tree in Triangular form is:\n");
		   print_Tree_Triangle_BST(root,2);
		   printf("\n");
		   printf("Binary Search Tree in Diagonal form is:\n");
		   print_Tree_Diagonal_BST(root,2);
		   printf("\n");
               int option;
	       char condition='Y';
	       printf("\nPress 1-Height of the Binary Search Tree\n");
	       printf("\n Press 2-Depth of the Binary Search Tree \n");
	       printf("\n Press 3-Total number of Leaf Nodes in the Binary Search Tree\n");
	       printf("\n Press 4-Total number of Non-Leaf Nodes in the Bianry Search Tree\n");
	       printf("\nPress 5-Total number of Nodes in the Binary Search Tree\n");
	       printf("\n Press 6-Preorder Traversal\n");
	       printf("\nPress 7-Post order Traversal\n");
	       printf("\n Press 8-Inorder Traversal\n");
	       printf("\n Press 9-Smallest Node in the Binary Search Tree\n");
	       printf("\n Press 10-Largest Node in the Binary Search Tree\n");
	       printf("\n Press 11- Delete a element in the Binary Search Tree\n");
          scanf("%d",&option);
	  getchar();
           while(condition=='Y')
	   {
	       switch(option)
	       {
		   case 1:
		   printf("Height of the given Binary Search Tree is %d\n",Height_BST(root));
		    break;
	          case 2:
		  printf("Depth of the given Binary Search Tree is %d\n",Depth_BST(root));
		  break;
		  case 3:
		  printf("\n");
		  printf("\n Total Number of Leaf Nodes in the given Binary Search Tree is %d\n",leaf_nodes_BST(root));
		  break;
		  case 4:
		  printf("\n");
		  printf("\n Total Number of Non -Leaf Nodes in the Binary Search Tree is %d\n",nonLeafNodes_BST(root));
		  break;
		  case 5:
		  printf("\n");
		  printf("\n Total Number of Nodes in the Binary Search Tree is %d\n",leaf_nodes_BST(root)+nonLeafNodes_BST(root));
		  break;
		  case 6:
		  printf("\n");
		   printf("\nPre order Traversal is:\n");
		  preOrderPrint_BST(root);
		  break;
		  case 7:
		  printf("\n");
		  printf("\n Post Order Traversal is:\n");
		  post_Order_BST(root);
		  break;
		  case 8:
		  printf("\n");
		  printf("\n In Order Traversal is:\n");
		  in_Order_BST(root);
		  break;
		  case 9:
                  printf("\n");
		  smallest_node_BST(root);
		  break;
		  case 10:
		  printf("\n");
		  largest_node_BST(root);
		  break;
		  case 11:
		  

		  printf("enter the character to be deleted\n");
		  scanf("%c",&key);
		  flag= search_BST(root,key);
                    if(flag)
		    
		      printf("Key %c found in the Tree \n",key);
		    else
		     {	printf("Key %c not found in the Tree\n",key);
		         exit(-1);
		         }

                         

		    printf("Binary Search Tree is :\n");

		  
		     printf("\n");
		     printf("Binary Search Tree after the deletion is :\n");
		     root=deleteNode_BST(root,key);
		     printf(" In Triangular Form :\n");
		     print_Tree_Triangle_BST(root,1);
		     printf("\n"); 
		     printf("\n");
		     printf("In Diagonal Form:\n");
		     print_Tree_Diagonal_BST(root,1);
		     printf("\n");
		     printf("Height of the Binary Search Tree after the deletion of  character is %d\n",Height_BST(root));
		     printf("\n");
		     printf("Depth of the Binary Search Tree after the deletion of the  character is %d\n",Depth_BST(root));
		     printf("\n");
		     printf("\n Number of nodes in the Binary Search Tree after the Deletion of  character is %d\n",(leaf_nodes_BST(root)+nonLeafNodes_BST(root)));
		     printf("\n");
		     printf("\n Pre ordering printing after the deletion of  character is :\n");
                     preOrderPrint_BST(root);
                     printf("\n");
                     printf("Post Order printing after the deletion of  character in the Binary Search Tree is :\n");
                     post_Order_BST(root);
                     printf("\n");
                     printf("In order printing after the deletion of the  character in the Binary Search Tree is \n");
                     in_Order_BST(root);
                     printf("\n");
                     printf("\n After the deletion :\n");
                     smallest_node_BST(root);
                     printf("\n\n");
                     largest_node_BST(root);
                     break;

               defaulf:
		     printf("!!!!!!!!!!!!!!!!!!!!Incorrect option please try again\n");
	       }
	       printf("enter Y to continue and N to stop\n");
	       scanf("%c",&condition);
	       printf("%c\n",condition);
	   
	  }
		}
		break;
	    case 2:
		break;
	    case 3:
		break;
	    default:
		printf("\n Incorrect option please Try again\n");
	}
	printf("\n enter M to continue and N to stop\n");
	scanf("%c",&indicator);
	printf("%c\n",indicator);
    }


             
		 
		    
		  
		  
}



