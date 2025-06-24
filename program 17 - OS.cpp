#include <stdio.h>

int main() {
    int n = 3; 
    int m = 3;

    int alloc[3][3] = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2} };
    int max[3][3] = { {7, 5, 3}, {3, 2, 2}, {9, 0, 2} };
    int avail[3] = {3, 3, 2};

    int need[3][3];
    int finish[3] = {0, 0, 0};
    int safeSeq[3];
    int work[3];
    int i, j, count = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (i = 0; i < m; i++) {
        work[i] = avail[i];
    }

    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == m) { 
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is not in a safe state.\n");
            return 0;
        }
    }

    printf("System is in a safe state.\nSafe sequence: ");
    for (i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}

