#include <stdio.h>
#define INF 9999
#define MAX 10

int main() {
int V, i, j, k;
int graph[MAX][MAX], dist[MAX][MAX];

printf("Enter number of vertices: ");
scanf("%d", &V);

printf("Enter adjacency matrix (use %d for INF):\n", INF);
for (i = 0; i < V; i++)
for (j = 0; j < V; j++)
scanf("%d", &graph[i][j]);

for (i = 0; i < V; i++)
for (j = 0; j < V; j++)
dist[i][j] = graph[i][j];

for (k = 0; k < V; k++)
for (i = 0; i < V; i++)
for (j = 0; j < V; j++)
if (dist[i][k] + dist[k][j] < dist[i][j])
dist[i][j] = dist[i][k] + dist[k][j];

printf("Shortest distances:\n");

for (i = 0; i < V; i++) {
for (j = 0; j < V; j++) {
if (dist[i][j] == INF)
printf("INF ");
else
printf("%3d ", dist[i][j]);
}
printf("\n");
}

return 0;
}
