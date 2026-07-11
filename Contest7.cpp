#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int n, m, s;
    std::cin >> n >> m >> s;
    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }
    std::vector<int> dist(n + 1, 0);
        std::priority_queue<std::pair<int, int>> pq;
 
    dist[s] = 2e9; 
    pq.push({2e9, s});
 
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d < dist[u]) continue;
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            int new_width = std::min(dist[u], w);
            if (new_width > dist[v]) {
                dist[v] = new_width;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i == s) {
            std::cout << -1 << (i == n ? "" : " ");
        } else {
            std::cout << (dist[i] == 0 ? 0 : dist[i]) << (i == n ? "" : " ");
        }
    }
    std::cout << std::endl;
    return 0;
}