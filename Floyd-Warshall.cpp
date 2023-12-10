#include <stdio.h>
#include <stdlib.h>

#define INF 1000
#define min(x, y) (x) < (y) ? (x) : (y)

typedef struct GraphType {
	int n;
	int length[100][100];
} GraphType;

int main() {
    // Get graph g
    GraphType g = {8, {{0, 4, INF, INF, INF, INF, 7, 4}, 
        {INF, 0, 9, INF, INF, 6, 8, 1},
        {INF, INF, 0, INF, 10, INF, INF, INF},
        {INF, INF, INF, 0, INF, INF, INF, INF},
        {INF, INF, 8, 6, 0, 5, INF, INF}, 
        {INF, INF, INF, INF, 6, 0, INF, INF}, 
        {INF, 4, INF, INF, INF, 7, 0, INF},
        {INF, INF, 3, INF, INF, INF, INF, 0}}
    };

    // Floid Warshall Algorithm
    for (int k = 0; k < g.n; k++) {
        for (int i = 0; i < g.n; i++) {
            for (int j = 0; j < g.n; j++) {
                g.length[i][j] = min(g.length[i][j], g.length[i][k] + g.length[k][j]);
            }
        }
    }
        
    // Print the length of the shortest path between each pair of nodes
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++) {
            if (g.length[i][j] == 1000)
                printf("INF ");
            else 
                printf("%d ", g.length[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
