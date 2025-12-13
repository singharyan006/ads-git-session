#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    float *sales;

    printf("Enter the number of days: ");
    scanf("%d", &n);

    // Dynamically allocate memory for 'n' float sales values using malloc
    sales = (float *)malloc(n * sizeof(float));
    if (sales == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read sales data using pointers
    printf("Enter sales data for %d days:\n", n);
    for (i = 0; i < n; i++) {
        printf("Day %d: ", i + 1);
        scanf("%f", sales + i);
    }

    // Display sales data
    printf("Sales data entered:\n");
    for (i = 0; i < n; i++) {
        printf("Day %d: %.2f\n", i + 1, *(sales + i));
    }

    // Free allocated memory
    free(sales);

    return 0;
}
