#include <iostream>
#include <stack>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        stack<char> Stack;
        string ans = "Yes";
        cin >> str;
        int len = str.length();
        for (int i = 0; i < len; i++) {
            char ch = str[i];
            if (ch == '(' || ch == '[')
                Stack.push(ch);
            else if (ch == ')') {
                if (!Stack.empty() && Stack.top() == '(')
                    Stack.pop();
                else {
                    ans = "No";
                    break;
                }
            } else if (ch == ']') {
                if (!Stack.empty() && Stack.top() == '[')
                    Stack.pop();
                else {
                    ans = "No";
                    break;
                }
            }
        }
        if (!Stack.empty())
            ans = "No";
        cout << ans << '\n';
    }
}