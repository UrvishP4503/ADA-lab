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
 * @brief This function makes node.
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
    this->graph[node].push_back(std::make_pair(neighbour, weight));

    // doing the same for the neighbour node.
    this->graph[neighbour].push_back(std::make_pair(node, weight));
}

template <typename T>
void Graph<T>::dfs(T start_node, std::unordered_set<T> &visited_list) {

    if (this->graph.find(start_node) == this->graph.end()) {
        return;
    }

    visited_list.insert(start_node);

    std::cout << start_node << " :: ";
    for (const auto &neigbour : graph[start_node]) {
        if (visited_list.find(neigbour.first) == visited_list.end()) {
            this->dfs(neigbour.first, visited_list);
        }
    }
}

template <typename T>
void Graph<T>::bfs(T start_node) {
    if (this->graph.find(start_node) == this->graph.end()) {
        return;
    }

    std::queue<T> quwuw;
    std::unordered_set<T> visited_list;

    quwuw.push(start_node);

    std::cout << std::endl;

    while (!quwuw.empty()) {
        T curr = quwuw.front();
        quwuw.pop();
        if (visited_list.find(curr) == visited_list.end()) {

            visited_list.insert(curr);
            std::cout << curr << " :: ";
            for (const auto &node : this->graph[curr]) {
                if (visited_list.find(node.first) == visited_list.end()) {
                    quwuw.push(node.first);
                }
            }
        }
    }
}

template <typename T>
void Graph<T>::prim(T start_node) {

    std::unordered_set<T> visited;

    // initializing a priority queue to find the smallest elements.
    std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, std::greater<std::pair<int, T>>> pq;

    int total_weight = 0;
    // starting with 0 weight
    pq.push({0, start_node});

    while (!pq.empty()) {
        // gets the node with lowest weight.
        T current_node = pq.top().second;

        // get the weight of the node with lowest weight.
        int current_weight = pq.top().first;

        pq.pop();

        // checking if the current node has already been visited.
        // If it has, the loop continues to the next iteration.
        if (visited.find(current_node) != visited.end()) {
            continue;
        }

        visited.insert(current_node);
        total_weight += current_weight;

        std::cout << " -> " << current_node;
        for (const auto &neighbor : this->graph[current_node]) {
            if (visited.find(neighbor.first) == visited.end()) {
                pq.push({neighbor.second, neighbor.first});
            }
        }
    }

    std::cout << "\nTotal Weight: " << total_weight << std::endl;
}

template <typename T>
void Graph<T>::kruskal(T start_node) {}
