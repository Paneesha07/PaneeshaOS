#include <stdio.h>

struct Employee {
    int id;
    char name[20];
};

int main() {
    FILE *fp;
    struct Employee emp;
    int id;

    fp = fopen("employee.dat", "wb+"); 
    if (fp == NULL) {
        printf("File error.\n");
        return 1;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Employee Name: ");
    scanf("%s", emp.name);

    fseek(fp, (emp.id - 1) * sizeof(emp), SEEK_SET);
    fwrite(&emp, sizeof(emp), 1, fp); 
    printf("Employee saved.\n");

    printf("\nEnter Employee ID to view: ");
    scanf("%d", &id);

    fseek(fp, (id - 1) * sizeof(emp), SEEK_SET); 
    fread(&emp, sizeof(emp), 1, fp);

    printf("Employee ID: %d\n", emp.id);
    printf("Employee Name: %s\n", emp.name);

    fclose(fp);
    return 0;
}

