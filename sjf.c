#include <stdio.h>
#include <string.h>

struct process
{
    char pid[10];
    int at, bt;
    int wt, tat;
    int completed;
};

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for(int i=0;i<n;i++)
    {
        scanf("%s %d %d", p[i].pid, &p[i].at, &p[i].bt);
        p[i].completed = 0;
    }

    int completed = 0, time = 0;
    float total_wt = 0, total_tat = 0;

    while(completed < n)
    {
        int idx = -1;
        int min_bt = 9999;

        for(int i=0;i<n;i++)
        {
            if(p[i].at <= time && p[i].completed == 0)
            {
                if(p[i].bt < min_bt)
                {
                    min_bt = p[i].bt;
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            time += p[idx].bt;

            p[idx].tat = time - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            p[idx].completed = 1;
            completed++;

            total_wt += p[idx].wt;
            total_tat += p[idx].tat;
        }
        else
        {
            time++;
        }
    }

    printf("\nWaiting Time:\n");
    for(int i=0;i<n;i++)
    printf("%s %d\n", p[i].pid, p[i].wt);

    printf("\nTurnaround Time:\n");
    for(int i=0;i<n;i++)
    printf("%s %d\n", p[i].pid, p[i].tat);

    printf("\nAverage Waiting Time: %.2f", total_wt/n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat/n);

    return 0;
}
