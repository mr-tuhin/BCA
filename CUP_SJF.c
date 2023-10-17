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
