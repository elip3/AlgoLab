#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void find_subarray(int n, int k, const vector<int>& arr) {
    int start = 0, end = 0;
    int sum = arr[0];
    int min_diff = abs(sum - k);
    int best_i = 0, best_j = 0;

    while (start < n && end < n) {
        if (sum == k) {
            best_i = start;
            best_j = end;
            break;
        }

        int current_diff = abs(sum - k);
        if (current_diff < min_diff || (current_diff == min_diff && (start < best_i || (start == best_i && end < best_j)))) {
            min_diff = current_diff;
            best_i = start;
            best_j = end;
        }

        if (sum < k) {
            end++;
            if (end < n) {
                sum += arr[end];
            }
        } else {
            sum -= arr[start];
            start++;
            if (start > end && start < n) {
                end = start;
                sum = arr[start];
            }
        }
    }

    if (sum == k) {
        if (start < best_i || (start == best_i && end < best_j)) {
            best_i = start;
            best_j = end;
        }
    } else {
        int current_diff = abs(sum - k);
        if (current_diff < min_diff || (current_diff == min_diff && (start < best_i || (start == best_i && end < best_j)))) {
            min_diff = current_diff;
            best_i = start;
            best_j = end;
        }
    }

    cout << best_i << " " << best_j << endl;
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        find_subarray(n, k, arr);
    }
    return 0;
}
