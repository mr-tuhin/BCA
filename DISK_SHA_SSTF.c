#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findShortestSeekTime(int *requests, int n, int currentPosition) {
    int minSeekTime = INT_MAX;
    int nextIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!requests[i])
            continue;

        int seekTime = abs(requests[i] - currentPosition);
        if (seekTime < minSeekTime) {
            minSeekTime = seekTime;
            nextIndex = i;
        }
    }

    return nextIndex;
}


void sstf(int *requests, int n, int initialPosition) {
    int currentPosition = initialPosition;
    int totalSeekTime = 0;

    printf("SSTF Sequence: %d", currentPosition);
    while (1) {
        int nextIndex = findShortestSeekTime(requests, n, currentPosition);

        if (nextIndex == -1)
            break;

        int seekTime = abs(requests[nextIndex] - currentPosition);
        totalSeekTime += seekTime;
        currentPosition = requests[nextIndex];
        requests[nextIndex] = 0;

        printf(" -> %d", currentPosition);
    }

    printf("\nTotal Seek Time: %d\n", totalSeekTime);
}

int main() {
    int n;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int *requests = (int *)malloc(n * sizeof(int));

    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    int initialPosition;
    printf("Enter the initial position: ");
    scanf("%d", &initialPosition);

    sstf(requests, n, initialPosition);

    free(requests);

    return 0;
}
