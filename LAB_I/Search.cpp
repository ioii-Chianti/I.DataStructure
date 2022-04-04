#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// vec(N, 10) init vec w/ size N and all vals are 10

int main() {
    int N, M, command, key;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());

    cin >> M;
    while (M--) {
        cin >> command >> key;
        if (command == 1)
            cout << binary_search(vec.begin(), vec.end(), key) << '\n';
        else if (command == 2) {
            vector<int>::iterator it = lower_bound(vec.begin(), vec.end(), key);
            cout << ((it != vec.begin()) ? *prev(it) : 0) << '\n';
        } else if (command == 3) {
            vector<int>::iterator it = upper_bound(vec.begin(), vec.end(), key);
            cout << ((it != vec.end()) ? *it : 0) << '\n';
        }
    }
}