/*
Q3: Sequential (Contiguous) File Allocation
1. Show Bit Vector
2. Delete File
3. Exit
*/
#include <stdio.h>

int blocks[10] = {0};

void display() {
    printf("Bit Vector: ");
    for (int i = 0; i < 10; i++) printf("%d ", blocks[i]);
    printf("\n");
}

void deleteFile() {
    int start, len;
    printf("Enter start and length to delete: ");
    scanf("%d %d", &start, &len);
    for (int i = start; i < start + len; i++) blocks[i] = 0;
    printf("File deleted\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Show Bit Vector\n2.Delete File\n3.Exit\n");
        scanf("%d", &choice);
        if (choice == 3) break;
        (choice == 1) ? display() : deleteFile();
    }
    return 0;
}
