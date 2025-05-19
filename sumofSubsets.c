#include <stdio.h>

int w[10], x[10], n, total = 0;

void sumOfSubsets(int i, int weight, int targetSum) {
    if (weight == targetSum) {
        printf("Subset: ");
        for (int j = 0; j < n; j++) {
            if (x[j])
                printf("%d ", w[j]);
        }
        printf("\n");
        return;
    }

    if (i >= n || weight > targetSum)
        return;

    // Include w[i]
    x[i] = 1;
    sumOfSubsets(i + 1, weight + w[i], targetSum);

    // Exclude w[i]
    x[i] = 0;
    sumOfSubsets(i + 1, weight, targetSum);
}

int main() {
    int target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        total += w[i];
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("Subsets that sum to %d:\n", target);
    sumOfSubsets(0, 0, target);

    return 0;
}
