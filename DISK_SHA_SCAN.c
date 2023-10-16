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

void scan(int requestQueue[], int head, int size, int disk_size) {
    int seekTime = 0;
    int current = head;

    int right[MAX_REQUESTS];
    int rightCount = 0;

    for (int i = 0; i < size; i++) {
        if (requestQueue[i] > head) {
            right[rightCount++] = requestQueue[i];
        }
    }


    sort(right, rightCount);

    for (int i = 0; i < rightCount; i++) {
        int nextRequest = right[i];
        int distance = abs(current - nextRequest);
        seekTime += distance;
        current = nextRequest;
    }


    seekTime += (disk_size - 1) - current;
    current = disk_size - 1;

    printf("Total number of seek operations = %d\n", seekTime);
}

int main() {
    int requestQueue[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    int size = sizeof(requestQueue) / sizeof(requestQueue[0]);
    int disk_size = 200;

    scan(requestQueue, head, size, disk_size);

    return 0;
}
