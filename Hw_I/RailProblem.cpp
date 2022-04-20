#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<int> seq;
        stack<int> st;
        int n, coach;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> coach;
            seq.push_back(coach);
        }

        int index = 0, num = 1;
        while (index < n) {
            if (st.empty() || st.top() != seq[index])
                st.push(num++);
            while (!st.empty() && st.top() == seq[index]) {
                st.pop();
                index++;
            }
            if (num > n) 
                index++;
        }

        if (st.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}