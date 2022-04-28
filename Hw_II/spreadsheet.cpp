#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

struct Node {
    int value;
    bool visited;
    bool error;
    bool inStack;
    list<int> neighbors;
    Node() : value(0), visited(false), error(false), inStack(false) {}
    Node(int value) : value(value), visited(false), error(false), inStack(false) {}
};

int num;
vector<Node> cells;

void checkCycle(Node &node) {
    if (node.visited) {
        node.inStack = false;
        return;
    }

    node.visited = true;
    node.inStack = true;
    for (auto it : node.neighbors) {
        if (!cells[it].visited && checkCycle())
            ;
    }

    // for (int i = 0; i < num; i++) {
    //     if (cells[i].visited || cells[i].error)
    //         continue;
    //     Stack.push_back(i);
    //     cells[i].visited = true;
    //     for (int it : cells[i].neighbors) {
    //         if (cells[it].error) {
    //             cells[i].error = true;
    //             break;
    //         }
    //         if (!cells[it].visited) {
    //             Stack.push_back(it);
    //             cells[it].visited = true;
    //         } else if (cells[it].visited) {
    //             // find cycle
    //             while (find(Stack.begin(), Stack.end(), it) != Stack.end()) {
    //                 cells[Stack.back()].error = true;
    //                 Stack.pop_back();
    //             }
    //         }
    //     }
    // }
}

void spreadSheet(vector<Node> &cells) {
    for (int i = 1; i <= num; i++) {
        checkCycle(cells[i]);
    }
}

int main() {
    int F;
    cin >> num >> F;
    // vector contains all nodes
    cells.resize(num + 1);

    while (F--) {
        char type;
        int id, B, C, D, value;
        cin >> type;
        if (type == 'A') {
            cin >> id >> value;
            cells[id].value = value;
        } else if (type == 'B') {
            cin >> id >> B >> value;
            cells[id].neighbors.push_back(B);
            cells[id].value = value;
        } else if (type == 'C') {
            cin >> id >> B >> C >> value;
            cells[id].neighbors.push_back(B);
            cells[id].neighbors.push_back(C);
            cells[id].value = value;
        } else if (type == 'D') {
            cin >> id >> B >> C >> D >> value;
            cells[id].neighbors.push_back(B);
            cells[id].neighbors.push_back(C);
            cells[id].neighbors.push_back(D);
            cells[id].value = value;
        }
    }
    spreadSheet(cells);
}