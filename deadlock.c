#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int processes, resources;
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int max_claim[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];
bool finished[MAX_PROCESSES];

// Function to check if there is an unmarked process
bool existsUnmarkedProcess() {
    for (int i = 0; i < processes; i++) {
        if (!finished[i]) {
            return true;
        }
    }
    return false;
}

// Function to detect deadlock using the Resource Allocation Graph (RAG)
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
    // Initialize the number of processes and resources, allocation, and max_claim arrays
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
