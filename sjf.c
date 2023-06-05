#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	int n,bt[10],p[10],wt[10],ct[10],tat[10],at[10],sum=0,pos,i,j,temp;
	float avg_wt,avg_tat,total_wt=0,total_tat=0;
	
	printf("Enter number of processes:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter arrival time of P[%d]: ",i+1);
		scanf("%d",&at[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("\nEnter burst time of P%d: ",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	
	for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
            {
            	pos=j;
			}
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    
    for(i=0;i<n;i++)
    {
        sum=sum+bt[i];
        ct[i]=sum;
       
    }

 
    wt[0]=0;
    
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        
    }
    
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        
    }
	
	for(i=0;i<n;i++)
	{
		total_tat=total_tat+tat[i];
	}
	
	for(i=0;i<n;i++)
	{
		total_wt=total_wt+wt[i];
	}

	printf("\nProcess\t Arrival Time\t Burst Time\t Completion Time \tTurnaround Time\t\tWait Time");
    for(i=0;i<n;i++)
    {    
        printf("\np%d\t\t %d\t\t %d\t\t\t %d\t\t %d\t\t %d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
 	
 	avg_wt=total_wt/n;
    avg_tat=total_tat/n;     
    
    printf("\n\nAverage Waiting Time= %f",avg_wt);
    printf("\nAverage Turnaround Time= %f",avg_tat);
    
    return 0;
}