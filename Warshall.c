#include <stdio.h>

#define MAX 10

int main() {
int V, i, j, k;
int graph[MAX][MAX], reach[MAX][MAX];

printf("Enter number of vertices: ");
scanf("%d", &V);

printf("Enter adjacency matrix (0 or 1):\n");
for (i = 0; i < V; i++)
for (j = 0; j < V; j++)
scanf("%d", &graph[i][j]);

for (i = 0; i < V; i++)
for (j = 0; j < V; j++)
reach[i][j] = graph[i][j];

for (k = 0; k < V; k++)
for (i = 0; i < V; i++)
for (j = 0; j < V; j++)
reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);

printf("Transitive closure:\n");
for (i = 0; i < V; i++) {

for (j = 0; j < V; j++)
printf("%d ", reach[i][j]);
printf("\n");
}

return 0;
}
