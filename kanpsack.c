#include <stdio.h>
#include <stdlib.h>

int V[100][100];

int max(int a, int b)
{
    return a > b ? a : b;
}

int knapscak(int W, int N, int val[], int wt[])
{

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                V[i][j] = 0;
            }
            else if (wt[i - 1] > j)
            {
                V[i][j] = V[i - 1][j];
            }
            else
            {
                V[i][j] = max(V[i - 1][j], V[i - 1][j - wt[i - 1]] + val[i - 1]);
            }
        }
    }
    return V[N][W];
}

void selecetd(int N, int W, int wt[])
{
    int X[N + 1];
    for (int i = 1; i <= N; i++)
    {
        X[i] = 0;
    }

    int i = N;
    int j = W;
    while (i != 0 && j != 0)
    {
        if (V[i][j] != V[i - 1][j])
        {
            X[i] = 1;
            j = j - wt[i - 1];
        }
        i--;
    }

    printf("\n");

    for (int i = 1; i <= N; i++)
    {
        if (X[i] == 1)
        {
            printf("Object %d Selected\n", i);
        }
    }
}

int main()
{
    int W, N;

    printf("\nEnter number of items: ");
    scanf("%d", &N);
    printf("Enter the Capcity of bag: ");
    scanf("%d", &W);

    int val[W], wt[N];

    for (int i = 0; i < N; i++)
    {
        printf("Enter profit and weight of item %d: ", i + 1);
        scanf("%d%d", &val[i], &wt[i]);
    }

    int result = knapscak(W, N, val, wt);
    selecetd(N, W, wt);
    printf("\nMaxmimum profit is: %d", result);
}