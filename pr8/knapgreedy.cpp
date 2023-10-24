#include <algorithm>
#include <iostream>
#include <vector>

struct Item {
    int value;
    int weight;
    double ratio;

    Item(int v, int w) : value(v), weight(w), ratio((double)v / w) {}
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int knapsack_greedy(int W, std::vector<Item>& items) {
    int n = items.size();
    int max_val = 0;

    std::sort(items.begin(), items.end(), compare);

    for (int i = 0; i < n; ++i) {
        if (W >= items[i].weight) {
            max_val += items[i].value;
            W -= items[i].weight;
        } else {
            max_val += W * items[i].ratio;
            break;
        }
    }

    return max_val;
}

int main() {
    std::vector<Item> items = {
        {10, 5},
        {40, 4},
        {30, 6},
        {50, 3},
    };
    int W = 10;
    int max_val = knapsack_greedy(W, items);
    std::cout << "Maximum value: " << max_val << std::endl;
    return 0;
}