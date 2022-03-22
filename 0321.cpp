#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numNode, numPair, x, y;
    cin >> numNode >> numPair;
    
    // adjacent graph (numNode * numNode 2D vector w/ all values 0)
    vector<vector<bool>> graph(numNode + 1, vector<bool>(numNode + 1));

    while (numPair--) {
        cin >> x >> y;
        graph[x][y] = true;
        graph[y][x] = true;
    }

    int ans = 0;
    for (int i = 1; i <= numNode; i++) {
        vector<bool> friendfriend(numNode + 1);
        // if i and u are friend, then check whether u and v are friend;
        // if true, then i and v are friendfriend
        for (int u = 1; u <= numNode; u++) 
            if (graph[i][u]) {   
                for (int v = 1; v <= numNode; v++)
                    if (graph[u][v])
                        friendfriend[v] = true;
            }

        // i can't be friend of himself
        friendfriend[i] = false;

        // sum up i's friendfriend
        int sum = 0;
        for (int j = 1; j <= numNode; j++)
            if (friendfriend[j])
                sum += j;
        // choose the maximum
        ans = max(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}