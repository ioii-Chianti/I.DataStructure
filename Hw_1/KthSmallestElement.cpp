#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int length, K, input;
    set<int> arr;
    set<int>::iterator it;
    vector<int> ans;
    cin >> length >> K;

    for (int i = 1; i <= length; i++) {
        cin >> input;
        arr.insert(input);
        if (i == K) {
            it = arr.begin();
            for (int i = 1; i < K; i++)
                it++;
            ans.push_back(*it);
        } else if (i > K) {
            if (input < *it)
                --it;
            ans.push_back(*it);
        }
    }
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
        cout << *it << ' ';
        
    return 0;
}