#include <stdio.h>
#include <stdlib.h>

int main()
{
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;

    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position\n");
    scanf("%d", &initial);

    printf("Enter total disk size\n");
    scanf("%d", &size);

    printf("Enter the head movement direction for High(1) or Low(0)\n");
    scanf("%d", &move);

    // Sorting Request Queue (Bubble Sort)
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (RQ[j] > RQ[j + 1])
            {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    int index;
    for (i = 0; i < n; i++)
    {
        if (initial < RQ[i])
        {
            index = i;
            break;
        }
    }

    // C-SCAN Logic 🔥
    if (move == 1)
    {
        for (i = index; i < n; i++)
        {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMoment += abs(size - 1 - initial); // Max to Last Track
        initial = 0;                                // Jump to 0
        for (i = 0; i < index; i++)
        {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    else if (move == 0)
    {
        for (i = index - 1; i >= 0; i--)
        {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMoment += abs(initial - 0); // First Track
        initial = size - 1;                  // Jump to Max Track
        for (i = n - 1; i >= index; i--)
        {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }

    printf("\nTotal Head Movement = %d\n", TotalHeadMoment);

    return 0;
}
