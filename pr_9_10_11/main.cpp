#include <unordered_set>

#include "graph.hpp"

int main() {
    Graph<int> graph;
    graph.insert_node(0, 1, 2);
    graph.insert_node(0, 4, 1);
    graph.insert_node(0, 3, 3);
    graph.insert_node(0, 2, 5);
    graph.insert_node(1, 6, 9);
    graph.insert_node(4, 7, 7);
    graph.insert_node(2, 5, 6);
    graph.insert_node(3, 5, 4);
    graph.insert_node(3, 6, 2);
    graph.insert_node(4, 8, 9);
    graph.insert_node(7, 6, 2);
    graph.insert_node(6, 5, 5);
    graph.insert_node(8, 9, 4);
    std::unordered_set<int> v;
    std::cout << "DFS: ";
    graph.dfs(4, v);

    std::cout << "BFS: ";
    graph.bfs(4);
    graph.prim(0);
    graph.kruskal(0);
    return 0;
}
