#  CPU SCHEDULING
A CPU scheduling algorithm is a method used by an operating system to determine which process to execute next on the CPU. It manages the allocation of CPU time to processes, optimizing system performance by ensuring fair and efficient resource utilization.

1. FCFS Shaduling
2. Priority Shaduling
3. SJF Shaduling (primitive/non-primitive)
4. Round Robin Shaduling


## FCFS Shaduling

First-Come, First-Served (FCFS) CPU scheduling is a non-preemptive scheduling algorithm where processes are executed in the order they arrive in the ready queue.

### Algorithm:
```C
#include <stdio.h>

struct Process {
    char name[2];
    int arrivalTime;
    int burstTime;
    int waitingTime;
};

int main() {
    int numProcesses;
    struct Process processes[5];
    int currentTime = 0;
    float totalWaitingTime = 0;
    int tat=0;
    int wating;
    printf("Enter Number of Process: ");
    scanf("%d",&numProcesses);

    for (int i = 0; i < numProcesses; i++)
    {
        printf("Enter Process Name: ");
        scanf("%s",processes[i].name);
        printf("Enter Arrival Time: ");
        scanf("%d",&processes[i].arrivalTime);
        printf("Enter Burst Time: ");
        scanf("%d",&processes[i].burstTime);
    }
    
    printf("\nProcess\tAT\tBT\tTAT\tWT\n");
    for (int i = 0; i < numProcesses; i++)
    {
        int pos = i;
        for (int j = i+1; j < numProcesses; j++)
        {
            if (processes[pos].arrivalTime > processes[j].arrivalTime)
            {
                pos = j;
            }
            
        }

        struct Process tmp = processes[i];
        processes[i]=processes[pos];
        processes[pos]= tmp;

        // calculate  and print
        currentTime += processes[i].burstTime;
        tat=(currentTime - processes[i].arrivalTime);
        wating = (tat-processes[i].burstTime);
        totalWaitingTime += wating;

        printf("%s\t%d\t%d\t%d\t%d\n",processes[i].name, processes[i].arrivalTime, processes[i].burstTime,tat,wating);
    }
    
    float averageWaitingTime = totalWaitingTime / numProcesses;
    printf("\nAverage Waiting Time: %.2f\n", averageWaitingTime);

    return 0;
}
```
### Input:
```
Enter Number of Process: 3
Enter Process Name: p0
Enter Arrival Time: 0
Enter Burst Time: 9
Enter Process Name: p1
Enter Arrival Time: 1
Enter Burst Time: 4
Enter Process Name: p2
Enter Arrival Time: 2
Enter Burst Time: 9
```
### Output:
```
Process AT      BT      TAT     WT
p0      0       9       9       0
p1      1       4       12      8
p2      2       9       20      11

Average Waiting Time: 6.33
```
## Priority Shaduling 
Priority CPU Scheduling is an algorithm that assigns priority levels to processes, with lower values indicating higher priority, and schedules them based on their priority to optimize execution order.
## Algorithm
```C
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
```
## Output
```
ProcessBurst Time     Waiting Time   Turnaround Time
P2   6              0              6              
P4   7              6              13             
P1   10             13             23             
P3   8              23             31             

Average Waiting Time: 10.50
Average Turnaround Time: 18.25
```
## SJF Shaduling
Shortest Job First (SJF) CPU scheduling selects the process with the shortest burst time for execution, minimizing waiting time.

### Algorithm:(Mode=primitive)
```C
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
```
# Input
```
Enter the number of processes: 3
Enter burst times for each process:
Process 1: 9
Process 2: 4
Process 3: 9
```
# Output
```
Process Burst Time      Waiting Time    Turnaround Time
P1      9               4               13
P2      4               0               4
P3      9               13              22
Average Waiting Time: 5.67
Average Turnaround Time: 13.00
```

### Algorithm:(Mode=non-primitive)

