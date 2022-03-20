#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int length, K, input, Kth, lessThanKth;
    set<int> arr;
    vector<int> ans;
    cin >> length >> K;

    for (int i = 1; i <= length; i++) {
        cin >> input;
        if (i < K)
            arr.insert(input);
        else if (i == K) {
            arr.insert(input);
            set<int>::iterator it = arr.end();
            Kth = *--it;
            lessThanKth = *--it;
            ans.push_back(Kth);
        } else {
            if (arr.find(input) == arr.end()) {
                arr.insert(input);
                if (input < lessThanKth) {
                    Kth = lessThanKth;
                    lessThanKth = input;
                } else if (input < Kth) {
                    Kth = input;
                }
            }
            ans.push_back(Kth);
        }
    }

    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
        cout << *it << ' ';

    return 0;
}