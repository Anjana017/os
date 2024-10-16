#include <stdio.h>

int q[100]; // Queue to store process IDs
int f = -1, r = -1; // Front and rear for the queue

// Function to insert a process into the queue
void insert(int n) {
    if (f == -1) f = 0; // Initialize front if it's the first element
    r = r + 1;
    q[r] = n;
}

// Function to delete a process from the queue
int delete() {
    int n = q[f];
    f = f + 1;
    return n;
}

int main() {
    int p, tq, n, i, t = 0; // `t` is the current time
    float twt = 0, ttat = 0; // Total waiting time and total turnaround time

    printf("\nEnter how many processes: ");
    scanf("%d", &n);

    int a[n][5], bt[10], exist[10] = {0}; // `a` stores process data; `bt` stores original burst times

    printf("\nEnter arrival time & burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process ID: ");
        scanf("%d", &a[i][0]); // Process ID

        printf("A.T of process %d: ", a[i][0]);
        scanf("%d", &a[i][1]); // Arrival Time

        printf("B.T of process %d: ", a[i][0]);
        scanf("%d", &a[i][2]); // Burst Time

        bt[i] = a[i][2]; // Store original burst time
    }

    printf("\nEnter time quantum: ");
    scanf("%d", &tq);

    insert(0); // Insert the first process
    exist[0] = 1; // Mark the first process as existing

    // Round Robin scheduling loop
    while (f <= r) {
        p = delete(); // Get the next process from the queue

        if (a[p][2] >= tq) { // If remaining burst time is greater than or equal to time quantum
            a[p][2] -= tq; // Decrease the burst time
            t += tq; // Increase the current time
        } else { // If remaining burst time is less than time quantum
            t += a[p][2]; // Add the remaining burst time to current time
            a[p][2] = 0; // Set burst time to 0 (process completed)
        }

        // Check for newly arrived processes and add them to the queue
        for (i = 0; i < n; i++) {
            if (exist[i] == 0 && a[i][1] <= t) { // If the process has arrived and is not in the queue
                insert(i); // Insert the process into the queue
                exist[i] = 1; // Mark it as existing
            }
        }

        // If the process is completed, calculate TAT and WT
        if (a[p][2] == 0) {
            a[p][4] = t - a[p][1]; // TAT = Completion time - Arrival time
            a[p][3] = a[p][4] - bt[p]; // WT = TAT - Original burst time

            ttat += a[p][4]; // Accumulate total TAT
            twt += a[p][3]; // Accumulate total WT
        } else {
            insert(p); // If process is not completed, re-insert it into the queue
        }
    }

    // Print process details
    printf("\nP.No.\tAT\tBT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", a[i][0], a[i][1], bt[i], a[i][4], a[i][3]);
    }

    // Print average TAT and WT
    printf("\nAverage Turnaround time = %.2f", ttat / n);
    printf("\nAverage Waiting time = %.2f\n", twt / n);

    return 0;
}
