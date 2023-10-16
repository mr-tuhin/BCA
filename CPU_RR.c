#include <stdio.h>

struct Process {
    int pid; 
    int arrival_time;
    int burst_time;
    int remaining_time;
};

void roundRobin(struct Process processes[], int n, int time_quantum) {
    int current_time = 0;
    int total_waiting_time = 0;
    int remaining_processes = n;
    printf("Process\tAT\tBT\tTAT\tWT\n");
    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= current_time) {
                int execute_time = (processes[i].remaining_time < time_quantum) ? processes[i].remaining_time : time_quantum;
                current_time += execute_time;
                processes[i].remaining_time -= execute_time;

                if (processes[i].remaining_time == 0) {
                    remaining_processes--;
                    int waiting_time = current_time - processes[i].arrival_time - processes[i].burst_time;
                    total_waiting_time += waiting_time;
                    printf("P%d\t%d\t%d\t%d\t%d\n",processes[i].pid,processes[i].arrival_time,processes[i].burst_time,(current_time-processes[i].arrival_time),waiting_time);
                }
            }
        }
    }

    float average_waiting_time = (float)total_waiting_time / n;
    printf("Average Waiting Time: %.2f\n", average_waiting_time);
}

int main() {
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    roundRobin(processes, n, time_quantum);

    return 0;
}
