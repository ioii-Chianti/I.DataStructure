#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* Concept: Use BFS to traverse graph,
   when queue is empty, there is one connected component */

struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node *next) : data(data), next(next) {}
};

int numVertex, numEdge;

int connectedComponent(vector<Node *> heads) {
    int cnt = 0;
    vector<bool> visited(numVertex + 1, false);
    queue<int> Queue;

    for (int i = 1; i <= numVertex; i++) {
        if (visited[i])
            continue;

        /* BFS */
        // push the starting point of the component
        Queue.push(i);
        visited[i] = true;

        while (true) {
            int lastPoped = Queue.front();
            Queue.pop();
            // enqueue all neighbors of current node
            Node *node = heads[lastPoped];
            while (node->data) {
                if (!visited[node->data]) {
                    Queue.push(node->data);
                    visited[node->data] = true;
                }
                node = node->next;
            }
            // end traversal of this connected component
            if (Queue.empty()) {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

// new edges for both x and y, adjList[i] points to the head of list
// b(adj[x]) -> a -> 0
// y -> b(adj[x]) -> a -> 0
// y(adj[x]) -> b -> a -> 0
void newEdge(int x, int y, vector<Node *> &adjList) {
    Node *newNode = new Node(y, adjList[x]);
    adjList[x] = newNode;
    newNode = new Node(x, adjList[y]);
    adjList[y] = newNode;
}

int main() {
    cin >> numVertex >> numEdge;
    vector<Node *> adjList(numVertex + 1);

    // init tail for all adjList w/ data 0
    for (int i = 0; i <= numVertex; i++)
        adjList[i] = new Node();

    for (int i = 0; i < numEdge; i++) {
        int x, y;
        cin >> x >> y;
        newEdge(x, y, adjList);
    }
    cout << connectedComponent(adjList);
}