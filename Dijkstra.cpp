#include <iostream>
#include <climits>

using namespace std;

int length[100][100];
int n;

bool visited[100]; // Can make prev, Q array with visited array
int dist[100]; 
int u, alt;

int get_min_vertex() {
    int min = INT_MAX;
    int minpos = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] < min && !visited[i]) {
            min = dist[i];
            minpos = i;
        }
    }
    return minpos;
}

void Dijkstra(int source) {
    for (int i = 0; i < n; i++) {        
        dist[i] = INT_MAX; // INT_MAX for infinite value
    }

    dist[source] = 0;
    visited[source] = true;
    
    for (int repeat = 0; repeat < n - 1; repeat++) {
        u = get_min_vertex(); // u <- vertex in Q with min dist[u]
        visited[u] = true; // remove u from Q
        
        for (int v = 0; v < n; v++) {
            // for each neighbor v of u still in Q
            if (!visited[v] && length[u][v] != 0 && dist[u] != INT_MAX) {
                alt = dist[u] + length[u][v];
                if (alt < dist[v])
                    dist[v] = alt;
            }
        }
    }
}

int main() {
    cin >> n;

    // Set weight of edge     
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> length[i][j];
        }
    }

    Dijkstra(0);

    // print dist[]
    for (int i = 0; i < n; i++)
        cout << dist[i] << " ";

    cout << "\n";

    // print prev[]
    for (int i = 0; i < n; i++) {
        if (visited[i])
            cout << i + 1 << " ";
    }
    return 0;
}
