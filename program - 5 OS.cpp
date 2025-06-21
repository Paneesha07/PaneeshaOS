#include <stdio.h>

int main() {
    int n, i, j, bt[10], priority[10], p[10], temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority for each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &bt[i], &priority[i]);
        p[i] = i + 1; 
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (priority[j] < priority[i]) {
                
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("\nExecution Order:\n");
    for (i = 0; i < n; i++) {
        printf("P%d ", p[i]);
    }
    printf("\n");

    return 0;
}

