#include <stdio.h>
#include <string.h>

int main() {

    int n;
    printf("");
    scanf("%d",&n);

    char pid[n][10];
    int at[n], bt[n], ct[n], tat[n], wt[n];
    int completed[n];

    for(int i=0;i<n;i++){
        completed[i]=0;
    }

    for(int i=0;i<n;i++){
        scanf("%s %d %d",pid[i],&at[i],&bt[i]);
    }

    int time=0;
    int done=0;

    while(done<n){

        int idx=-1;
        int minBT=100000;

        for(int i=0;i<n;i++){
            if(at[i]<=time && completed[i]==0){
                if(bt[i]<minBT){
                    minBT=bt[i];
                    idx=i;
                }
            }
        }

        if(idx!=-1){

            time+=bt[idx];
            ct[idx]=time;

            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];

            completed[idx]=1;
            done++;
        }
        else{
            time++;
        }
    }

    float avgWT=0, avgTAT=0;

    printf("Waiting Time:\n");
    for(int i=0;i<n;i++){
        printf("%s %d\n",pid[i],wt[i]);
        avgWT+=wt[i];
    }

    printf("Turnaround Time:\n");
    for(int i=0;i<n;i++){
        printf("%s %d\n",pid[i],tat[i]);
        avgTAT+=tat[i];
    }

    avgWT/=n;
    avgTAT/=n;

    printf("Average Waiting Time: %.2f\n",avgWT);
    printf("Average Turnaround Time: %.2f\n",avgTAT);

    return 0;
}