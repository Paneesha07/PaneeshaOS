#include <stdio.h>

int main() {
    int buffer = 0; 
    int full = 0;   
    int empty = 1;  

    int choice, item = 0;

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) { 
            if (empty == 0) {
                printf("Buffer is full! Cannot produce.\n");
            } else {
                item++;
                buffer = item;
                empty = 0;
                full = 1;
                printf("Produced item: %d\n", buffer);
            }
        }

        else if (choice == 2) { 
            if (full == 0) {
                printf("Buffer is empty! Cannot consume.\n");
            } else {
                printf("Consumed item: %d\n", buffer);
                buffer = 0;
                full = 0;
                empty = 1;
            }
        }

        else if (choice == 3) {
            break;
        }

        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

