#include <stdio.h>

void main() {
	int n,m,i,j;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	printf("Enter the number of resources: ");
	scanf("%d",&m);
	int allocation[n][m], max[n][m], need[n][m], available[m],t_instance[m], i_sum[m],safe = 1, seq[n],c, finish[n];
	printf("Enter the total number of instances for each of the resources: \n");
	for(i=0;i<m;i++){
		printf("Resource %c: ",'A'+i);
		scanf("%d",&t_instance[i]);
	}
	printf("Enter the allocation matrix: \n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&allocation[i][j]);
	printf("Enter the max matrix: \n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&max[i][j]);

	for(i=0;i<m;i++){
		i_sum[i] = 0;
		for(j=0;j<n;j++)
			i_sum[i] += allocation[j][i];
	}

	for(i=0;i<m;i++)
		available[i] = t_instance[i] - i_sum[i];

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			need[i][j] = max[i][j] - allocation[i][j];

	printf("Need matrix: \n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			printf("%d ",need[i][j]);
		printf("\n");
	}

	for(i=0;i<n;i++)
		finish[i] = 0;

	int k = 0, done = 0, time = 0;
	i = 0;

	while(!done){
		// printf("Available: \n");
		// for(int t=0;t<m;t++)
		// 	printf("%c: %d\n",'A'+t, available[t]);

		c = 1;
		for(j=0;j<m;j++){
			if(finish[i] || need[i][j]>available[j]){
				c = 0;
				break;
			}
		}
		if(c){
			seq[k++] = i;
			finish[i] = 1;
			for(int t=0;t<m;t++)
				available[t] += allocation[i][t];
		}

		if(k == n)
			done = 1;
		i = (i+1)%n;
		time++;

		if(time>m*n*n){
			printf("No safe state\n");
			safe = 0;
			break;
		}
	}

	if(safe){
		printf("Safe sequence: \n");
		for(i=0;i<n;i++)
			printf("P%d ",seq[i]);
	}

	char ch;
	int p,req[m];
	do{
		printf("Request? (y/n): ");
		scanf("%c",&ch);
		if(ch == 'y'){
			printf("Enter the process number: ");
			scanf("%d",&p);
			printf("Enter resource request: \n");
			for(i=0;i<m;i++)
				scanf("%d",&req[i]);
			
		}
	}while(ch == 'y')


	printf("\n");
}