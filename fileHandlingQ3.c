#include <stdio.h>
//NAME:Akshra Singh    PRN: 21070122014   CSA-1
int main() {
    int n, i;
    char name[50];
    int marks;
    FILE *fptr;
    fptr = fopen("students.txt", "w");

    if (fptr == NULL) {
        printf("Error opening file!");
        return 1;
    }
    
    printf("Enter number of students: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter name and marks for student %d: ", i+1);
        scanf("%s %d", name, &marks);
        fprintf(fptr, "Name: %s, Marks: %d\n", name, marks);
    }
    fclose(fptr);
    
    printf("Data written to file successfully!");
    return 0;
}