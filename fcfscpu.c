#include<stdio.h>

struct process{
    int id;
    int complTime;
    int waitingTime;
    int arrTime;
    int burstTime;
    int turnarndTime;
}p[10],temp;

int main(){
    int i,n,j;
    printf("\nEnter the no:of processes:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\nEnter the arrival time & burst time of Process[%d]:",i);
        scanf("%d%d",&p[i].arrTime,&p[i].burstTime);
        p[i].id=i;
    }

    //sorting the process 
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(p[j].arrTime > p[j+1].arrTime){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    int com=0,totWaiting=0,totTurnaround=0;
    for(i=0;i<n;i++){
         if(com<p[i].arrTime){
            com=p[i].arrTime;
        }
        p[i].complTime=com+p[i].burstTime;
        com=p[i].complTime;
        p[i].turnarndTime=p[i].complTime-p[i].arrTime;
        p[i].waitingTime=p[i].turnarndTime-p[i].burstTime;
        totWaiting+=p[i].waitingTime;
        totTurnaround+=p[i].turnarndTime;
    }
    printf("\n\n--------------------\n");
    printf("Process\tCompletion\tWaiting\tTurnAround\n");
    for ( i = 0; i <n; i++)
    {
        printf("%d\t%d\t\t%d\t%d\n",p[i].id,p[i].complTime,p[i].waitingTime,p[i].turnarndTime);
    }
    float avgwt=(float)totWaiting/n;
    float avgtrn=(float)totTurnaround/n;
    printf("Avg waiting time=%f",avgwt);
        printf("Avg Turn around time=%f",avgtrn);
}