#include <iostream>
#include <stack>
using namespace std;

const string y = "Yes\n";
const string n = "No\n";

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str, ans = y;
        stack<char> Stack;
        cin >> str;
        
        for (char ch : str) {
            if (ch == '(' || ch == '[')
                Stack.push(ch);
            else if (ch == ')') {
                if (!Stack.empty() && Stack.top() == '(')
                    Stack.pop();
                else {
                    ans = n;
                    break;
                }
            } else if (ch == ']') {
                if (!Stack.empty() && Stack.top() == '[')
                    Stack.pop();
                else {
                    ans = n;
                    break;
                }
            }
        }
        if (!Stack.empty())
            ans = n;
        cout << ans;
    }
}