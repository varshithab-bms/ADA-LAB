#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int x[MAX];

int place(int x[], int k) {
    for (int i = 1; i < k; i++) {
        if (x[i] == x[k] || abs(i - k) == abs(x[i] - x[k])) {
            return 0;
        }
    }
    return 1;
}
void nqueens(int n) {
    int k = 1;
    x[k] = 0;

    while (k != 0) {
        x[k] = x[k] + 1;

        while (x[k] <= n && !place(x, k)) {
            x[k] = x[k] + 1;
        }
        if (x[k] <= n) {
            if (k == n) {
                for (int i = 1; i <= n; i++) {
                    printf("Queen %d placed at column %d\n", i, x[i]);
                }
                printf("-------------------\n");
            } else {
                k = k + 1;
                x[k] = 0;
            }
        } else {
            k = k - 1;
        }
    }
}
int main() {
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid input. Enter n between 1 and %d.\n", MAX);
        return 1;
    }

    nqueens(n);

    return 0;
}
