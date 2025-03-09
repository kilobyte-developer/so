/*
Q1: C Menu-driven Program
1. Accept Available resources
2. Display Allocation & Max
3. Display Need Matrix
4. Display Available resources
*/
#include <stdio.h>

void display(int mat[5][3], int rows) {
    for (int i = 0; i < rows; i++)
        printf("%d %d %d\n", mat[i][0], mat[i][1], mat[i][2]);
}

int main() {
    int alloc[5][3] = {{2,3,2},{4,0,0},{5,0,4},{4,3,3},{2,2,4}};
    int max[5][3] = {{9,7,5},{5,2,2},{1,0,4},{4,4,4},{6,5,5}};
    int avail[3] = {3,3,2}, choice;

    while (1) {
        printf("\n1.Accept Available\n2.Display Allocation, Max\n3.Display Need Matrix\n4.Display Available\n5.Exit\n");
        scanf("%d", &choice);
        if (choice == 5) break;

        switch (choice) {
            case 1: printf("Enter Available: "); scanf("%d%d%d", &avail[0], &avail[1], &avail[2]); break;
            case 2: printf("Allocation:\n"); display(alloc, 5); printf("Max:\n"); display(max, 5); break;
            case 3: printf("Need Matrix:\n"); 
                for (int i = 0; i < 5; i++)
                    printf("%d %d %d\n", max[i][0]-alloc[i][0], max[i][1]-alloc[i][1], max[i][2]-alloc[i][2]);
                break;
            case 4: printf("Available: %d %d %d\n", avail[0], avail[1], avail[2]); break;
            default: printf("Invalid Choice\n");
        }
    }
    return 0;
}
