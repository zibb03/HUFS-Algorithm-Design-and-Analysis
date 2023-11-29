#include <stdio.h>
#include <stdlib.h>

#define INF 1000

typedef struct GraphType {
	int n;
	int length[100][100];
} GraphType;

int ReachSet[100];
int dist[100];
int sum = 0;

int get_min_vertex(int n) {
	int v, i;
	for (int i = 0; i < n; i++)
		if (!ReachSet[i]) { //UnReachSet
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!ReachSet[i] && (dist[i] < dist[v])) v = i;
	return (v);
}

void prim(GraphType* g, int s) {
	int i, u, v;

	for (u = 0; u < g->n; u++)
		dist[u] = INF;
	dist[s] = 0;
	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		ReachSet[u] = 1;
		if (dist[u] == INF) 
			return;
		sum += dist[u];
		for (v = 0; v < g->n; v++)
			if (g->length[u][v] != INF)
				if (!ReachSet[v] && g->length[u][v] < dist[v])
					dist[v] = g->length[u][v];
	}
}
int main(void) {
    GraphType g = { 9, {{0, INF, INF, 2, INF, INF, INF, INF, 4},
        {3, 0, INF, INF, INF, INF, INF, 4, INF},
        {INF, INF, 0, 6, INF, INF, INF, 2, INF},
        {2, INF, 6, 0, 1, INF, INF, INF, INF},
        {INF, INF, INF, 1, 0, INF, INF, INF, 8},
        {INF, INF, INF, INF, INF, 0, 8, INF, INF},
        {INF, INF, INF, INF, INF, 8, 0, INF, INF},
        {INF, 4, 2, INF, INF, INF, INF, 0, INF},
        {4, INF, INF, INF, 8, INF, INF, INF, 0}}
	};

	prim(&g, 0);
    
    for (int i = 0; i < 9; i++)
        printf("%d ", dist[i]);
	
    return 0;
}