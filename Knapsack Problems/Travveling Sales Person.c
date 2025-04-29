#include <stdio.h>

int n, cost[10][10], visited[10], minCost = 9999;

void tsp(int city, int count, int total)
{
    if (count == n && cost[city][0]) {
        int tourCost = total + cost[city][0];
        if (tourCost < minCost)
            minCost = tourCost;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i] > 0) {
            visited[i] = 1;
            tsp(i, count + 1, total + cost[city][i]);
            visited[i] = 0;
        }
    }
}

int main()
{
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;
    tsp(0, 1, 0);

    printf("Minimum tour cost: %d\n", minCost);

    return 0;
}
