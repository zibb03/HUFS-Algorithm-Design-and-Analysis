#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <int> dist;
vector <int> previous;
vector <int> Q;
vector <vector<int>> length;

int tmp, n, u, v, alt; 

// Find vertex with minimum weight which is connected to node in "previous"
void findmin() {
    u = 0;
    tmp = INT32_MAX;

    // 방문 안된 곳 가야 하는데..
    for (int i = 0; i < previous.size(); i++) {
        for (int j = 1; j <= length[previous[i]].size(); j++) {
            if (length[previous[i]][j] != 0 && length[previous[i]][j] < tmp) {
                u = j; // Vertex
                tmp = length[previous[i]][j]; // Weight
            }
        }
    } 
}

void Dijkstra() {
	cin >> n;
    length.resize(n + 1);

    // Set weight of edge     
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tmp;
            length[i].push_back(tmp);
        }
    }

    //dist[v] <- INFINITY
    dist.assign(n + 1, -1);
    //prev[v] <- UNDEFINDED
    // add v to Q
    Q.assign(n + 1, 1);

    // dist[source] <- 0
    // Start node 1
    dist[1] = 0;
    previous.push_back(1); 

    while(!Q.empty()) {
        // u <- vertex in Q with min dist[u]
        findmin();

        // remove u from Q
        Q[u] = 0;

        // alt <- dist[u] + length(u, v)
        alt = dist[u] + tmp;
        if (alt < dist[v]) {
            dist[v] = alt;
            previous[v] = u;
        }
    }
}

int main() {
    Dijkstra();

    //print dist[]
    for (int i = 1; i < n + 1; i++) {

    }
    //print prev[]
    for (int i = 1; i < n + 1; i++) {

    }

	return 0;
}