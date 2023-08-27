#include <stdio.h>
void BFS(int);

int Q[100], F = 0, R = -1;
int A[100][100], vis[100];
int n, m;

int main()
{
    int v, u, st;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            A[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges\n");
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &u, &v);
        A[u][v] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }

    printf("Enter the starting Node: ");
    scanf("%d", &st);
    printf("\nNodes rechable from %d:\n", st);

    BFS(st);
    return 0;
}

void BFS(int v)
{
    int u;
    vis[v] = 1;
    Q[++R] = v;

    while (F <= R)
    {
        u = Q[F++];
        printf("%d ", u);
        for (int i = 1; i <= n; i++)
        {
            if (A[u][i] == 1 && vis[i] == 0)
            {

                Q[++R] = i;
                vis[i] = 1;
            }
        }
    }
}