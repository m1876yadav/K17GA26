#include<stdio.h> 
int main() 
{ 
 
  int count,n,i,j,tq,remain,time,flag=0; 
  int wt=0, tt=0, at[10], rt[10], bt[10]; 
  printf("Enter Total Process:- "); 
  scanf("%d",&n); 
  remain=n; 
   printf("\n****************************************\n");
  printf("\n*ENTER DETAIL OF %d PROCESSES*\n\n",n);
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time For The Process %d:- ",count+1);
    scanf("%d",&at[count]); 
    printf("Enter Burst Time For The Process %d:- ",count+1);
    scanf("%d",&bt[count]); 
    rt[count]=bt[count]; 
    printf("\n");
  } 
  tq=2;
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=tq && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=tq; 
      time+=tq; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
	  printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
	  wt+=time-at[count]-bt[count]; 
      tt+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
     
  } 
  
   printf("\n*Average Waiting Time= %f\n",wt*1.0/n); 
  printf("*Avg Turnaround Time = %f",tt*1.0/n); 
  return 0;
}

