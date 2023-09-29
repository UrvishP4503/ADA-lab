#include "graph.hpp"
#include <unordered_set>

int main() {
    Graph<int> graph;
    graph.insert_node(0, 1, 4);
    graph.insert_node(0, 7, 7);
    graph.insert_node(7, 1, 11);
    graph.insert_node(7, 8, 7);
    graph.insert_node(1, 2, 8);
    graph.insert_node(8, 2, 2);
    graph.insert_node(8, 6, 6);
    graph.insert_node(7, 6, 1);
    graph.insert_node(5, 6, 2);
    graph.insert_node(2, 5, 4);
    graph.insert_node(2, 3, 7);
    graph.insert_node(3, 5, 14);
    graph.insert_node(3, 4, 9);
    graph.insert_node(5, 4, 10);

    // arr.print();
    // std::unordered_set<int> v;
    // graph.dfs(4, v);
    // graph.bfs(4);
    graph.prim(0);
    return 0;
}
