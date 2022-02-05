#include <stdio.h>

void main() {
    int a[3][3] = {1, 9, 2, 5, 7, 6, 4, 3, 8};
    int i, j;
    bubbleSort3gi(a, sizeof(int), 9, intSort);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
    }
}
