#include <iostream>
#include <vector>
#include <queue>
#define SIZE 1005
#define INF 9999999
using namespace std;

typedef pair<int, int> Point;

char maze[SIZE][SIZE];
int dis[SIZE][SIZE];
int numRow, numCol;
int Ax, Ay, Bx, By;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs() {
    queue<Point> queue;
    for (int i = 0; i < numRow; i++)
        for (int j = 0; j < numCol; j++)
            dis[i][j] = INF;

    queue.push(Point(Ax, Ay));
    dis[Ax][Ay] = 0;
    while (!queue.empty()) {
        Point point = queue.front();
        queue.pop();
        if (point.first == Bx && point.second == By)
            break;

        for (int i = 0; i < 4; i++) {
            int Nx = point.first + dx[i];
            int Ny = point.second + dy[i];
            if ( 0 <= Nx && Nx < numRow && 0 <= Ny && Ny < numCol && maze[Nx][Ny] != '#' && dis[Nx][Ny] == INF) {
                queue.push(Point(Nx, Ny));
                dis[Nx][Ny] = dis[point.first][point.second] + 1;
            }
        }
    }
    return dis[Bx][By];
}

int main() {
    cin >> numRow >> numCol;
    // init maze and record start point
    for (int i = 0; i < numRow; i++) {
        for (int j = 0; j < numCol; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'A')
                Ax = i, Ay = j;
            if (maze[i][j] == 'B')
                Bx = i, By = j;
        }
    }
    int ans = bfs();
    ans == INF ? cout << "IMPOSSIBLE" : cout << ans;
}