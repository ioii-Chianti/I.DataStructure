#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<int> seq;
        queue<int> origin;
        queue<int> station;
        int n, coach;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> coach;
            seq.push_back(coach);
            origin.push(i + 1);
        }

        int index = 0;
        while (index < n) {
            if (!origin.empty() && origin.front() == seq[index]) {
                origin.pop();
                index++;
            } else if (!station.empty() && station.front() == seq[index]) {
                station.pop();
                index++;
            } else if (!origin.empty()) {
                station.push(origin.front());
                origin.pop();
            } else
                index++;
        }

        if (origin.empty() && station.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}