#include <stdio.h>

void sjf(int burst_time[], int n) {
    int waiting_time[n], turnaround_time[n];
    int completion_time[n];
    int remaining_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;

    // Copy burst_time to remaining_time
    for (int i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i];
    }

    int complete = 0, time = 0, min = 9999, shortest = 0;

    while (complete < n) {
        // Find the process with the minimum remaining time
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && remaining_time[i] < min) {
                min = remaining_time[i];
                shortest = i;
            }
        }

        // Execute the shortest job
        remaining_time[shortest] = 0;
        min = 9999;
        completion_time[shortest] = time + burst_time[shortest];
        time += burst_time[shortest];
        complete++;

        waiting_time[shortest] = completion_time[shortest] - burst_time[shortest];
        turnaround_time[shortest] = completion_time[shortest];

        total_waiting_time += waiting_time[shortest];
        total_turnaround_time += turnaround_time[shortest];
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n];

    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    sjf(burst_time, n);

    return 0;
}
