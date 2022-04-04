#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

vector<int> ans;

void swing(list<int> &List, bool &flag) {
    if (flag) {
        // record, push, delete
        int lastPoped = List.front();
        ans.push_back(lastPoped);
        List.pop_front();

        for (list<int>::iterator it = List.begin(); it != List.end(); it++) {
            if (*it > lastPoped) {
                list<int>::iterator toDelete = it;
                it--;
                // record, push, delete
                lastPoped = *toDelete;
                ans.push_back(lastPoped);
                List.erase(toDelete);
            }
        }
        flag = false;
    } else {
        // record, push, delete
        int lastPoped = List.back();
        ans.push_back(lastPoped);
        List.pop_back();

        for (list<int>::iterator it = prev(List.end()); it != List.begin(); it--) {
            if (*it < lastPoped) {
                list<int>::iterator toDelete = it;
                it++;
                // record, push, delete
                lastPoped = *toDelete;
                ans.push_back(lastPoped);
                List.erase(toDelete);
            }
        }
        if (!List.empty() && List.front() < lastPoped) {
            ans.push_back(List.front());
            List.pop_front();
        }
        flag = true;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        // init and sort list
        list<int> List;
        int len, input;
        cin >> len;
        for (int i = 0; i < len; i++) {
            cin >> input;
            List.push_back(input);
        }
        List.sort();

        bool flag = true;
        while (!List.empty())
            swing(List, flag);
            
        // print and clear ans
        for (auto it : ans)
            cout << it << ' ';
        cout << '\n';
        ans.clear();
    }
}