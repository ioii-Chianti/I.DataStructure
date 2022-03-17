#include <stdio.h>

int main() {
    int arr[20] = {3, 5, 6, 8, 13, 2, 1, 4, 7, 9, 15, 14, 16, 10, 12, 11, 19, 20, 18, 17};
    int pivot, j;

    /* Insertion Sort */

    // 從 index 1 到 index 20，共 19 回合
    for (int i = 1; i < 20; i++) {
        int j;
        pivot = arr[i];

        // 往前看每個數字
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > pivot)
                arr[j + 1] = arr[j];
            else {
                arr[j + 1] = pivot;
                break;
            } 
        }
        if (j < 0)
            arr[0] = pivot;
    }

    for (int i = 0; i < 20; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}