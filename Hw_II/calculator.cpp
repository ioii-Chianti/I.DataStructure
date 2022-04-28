#include <iostream>
#include <stack>
using namespace std;

int priority(char ch) {
    if (ch == '*' || ch == '/')
        return 3;
    if (ch == '+' || ch == '-') 
        return 2;
    return 0;
}

string infixToPostfix(string &expr) {
    stack<char> stack;
    string postExpr;
    for (char ch : expr) {
        if ('A' <= ch && ch <= 'E')
            postExpr += ch;
        else if (ch == '(')
            stack.push(ch);
        else if (ch == ')') {
            while (stack.top() != '(') {
                postExpr += stack.top();
                stack.pop();
            }
            stack.pop();
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!stack.empty() && priority(ch) <= priority(stack.top())) {
                postExpr += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }
    while (!stack.empty()) {
        postExpr.push_back(stack.top());
        stack.pop();
    }
    return postExpr;
}

int calculate(int A, int B, int C, int D, int E, string postfix) {
    stack<int> stack;
    for (char ch : postfix) {
        if ('A' <= ch && ch <= 'E') {
            switch (ch) {
                case 'A': stack.push(A); break;
                case 'B': stack.push(B); break;
                case 'C': stack.push(C); break;
                case 'D': stack.push(D); break;
                case 'E': stack.push(E); break;
            }
        } else {
            int y = stack.top();
            stack.pop();
            int x = stack.top();
            stack.pop();
            switch (ch) {
                case '+': stack.push(x + y); break;
                case '-': stack.push(x - y); break;
                case '*': stack.push(x * y); break;
                case '/': stack.push(x / y); break;
            }
        }
    }
    return stack.top();
}

int main () {
    string expr;
    int T;
    cin >> expr >> T;
    expr = infixToPostfix(expr);
    while (T--) {
        int A, B, C, D, E;
        cin >> A >> B >> C >> D >> E;
        cout << calculate(A, B, C, D, E, expr) << '\n';
    }
}