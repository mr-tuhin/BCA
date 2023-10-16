
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
