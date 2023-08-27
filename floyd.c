#include <stdio.h>

int min(int, int);
void floyds(int p[10][10], int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (i == j)
                    p[i][j] = 0;
                else
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}

int min(int a, int b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

void main()
{
    int p[10][10], w, n, e, u, v, i, j;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            p[i][j] = 999;
    }

    for (i = 1; i <= e; i++)
    {
        printf("\nEnter the end vertices of edge %d: ", i);
        scanf("%d%d", &u, &v);
        printf("Enter Weight: ");
        scanf("%d",&w);
        p[u][v] = w;
    }

    printf("\nAdjacency Matrix: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d \t", p[i][j]);
        printf("\n");
    }

    floyds(p, n);

    printf("\nPath Matrix: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d \t", p[i][j]);
        printf("\n");
    }

}