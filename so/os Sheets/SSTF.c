#include <stdio.h>
#include <stdlib.h>

int findClosest(int requests[], int n, int head, int processed[]) {
    int min_distance = 9999, index = -1;
    for (int i = 0; i < n; i++) {
        if (!processed[i] && abs(requests[i] - head) < min_distance) {
            min_distance = abs(requests[i] - head);
            index = i;
        }
    }
    return index;
}

void SSTF(int requests[], int n, int head) {
    int seek_count = 0, processed[n];
    for (int i = 0; i < n; i++)
        processed[i] = 0;

    printf("Order of execution: %d ", head);

    for (int i = 0; i < n; i++) {
        int index = findClosest(requests, n, head, processed);
        if (index == -1) break;

        seek_count += abs(head - requests[index]);
        head = requests[index];
        processed[index] = 1;

        printf("-> %d ", head);
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
    
    int n = sizeof(requests) / sizeof(requests[0]);

    SSTF(requests, n, head);
    return 0;
}
