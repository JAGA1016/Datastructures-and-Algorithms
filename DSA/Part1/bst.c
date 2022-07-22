#include <stdio.h>
#include <stdlib.h>
struct node            // each node has some element ,address of its parent node,addresses of its left and right subtrees
{
	int key;
	struct node *parent;
	struct node *left;
	struct node *right;
	
};
  //this function prints the key value of nodes of binary search tree in inorder format
 void inorder(struct node* root) 
{
	if (root != NULL) 
	{
		inorder(root->left); // recursively printing left subtree key values
		printf("%d\n", root->key);// printing root_key value
		inorder(root->right);//recursively printing right subtree key values
	}
	
}
 //this function prints the key value of nodes of the bst in preorder traversal format
  void preorder(struct node* root)
 {
    if(root != NULL)
    {   
        printf("%d\n", root->key); //print root_key element of the bst
        preorder(root->left); //recursively printimg left subtree key values
		preorder(root->right);//recuursively printing right subtree key values
    }
    
 }
  void postorder(struct node* root)
 {
    if(root != NULL)
    {   
        postorder(root->left);// recursively goes left
		postorder(root->right);//recursively goes right
		printf("%d\n", root->key);// print the root_key value of bst
    }
    
 }
 //thi function searches element if it is found returns its address of node
  struct node* search(struct node* root, int key)
 {
	
	 if (root == NULL)//if root is equql to NULL means element not found
	{
	 
	  return root;
	}
	
     if (root->key < key)
	{
	  return search(root->right, key);//recursively seaching in the right subtree 
    }
      else if(root->key > key)
	{
	  return search(root->left, key);//recursively searching in the left subtree 
	}
	  else if (root->key == key)
	{
	  return root; // if element found return the address of that node
	}
 }
  //this function takes the node address of the element for which we need to find predecessor 
  struct node* predecessor(struct node* root)
 {   struct node*prev=NULL,*curptr=NULL;
       curptr=root->left; // going in the left subtree 
         if(curptr!=NULL) //if the left of that node is  not null
        {
         while(curptr->right!=NULL)
        {
           curptr=curptr->right; // going in right direction and returning the node which has right null
        }
       
         return curptr;
        }
      else 
     {
        curptr=root;
        prev=curptr->parent;
        while(prev!=NULL && curptr == prev->left)
       {
          curptr=prev;              //here moving up with the help of parent untill prev==null or cuptr is not equal to the previous left
          prev=curptr->parent;
       }
        return prev;
     }
     
 }
   //this function takes the node address of the element for which we need to find successor
  struct node* successor(struct node* root)
 {    
    struct node*prev=NULL,*curptr=NULL;
     curptr=root->right;  // going in the right subtree 
        if(curptr!=NULL) //if the right of that node is  not null
       {
       while(curptr->left!=NULL)
       {
           curptr=curptr->left; // going in left direction and returning the node which has right null
       }
       
       return curptr;
     }
     else 
     {
       curptr=root;
       prev=curptr->parent;
       while(prev!=NULL && curptr == prev->right)
       {
        curptr=prev;                         //here moving up with the help of parent untill prev==null or cuptr is not equal to the previous right
        prev=curptr->parent;
       }
        return prev;
     }
     
 }

  //this function inserts a node in the bst so that the bst property is valid 
 struct node* insert(struct node* node, int key)
{  
	if (node == NULL)                                   //if  bst is empty creates a node
	 {
	    struct node* temp = (struct node*)malloc(sizeof(struct node));
	    if(temp==NULL)
	   {
	     printf("Insert Fail\n");
	   }
	    temp->key = key;
	    temp->left =NULL;
	    temp->right = NULL;
	    temp->parent=NULL;
	    return temp;
	 }

	if (key <= node->key)
	{                                  //if the inserting key is less than or equal to root_key
	     struct node*t=NULL;
	     t = insert(node->left, key); //going recuressively in the left direction until it reaches null
		 t->parent=node;              //storing the address of node in the newley created node->parent
		 node->left=t;              // storing the newly created node address in the node left
		 return node;
    }		
	else if (key > node->key)         //if the inserting key is greater  than  root_key
	{
	    struct node*t=NULL;
	    t = insert(node->right, key);   //going recuressively in the right direction until it reaches null
	    t->parent=node;                 //storing the address of node in the newley created node->parent
		node->right=t;                   // storing the newly created node address in the node left
		return node;
    }
	return node;
}

int main()
{   struct node* root=NULL,*result=NULL;
	  while(1)      
   {    int choice=0,x=0;
        scanf("%d",&choice); 
        switch(choice)          // calling the function based on the user's choice
       {
          case 1: scanf("%d",&x);
                  root=insert(root,x);
                  break;
          case 2: scanf("%d",&x);
                  result=search(root,x);
                   if(result==NULL)
                  {
                    printf("Not Found\n");
                  }
                   else
                  {
                    printf("Found\n");
                  }
                  break;
          case 3: inorder(root);
                  break;
          case 4: preorder(root); 
                  break;
          case 5: postorder(root);
                  break;
          case 6: scanf("%d",&x);   
                   result=search(root,x);
                   if(result==NULL)
                  {
                    printf("Invalid Input\n");
                  }
                   else
                  {
                   result=predecessor(result);
                  if(result==NULL)
                  {
                     printf("No predecessor\n");
                  }
                   else
                  {
                    printf("%d\n",result->key);
                  }
                  }
                  break;
          case 7: scanf("%d",&x);
                  result=search(root,x);
                   if(result==NULL)
                  {
                    printf("Invalid Input\n");
                  }
                   else
                  {
                   result=successor(result);
                   if(result==NULL)
                  {
                     printf("No successor\n");
                  }
                   else
                  {
                    printf("%d\n",result->key);
                  }
                  }
                  break;
          case 8: return 0;
       }
   }
}
