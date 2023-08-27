#include<stdio.h>
#include<conio.h>

int a[10][10],n,vis[10];
int dfs(int root){
    int j;
     vis[root]=1;
     for(j=1;j<=n;j++)
      if(a[root][j]==1&&vis[j]!=1)
       dfs(j);
     for(j=1;j<=n;j++) {
      if(vis[j]!=1)
       return 0;
     }
     return 1;
}
void main()
{
 int i,j,root,ans;
 for(j=1;j<=n;j++)
  vis[j]=0;
 printf("\nEnter the no of nodes:\t");
 scanf("%d",&n);
 printf("\nEnter the adjacency matrix:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   scanf("%d",&a[i][j]);
 printf("\nEnter the source node:\t");
 scanf("%d",&root);
 ans=dfs(root);
 if(ans==1)
  printf("\nGraph is connected\n");
 else
  printf("\nGraph is not connected\n");
 getch();
}
