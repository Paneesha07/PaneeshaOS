#include <stdio.h>

int main() {
    int blockSize[3] = {100, 500, 200}; 
    int processSize[3] = {212, 417, 112}; 
    int allocation[3] = {-1, -1, -1}; 

    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j; 
                blockSize[j] -= processSize[i]; 
                break; 
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("Process %d of size %d KB -> ", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("allocated to Block %d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}

