#include<stdio.h>

void dijkstra(int n, int s, int cost[][10]) {
    int i, count, u, v, min, dis[10], visited[10];

    for (i = 0;i < n;i++) {
        dis[i] = cost[s][i];
        visited[i] = 0;
    }
    dis[s] = 0;
    visited[s] = 1;
    for (count = 0;count < n - 1;count++) {
        min = 999;
        for (i = 0;i < n;i++) {
            if (visited[i] == 0 && dis[i] < min) {
                min = dis[i];
                u = i;
            }
        }
        visited[u] = 1;

        for (v = 0;v < n;v++) {
            if (visited[v] == 0 && cost[u][v] != 999 && dis[v] > (dis[u] + cost[u][v]))
                dis[v] = dis[u] + cost[u][v];
        }
    }

    printf("The shortest path is\n");
    for (v = 0;v < n;v++)
        printf("%d to %d is %d\n", s, v, dis[v]);
}


void main() {
    int n, i, j, s, cost[10][10];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix\n");
    for (i = 0;i < n;i++)
        for (j = 0;j < n;j++)
            scanf("%d", &cost[i][j]);
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    dijkstra(n, s, cost);
}
// Output:
// Enter the number of vertices: 5
// Enter the cost matrix
// 0 10 999 999 999
// 999 0 999 999 5
// 999 999 0 3 999
// 999 999 999 0 1
// 999 999 999 999 0
// Enter the source vertex: 0
// The shortest path is
// 0 to 0 is 0
// 0 to 1 is 10
// 0 to 2 is 13
// 0 to 3 is 14
// 0 to 4 is 15
// Time Complexity: O(n^2)