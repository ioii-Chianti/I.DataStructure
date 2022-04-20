#include <iostream>
#include <limits>
#define SIZE 1005
using namespace std;

/* testcase: 12/17 by DFS */

char maze[SIZE][SIZE];
int numRow, numCol, minStep = INT32_MAX;

void step(int x, int y, int curStep) {
    if (curStep > minStep)
        return;
    if (maze[x][y] == 'B')
        minStep = min(curStep, minStep);
    else {
        maze[x][y] = '#';
        if (x > 0 && maze[x - 1][y] != '#')
            step(x - 1, y, curStep + 1);
        if (x < numRow - 1 && maze[x + 1][y] != '#')
            step(x + 1, y, curStep + 1);
        if (y > 0 && maze[x][y - 1] != '#')
            step(x, y - 1, curStep + 1);
        if (y < numCol - 1 && maze[x][y + 1] != '#')
            step(x, y + 1, curStep + 1);
        maze[x][y] = '.';
    }
}

int main() {
    int Ax, Ay;
    cin >> numRow >> numCol;

    // init maze and record start point
    for (int i = 0; i < numRow; i++) {
        for (int j = 0; j < numCol; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'A')
                Ax = i, Ay = j;
        }
    }

    step(Ax, Ay, 0);
    if (minStep == INT32_MAX)
        cout << "IMPOSSIBLE";
    else
        cout << minStep;
}