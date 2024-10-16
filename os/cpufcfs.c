#include <stdio.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void fcfs(int at[],int bt[],int n)
{
    int p[n],wt[n],tat[n],ct[n];
    int i,j,temp=0;
    float ttat=0,twt=0;
    for(i=0;i<n;i++){
        p[i]=i;
    }
    for ( i = 0; i <n; i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(at[j]>at[j+1]){
                swap(&at[j+1],&at[j]);
                swap(&bt[j+1],&bt[j]);
                swap(&p[j+1],&p[j]);

            }
        }
    }
    for(i=0;i<n;i++){
        if (temp<at[i])
              temp=at[i];
        temp=temp+bt[i];
        ct[i]=temp;
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        ttat+=tat[i];
        twt+=wt[i];
    }
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("Avg TAT=%f\n",ttat/n);
    printf("Avg WT=%f",twt/n);
}
int main()
{
    int i,n;
    printf("enter no of process");
    scanf("%d",&n);
    int bt[n],at[n];
    for(i=0;i<n;i++)
    {
        printf("enter at and bt for each process %d:",i);
        scanf("%d",&at[i]);
        scanf("%d",&bt[i]);
    }
    fcfs(at,bt,n);
}