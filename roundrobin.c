#include <stdio.h>

int main() {
    int n, tq;
    int at[20], bt[20], rt[20];
    int wt[20], tat[20];
    int time = 0, remain, i;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");

    while(remain != 0) {
        for(i = 0; i < n; i++) {

            if(rt[i] > 0 && at[i] <= time) {

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                }
                else {
                    time += rt[i];
                    wt[i] = time - at[i] - bt[i];
                    tat[i] = time - at[i];
                    rt[i] = 0;
                    remain--;

                    avg_wt += wt[i];
                    avg_tat += tat[i];

                    printf("P%d\t%d\t%d\t%d\t%d\n",
                           i+1, at[i], bt[i], wt[i], tat[i]);
                }
            }
        }
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
