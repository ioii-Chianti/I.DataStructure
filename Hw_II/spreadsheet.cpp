#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Node {
    int data;
    bool visited;
    list<int> neighbors;
    Node() : data(0), visited(false) {}
    Node(int data) : data(data), visited(false) {}
};

int num;

void spreadSheet(vector<Node> &cells) {
    for (int i = 0; i < num; i++) {
        
    }
}

int main() {
    int F;
    cin >> num >> F;
    // vector contains all nodes
    vector<Node> cells(num + 1);

    while (F--) {
        char type;
        int id, B, C, D, data;
        cin >> type;
        if (type == 'A') {
            cin >> id >> data;
            cells[id].data = data;
        } else if (type == 'B') {
            cin >> id >> B >> data;
            cells[id].neighbors.push_back(B);
            cells[id].data = data;
        } else if (type == 'C') {
            cin >> id >> B >> C >> data;
            cells[id].neighbors.push_back(B);
            cells[id].neighbors.push_back(C);
            cells[id].data = data;
        } else if (type == 'D') {
            cin >> id >> B >> C >> D >> data;
            cells[id].neighbors.push_back(B);
            cells[id].neighbors.push_back(C);
            cells[id].neighbors.push_back(D);
            cells[id].data = data;
        }
    }
    spreadSheet(cells);
}