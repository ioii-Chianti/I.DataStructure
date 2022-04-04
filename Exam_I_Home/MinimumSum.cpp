#include <iostream>
#include <queue>
#include <set>
#define MAXR 105
#define MAXC 1005
using namespace std;
typedef pair<int, vector<int>> PIV;   // (sum, coordinate)

int numRow, numCol, K, mx[MAXR][MAXC];

vector<int> MinimumSum() {
    vector<int> ans;
    priority_queue<PIV, vector<PIV>, greater<>> pq;
    set<vector<int>> visited;   // record visited coordinate

    // push 1st smallest
    int sumInit = 0;
    vector<int> coordinateInit;
    for (int i = 0; i < numRow; i++) {
        sumInit += mx[i][0];
        coordinateInit.push_back(0);
    }
    pq.push({sumInit, coordinateInit});
    visited.insert(coordinateInit);

    while (K--) {
        // push current smallest into ans
        int sum = pq.top().first;
        vector<int> coordinate = pq.top().second;
        pq.pop();
        ans.push_back(sum);

        // dfs
        for (int i = 0; i < numRow; i++) {
            coordinate[i]++;
            // no overflow and not yet visit
            if (coordinate[i] < numCol && visited.find(coordinate) == visited.end()) {
                pq.push({sum + mx[i][coordinate[i]] - mx[i][coordinate[i] - 1], coordinate});
                visited.insert(coordinate);
            }
            coordinate[i]--;
        }
    }
    return ans;
}

int main() {
    cin >> numRow >> numCol;
    K = numCol;
    for (int i = 0; i < numRow; i++)
        for (int j = 0; j < numCol; j++)
            cin >> mx[i][j];

    vector<int> ans = MinimumSum();
    for (int it : ans)
        cout << it << ' ';
}