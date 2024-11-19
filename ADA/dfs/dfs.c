#include<stdio.h>
#include<stdlib.h>

int n;
int isCycle=0;
int comp=0;
int istester=0;
int opcount=0;

void dfs(int mat[n][n],int *vis,int source,int parent)
{
    vis[source]=1;
    if(istester==1)
    {
        printf("%d  ",source);
    }
    for(int i=0;i<n;i++)
    {
        //opcount++;
        if(mat[source][i] && vis[i] && i!=parent)
            isCycle=1;
        else if(mat[source][i] && !vis[i])
            dfs(mat,vis,i,source);
    }
}

void checkConnectivity(int mat[n][n])
{
    int vis[n],i,k=1;

    for(i=0;i<n;i++)
    {
        vis[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            comp++;
            if(istester)
            {
                printf("\nComponent %d :",k++);
            }
            dfs(mat,&vis[0],i,-1);
        }
    }
}

void tester()
{
    istester=1;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    int mat[n][n];
    printf("Enter the adjacency matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    checkConnectivity(mat);
    printf("\nNumber of connected components are %d\n",comp);

    if(isCycle==1)
        printf("Cyclic\n");
    else    
        printf("Not Cyclic\n");
}

void main()
{
    tester();
}
