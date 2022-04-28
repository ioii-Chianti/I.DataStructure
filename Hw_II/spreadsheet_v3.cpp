#include <iostream>
#include <queue>
#include <vector>
#define REF 999999999
using namespace std;

struct Node {
    int value;
    Node *parents;
    Node *childen;
    Node() : value(0), parents(nullptr), childen(nullptr) {}
    Node(int value) : value(value), parents(nullptr), childen(nullptr) {}
    Node(int value, Node *parents) : value(value), parents(parents), childen(childen) {}
};

// cycle remaining after this function
void spreadSheet(vector<vector<int>> adjList, vector<int> &indegree, int numCell) {
    queue<int> queue;
    for (int i = 1; i <= numCell; i++) {
        if (indegree[i] == 0)
            queue.push(i);
    }
    while (!queue.empty()) {
        int pivot = queue.front();
        queue.pop();
        for (int neighbor : adjList[pivot])
            if (--indegree[neighbor] == 0)
                queue.push(neighbor);
    }
}

int main() {
    int num, F;
    cin >> num >> F;
    // vector contains all nodes
    vector<int> indegree(num + 1);
    vector<Node> graph(num + 1);

    while (F--) {
        char type;
        int cell, B, C, D, val;
        cin >> type;
        if (type == 'A') {
            cin >> cell >> val;
            graph[cell].value = val;
        } else if (type == 'B') {
            cin >> cell >> B >> val;
            graph[cell].value = val;
            graph[cell].childen = new Node(B);
            adjList[cell].push_back(B);
            indegree[B]++;
        } else if (type == 'C') {
            cin >> cell >> B >> C >> val;
            value[cell] = val;
            adjList[cell].push_back(B);
            adjList[cell].push_back(C);
            indegree[B]++;
            indegree[C]++;
        } else if (type == 'D') {
            cin >> cell >> B >> C >> D >> val;
            value[cell] = val;
            adjList[cell].push_back(B);
            adjList[cell].push_back(C);
            adjList[cell].push_back(D);
            indegree[B]++;
            indegree[C]++;
            indegree[D]++;
        }
    }

    spreadSheet(adjList, indegree, num);
    for (int i = 1; i <= num; i++) {
        if (indegree[i] != 0)
            value[i] = REF;
    }
    for (int i = 1; i <= num; i++) {
        if (value[i] == REF)
            continue;
        for (int neighbor : adjList[i]) {
            if (value[neighbor] == REF) {
                value[i] = REF;
                break;
            }
        }
    }
    for (int i = 1; i <= num; i++) {
        if (value[i] == REF)
            cout << "#REF!\n";
        else {
            for (int neighbor : adjList[i])
                value[i] += value[neighbor];
            cout << value[i] << '\n';
        }
    }
}