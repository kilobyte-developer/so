#include <stdio.h>
#include <stdlib.h>

int main()
{
    int RQ[100], i, n, TotalHeadMoment = 0, initial, count = 0;
    printf("Enter the number of Requests: ");
    scanf("%d", &n);

    printf("Enter the Request sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position: ");
    scanf("%d", &initial);

    printf("\nSeek Sequence: %d --> ", initial);

    // SSTF Logic
    while (count != n)
    {
        int min = __INT_MAX__, d, index = -1;

        for (i = 0; i < n; i++)
        {
            if (RQ[i] != -1)
            {
                d = abs(RQ[i] - initial);
                if (d < min)
                {
                    min = d;
                    index = i;
                }
            }
        }

        TotalHeadMoment += min;
        initial = RQ[index];
        printf("%d --> ", RQ[index]);
        RQ[index] = -1;
        count++;
    }

    printf("\nTotal Head Movement = %d\n", TotalHeadMoment);
    return 0;
}
