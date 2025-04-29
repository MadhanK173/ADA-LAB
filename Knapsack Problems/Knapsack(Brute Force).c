#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int W, int w[], int v[], int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (w[n-1] > W)
        return knapsack(W, w, v, n-1);
    else
        return max(v[n-1] + knapsack(W - w[n-1], w, v, n-1),
                   knapsack(W, w, v, n-1));
}

int main()
{
    int n, W, w[100], v[100], i;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter max capacity: ");
    scanf("%d", &W);
    printf("Enter weight and value of each item:\n");
    for (i = 0; i < n; i++)
        scanf("%d%d", &w[i], &v[i]);

    printf("Maximum value = %d\n", knapsack(W, w, v, n));
    return 0;
}
