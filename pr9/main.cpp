#include "bfs.hpp"
#include "dfs.hpp"

int main(int argc, char const *argv[]) {
    int G[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 0, 0, 0, 1, 0},
                   {0, 0, 0, 0, 0, 1, 0, 1},
                   {0, 0, 0, 0, 1, 0, 0, 1},
                   {0, 0, 0, 1, 0, 1, 1, 0},
                   {0, 0, 1, 0, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0, 0}};

    BFS(G, 4, 8);
    DFS(G, 4, 8);
    return 0;
}
