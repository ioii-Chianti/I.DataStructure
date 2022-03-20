#include <iostream>
#include <vector>
using namespace std;

int main() {
    int na, nb, nc, input, cnt = 0;
    vector<int> A, B, C;
    cin >> na >> nb >> nc;
    for (int i = 0; i < na; i++) {
        cin >> input;
        A.push_back(input);
    }
    for (int i = 0; i < nb; i++) {
        cin >> input;
        B.push_back(input);
    }
    for (int i = 0; i < nc; i++) {
        cin >> input;
        C.push_back(input);
    }

    for (int i = 0; i < na; i++) {
        for (int j = 0; j < nb; j++) {
            if (A[i] > B[j]) {
                for (int k = 0; k < nc; k++)
                    if (B[j] < C[k])
                        cnt++;
            }
        }
    }
        
    cout << cnt;

    return 0;
}