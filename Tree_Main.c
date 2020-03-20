                                             // Written by: N Mohan Teja
                                             // Date:  18th March 2020
                                             // Contents: Implementation of Different Tree Data Structures.
#include<stdio.h>
#include<stdlib.h>
#include"Tree_Algorithms.c"
int main(int n,char *file[])
{
    int choice;
    char key,c;
    system("clear");
    int flag = 0;
    char ch[1];
    nodee *avl=NULL;
    node *root=NULL;
    struct btnode *btree=NULL;  
    FILE *fp;
    int count=0;
    int valid;
    int quit;


    if(n!=2)
    {
	printf("\n Sorry Input You given is Absorted\n");
	printf("Usage:a.out fileneme  \n");
	exit(-1);
    }
   
    
	
     
    fp=fopen(file[1],"r");
    if(fp==NULL)
    {
	printf("\n The file that you requesed is not available !!! try again\n");
	printf("please give the appropriate file that is available in the current directory\n");
	exit(-1);
    }
    printf("\n");
    fscanf(fp,"%s",ch);
    printf("==================================================================TREE LIBRARY=========================================================================\n");
   
    printf("\n  Name : N Mohan Teja \n");
    printf("\n  Class : 3rd Year Mathematics Honours\n");
    printf("\n  Registeration no: 171203 \n");
    printf("\n  Language: C \n");
    printf("\n  Complier : GNU Complier\n");
    printf("\n  Project : Implementation of the Tree Algorithms \n");
    printf("\n Git Hub ID: nmohanteja8@gmail.com\n");
    printf("\n  University: Sri Sathya Sai Institute of Higher Learning \n");
    printf("\n  Guided by: Sai Kumar \nSanaka \nShiva Sundar \nUday Kiran\nDarshan Gera\n");
                                  
    
    
    printf("\n****************************************************************************************************************************************\n");
   printf("\n*                                                                                                                                      *\n");
   printf("\n*                                                                                                                                      *\n");
   printf("\n                                 This is the Tree Implementation Menu Driven Program                                                  \n"  ); 
   printf("\n***************************************************************************************************************************************\n");

   while(1)
    {	
        printf("\n===================================================================================================================================================\n");
        printf("\n\t\t\t\t Press 1- Binary Search Tree\t\t\t\t");
        printf("\n\t\t\t\t Press 2- Adelson Velski Landis Tree\t\t\t\t\n");
        printf("\n\t\t\t\t Press 3- B Tree  \t\t\t\t\n");
        printf("\n\t\t\t\t Press 4- Termination of the Program\t\t\t\t\n");
        printf("\n===================================================================================================================================================\n");
        printf("\n\n");
        printf("\n enter your choice\n");
        printf("\n\n");
        scanf("%d",&choice);
        printf("\n %d\n",choice);



	switch(choice)
	{
	    case 1:
	       rewind(fp);	
	       system("clear");
		while(!feof(fp)) //scanf through the file
		{
		    root=Insert_node_BST(root,ch[0]);

                 fscanf(fp,"%s",ch);
		}
		if(root==NULL)
		{
		    printf("Tree is empty\n");// check for empty tree
		    exit(-1);
		}
	
		  else
		  {   
		   root=Insert_node_BST(root,ch[0]);// inserting the characters into the tree by reading from the specified file
		   fscanf(fp,"%s",ch);
		   printf("Binary Search Tree in Triangular form is:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		   print_Tree_Triangle_BST(root,2);// printing in triangle form
		   printf("\n");
		   printf("Binary Search Tree in Diagonal form is:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		   print_Tree_Diagonal_BST(root,2);// printing in diagonal form
		   printf("\n");
		   printf("\n");
		   int option;
		   int quit;
		 
		  
		  do
		   {
		  printf("\n=======================================================================\n");   
                  printf("\nPress 1- Height of the Binary Search Tree\n");
		  printf("\n Press 2- Depth of the Binary Search Tree\n");
		  printf("\n Press 3- Total Number of Leaf Nodes in the Binary Search Tree\n");
		  printf("\n Press 4- Total Number of Nodes in the Binmary Search Tree\n");
		  printf("\n Press 5- Pre order Traversal of the Binary Search Tree\n");
		  printf("\n Press 6- Post order Traversal of the Binary Search Tree\n");
		  printf("\n Press 7- In order Traversal of the Binary Search Tree\n");
		  printf("\n Press 8-Smallest node in the Binary Search Tree\n");
		  printf("\n Press 9- Largest Node in the Binary Search Tree\n");
		  printf("\n Press 10- Deleting any random character in the Binary Search Tree\n");
		  printf("\n Press 11 - For Coming out of the Binary Search Tree\n");
		  printf("\n==========================================================================\n");
                  scanf("%d",&option);
		 
		    switch(option)
		    {
		case 1:

                   printf("\n=====================================================================================================================================\n");
		   printf("\nHeight of the given Binary Search Tree is %d\n",Height_BST(root));
		   printf("\n======================================================================================================================================\n");
		   break;
		case 2:

		   printf("\n======================================================================================================================================\n");
		   printf("\n");
		   printf("\n======================================================================================================================================\n");  
		   printf("\nDepth of the given Binary Search Tree is %d\n",Depth_BST(root));
		   printf("\n======================================================================================================================================\n");
		   break;
		case 3:
		   printf("\n");
		   count=0;
		   printf("\n======================================================================================================================================\n");
		   printf("\n Total Number of Leaf Nodes in the given Binary Search Tree is %d\n",leaf_nodes_BST(root));
		   printf("\n=======================================================================================================================================\n");
		   break;
			
	        case 4:
		   printf("\n");
		   count=0;
		   count=0;
		   printf("\n======================================================================================================================================\n");
		   printf("\n Total Number of Nodes in the Binary Search Tree is %d\n",countNodes_BST(root));
		   printf("\n======================================================================================================================================\n");
		   break;
		case 5:
		   printf("\n");
		   system("clear");
		   printf("\n======================================================================================================================================\n");
		   print_Tree_Triangle_BST(root,2);
		   printf("\n");
		   printf("\n======================================================================================================================================\n");
		   printf("\n");
		   printf("\n======================================================================================================================================\n");
		   printf("\n");
		   printf("\nPre order Traversal is:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		   printf("\n");
		   preOrderPrint_BST(root);
		   printf("\n");
		   printf("\n======================================================================================================================================\n");
		   break;
		case 6:

		   printf("\n");
		   printf("\n======================================================================================================================================\n");
		   printf("\n");
		   printf("\n Post Order Traversal is:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		   post_Order_BST(root);
		   printf("\n");
		   printf("\n======================================================================================================================================\n");
		   break;
		case 7:

		   printf("\n");
		   printf("\n");
		   printf("\n======================================================================================================================================\n");
		   
		   printf("\n");
		   printf("\n In Order Traversal is:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		   in_Order_BST(root);
		   printf("\n");
		   printf("\n======================================================================================================================================\n");
		   break;
		case 8:
		   printf("\n");
                   printf("\n");
		   printf("\n======================================================================================================================================\n");
		   smallest_node_BST(root);
		   printf("\n======================================================================================================================================\n");
		   break;
	       case 9:

		   printf("\n");
		   printf("\n======================================================================================================================================\n");
		   largest_node_BST(root);
		   printf("\n======================================================================================================================================\n");
		   break;
		case 10:
		  
                   printf("\n======================================================================================================================================\n");
		   printf("enter the character to be deleted:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		   printf("\n======================================================================================================================================\n");
		   scanf("%c",&key);
		   printf("\n%c\n",key);
		   key=getchar();
		   flag= search_BST(root,key);
                    if(flag)
		      
		    {
		     printf("\n====================================================================================================================================\n");
		     printf("Key %c found in the Tree \n",key);
                     printf("\n====================================================================================================================================\n"); 
		     printf("\n===================================================================================================================================\n");
                     printf("\n");
		     printf("\n===================================================================================================================================\n");
		     printf("Binary Search Tree after the deletion is :>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		     printf("\n===================================================================================================================================\n");
		     root=deleteNode_BST(root,key);
		     printf("\n===================================================================================================================================\n");
		     printf(" In Triangular Form >>>>>>>>>>>>>>>>>>>>>>>:\n");
		     printf("\n===================================================================================================================================\n");
		     print_Tree_Triangle_BST(root,1);
		     printf("\n"); 
		     printf("\n");
		     printf("\n ==================================================================================================================================\n");
		     printf("In Diagonal Form:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		     printf("\n===================================================================================================================================\n");
		     print_Tree_Diagonal_BST(root,1);
		     printf("\n");
		     printf("\n===================================================================================================================================\n");
		     printf("Height of the Binary Search Tree after the deletion of  character is %d\n",Height_BST(root));
		     printf("\n===================================================================================================================================\n");
		     printf("\n");
		     printf("\n===================================================================================================================================\n");
		     printf("Depth of the Binary Search Tree after the deletion of the  character is %d\n",Depth_BST(root));
		     printf("\n===================================================================================================================================\n");
		     printf("\n");
		     count=0;
		     printf("\n===================================================================================================================================\n");
		  
                    
		     printf("\n===================================================================================================================================\n");
		     
		   
		     printf("\n Pre ordering printing after the deletion of  character is >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>:\n");
                     printf("\n\n");
		     preOrderPrint_BST(root);
		     printf("\n===================================================================================================================================\n");
                     printf("\n");
                     printf("\n===================================================================================================================================\n");
                     printf("Post Order printing after the deletion of  character in the Binary Search Tree is >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>:\n");
		     printf("\n");
                     post_Order_BST(root);
		     printf("\n===================================================================================================================================\n");
                     printf("\n");
                     printf("In order printing after the deletion of the  character in the Binary Search Tree is >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                     in_Order_BST(root);
		     printf("\n=====================================================================================================================================");
                     printf("\n");
		     printf("======================================================================================================================================");
                     printf("\n After the deletion :\n");
                     smallest_node_BST(root);
                     printf("\n\n");
                     largest_node_BST(root);
		     printf("\n\n");
		     printf("=======================================================================================================================================");                         }
		      else
		      {
			  printf("\n %c not found in the Binary Search Tree \n",key);
		      }

		       break;
	             case 11:
		       printf("\n");
		       quit=1;
		       printf("\n==================================================================================\n");
		       printf("\n End of Binary Search Tree Implementation.................................\n");
		       printf("\n=====================================================================================\n");
		       printf("\n");
		       break;
		     default:
		        quit=0;
			printf("\n=====================================================================================================\n");     
		        printf("\n !!!!!!!!!!!!!!!!!!!!!!OOOOOOOOOO    Sorrry Wrong choice Please Try Again!!!!!!!!!!!!!!!!!!!!!!!!!!");
			printf("\n=========================================================================================================\n");
		    }
		   
		}while(option!=11);// end of do while loop
	  }//end of the Binary Search Tree
                 break;
             case 2:
		     
                 system("clear");// clearing the screen
                 rewind(fp);   
	         while(!feof(fp))// reading the file until we reach the end of file
	           {
		     avl=_insert(avl,ch[0]);// reading from the file
		     fscanf(fp,"%s",ch);
	           }   
		
	            if(avl==NULL)
		     {
		   
		       printf("Tree is empty\n");
		       exit(-1);
		     }
		
		
		    else
		     {
		      avl=_insert(avl,ch[0]);
		      fscanf(fp,"%s",ch);
		      printf("AVL Tree printing\n");
		      preorder(avl);
		      inorder(avl);
		      print_AVL(avl,2);
		      printf("\n");
		      printf("\n");
		      int opt;
		      printf("\n=======================================================\n");
		      printf("\n Adelson Velski Landis Tree Implementation\n");
		      printf("\n========================================================\n");
		   
		   do
		    {
			printf("\n================================================================================\n");
			printf("\n Press 1- height of the Adelson Velski Landis Tree\n");
			printf("\n Press 2- Pre order Traversal of the Adelson velski Landis Tree\n");
			printf("\n Press 3- Post order Traversal of the Adelson Velski Landis Tree\n");
			printf("\n Press 4- In order Traversal of the Adelson Velski Landis Tree \n");
			printf("\n Press 5- Deleting an element in the Adelson Velski Landis Tree\n");
			printf("\n Press 6- Balance Factor \n");
			printf("\n Press 7- Maximum element in the Adelson Velski Landis Tree\n");
			printf("\n Press 8- Minimum Element in the Adelson Velski Landis Tree \n");
			printf("\n Press 9 - Termination From the Adelson Velski Tree\n");
			printf("\n=================================================================================\n");
			scanf("%d",&opt);

			getchar();

                   switch(opt)
		   {
		       case 1:
			   printf("\n\n");
			   printf("\n==============================================================================================================================\n");
		           print_AVL(avl,2);
			   printf("\n=============================================================================================================================\n");
			   printf("\n");
			   printf("\n==============================================================================================================================\n");
			   printf("Height of the Adelson Velski Landis Tree is %d\n",height(avl));
                           printf("\n\n");
			   printf("\n==============================================================================================================================\n");           	           
			   break;		      		  		       
		       case 2:
			 system("clear");
		         printf("\n");
			 print_AVL(avl,2);
		         printf("\n================================================================================================================================\n");
	                 printf("\n pre order printing of the Adelson Velski Landis Tree is >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>:\n");
		         printf("\n");
	                 preorder(avl);
		         printf("\n");
		         printf("\n===============================================================================================================================\n");
			     break;

		       case 3:
			 system("clear");    
		         printf("\n");
			 print_AVL(avl,2);
			 printf("\n================================================================================================================================\n");
		         printf("\n Post order printing of the Adelson Velski Landis Tree is >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>:\n");
		         postorder(avl);
			 printf("\n");
			 printf("\n================================================================================================================================\n");
			     break;
		       case 4:
			 system("clear");
			 printf("\n");
			 print_AVL(avl,2);
			 printf("\n================================================================================================================================\n");
			 printf("In order printing of the Adelson Velski Tree is >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>:\n");
			 inorder(avl);
			 printf("\n");
			 printf("\n================================================================================================================================\n");
			    break;
		       case 5:
			   system("clear");
			   printf("\n");
                           printf("\n==============================================================================================================================\n");
			   printf("Enter the character to be deleted from the Adelson Velski Landis Tree:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			   printf("\n==============================================================================================================================\n");
		           scanf("%c",&key);
			   printf("\n %c\n",key);
		           flag=search_AVL(avl,key);// searching the element in the Avl tree
			     if(flag)
			     {
				 printf("\n========================================================================================================================\n");
		         	 printf("Key %c found in the Adelson Velski Landis Tree \n",key);
				 printf("============================================================================================================================");
                                              
                                 printf("\n");
			         printf("\n Adelson Velski Landis Tree after the deletion is >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>:\n");
			         avl=Delete(avl,key);
			         print_AVL(avl,1);
			         printf("\n");
			         printf("\n========================================================================================================================\n");
			         printf("Height of the Adelson Velski Landis Tree after the deletion is %d\n",height(avl));
			         printf("\n========================================================================================================================\n");
			         printf("\n");
				 printf("\n========================================================================================================================\n");
			         printf("\n Pre Order Printing of the Adelson Velski Tree after the deletion process is >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>:\n");
			         preorder(avl);
			         printf("\n");
				 printf("\n========================================================================================================================\n");
			         printf("\n\n");
				 printf("\n=========================================================================================================================\n");
				 printf("\n Post Order Printing after the deletion process is >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>:\n");
			         postorder(avl);
			         printf("\n");
				 printf("\n========================================================================================================================\n");
			         printf("\n");
				 printf("\n========================================================================================================================\n");
				 printf("\n In order printing of the Adelosn Velski Tree after the deletion process is>>>>>>>>>>>>>>>>>>>>>>>>>>>:\n");
			         inorder(avl);
			         printf("\n\n");
				 printf("\n========================================================================================================================\n");
                                      }
                                
			     else
			     {
				 printf("\n=======================================================================================================================\n");
				 printf("Key %c not found in the Adelson Velski Tree \n",key);
				 printf("\n========================================================================================================================\n");
				
			     }
		
			     	break;
		       case 6:			
			    
				 printf("\n========================================================================================================================\n");
		                 printf("\n balance factor of the Adelson Velski Tree is %d \n",BalanceFactor(avl));
				 printf("\n========================================================================================================================\n");
				 
			   
			 
			     break;
		       case 7:
			     printf("\n\n");
			     printf("\n============================================================================================================================\n");
			     largest_AVL(avl);
			     printf("\n=============================================================================================================================\n");
			     break;
		       case 8:
			     printf("\n\n");
			     printf("\n===============================================================================================================================\n");
			       smallest_AVL(avl);
			     printf("\n==========================================================================================================================\n");
                                   break;
		       case 9:
			        printf("\n\n");
				printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
	                         
				quit=1;
			        printf("\n End of the Adelson Velski Landis Tree Implementation......................................\n\n");
				printf("\n////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
				break;
		      default:
		            printf("\n");
			    printf("\n===================================================================================================\n");
			    printf("\n !!!!!!!!!!!!!!!!!!!!!!!!!!!!!Incorrect option!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			    printf("\n====================================================================================================\n");
			    quit=0;
			       }
			     printf("\n\n");
			  
		   }while(opt!=9);// end of do while loop
               }//end of the AVL Tree implementation		    
		break;	
	     case 3:
		rewind(fp);// positioning the file pointer to the starting position for the each Tree implementation
		while(!feof(fp))//Reading the till the end of the file pointer
		{
		   btree=insert(ch[0],btree);
		    fscanf(fp,"%s",ch);
		}
		if(btree==NULL)// check for empty
		{
		    printf("Tree is empty\n");
		    exit(-1);
		}
		
		else
		{
		    btree=insert(ch[0],btree);// inserting the characters onto the b tree
		    fscanf(fp,"%s",ch);
		   
		    printf("\n");
		    print_btree(btree,1);
		    display(btree);
		}
		     do
		     {
			 printf("\n================================================\n");
			 printf("\n Press 1  Height of the B tree\n");
			 printf("\n Press 2- Printing of  the B-Tree\n");
			 printf("\n Press 3- Pre-Traversal of the B tree\n"); 
			 printf("\n Press 4-Deleting an element in the B tree \n");
			 printf("\n Press 5- termination from the B tree\n");
			 printf("\n=====================================================\n");
			 printf("\n\n");
			 printf("\n Please enter your choice as preferred\n");
			
		         scanf("%d",&valid);
			 printf("\n %d\n",valid);
			 switch(valid)
			 {
			     case 1:

				 printf("\n");
				 printf("\n=====================================================\n");
				 printf("\n Height of the B tree is %d\n",maxLevel(btree));
				 printf("\n=======================================================\n");
				 printf("\n");
				 break;
			     case 2:
				 printf("\n");
				 printf("\n=========================================================\n");
				print_btree(btree,1);
				printf("\n============================================================\n");

				 printf("\n ");
				 break;
				  
			     case 3:
				 printf("\n ");
				 print_btree(btree,1);
				 printf("\n");
				 printf("\n====================================================\n");
				 printf("\n pre order traversal of the B tree is>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
				  printf("\n");
				  display(btree);
				  printf("\n");
                                   printf("\n======================================================\n");
				    break;
			     case 4:
				 {
				 printf("\n");
                                 printf("\n======================================================\n");				 
			         printf("\n Deleting the character ||z|| .............\n");
				 btree=delete_('z',btree);
				 printf("\n==========================================================\n");
			
				 printf("\n=====================================================================\n");
				 printf("\n B tree after the deletion process is \n");
				 printf("\n");
				 printf("\n Btree display sfter the Deletion process is\n");
				 print_btree(btree,1);
				 printf("\n\n");
				 display(btree);
		                 printf("\n==========================================================================\n");
				 }
				 printf("\n");

				break;
			    

			     case 5:
				quit=1;
				printf("\n\n");
				printf("\n===============================================================================\n");
				printf("\n End of the B tree INmplmentation...................\n");
				printf("\n================================================================================\n");
	                       printf("\n");


				 break;
            
                     default:
				 printf("\n");
				 quit=0;
				 printf("\n============================================================================================\n");
				 printf("\n !!!!!!!!!!!!!!!!!!!!!!!!!!In correct option please try again!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
				 printf("\n=================================================================================================\n");
			 }//end of switch case for B tree choices
                 
		 
		     }while(valid!=5);// end of while loop

		     printf("\n");
		
	               break;
	     case 4:
	        printf("\n=========================================================================\n");
		 printf("\n TERMINATION OF THE TREE LIBRARY PROGRAM.......................... \n");
	         printf("\n");
		 printf("\n===========================================================================\n");
		 exit(-1);
		 break;
	     default:
	           printf("\n=========================================================================================================\n");  
	           printf("\n !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Incorrect option please try again!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		   printf("\n=============================================================================================================\n");
		   printf("\n");
	}//end of switch case for Tree Algorithms options
	
    }while(choice!=4);

    fclose(fp);// closing the file that has been opened for reading the input

			
}// end of the main function


             
		 
		    
		  
		  





