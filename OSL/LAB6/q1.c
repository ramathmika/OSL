#include <stdio.h>

void main() {
	int n,i, bsum, completed, time, min=99999,min_ind, flag;
	
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int arrivalTime[n], burstTime[n],temp[n], FT[n], TAT[n], WT[n], qt;

	printf("Enter arrival times: \n");
	for(i=0;i<n;i++)
		scanf("%d",&arrivalTime[i]);
	printf("Enter burst times: \n");
	for(i=0;i<n;i++)
		scanf("%d",&burstTime[i]);
	printf("Enter quantum time: \n");
	scanf("%d",&qt);

	float awt=0,atat=0;

	printf("\nP\tAT\tBT\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\n",i+1,arrivalTime[i],burstTime[i]);
	}

	printf("--------------------------------------------\n");

	//First Come First Serve
	printf("\nFCFS: \n");
	FT[0] = burstTime[0];
	time = completed = i = 1;
	//printf("Time %d--Process %d started\n",0,1);
	printf("Time %d-- Process %d finished\n",FT[0], 1);

	while(completed != n){
		if(arrivalTime[i] <= FT[i-1]){
		//	printf("Time- %d-- Process %d started.\n",time,i+1);
			FT[i] = FT[i-1] + burstTime[i];
			time = FT[i];
			printf("Time %d-- Process %d finished\n",time, i+1);
			i = (i+1) % n;
			completed++;

		}
		else
			time++;
	}
	for(i=0;i<n;i++){
		TAT[i] = FT[i] - arrivalTime[i];
		atat += TAT[i];
		WT[i] = TAT[i] - burstTime[i];
		awt += WT[i];
	}
	awt /= n;
	atat /= n;

	// for(i=0;i<n;i++){
	// 	printf("Process %d started at %d and ended at %d\n",i+1, arrivalTime[i], FT[i]);
	// }

	// printf("\nFT\tTAT\tWT\n");
	// for(i=0;i<n;i++){
	// 	printf("%d\t%d\t%d\n",FT[i],TAT[i],WT[i]);
	// }
	printf("\nAverage waiting time: %f\nAverage Turn Around Time: %f\n",awt,atat);

	
	printf("--------------------------------------------\n");

	
	//Shortest Remaining Time First
	printf("\nSRTF:\n");
	awt = atat = completed = time = 0;

	for(i=0;i<n;i++){
		temp[i] = burstTime[i];
		FT[i] = 0;
	}
	
	flag = 0; 

	while(completed!=n){
		for(i=0;i<n;i++) {
			if(arrivalTime[i] <= time && temp[i] < min && temp[i]>0) {
				min = temp[i];
				min_ind = i;
				flag = 1;
			}
		}
		if(!flag){
			time++;
			continue;
		}

		//printf("Time- %d-- Process %d started.\n",time+1,min_ind+1);
		temp[min_ind]--;
		min = temp[min_ind];
		if(min==0)
			min = 9999999;
		if(temp[min_ind] == 0){
			completed++;
			flag = 0;
			FT[min_ind] = time+1;
			printf("Time %d-- Process %d finished\n",time+1, min_ind+1);
		}
		time++;
	}

	for(i=0;i<n;i++){
		TAT[i] = FT[i] - arrivalTime[i];
		atat += TAT[i];
		WT[i] = TAT[i] - burstTime[i];
		awt += WT[i];
	}
	awt /= n;
	atat /= n;


	// for(i=0;i<n;i++){
	// 	printf("Process %d started at %d and ended at %d\n",i+1, arrivalTime[i], FT[i]);
	// }

	// printf("\nFT\tTAT\tWT\n");
	// for(i=0;i<n;i++){
	// 	printf("%d\t%d\t%d\n",FT[i],TAT[i],WT[i]);
	// }
	printf("\nAverage waiting time: %f\nAverage Turn Around Time: %f\n",awt,atat);

	
	printf("--------------------------------------------\n");

	
	//Round Robin
	printf("\nRound Robin:\n");
	completed = time = awt = atat = 0;

	for(i=0;i<n;i++){
		temp[i] = burstTime[i];
		FT[i] = 0;
	}
	i = 0;
	while(completed!=n){
		//printf("Time- %d-- Process %d started.\n",time,i);
		temp[i] -= qt;
		if(temp[i]<=0){
			if(FT[i] == 0){
				FT[i] = time + qt + temp[i];
				time = FT[i];
				completed++;
				printf("Time %d-- Process %d finished\n",time, i+1);
			}
		} 
		else{
			bsum -= qt;
			time += qt;
		}

		// if(arrivalTime[(i+1)%n] >= time)
		// 	i = (i+1) % n;
		
	}
	for(i=0;i<n;i++){
		TAT[i] = FT[i] - arrivalTime[i];
		atat += TAT[i];
		WT[i] = TAT[i] - burstTime[i];
		awt += WT[i];
	}
	awt /= n;
	atat /= n;

	// printf("\nFT\tTAT\tWT\n");
	// for(i=0;i<n;i++){
	// 	printf("%d\t%d\t%d\n",FT[i],TAT[i],WT[i]);
	// }

	// for(i=0;i<n;i++){
	// 	printf("Process %d started at %d and ended at %d\n",i+1, arrivalTime[i], FT[i]);
	// }


	printf("\nAverage waiting time: %f\nAverage Turn Around Time: %f\n\n",awt,atat);


}