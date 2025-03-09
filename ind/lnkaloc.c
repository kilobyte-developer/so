/*
Q2: Linked File Allocation
1. Show Bit Vector
2. Create New File
3. Show Directory
4. Exit
*/
#include <stdio.h>
#include <stdlib.h>

int blocks[10] = {0}; // 0 = Free, 1 = Allocated

void display() {
    printf("Bit Vector: ");
    for (int i = 0; i < 10; i++) printf("%d ", blocks[i]);
    printf("\n");
}

void createFile() {
    int start, len;
    printf("Enter start block and length: ");
    scanf("%d %d", &start, &len);
    for (int i = start; i < start + len && i < 10; i++) {
        if (blocks[i]) { printf("Block %d already allocated\n", i); return; }
        blocks[i] = 1;
    }
    printf("File created\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Show Bit Vector\n2.Create New File\n3.Show Directory\n4.Exit\n");
        scanf("%d", &choice);
        if (choice == 4) break;
        (choice == 1) ? display() : (choice == 2) ? createFile() : printf("No directory structure\n");
    }
    return 0;
}
