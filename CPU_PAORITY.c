#include <stdio.h>

struct Process {
    int id;
    int burst_time;
    int priority;
};

void priorityScheduling(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int total_time = 0;
    printf("Process Execution Order: ");
    for (int i = 0; i < n; i++) {
        total_time += processes[i].burst_time;
        printf("P%d ", processes[i].id);
    }
    printf("\n");

    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    int current_time = 0;

    printf("\n%-5s%-15s%-15s%-15s\n", "Process", "Burst Time", "Waiting Time", "Turnaround Time");
    for (int i = 0; i < n; i++) {
        avg_waiting_time += current_time;
        int turnaround_time = current_time + processes[i].burst_time;
        avg_turnaround_time += turnaround_time;

        printf("P%-4d%-15d%-15d%-15d\n", processes[i].id, processes[i].burst_time, current_time, turnaround_time);

        current_time += processes[i].burst_time;
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    struct Process processes[] = {
        {1, 10, 3},
        {2, 6, 1},
        {3, 8, 4},
        {4, 7, 2}
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    priorityScheduling(processes, n);

    return 0;
}
