#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct bstnode
{
    char item;                //defining a bstnode
    struct bstnode *left;
    struct bstnode *right;
};

// node for stack which can store address of tree node
struct stack
{
    struct bstnode*item;     //defining a stack node which contains address of bst node and the address of next stack node 
    struct stack*next;
};

//this fuction takes head adress of stack node and a bstnode and pushes the bstnode into the stack and returns new head address of stack 
 struct stack *push(struct stack*head, struct bstnode*item)
{
    struct stack*newptr = (struct stack *)malloc(sizeof(struct stack));
    if (newptr == NULL) //checking main stack is full or not
    {
        printf("Stack is FULL\n");
        return head;
    }
    newptr->item = item;
    newptr->next = head;  
    return newptr;
}

//this function deletes the top element of stack 
  struct stack*pop(struct stack*head)
{
    struct stack *temp = head;
    head = head->next; //moving the head to next node
    free(temp); //freeing the space
    return head;
}

//this function returns the top element of the stack 
 struct bstnode*top(struct stack *head)
{
    return head->item;    
}

//this function printsthr elements of expression tree in  inorder traversal format
void inorder(struct bstnode *root)
{
    if (root  == NULL) //base condition
        return;

    //small open  bracket before root->left
    if (root ->left != NULL && root ->right != NULL)
    {
        printf("(");
    }
    inorder(root->left);
    printf("%c", root->item);
    inorder(root->right);
    //small close bracket after root=>right
    if (root->left != NULL && root->right != NULL)
    {
        printf(")");
    }
}

//this function prints the elements of expression tree in  preorder traversal format
void preorder(struct bstnode *root)
{
    if (root == NULL)
        return;

    printf("%c", root->item);
    preorder(root->left);
    preorder(root->right);
}

//function for making Expression tree 
void Exptree(char S[])
{
	    struct stack*head = NULL; 
    	struct bstnode *root  = NULL;  
    
    for( int i=0;i< strlen(S);i++)
    {
        char c = S[i];
        // if char c is operand then  create bnode and push to stack
        if (c >= 97 && c <= 122)
        {
           struct bstnode* bnode= (struct bstnode*)malloc(sizeof(struct bstnode));
            bnode->left = NULL;
            bnode->right = NULL;
            bnode->item = c;
            head = push(head, bnode);
        }
        //if c is operator pop two elements from the stack and create a tree with them and push the tree into stack 
        else
        {
            struct bstnode* bnode= (struct bstnode*)malloc(sizeof(struct bstnode));

            if (bnode == NULL) 
            {
                printf("error in creating bstnode\n");
                
            }
            bnode->item = c;
            bnode->right = top(head);//store the top element of the stack in the the right subtree before poping it from the stack
            head = pop(head);
            if (head == NULL) 
            {
                printf("error\n");
            }
            bnode->left = top(head); //store the top element of the stack in the the right subtree before poping it from the stack
            head = pop(head);
            head = push(head, bnode);
        }
    }

    //now stack contains only epression tree
    root  = top(head);
    inorder(root); //formate 1
    printf("\n");
    preorder(root); //formate 2
}

int main()
{
    char S[1000]; //declaring a string
    scanf("%s",S);//read and store string
    Exptree(S);//calling expression tree function
    return 0;
}
