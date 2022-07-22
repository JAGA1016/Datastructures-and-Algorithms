#include <stdio.h>
// move n discs from pole 0 to pole 2 using pole 1 as intermediate
void TOH(int n,int source,int interm,int target)
{

        if(n==1) // base case
        {
             printf("Move Disk %d from Pole %d to Pole %d\n",n,source,target);
             return ;
        }
        //recursively move n-1 discs from pole 0 to pole 1 using pole 2 as intermediate 
        TOH(n-1,source,target,interm);
        
        //atomic move of single disc
        printf("Move Disk %d from Pole %d to Pole %d\n",n,source,target);
        
        // recursively move n-1 discs from pole 1 to pole 2 using pole 0 as intermediate
        TOH(n-1,interm,source,target);
        }    




int main()

{
    int n;
    scanf("%d",&n);
    TOH(n,0,1,2);
    return 0;

}
