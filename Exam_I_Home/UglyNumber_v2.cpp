#include <iostream>
#define MAX 100000
using namespace std;

// dynamic programming, testcase: 5/5

unsigned long uglyNumber(int n) {
    unsigned long dp[MAX];
    unsigned long idx_2 = 0, idx_3 = 0, idx_5 = 0;
    unsigned long next_2 = 2;
    unsigned long next_3 = 3;
    unsigned long next_5 = 5;
    unsigned long next_ugly = 1;

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        next_ugly = min(next_2, min(next_3, next_5));
        dp[i] = next_ugly;
        if (next_ugly == next_2) {
            idx_2++;
            next_2 = dp[idx_2] * 2;
        }
        if (next_ugly == next_3) {
            idx_3++;
            next_3 = dp[idx_3] * 3;
        }
        if (next_ugly == next_5) {
            idx_5++;
            next_5 = dp[idx_5] * 5;
        }
    }
    return next_ugly;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << uglyNumber(n) << '\n';
    }
}