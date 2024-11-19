#include<stdio.h>
#include<stdlib.h>

int n;
int opcount=0,comp=0,istester=0,iscyclic=0;

void bfs(int mat[n][n],int *vis,int source)
{
    vis[source]=1;
    int queue[n],parent[n];
    int front=-1,rear=-1;
    queue[++rear]=source;
    parent[rear]=-1;
    while(front!=rear)
    {
        int curr=queue[++front];
        int par=parent[front];
        if(istester==1)
        {
            printf("%d ",curr);
        }
        for(int i=0;i<n;i++)
        {
            //opcount++;
            if(mat[curr][i] && vis[i] && i!=par)
                iscyclic=1;
            else if(mat[curr][i] && !vis[i])
            {
                queue[++rear]=i;
                parent[rear]=curr;
                vis[i]=1;
            }
        }
    }
}

void checkConnectivity(int mat[n][n])
{
    int k=1,vis[n],i;
    
    for(i=0;i<n;i++)
        vis[i]=0;
    
    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            comp++;
            if(istester==1)
                printf("\nComponent %d: ",k++);
            bfs(mat,&vis[0],i);
        }
    }
}

void tester()
{
    istester=1;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    int mat[n][n];
    printf("Enter the elements of the matrix\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    
    checkConnectivity(mat);
    printf("\nThe number of connected components are %d\n",comp);

    if(iscyclic==1)
        printf("Cyclic\n");
    else
        printf("Not Cyclic\n");
}

/*void plotter()
{
    istester=0;
    FILE *fp=fopen("bfs.txt","w");
    for(int k=1;k<=10;k++)
    {
        n=k;
        int mat[n][n];
        for(int i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                    mat[i][j]=1;
                else
                    mat[i][j]=0;
            }
        }
        opcount=0;
        checkConnectivity(mat);
        fprintf(fp,"%d\t%d\n",n,opcount);
    }
    fclose(fp);
}*/

void main()
{
    tester();
}
