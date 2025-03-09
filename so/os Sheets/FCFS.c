#include <stdio.h>
#include <stdlib.h>

void FCFS(int requests[], int n, int head) {
    int seek_count = 0;
    printf("Order of execution: %d ", head);

    for (int i = 0; i < n; i++) {
        seek_count += abs(head - requests[i]);
        head = requests[i];
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

    FCFS(requests, n, head);
    return 0;
}