#include <iostream>
#include <algorithm>

using namespace std;

int knapsack01Recursive(int capacity, int weights[], int values[], int n) {
    if (n == 0 || capacity == 0) {
        return 0;//base condiction
    }

    if (weights[n - 1] > capacity) {
        return knapsack01Recursive(capacity, weights, values, n - 1);
    } else {
        return max(values[n - 1] + knapsack01Recursive(capacity - weights[n - 1], weights, values, n - 1),
                   knapsack01Recursive(capacity, weights, values, n - 1));
    }
}

int main() {
    int capacity = 20;
    int weights[] = {18, 15, 10};
    int values[] = {25, 24, 15};
    int n = sizeof(weights) / sizeof(weights[0]);

    int maxValue = knapsack01Recursive(capacity, weights, values, n);

    cout << "Maximum value in Knapsack (0/1 Knapsack): " << maxValue << endl;

    return 0;
}
