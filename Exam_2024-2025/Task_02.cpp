#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> graph;
unordered_set<int> visited;

bool dfs(int current, int parent) {
    visited.insert(current);
    for (const auto& n : graph[current]) {
        if (n == parent) {
            continue;
        }        
        if (visited.count(n)) {
            return true;
        }       
        if (dfs(n, current)) {    
            return true;
        }
    }
    return false;
}

bool traverse(int V, int E) {   
    if (E != V - 1) return false;

    visited.clear();
    
    if (dfs(0, -1)) return false;

    return visited.size() == V;
}

void solve() {
    int V, E;
    cin >> V >> E;
    
    graph.clear();
    
    
    for (int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;        
        graph[x].push_back(y);
        graph[y].push_back(x);  
    }
    
    bool b = traverse(V, E);
    
    if (b) {
        cout << 1 << endl;
        return;
    }
    cout << 0 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
    
    while (Q--) {
        solve();
    }

    return 0;
}
