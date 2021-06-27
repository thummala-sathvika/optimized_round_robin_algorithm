#include <stdio.h>
 #include<stdio.h>
#include<unistd.h>
void clrscr()
{
system("@cls||clear");
}
struct proc
{
int id,bt,rem,wait,priority,arrivaltime,turnaround,optord;
};
void sort(struct proc p[],int n)
{
int i=0,j=0;
struct proc temp;
for (i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
if ( p[j].optord<p[i].optord)
{
temp=p[j];
p[j]=p[i];
p[i]=temp;
}}
}
void compalgo(int n,struct proc sev[],int quant)
{
int i,total=0,count=n,low=30000;
float avgtat=0,avgwait=0;
for(i=0;i<n;i++)
{
if(sev[i].arrivaltime<low)
{
low=sev[i].arrivaltime;
}
}
total=low;
while(count)
  {
for (i=0;i<n;i++)
{
if(sev[i].arrivaltime<=total)
{
if (sev[i].rem!=0)
{
if (sev[i].rem-quant>0)
{
total=total+quant;
sev[i].rem=sev[i].rem-quant;
}
else
{
total=total+sev[i].rem;
sev[i].rem=0;
count--;
sev[i].turnaround=total-sev[i].arrivaltime;
sev[i].wait=total-sev[i].bt-sev[i].arrivaltime;
}}}}
}
for(int i=0;i<n;i++)
{
avgtat=avgtat+sev[i].turnaround;
avgwait= avgwait +sev[i].wait;
}
avgtat=avgtat/(1.0*n);
avgwait=avgwait/(1.0*n);
printf("\nThe average Turn Around Time of Round robin is : %f",avgtat);
printf("\nThe average Waiting Time of the Round Robin is : %f",avgwait);
for (i=0;i<n;i++)
{
sev[i].rem=sev[i].bt;
}
avgtat=0.0;
avgwait=0.0;
total=0;
count=n;
quant=0;
int flag=1;
  for(i=0;i<n;i++)
{
if(sev[i].arrivaltime<low)
{
low=sev[i].arrivaltime;
}
}
total=low;
quant=(sev[0].rem+sev[n-1].rem)/2;
while(count)
{
for (i=0;i<n;i++)
{
if (sev[i].arrivaltime<=total)
{
if (sev[i].rem!=0)
{
if (sev[i].rem-quant>0)
{
total=total+quant;
sev[i].rem=sev[i].rem-quant;
}
else
{
total=total+sev[i].rem;
sev[i].rem=0;
count--;
sev[i].turnaround=total-sev[i].arrivaltime;
sev[i].wait=total-sev[i].bt-sev[i].arrivaltime;
flag=1;
}}}}
}
for(int i=0;i<n;i++)
{
avgtat=avgtat+sev[i].turnaround;
avgwait= avgwait +sev[i].wait;
}
avgtat=avgtat/(1.0*n);
avgwait=avgwait/(1.0*n);
  printf("\nThe average Turn Around Time of Optimized Round robin is : %f",avgtat);
printf("\nThe average Waiting Time of the Optimized Round Robin is : %f",avgwait);
for (i=0;i<n;i++)
{
sev[i].rem=sev[i].bt;
}
}
int main()
{
 int n,i,choice=0,tquant;
 printf("\nEnter the number of processes you want to insert: ");
scanf("%d",&n);
clrscr();
struct proc process[n];
for (i=0;i<n;i++)
{
printf("\nEnter the arrival Time process P%d: ",i);
scanf("%d",&process[i].arrivaltime);
printf("\nEnter the Burst Time process P%d: ",i);
scanf("%d",&process[i].bt);
printf("\nEnter the priority of the process P%d: ",i);
scanf("%d",&process[i].priority);
process[i].rem=process[i].bt;
process[i].id=i;
process[i].wait=0;
process[i].turnaround=0;
process[i].optord=0.2*process[i].arrivaltime+0.3*process[i].bt+0.5*process[i].priority;
}
sort(process,n);
printf("\nEnter the time quantum for the round robin: ");
scanf("%d",&tquant);
clrscr();
compalgo(n,process,tquant);
return 0;
}
