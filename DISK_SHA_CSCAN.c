#include <stdio.h>
#include <stdlib.h>
#define MAX_REQUESTS 100

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

void cscan(int requestQueue[], int head, int size, int disk_size) {
    int seekTime = 0;
    int current = head;
    
    int left[MAX_REQUESTS];
    int right[MAX_REQUESTS];
    int leftCount = 0, rightCount = 0;

    for (int i = 0; i < size; i++) {
        if (requestQueue[i] < head) {
            left[leftCount++] = requestQueue[i];
        } else {
            right[rightCount++] = requestQueue[i];
        }
    }
    
    sort(left, leftCount);
    sort(right, rightCount);

    for (int i = 0; i < rightCount; i++) {
        int nextRequest = right[i];
        int distance = abs(current - nextRequest);
        seekTime += distance;
        current = nextRequest;
    }
    
    seekTime += disk_size - 1 - current;
    current = 0;

    for (int i = 0; i < leftCount; i++) {
        int nextRequest = left[i];
        int distance = abs(current - nextRequest);
        seekTime += distance;
        current = nextRequest;
    }

    printf("Total seek time: %d\n", seekTime);
}

int main() {
    int requestQueue[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    int size = sizeof(requestQueue) / sizeof(requestQueue[0]);
    int disk_size = 200;

    cscan(requestQueue, head, size, disk_size);

    return 0;
}
