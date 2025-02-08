#include <bits/stdc++.h>
using namespace std;
struct DJS { 
    vector<int> parent, heaviest;
    vector<bool> isParent;

    DJS(int n) {
        parent.resize(n);
        heaviest.resize(n, 0);
        isParent.resize(n, true);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    bool unify(int u, int v, int w) {
        int parentU = find(u);
        int parentV = find(v);

        if(parentU == parentV) {
            return false;
        }
        
        parent[parentU] = parentV;
        heaviest[parentV] = w;
        
        isParent[parentU] = false;
        
        return true;
    }
     
     void printHeaviest() const {
         vector<int> res;
         
         for(int i = 0; i < isParent.size(); i++) {
             if(isParent[i]) {
                 res.push_back(heaviest[i]);
             }
         }
         
         sort(res.begin(), res.end());
         
         for(auto& w : res) {
             cout << w << " ";
         }
     }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
        
    int u, v, w;
    int V, E, K;
    cin >> V >> E >> K; 
    vector<pair<int, pair<int, int>>> edges; 
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    DJS s(V); 
    int maxEdge = INT_MIN;
    int count = 0; 
    for(int i = 0; i < edges.size(); i++) { 
        if(count == V - K)
            break; 
        auto& edge = edges[i];
        int vert1 = edge.second.first;
        int vert2 = edge.second.second;
        int currW = edge.first;
        
        if(s.unify(vert1, vert2, currW)) {
            maxEdge = max(maxEdge, currW);
            count++;
        }
    }
    s.printHeaviest();
    return 0;
}
