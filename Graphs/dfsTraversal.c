#include<stdio.h>
int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {   //Creating adjacency matrix
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
void DFS(int i)
{
    int j;
    printf("%d ",i);
    visited[i]=1;
    for(j=0;j<7;j++)
    {
        if(a[i][j]==1 && !visited[j])
            DFS(j);
    }
}
int main()
{
    printf("The DFS Traversal is: ");
    DFS(1);
    return 0;
}
  