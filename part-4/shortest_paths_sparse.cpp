#include "shortest_paths_sparse.hpp"
#include <priority_queue.hpp>

#include <cmath>

std::vector<hop_t> bellman_ford(const SparseGraph &graph, const int source,
                                bool &has_negative_cycle)
{
    const int V = static_cast<int>(graph.size());
    auto DP = std::vector<hop_t>(V, {inf, -1});

    // WRITE YOUR CODE HERE
    // 1. Initialize the distance to the source node
    DP[source].d = 0.0f;
    DP[source].p = -1;
    has_negative_cycle = false;

    // 2. Relax all edges V - 1 times
    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            // Loop through only the actual outgoing edges for vertex u
            for (const auto& edge : graph[u]) {
                int v = edge.v;
                float w = edge.w;
                
                // If a shorter path is found, update it
                if (DP[u].d != inf && DP[u].d + w < DP[v].d) {
                    DP[v].d = DP[u].d + w;
                    DP[v].p = u;
                }
            }
        }
    }

    // 3. Check for negative-weight cycles
    for (int u = 0; u < V; ++u) {
        for (const auto& edge : graph[u]) {
            int v = edge.v;
            float w = edge.w;
            
            // If we can STILL relax an edge, a negative cycle exists
            if (DP[u].d != inf && DP[u].d + w < DP[v].d) {
                has_negative_cycle = true;
                break;
            }
        }
        if (has_negative_cycle) break;
    }

    return DP;
}

struct triplet_t {
    float d;
    int r;
    int v;
};

std::vector<hop_t> dijkstra(const SparseGraph &graph, const int source)
{
    assert(source >= 0);
    assert(source < (signed)graph.size());

    auto DP = std::vector<hop_t>(graph.size(), {inf, -1});

    // WRITE YOUR CODE HERE
    assert(source >= 0);
    assert(source < (signed)graph.size());

    auto DP = std::vector<hop_t>(graph.size(), {inf, -1});

    // 1. Set up a Min-Heap priority queue based on distance 'd'
    auto cmp = [](const triplet_t& left, const triplet_t& right) {
        return left.d > right.d; 
    };
    std::priority_queue<triplet_t, std::vector<triplet_t>, decltype(cmp)> pq(cmp);

    // 2. Initialize the source
    DP[source].d = 0.0f;
    DP[source].p = -1;
    pq.push({0.0f, -1, source});

    // 3. Process the queue
    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        int u = current.v;
        float d = current.d;

        // Optimization: If we already found a better path to 'u' earlier, 
        // discard this outdated queue entry.
        if (d > DP[u].d) continue;

        // Check all neighboring vertices of u
        for (const auto& edge : graph[u]) {
            int v = edge.v;
            float w = edge.w;

            // Relaxation step
            if (DP[u].d + w < DP[v].d) {
                DP[v].d = DP[u].d + w;
                DP[v].p = u;
                
                // Push the newly discovered shorter path into the queue
                pq.push({DP[v].d, u, v});
            }
        }
    }

    return DP;
}


