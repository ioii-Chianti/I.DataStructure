#include <iostream>
#define SIZE 200000
using namespace std;

int arr[SIZE];

int main() {
    int N, cnt = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i];
        }
    }
        

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (arr[i] > arr[j])
                cnt++;
        }
    }
    cout << cnt << endl;
}