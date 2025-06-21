#include <stdio.h>

int main() {
    int n, i, j, bt[10], p[10], temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        p[i] = i + 1; 
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[j] < bt[i]) {
                
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("\nExecution Order: ");
    for (i = 0; i < n; i++) {
        printf("P%d ", p[i]);
    }
    printf("\n");

    return 0;
}

