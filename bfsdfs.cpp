#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<int> adj[], int n) {
    vector<bool> visited(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS: ";
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << char('A'+u) << " ";
        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

int main() {
    int n = 5; // Locations A,B,C,D,E

    vector<int> adjList[5];
    adjList[0] = {1,3};    // A->B,D
    adjList[1] = {0,2,4};  // B->A,C,E
    adjList[2] = {1,4};    // C->B,E
    adjList[3] = {0,4};    // D->A,E
    adjList[4] = {1,2,3};  // E->B,C,D

    BFS(0, adjList, n); // Start from A
    return 0;
}



#include <iostream>
#include <vector>
using namespace std;

void DFS(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << char('A'+u) << " ";
    for(int v = 0; v < adj.size(); v++) {
        if(adj[u][v] && !visited[v])
            DFS(v, adj, visited);
    }
}

int main() {
    int n = 5; // Locations A,B,C,D,E

    vector<vector<int>> adjMat = {
        {0,1,0,1,0}, // A
        {1,0,1,0,1}, // B
        {0,1,0,0,1}, // C
        {1,0,0,0,1}, // D
        {0,1,1,1,0}  // E
    };

    vector<bool> visited(n, false);
    cout << "DFS: ";
    DFS(0, adjMat, visited); // Start from A
    cout << endl;

    return 0;
}
