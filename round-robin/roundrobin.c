#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int tq=2;

void main(){
	int timer=0;
	int at[5]={0},bt[5]={2,6,1,3,8},bbt[5]={2,6,1,3,8};;
	int ct[5],tt[5],wt[5];
	int l=0,avg_tt=0,avg_wt=0;
	do{
		if(bt[l]!=0){
			if(bt[l]<=tq){
				timer=timer+bt[l];				
				bt[l]=0;
				printf("%d ",l+1);
				ct[l]=timer;
							
			}else{
				timer=timer+tq;				
				bt[l]=bt[l]-tq;			
			}
								
		}
	l=(l+1)%5;
	}while(timer<20);
	
	printf("\n");
	
	for(int j=0;j<5;j++){
		tt[j]=ct[j]-at[j];
		printf("%d ",tt[j]);
		avg_tt+=tt[j];	
	}
	
	printf("\nAvg tt=%d\n",avg_tt/5); 
	
	for(int j=0;j<5;j++){
		wt[j]=tt[j]-bbt[j];
		printf("%d ",wt[j]);
		avg_wt+=wt[j];	
	}
	
	printf("\nAvg wt=%d\n",avg_wt/5); 
}
