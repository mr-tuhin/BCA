#include <stdio.h>
#include <stdlib.h>

#define MAX_CYLINDERS 200 
#define MIN_CYLINDERS 0     

void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void look(int requestQueue[], int head, int size, int direction) {
    int seekTime = 0;
    int current = head;

    sort(requestQueue, size);

    int start, end;

    if (direction == 0) {
        start = MIN_CYLINDERS;
        end = MAX_CYLINDERS;
    } else {
        start = MAX_CYLINDERS;
        end = MIN_CYLINDERS;
    }

    int i = 0;
    while (i < size) {
        if (requestQueue[i] >= start && requestQueue[i] <= end) {
            seekTime += abs(current - requestQueue[i]);
            current = requestQueue[i];
            printf("Move from %d to %d\n", current, requestQueue[i]);
            i++;
        } else {
            if (direction == 0) {
                direction = 1;
                end = current;
            } else {
                direction = 0;
                start = current;
            }
        }
    }

    printf("Total seek time: %d\n", seekTime);
}

int main() {
    int requestQueue[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;
    int size = sizeof(requestQueue) / sizeof(requestQueue[0]);
    int direction = 0;
    look(requestQueue, head, size, direction);

    return 0;
}
