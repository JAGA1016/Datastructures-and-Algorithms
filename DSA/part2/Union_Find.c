#include<stdio.h>
#include<stdlib.h>
int n;//no of sets
typedef struct node
{
   // int id;
    int rank;
    int id;
    struct node* parent;
}Node;
//making all the singleton sets with initialsiing their parents as itself
void makeset(Node*S)
{   
    for(int i=1;i<=n;i++)
    {
        S[i].rank=0;      
        S[i].parent=&S[i];
        S[i].id=i;
    }
}
//this function takes an element as in input and computes its representative 
int Find(Node* S,int a)
{
    int b,x,p;
    b=a;
    //finding the representatives of  element a
    while(S[b].parent->id!=b)
    {
        b = S[b].parent->id;
    }
    x = a;
    //setting the parents of all elements in the path from the element to the root as the root element
    while(S[x].parent->id != x)
    {
        p = S[x].parent->id;
        S[x].parent = &S[b];
        x = p;
    }
    return b;
}
//this function takes two sets and makes union 
void Union(Node*S,int x,int y)
{    
    int id1,id2,r1,r2;
     id1 = Find(S,x);
     id2 = Find(S,y);
    if(id1 == id2)//if the the two sets are the subsets of a set then print its id and rank
    {
        printf("%d %d\n", id1, S[id1].rank);
    }
    else{
        r1 = S[id1].rank;//find the rank of two sets(height)
        r2 = S[id2].rank;
        if(r1 == r2)     //if the both sets have same rank then add 1 set to the another 
        {
            S[id2].parent = &S[id1];
            S[id1].rank++;// increse the rank by 1
            printf("%d %d\n",id1,S[id1].rank);
        }
        else if(r1 < r2)      //if the rank of  set2 is greater than the 1 then add the set with r1 rank to the set with rank r2 
        {
            S[id1].parent = &S[id2];
            printf("%d %d\n", id2, S[id2].rank);
        }
        else{                 //if the rank of  set1 is greater than the set2  then add the set with r2 rank to the set with rank r1
            S[id2].parent = &S[id1];
            printf("%d %d\n", id1, S[id1].rank);
        }
    }
}
//print the elemnts and their ids
void my_print(Node*S)
{   int id;
    for(int i=1;i<=n;i++)
    {   
        id =  Find(S,i);
        printf("%d %d\n",i,id);
    }
}

int main()
{
    scanf("%d",&n);
    //array of structure of nodes
    Node S[n+1];
    makeset(S);
    while(1)
    {
        int choice,res,x,y,num;
        scanf("%d",&choice);
        switch(choice)  //selecting the opertations based on the choice
        {
            case 1:
                    scanf("%d",&num);
                    res=Find(S,num);      //finds the id of set containing num 
                    printf("%d\n",res); 
                    break;        
            case 2:
                    scanf("%d%d",&x,&y); //making the union of two sets
                    Union(S,x,y);        
                    break;
            case 3:
                    my_print(S);// prints the values of elements with their ids
                    break;
            case 4:
                    return 0;
            return 0;
        }
    }


}