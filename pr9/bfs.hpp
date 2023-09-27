#pragma 0
#define BFS_HPP

#include <iostream>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;

} *front = nullptr, *rear = nullptr;

void enqueue(int x) {
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == nullptr) {
        return;
    } else {
        t->data = x;
        t->next = nullptr;
        if (front == nullptr)
            front = rear = t;
        else {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue() {
    int x = -1;
    struct Node *t;

    if (front == nullptr) {
        return -1;
    } else {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

bool isEmpty() {
    return front == nullptr;
}

void BFS(int G[][8], int start, int n) {
    int i = start, j;

    int visited[8] = {0};

    std::cout << i << " ";

    visited[i] = 1;
    enqueue(i);

    while (!isEmpty()) {
        i = dequeue();
        for (j = 1; j < n; j++) {
            if (G[i][j] == 1 && visited[j] == 0) {
                std::cout << j << " ";
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
    std::cout << std::endl;
}
