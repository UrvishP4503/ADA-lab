#include "graph.hpp"
#include <unordered_set>

int main() {
    Graph<int> graph;
    graph.insert_node(0, 1, 6);
    graph.insert_node(0, 4, 1);
    graph.insert_node(0, 3, 3);
    graph.insert_node(0, 2, 5);
    graph.insert_node(1, 6, 7);
    graph.insert_node(4, 7, 7);
    graph.insert_node(2, 5, 6);
    graph.insert_node(3, 5, 4);
    graph.insert_node(3, 6, 2);
    graph.insert_node(4, 8, 5);
    graph.insert_node(7, 6, 9);
    graph.insert_node(6, 5, 5);
    graph.insert_node(8, 9, 4);
    // arr.print();
    // std::unordered_set<int> v;
    // graph.dfs(4, v);
    // graph.bfs(4);
    // graph.prim(0);
    graph.kruskal(0);
    return 0;
}
