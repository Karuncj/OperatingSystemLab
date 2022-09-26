#include<stdio.h>

struct process{
    int complTime;
    int waitingTime;
    int burstTime;
    int turnarndTime;
    int burstcopy;
    int id;
}p[10],temp;

int main(){
    int i,n,j,quanta=0,totBurst=0,complete=0;
    printf("\nEnter the no:of processes:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\nEnter the burst time of Process[%d]:",i);
        scanf("%d",&p[i].burstTime);
        totBurst+=p[i].burstTime;
        p[i].burstcopy=p[i].burstTime;
        p[i].id=i;
    }
    printf("\nEnter the Time quanta for Processes");
        scanf("%d",&quanta);

    int totWaiting=0,totTurnaround=0;
    while(complete<totBurst){
        for(i=0;i<n;i++){
             if(p[i].burstTime>0){
                  if(p[i].burstTime<=quanta){
                        complete=complete+p[i].burstTime;
                        p[i].burstTime=0;
                        p[i].turnarndTime=complete;
                         p[i].waitingTime=p[i].turnarndTime-p[i].burstcopy;
                    }
                    else{
                        complete=complete+quanta;
                         p[i].burstTime=p[i].burstTime-quanta;
                    }
            }
        }
    }
     for(i=0;i<n;i++){
        totTurnaround=totTurnaround+p[i].turnarndTime;
        totWaiting=totWaiting+p[i].waitingTime;
    }
    printf("\n\n--------------------\n");
    printf("Process\tCompletion\tWaiting\tTurnAround\n");
    for ( i = 0; i <n; i++)
    {
        printf("%d\t%d\t\t%d\t%d\n",i,p[i].complTime,p[i].waitingTime,p[i].turnarndTime);
    }
    float avgwt=(float)totWaiting/n;
    float avgtrn=(float)totTurnaround/n;
    printf("Avg waiting time=%f",avgwt);
        printf("Avg Turn around time=%f",avgtrn);
}