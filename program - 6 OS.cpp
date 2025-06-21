#include <stdio.h>

int main() {
    int n, i, j, at[10], bt[10], pr[10], rt[10];
    int time = 0, completed = 0, smallest;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time, Burst Time, Priority:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    printf("\nExecution Order:\n");

    while (completed < n) {
        smallest = -1;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (smallest == -1 || pr[i] < pr[smallest]) {
                    smallest = i;
                }
            }
        }

        if (smallest == -1) {
            time++;
            continue;
        }

        printf("P%d ", smallest + 1);
        rt[smallest]--;
        time++;

        if (rt[smallest] == 0)
            completed++;
    }

    printf("\nAll processes finished.\n");
    return 0;
}

