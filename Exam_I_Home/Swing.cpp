#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

vector<int> ans;
const bool increase = true;
const bool decrease = false;

void swing(list<int> &ls, bool &mode) {
    if (mode) {
        // record, push, delete
        int lastPoped = ls.front();
        ans.push_back(lastPoped);
        ls.pop_front();

        for (list<int>::iterator it = ls.begin(); it != ls.end(); it++) {
            if (*it > lastPoped) {
                list<int>::iterator toDelete = it;
                it--;
                // record, push, delete
                lastPoped = *toDelete;
                ans.push_back(lastPoped);
                ls.erase(toDelete);
            }
        }
        mode = decrease;
    } else {
        // record, push, delete
        int lastPoped = ls.back();
        ans.push_back(lastPoped);
        ls.pop_back();

        for (list<int>::iterator it = prev(ls.end()); it != ls.begin(); it--) {
            if (*it < lastPoped) {
                list<int>::iterator toDelete = it;
                it++;
                // record, push, delete
                lastPoped = *toDelete;
                ans.push_back(lastPoped);
                ls.erase(toDelete);
            }
        }
        // remember the first elememt
        if (!ls.empty() && ls.front() < lastPoped) {
            ans.push_back(ls.front());
            ls.pop_front();
        }
        mode = increase;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        // init and sort list
        list<int> ls;
        int len, input;
        cin >> len;
        for (int i = 0; i < len; i++) {
            cin >> input;
            ls.push_back(input);
        }
        ls.sort();

        bool mode = increase;
        while (!ls.empty())
            swing(ls, mode);
            
        // print and clear ans
        for (int it : ans)
            cout << it << ' ';
        cout << '\n';
        ans.clear();
    }
}