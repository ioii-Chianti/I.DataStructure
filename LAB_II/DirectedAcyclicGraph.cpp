#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

int main() {
    int numV, numE;
    cin >> numV >> numE;
    vector<vector<int>> adjList(numV + 1);
    vector<int> indegree(numV + 1, 0);

    // add edges and set indegree
    for (int i = 0; i < numE; i++) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        indegree[y]++;
    }

    // init queue w/ 0-indegree
    queue<int> Queue;
    vector<int> sorted;
    for (int i = 1; i <= numV; i++) {
        if (indegree[i] == 0)
            Queue.push(i);
    }
    while (!Queue.empty()) {
        int pivot = Queue.front();
        Queue.pop();
        sorted.push_back(pivot);
        for (int neighbor : adjList[pivot])
            if (--indegree[neighbor] == 0)
                Queue.push(neighbor);
    }

    (sorted.size() == numV) ? cout << "yes" : cout << "no";
    // (accumulate(indegree.begin(), indegree.end(), 0) == 0) ? cout << "yes" : cout << "no";
}