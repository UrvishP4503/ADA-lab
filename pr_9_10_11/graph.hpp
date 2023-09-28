#pragma 0
#define GRAPH_HPP

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename T>
class Graph {
private:
    std::unordered_map<T, std::vector<std::pair<T, int>>> graph;

public:
    void insert_node(T node, T neighbour, int weight);
    void dfs(T start_node, std::unordered_set<T> &visited_list);
    void bfs(T start_node);
    void prim(T start_node);
    void kruskal(T start_node);
    void print() {

        std::cout << std::endl;
        for (const auto &p : this->graph) {

            std::cout << p.first << "->";

            for (const auto &v : p.second) {
                std::cout << " :: " << v.first << " " << v.second;
            }

            std::cout << std::endl;
        }
    }
};

/**
 * @brief This function adds node.
 * 
 * If node already exists then it will just update the adjacency lists.
 * 
 * @tparam T 
 * @param node The node to added.
 * @param neighbour it is the neighbour of `node`.
 * @param weight the cost of edge between `node` and `neighbour`.
 */
template <typename T>
void Graph<T>::insert_node(T node, T neighbour, int weight) {
    // if it does't exists then it will make it and then add the edge.
    graph[node].push_back(std::make_pair(neighbour, weight));
}

template <typename T>
void Graph<T>::dfs(T start_node, std::unordered_set<T> &visited_list) {
    visited_list.insert(start_node);
    std::cout << start_node << " :: ";

    for (const auto &neigbour : graph[start_node]) {
        if (visited_list.find(neigbour.first) == visited_list.end()) {
            this->dfs(neigbour.first, visited_list);
        }
    }
}

template <typename T>
void Graph<T>::bfs(T start_node) {}

template <typename T>
void Graph<T>::prim(T start_node) {}

template <typename T>
void Graph<T>::kruskal(T start_node) {}
