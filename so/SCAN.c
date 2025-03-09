#include <stdio.h>
#include <stdlib.h>

void SCAN(int requests[], int n, int head, int direction, int max_range) {
    int seek_count = 0, i, j;
    int left[20], right[20], left_size = 0, right_size = 0;

    if (direction == 0) { // Moving left
        left[left_size++] = 0;
    } else { // Moving right
        right[right_size++] = max_range;
    }

    for (i = 0; i < n; i++) {
        if (requests[i] < head)
            left[left_size++] = requests[i];
        else
            right[right_size++] = requests[i];
    }

    // Sort left and right arrays
    for (i = 0; i < left_size - 1; i++)
        for (j = i + 1; j < left_size; j++)
            if (left[i] > left[j]) {
                int temp = left[i];
                left[i] = left[j];
                left[j] = temp;
            }

    for (i = 0; i < right_size - 1; i++)
        for (j = i + 1; j < right_size; j++)
            if (right[i] > right[j]) {
                int temp = right[i];
                right[i] = right[j];
                right[j] = temp;
            }

    printf("Order of execution: %d ", head);

    // Move towards the direction first
    if (direction == 0) { // Left
        for (i = left_size - 1; i >= 0; i--) {
            seek_count += abs(head - left[i]);
            head = left[i];
            printf("-> %d ", head);
        }
        for (i = 0; i < right_size; i++) {
            seek_count += abs(head - right[i]);
            head = right[i];
            printf("-> %d ", head);
        }
    } else { // Right
        for (i = 0; i < right_size; i++) {
            seek_count += abs(head - right[i]);
            head = right[i];
            printf("-> %d ", head);
        }
        for (i = left_size - 1; i >= 0; i--) {
            seek_count += abs(head - left[i]);
            head = left[i];
            printf("-> %d ", head);
        }
    }

    printf("\nTotal head movement: %d\n", seek_count);
}

int main() {

    int nr;
    printf("Enter The Number Of Requests: ");
    scanf("%d",&nr);

    int requests[nr];
    printf("Enter The Request Sequence: ");
    for(int i = 0 ; i<nr;i++){
        scanf("%d",&requests[i]);
    }

    int head;
    printf("Enter Starting Head Position: ");
    scanf("%d",&head);

    int direction;
    printf("Enter The Direction for LEFT(0) and for RIGHT(1): ");
    scanf("%d",&direction);

    int n = sizeof(requests) / sizeof(requests[0]);
    int max_range = 200; // 1 for right, 0 for left

    SCAN(requests, n, head, direction, max_range);
    return 0;
}