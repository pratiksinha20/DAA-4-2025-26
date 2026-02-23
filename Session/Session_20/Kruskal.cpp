// this is kruskal's algorithm for finding minimum spanning tree of a graph using DSU (disjoint set union) or union find data structure
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// DSU (Disjoint Set Union) with path compression and union by rank
vector<int> parent, rank_;

void makeSet(int n) {
    parent.resize(n);
    rank_.resize(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]); // path compression
    return parent[x];
}

bool unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return false; // already in the same component → cycle
    // union by rank
    if (rank_[px] < rank_[py]) swap(px, py);
    parent[py] = px;
    if (rank_[px] == rank_[py]) rank_[px]++;
    return true;
}

int main() {
    int V, E;
    cin >> V >> E;

    // edges stored as {weight, u, v}
    vector<tuple<int,int,int>> edges(E);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }

    // Step 1: sort edges by weight
    sort(edges.begin(), edges.end());

    makeSet(V);

    int minCost = 0;
    int edgesUsed = 0;
    vector<pair<int,int>> mstEdges; // to print MST edges (optional)

    // Step 2: greedily pick edges that don't form a cycle
    for (int i = 0; i < (int)edges.size(); i++) {
        int w = get<0>(edges[i]);
        int u = get<1>(edges[i]);
        int v = get<2>(edges[i]);
        if (unite(u, v)) {
            minCost += w;
            mstEdges.push_back({u, v});
            edgesUsed++;
            if (edgesUsed == V - 1) break; // MST complete
        }
    }

    cout << "Minimum Cost: " << minCost << endl;
    cout << "MST Edges:" << endl;
    for (int i = 0; i < (int)mstEdges.size(); i++)
        cout << mstEdges[i].first << " - " << mstEdges[i].second << endl;

    return 0;
}