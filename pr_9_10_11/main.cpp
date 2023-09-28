#include "graph.hpp"

int main() {
    Graph<char> arr;
    arr.insert_node('1', '2', 3);
    arr.insert_node('1', '3', 3);
    arr.insert_node('2', '3', 6);
    arr.insert_node('3', '4', 9);
    arr.print();
    return 0;
}
