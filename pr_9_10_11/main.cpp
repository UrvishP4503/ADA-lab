#include "graph.hpp"
#include <unordered_set>

int main() {
    Graph<int> graph;
    graph.insert_node(0, 1, 2);
    graph.insert_node(1, 0, 2);
    graph.insert_node(0, 3, 3);
    graph.insert_node(2, 4, 2);
    graph.insert_node(2, 3, 4);
    graph.insert_node(0, 2, 4);
    // arr.print();
    std::unordered_set<int> v;
    graph.dfs(3, v);
    return 0;
}
