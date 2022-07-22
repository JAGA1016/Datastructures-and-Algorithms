#include<stdio.h>
int v;//no. of vertices
//this function takes the weighted graph and outputs the predecessor matrix and all pair shortest path
void Floyd_Warshall(int W[v+1][v+1])
{
    int D[v+1][v+1],P[v+1][v+1];//2d-arrays for storing all pair shortest path and predecessors
    //initially intialising the distance matrix with their edges weights
    // initialsing the predecessor values for those vetices having their distances as edge weights intialse to their neighbours 
    // and for remaining all vertices initialise them as -1
    //no intermediate vertices  
    for(int i=1; i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            D[i][j]=W[i][j];
            if (D[i][j] != 55555 && D[i][j] != 0)
            {
                P[i][j] = i;
            }   
            else
            {
                P[i][j] = -1;
            }   
        }
    }
    //find the distances matrix all pairs of vertices with at most k  no of vertices as intermediates
    for(int k=1;k<=v;k++)
    {
        for(int i=1;i<=v;i++)
        {
            for(int j=1;j<=v;j++)
            {
                if(D[i][j]>(D[i][k]+D[k][j])) //if we find better shorter distance than previous betwen any two vertex
                {                             //update the distance value and modify the predecessor also
                    D[i][j]=(D[i][k]+D[k][j]);
                    P[i][j] = P[k][j];
                }
                
            }
        }
        //printing the distance between all pairs after second round means at most 2 vertices as intermediates 
        if(k==2)
        {   
            printf("Pairwise Distance Matrix After Two Rounds\n");
            for(int a=1;a<=v;a++)
            {
                for(int b=1;b<=v;b++)
                {     
                    if(b!=v)
                    {
                        printf("%d ",D[a][b]);
                    }
                    else
                    {
                        printf("%d",D[a][b]);
                    }
                }
                printf("\n");
            }
            //printing pair wise predecessor values after 2nd round
            printf("Pairwise Predecessor Matrix After Two Rounds\n");
            for(int l=1;l<=v;l++)
            {
                for(int m=1;m<=v;m++)
                {   
                    if(m!=v)
                    {   
                        if(P[l][m]!=-1)
                        {
                            printf("%d ",P[l][m]);
                        }
                        else
                        {
                            printf("NIL ");//if no predecessor print nil
                        }
                    }
                    else
                    {
                        if(P[l][m]!=-1)
                        {
                            printf("%d",P[l][m]);
                        }
                        else
                        {
                            printf("NIL");
                        }
                    }
                }
                printf("\n");
            }
        }
    }
    //all pairs shortest paths
    printf("Final Pairwise Distance Matrix\n");
    for(int a=1;a<=v;a++)
    {
        for(int b=1;b<=v;b++)
        {   
            if(b!=v)
            {
                printf("%d ",D[a][b]);
            }
            else
            {
                printf("%d",D[a][b]);
            }
        }
        printf("\n");
    }
    //final predecessor matrix
    printf("Final Pairwise Predecessor Matrix\n");
    for(int l=1;l<=v;l++)
    {
        for(int m=1;m<=v;m++)
                {   
                    if(m!=v)
                    {   
                        if(P[l][m]!=-1)
                        {
                            printf("%d ",P[l][m]);
                        }
                        else
                        {
                            printf("NIL ");
                        }
                    }
                    else
                    {
                        if(P[l][m]!=-1)
                        {
                            printf("%d",P[l][m]);
                        }
                        else
                        {
                            printf("NIL");
                        }
                    }
                }
        
        printf("\n");
    }
}
int main()
{
    scanf("%d",&v);
    int W[v+1][v+1];//for the weighted graph
    //input of the given graph
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            scanf("%d",&W[i][j]);
        }
    }
    Floyd_Warshall(W); //calling floyd_warshall function   
    return 0;
}
