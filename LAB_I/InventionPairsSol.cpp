#include <iostream>
#include <vector>
using namespace std;

int CalculateInversionPairsByInsertionSort (vector<int>& vec) {
    int cnt {};
    for (auto it {next(vec.begin())}; it != vec.end(); ++it) {
        for (auto rit {it}; rit != vec.begin() && *rit < *prev(rit); --rit) {
            ++cnt;
            swap(*rit, *prev(rit));
        }
    }
    return cnt;
}

int main () {
    int n {};
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    /* only for small n */
    cout << CalculateInversionPairsByInsertionSort(vec) << '\n';
    return 0;
}