```C
#include <stdio.h>

struct Process {
    char name[2];
    int arrivalTime;
    int burstTime;
    int waitingTime;
};

int main(int argc, char const *argv[])
{

    int numProcesses;
    struct Process processes[5];
    int currentTime = 0;
    float totalWaitingTime = 0;
    int tat=0;
    int wating;
    
    printf("Enter Number of Process: ");
    scanf("%d",&numProcesses);


    for (int i = 0; i < numProcesses; i++)
    {
        
        printf("Enter process name: ");
        scanf("%s",processes[i].name);
        printf("Enter AT and BT: ");
        scanf("%d %d",&processes[i].arrivalTime,&processes[i].burstTime);
    }

    printf("Process\tAT\tBT\tTAT\tWT\n");
    for (int i = 0; i < numProcesses; i++) 
    {
        for (int j  = i; j < numProcesses; j++)
        {
            if (((processes[i].arrivalTime+currentTime) >= processes[j].arrivalTime) && processes[i].burstTime > processes[j].burstTime)
            {
                struct Process tmp = processes[i];
                processes[i]=processes[j];
                processes[j]=tmp;
            }
            
        
        }
        currentTime += processes[i].burstTime;
        tat = currentTime - processes[i].arrivalTime;
        wating = tat - processes[i].burstTime;
        totalWaitingTime += wating;


        printf("%s\t%d\t%d\t%d\t%d\n",processes[i].name, processes[i].arrivalTime, processes[i].burstTime, tat, wating);
    }

    
    
    

    
    
    return 0;
}
```
### Input
```
Enter Number of Process: 3
Enter process name: p1
Enter AT and BT: 0 9
Enter process name: p2
Enter AT and BT: 0 4
Enter process name: p3
Enter AT and BT: 0 9
```
### Output
```
Process AT      BT      TAT     WT
p2      0       4       4       0
p1      0       9       13      4
p3      0       9       22      13
```

## Round Robin Shaduling (RR)
Round robin CPU scheduling is a time-sharing algorithm that allocates a fixed time quantum to each process in a circular manner.


### Algorithm:
```C
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
```

### Input
```
Enter the number of processes: 3
Enter the time quantum: 1
Enter arrival time for process P1: 0
Enter burst time for process P1: 9
Enter arrival time for process P2: 0
Enter burst time for process P2: 4
Enter arrival time for process P3: 0
Enter burst time for process P3: 9
```
### Output
```
Process AT      BT      TAT     WT
P2      0       4       11      7
P1      0       9       21      12
P3      0       9       22      13
Average Waiting Time: 10.67
```
# Memory Management
Memory allocation algorithms in operating systems manage how memory is assigned to processes, ensuring efficient utilization and allocation based on the system's requirements.


1. First Fit
2. Best Fit
3. Worst Fit

## First Fit
First Fit is a memory allocation algorithm in operating systems where the OS allocates the first available block of memory that is large enough to accommodate a process, which can lead to fragmentation.

### Algorithm:
```C
#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    int fragmentation = 0;  // Initialize fragmentation to zero

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                fragmentation += blockSize[j];  // Add remaining block size to fragmentation
                break;
            }
        }
    }

    printf("Process No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t\t%d\t\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d", allocation[i] + 1);
        } else {
            printf("Not Allocated");
        }
        printf("\n");
    }

    printf("Fragmentation: %d\n", fragmentation);
}

int main() {
    int m;
    int n;
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    m = sizeof(blockSize) / sizeof(blockSize[0]);
    n = sizeof(processSize) / sizeof(processSize[0]);

    firstFit(blockSize, m, processSize, n);

    return 0;
}
```
### Output:
```
Process No.     Process Size    Block no.
1                       212                     2
2                       417                     5
3                       112                     2
4                       426                     Not Allocated
Fragmentation: 647
```
### Best Fit
The Best Fit memory allocation algorithm in operating systems assigns the smallest available block of memory that can accommodate a process, minimizing wastage but potentially leading to memory fragmentation.

### Algorithm:
```C
#include <stdio.h>

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    int fragmentation = 0;

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[bestIdx] > blockSize[j]) {
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d", allocation[i] + 1);
        } else {
            printf("Not Allocated");
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        fragmentation += blockSize[i];
    }
    printf("Fragmentation: %d\n", fragmentation);
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    bestFit(blockSize, m, processSize, n);

    return 0;
}
```
### Output
```
Process No.     Process Size    Block no.
 1              212             5
 2              417             2
 3              112             5
 4              426             Not Allocated
Fragmentation: 959
```
### Worst Fit
Worst Fit is a memory allocation algorithm that selects the largest available memory block for a process, making it more prone to fragmentation and less efficient than other allocation methods like Best Fit or First Fit.

### Algorithm
```C
#include <stdio.h>

// Function to allocate memory to blocks as per the worst-fit algorithm
void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    int fragmentation = 0;

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int wstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (wstIdx == -1 || blockSize[wstIdx] < blockSize[j]) {
                    wstIdx = j;
                }
            }
        }

        if (wstIdx != -1) {
            allocation[i] = wstIdx;
            blockSize[wstIdx] -= processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d", allocation[i] + 1);
        } else {
            printf("Not Allocated");
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        fragmentation += blockSize[i];
    }
    printf("Fragmentation: %d\n", fragmentation);
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    worstFit(blockSize, m, processSize, n);

    return 0;
}
```
### Output:
```
Process No.     Process Size    Block no.
 1              212             5
 2              417             2
 3              112             5
 4              426             Not Allocated
Fragmentation: 959
```
# DISK SCHEDULING
Disk scheduling is a crucial component of operating systems, responsible for optimizing data access on storage devices. It involves deciding the order in which pending I/O requests are serviced to minimize seek time and improve overall system performance. Various disk scheduling algorithms, such as FCFS, SSTF, SCAN, C-SCAN, and LOOK, are used to manage this task efficiently.

