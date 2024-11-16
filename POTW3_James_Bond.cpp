#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> x(n);
        for (int i = 0; i < n; ++i)
            cin >> x[i];
        vector<vector<long long>> DP(n, vector<long long>(n, 0));
        for (int len = 1; len <= n; ++len) {
            for (int l = 0; l + len -1 < n; ++l) {
                int r = l + len - 1;
                int t_remaining = r - l + 1;
                int total_moves = n - t_remaining;
                int current_player = total_moves % m;
                if (l == r) {
                    if (current_player == k)
                        DP[l][r] = x[l];
                    else
                        DP[l][r] = 0;
                } else {
                    if (current_player == k) {
                        long long pick_left = x[l] + DP[l+1][r];
                        long long pick_right = x[r] + DP[l][r-1];
                        DP[l][r] = max(pick_left, pick_right);
                    } else {
                        long long opponent_left = DP[l+1][r];
                        long long opponent_right = DP[l][r-1];
                        DP[l][r] = min(opponent_left, opponent_right);
                    }
                }
            }
        }
        cout << DP[0][n-1] << endl;
    }
    return 0;
}

