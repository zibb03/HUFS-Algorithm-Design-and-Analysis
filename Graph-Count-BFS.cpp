//Graph count using BFS
//Using Adjacency Matrix

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector < vector < int > > G;
vector < bool > flag;
queue < int > Q;

// Auto initialize global variable
// n is an amount of vertex
// v is a target vertex
// cnt is a variable that counts the number of graph components
int n, v, cnt; 

void BFS(int s) {
	if (!flag[s]) {
		Q.push(s);
		flag[s] = true;
		cnt++;
	}

	while (!Q.empty()) {
		//do v := dequeue(Q);
		v = Q.front();
		Q.pop(); 

		// for each w adjacent to v
		for (int w = 1; w <= n; w++) {
			if (G[v][w] == 1 && !flag[w]) {
				flag[w] = true;
				// enqueue				
				Q.push(w);
			}
    	}
	}	
}

int main() {
	cin >> n;
	G.resize(n + 1);
	
	// for every vertex v
	// 	   flag[v] = false;
	flag.resize(n + 1, false);

	// Get Graph's Adjacency Matrix
	for (int i = 1; i <= n; i++) {
		G[i].push_back(0);
		for (int j = 1; j <= n; j++) {
			cin >> v;
			G[i].push_back(v);
		}
	}

	for (int s = 1; s <= n; s++) {
		// s is the source vertex
		BFS(s);
	}

	cout << cnt;
	return 0;
}

/*
//Graph count using BFS
//Using Adjacency Matrix

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector < vector < int > > G;
vector < bool > flag;
queue < int > Q;

int n, v, cnt, gcnt; 
// Auto initialize global variable

void check(int s) {
    // Find ...
    for (int w = 1; w <= n; w++) {
		// cout << v << "/" << i  << "/" << V[v][i] << "\n";
		if (G[s][w] == 1 && !flag[w]) {
			Q.push(w);
		}
    }
	// 인접 노드 w로?
}

void BFS() {
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();		
		flag[v] = true;
		cnt++;
		check(v);
	}
	if (cnt > 0) {
		gcnt++;
		cnt = 0;
	}
}

int main() {
	// vertex수 v로?
	cin >> n; //height, width of Graph Adjacency Matrix
	G.resize(n + 1);
	flag.resize(n + 1, false);

	for (int i = 1; i <= n; i++) {
		G[i].push_back(0);
		for (int j = 1; j <= n; j++) {
			cin >> v;
			G[i].push_back(v);
		}
	}

	// Q.push(1);
	for (int s = 1; s <= n; s++) {
		for (int w = 1; w <= n; w++) {
			if (G[s][w] == 1 && !flag[s]) {
				Q.push(s);
				BFS();
                // if (cnt > 0) {
    			// 	gcnt++;
				// 	cnt = 0;
				// }
			}
		}
	}

	cout << gcnt;
	return 0;
}
*/