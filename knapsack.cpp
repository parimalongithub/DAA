#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio; // value-to-weight ratio
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int capacity, Item items[], int n) {
    sort(items, items + n, compare);
    
    double totalValue = 0.0;

    for (int i = 0; i < n; ++i) {
        if (capacity >= items[i].weight) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += (static_cast<double>(capacity) / items[i].weight) * items[i].value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity = 20;
    Item items[] = {{18, 25,1.389}, {15, 24, 1.6}, {10, 15, 1.5}};
    int n = sizeof(items) / sizeof(items[0]);

    double maxValue = fractionalKnapsack(capacity, items, n);

    cout << "Maximum value in Knapsack (Fractional Knapsack): " << maxValue << endl;

    return 0;
}
