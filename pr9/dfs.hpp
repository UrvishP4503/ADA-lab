#pragma 0
#define DFS_HPP

#include <iostream>

void DFS(int G[][8], int start, int n) {
    static int visited[8] = {0};
    int j;

    if (visited[start] == 0) {
        std::cout << start << " ";
        visited[start] = 1;

        for (j = 1; j < n; j++) {
            if (G[start][j] == 1 && visited[j] == 0)
                DFS(G, j, n);
        }
    }
}
