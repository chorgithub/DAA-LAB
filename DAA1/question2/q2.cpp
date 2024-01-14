#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    
    ifstream in("q2_in.txt");
    ofstream out("q2_out.txt");

    if (!in.is_open()) {
        cerr << "Error" << endl;
        return 1;
    }

    if (!out.is_open()) {
        cerr << "Error" << endl;
        return 1; 
    }

    int W, n;
    in >> W >> n;

    vector<int> weights(n);
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        in >> weights[i] >> values[i];
    }

    in.close();

    int maxValue = knapsack(W, weights, values, n);

    out << "Maximum possible value is: " << maxValue << endl;

    out.close();


    return 0; 
}
