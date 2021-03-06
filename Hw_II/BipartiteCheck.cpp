#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int black = 0;
const int white = 1;
const int unknown = 2;

struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node *next) : data(data), next(next) {}
};

int numVertex, numEdge;

void newEdge(int x, int y, vector<Node *> &adjList) {
    Node *newNode = new Node(y, adjList[x]);
    adjList[x] = newNode;
    newNode = new Node(x, adjList[y]);
    adjList[y] = newNode;
}

string bipartiteCheck(vector<Node *> heads) {
    vector<int> colors(numVertex + 1, unknown);
    queue<int> Queue;

    for (int i = 1; i < numVertex + 1; i++) {
        if (colors[i] != unknown)
            continue;

        /* BFS */
        // the starting point of the connected component
        Queue.push(i);
        colors[i] = black;
        while (!Queue.empty()) {
            int lastPoped = Queue.front();
            Queue.pop();

            Node *node = heads[lastPoped];
            while (node->data) {
                if (colors[node->data] == colors[lastPoped])
                    return "NO";
                
                // enqueue not visited node and color it
                if (colors[node->data] == unknown) {
                    Queue.push(node->data);
                    colors[node->data] = (colors[lastPoped] == black) ? white : black;
                }
                node = node->next;
            }
        }
    }
    return "YES";
}

int main() {
    cin >> numVertex >> numEdge;
    vector<Node *> adjList(numVertex + 1);

    // init tail for all adjList w/ data 0
    for (int i = 0; i < numVertex + 1; i++)
        adjList[i] = new Node();

    for (int i = 0; i < numEdge; i++) {
        int x, y;
        cin >> x >> y;
        newEdge(x, y, adjList);
    }
    
    cout << bipartiteCheck(adjList);
}