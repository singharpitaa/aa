#include <iostream>
using namespace std;

int main() {
    int n = 5; // number of vertices
    int cost[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int selected[5] = {0};
    selected[0] = 1; 

    int edges = 0, minCost = 0;

    cout << "Using Prim's Algorithm" << endl;

    while (edges < n - 1) {
        int x, y;
        int minimum = 999;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] && cost[i][j] < minimum) {
                        minimum = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        cout << x << " - " << y << " : " << cost[x][y] << endl;
        minCost += cost[x][y];
        selected[y] = 1;
        edges++;
    }

    cout << "Total Minimum Cost: " << minCost << endl;
    return 0;
}
  

  #include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

Edge edges[10];
int parent[10];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    parent[find(a)] = find(b);
}

int main() {
    int n = 5, e = 7;

   
    int g[7][3] = {
        {0,1,2},{1,2,3},{1,4,5},
        {0,3,6},{2,4,7},{1,3,8},{3,4,9}
    };

    
    for(int i=0; i<e; i++){
        edges[i].u = g[i][0];
        edges[i].v = g[i][1];
        edges[i].w = g[i][2];
    }

    
    for(int i=0; i<e-1; i++){
        for(int j=0; j<e-i-1; j++){
            if(edges[j].w > edges[j+1].w){
                swap(edges[j], edges[j+1]);
            }
        }
    }

    // Make every node its own parent
    for(int i=0; i<n; i++)
        parent[i] = i;

    int minCost = 0, count = 0;
    cout << "Edges in MST:\n";

    for(int i=0; i<e && count < n-1; i++){
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if(a != b){
            cout << edges[i].u << " - " 
                 << edges[i].v << " : " 
                 << edges[i].w << endl;

            minCost += edges[i].w;
            Union(a, b);
            count++;
        }
    }

    cout << "Minimum Cost: " << minCost;
    return 0;
}
