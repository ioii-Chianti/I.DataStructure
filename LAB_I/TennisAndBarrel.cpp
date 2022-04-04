#include <iostream>
#include <list>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    list<int> List[N];
    while (T--) {
        int action, ball, end, barrel;
        cin >> action;
        switch (action) {
            // store ball
            case 0: {
                cin >> ball >> end >> barrel;
                if (end == 0)
                    List[barrel - 1].push_front(ball);
                else if (end == 1)
                    List[barrel - 1].push_back(ball);
                break;
            }
            // retrieve
            case 1: {
                cin >> end >> barrel;
                if (end == 0) {
                    cout << List[barrel - 1].front() << "\n";
                    List[barrel - 1].pop_front();
                } else if (end == 1) {
                    cout << List[barrel - 1].back() << "\n";
                    List[barrel - 1].pop_back();
                }
                break;
            }
        }
    }
}