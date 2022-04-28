#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Node {
    int data;
    long long sumSubTree = 0;
    set<int> neighbors; // parents and children
};

// Recursively sum subtrees DOWNWARD
void sumSub(vector<Node> &nodes, set<int> &parents, int n) {
    nodes[n].sumSubTree = nodes[n].data;
    for (int neighbor : nodes[n].neighbors) {
        // Prevents going UP a generation
        if (parents.insert(neighbor).second) {
            sumSub(nodes, parents, neighbor);
            nodes[n].sumSubTree += nodes[neighbor].sumSubTree;
        }
   }
}

int main() {
    int numNode;
    cin >> numNode;
    vector<Node> nodes(numNode + 1);
    for (int i = 1; i <= numNode; i++)
        cin >> nodes[i].data;
    for (int i = 1; i < numNode; i++) {
        int x, y;
        cin >> x >> y;
        nodes[x].neighbors.insert(y);
        nodes[y].neighbors.insert(x);
    }

    set<int> parents{1};
    sumSub(nodes, parents, 1);

    for (int i = 1; i <= numNode; i++)
        cout << nodes[i].sumSubTree << ' ';
    cout << '\n';
}