1. FCFS
2. SSTF
3. SCAN
4. C-SCAN
5. LOOK
6. C-LOOK

### First-Come-First-Served
FCFS (First-Come, First-Served) is a disk scheduling algorithm that services I/O requests in the order they arrive, without considering seek time optimization.

### Algorithm:
```C
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
```
### Input
```
Enter the number of disk requests: 7
Enter the initial head position: 50
Enter the disk requests: 82
170
43
140
24
16
190
```
### Output
```C
Total head movement: 642
```
### Shortest Seek Time First 
Shortest Seek Time First (SSTF) is a disk scheduling algorithm that selects the I/O request with the closest track to the current position of the disk's read/write head, minimizing seek time.

### Algorithm:
```C
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
```
### Input
```
Enter the number of disk requests: 7
Enter the disk requests: 82 170 43 140 24 16 190
Enter the initial position: 50
```
### Output
```
SSTF Sequence: 50 -> 43 -> 24 -> 16 -> 82 -> 140 -> 170 -> 190
Total Seek Time: 208
```

### SCAN (Elevator)
SCAN (Elevator) is a disk scheduling algorithm that services I/O requests by moving the disk arm from one end to the other, scanning inwards or outwards, to minimize seek time.

###  Algorithm:
```C
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
```

### Output
```
Total number of seek operations = 149
```

### C-SCAN
C-SCAN (Circular SCAN) is a disk scheduling algorithm that services I/O requests in a circular fashion, only moving in one direction, enhancing throughput by reducing seek time.

### Algorithm:
```C
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
```
### Output
```
Total seek time: 190
```

### LOOK
LOOK is a disk scheduling algorithm that scans the disk in a specific direction to service pending I/O requests without going to the disk's end, reducing seek time.

### Algorithm:
```C
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
```
### Output
```
Move from 14 to 14
Move from 37 to 37
Move from 65 to 65
Move from 67 to 67
Move from 98 to 98
Move from 122 to 122
Move from 124 to 124
Move from 183 to 183
Total seek time: 208
```

### C-LOOK
C-LOOK is a disk scheduling algorithm that serves I/O requests in a circular manner, only in the direction of the requests, seeking to minimize seek time

### Algorithm:
```C
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

void clook(int requestQueue[], int head, int size, int disk_size) {
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
    
    seekTime += (disk_size - 1) - current;
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

    clook(requestQueue, head, size, disk_size);

    return 0;
}
```
### Output
```
Total seek time: 190
```
# Deadlock
Deadlock is a state in a computer system where multiple processes are unable to proceed because each is waiting for a resource held by another, creating a mutual blocking condition.
## Deadlock detection using the Resource Allocation Graph (RAG)
```C
#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int processes, resources;
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int max_claim[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];
bool finished[MAX_PROCESSES];

bool existsUnmarkedProcess() {
    for (int i = 0; i < processes; i++) {
        if (!finished[i]) {
            return true;
        }
    }
    return false;
}

bool detectDeadlock() {
    bool marked[MAX_PROCESSES];
    for (int i = 0; i < processes; i++) {
        marked[i] = false;
    }

    for (int i = 0; i < resources; i++) {
        available[i] = 0;
        for (int j = 0; j < processes; j++) {
            available[i] += allocation[j][i];
        }
        available[i] = available[i] == 0 ? 1 : available[i];
    }

    while (existsUnmarkedProcess()) {
        bool found = false;
        for (int i = 0; i < processes; i++) {
            if (!finished[i]) {
                bool safe = true;
                for (int j = 0; j < resources; j++) {
                    if (max_claim[i][j] - allocation[i][j] > available[j]) {
                        safe = false;
                        break;
                    }
                }

                if (safe) {
                    for (int j = 0; j < resources; j++) {
                        available[j] += allocation[i][j];
                    }
                    marked[i] = true;
                    finished[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            for (int i = 0; i < processes; i++) {
                if (!finished[i] && !marked[i]) {
                    printf("Deadlock detected with process %d.\n", i);
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    processes = 5;
    resources = 3;
    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int max_claim[MAX_PROCESSES][MAX_RESOURCES] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    if (!detectDeadlock()) {
        printf("No deadlock detected.\n");
    }

    return 0;
}
```
## Output
```
No deadlock detected.
```