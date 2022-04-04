#include <iostream>
#include <set>
using namespace std;

// set, testcase: 4/5

unsigned uglyNumber(int n) {
    if (n == 1 || n == 2 || n == 3 || n == 4 || n == 5)
        return n;

    set<unsigned> Set;
    Set.insert(1);
    n--;

    while (n--) {
        set<unsigned>::iterator it = Set.begin();
        unsigned front = *it;
        Set.erase(it);
        Set.insert(front * 2);
        Set.insert(front * 3);
        Set.insert(front * 5);
    }
    return *Set.begin();
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