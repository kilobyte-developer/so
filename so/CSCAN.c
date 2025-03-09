#include <stdio.h>
#include <stdlib.h>

void CSCAN(int requests[], int n, int head, int max_range) {
    int seek_count = 0, i;
    
    printf("Order of execution: %d ", head);
    
    for (i = 0; i < n; i++) {
        if (requests[i] >= head) {
            seek_count += abs(head - requests[i]);
            head = requests[i];
            printf("-> %d ", head);
        }
    }
    
    seek_count += abs(head - max_range);
    head = 0;
    seek_count += max_range;

    for (i = 0; i < n; i++) {
        if (requests[i] < head) {
            seek_count += abs(head - requests[i]);
            head = requests[i];
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

    int n = sizeof(requests) / sizeof(requests[0]);
    int max_range = 200;

    CSCAN(requests, n, head, max_range);
    return 0;
}