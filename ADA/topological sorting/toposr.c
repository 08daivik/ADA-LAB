#include<stdio.h>
#include<stdlib.h>

int front,rear,count,queue[10];
int adj[10][10],vis[10],indegree[10],topo[10];

void reset(int n)
{
    for(int i=0;i<n;i++)
    {
        vis[i]=0;
        indegree[i]=0;
    }
    front=0;
    rear=-1;
    count=0;
}

void calcindegree(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(adj[j][i]==1)
                indegree[i]=1;
        }
        if(indegree[i]==0)
        {
            rear=(rear+1)%n;
            queue[rear]=i;
            count++;
            vis[i]=1;
        }
    }
}

void removesource(int n)
{
    int processed=0;
    while(count!=0)
    {
        int src=queue[front];
        front=(front+1)%n;
        count--;
        topo[processed++]=src;

        for(int i=0;i<n;i++)
        {
            if(adj[src][i]==1)
                indegree[i]--;
            
            if(indegree[i]==0 && !vis[i])
            {
                rear=(rear+1)%n;
                queue[rear]=i;
                count++;
                vis[i]=1;
            }
        }
    }

    if(processed!=n)
        printf("Contains a cycle\n");

    printf("Topological order is\n");
    for(int i=0;i<n;i++)
        printf("--->%c",topo[i]+65);
}

void main()
{
    int n;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    
    reset(n);
    calcindegree(n);
    removesource(n);
    printf("\n");
}