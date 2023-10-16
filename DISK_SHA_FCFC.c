#include <stdio.h>
#include <stdlib.h>

int fcfs(int request[], int n, int initial_position) {
    int total_movement = 0;

    for (int i = 0; i < n; i++) {
        total_movement += abs(initial_position - request[i]);
        initial_position = request[i];
    }

    return total_movement;
}

int main() {
    int n, initial_position;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the initial head position: ");
    scanf("%d", &initial_position);

    int request[n];

    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    int total_head_movement = fcfs(request, n, initial_position);

    printf("Total head movement: %d\n", total_head_movement);

    return 0;
}
