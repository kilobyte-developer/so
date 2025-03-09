#include <stdio.h>
#include <stdlib.h>

int allocation[20][20], max[20][20], available[20], need[20][20], safe[10], s = 0;
int finish[10], work[10], p, r, i, j, ch, idx, req[10];

void check()
{
    int temp = 0, flag = 0;

    // Calculate Need = Max - Allocation
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    printf("\nNeed Matrix:\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
            printf("%d\t", need[i][j]);
        printf("\n");
    }

    for (i = 0; i < p; i++)
        finish[i] = 0;

    for (i = 0; i < r; i++)
        work[i] = available[i];

    while (temp < p)
    {
        flag = 0;
        for (i = 0; i < p; i++)
        {
            if (finish[i] == 0)
            {
                int possible = 1;
                for (j = 0; j < r; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        possible = 0;
                        break;
                    }
                }
                if (possible)
                {
                    for (j = 0; j < r; j++)
                        work[j] += allocation[i][j];
                    safe[s++] = i;
                    finish[i] = 1;
                    flag = 1;
                }
            }
        }
        if (flag == 0)
            break;
        temp++;
    }

    flag = 0;
    for (i = 0; i < p; i++)
        if (finish[i] == 0)
            flag = 1;

    if (flag)
        printf("\nSystem is in DEADLOCK!");
    else
    {
        printf("\nSystem is in SAFE State\nSafe Sequence: ");
        for (i = 0; i < s; i++)
            printf("P%d ", safe[i]);
    }
}

int main()
{
    printf("~~~ Banker's Algorithm ~~~\n");

    printf("Enter number of Processes and Resources: ");
    scanf("%d%d", &p, &r);

    printf("\nEnter Allocation Matrix:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &allocation[i][j]);

    printf("\nEnter Max Matrix:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("\nEnter Available Resources:\n");
    for (i = 0; i < r; i++)
        scanf("%d", &available[i]);

    check();

    printf("\nDo you want to add new Request? (1: Yes, 0: No): ");
    scanf("%d", &ch);

    if (ch == 0)
        exit(0);

    printf("\nEnter Process Number: ");
    scanf("%d", &idx);

    printf("\nEnter Request Vector: ");
    for (i = 0; i < r; i++)
        scanf("%d", &req[i]);

    for (i = 0; i < r; i++)
    {
        if (req[i] > need[idx][i])
        {
            printf("\nRequest cannot be satisfied (Exceeds Maximum Need)");
            exit(1);
        }
        if (req[i] > available[i])
        {
            printf("\nRequest cannot be satisfied (Not enough Available Resources)");
            exit(1);
        }
    }

    for (i = 0; i < r; i++)
    {
        allocation[idx][i] += req[i];
        available[i] -= req[i];
    }

    check();

    return 0;
}
