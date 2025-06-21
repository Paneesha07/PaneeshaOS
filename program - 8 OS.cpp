#include <stdio.h>

int main() {
    int n, i, bt[10], rt[10], tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    printf("\nExecution Order: ");

    int remain = n;
    while (remain > 0) {
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                printf("P%d ", i + 1);
                if (rt[i] > tq)
                    rt[i] -= tq;
                else {
                    rt[i] = 0;
                    remain--;
                }
            }
        }
    }

    printf("\n");
    return 0;
}

