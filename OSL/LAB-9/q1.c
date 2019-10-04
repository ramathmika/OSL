# include <stdio.h>

int m , n;

int CanStart(int a[],int b[])
{
	for (int i = 0; i < m; ++i)
		if(a[i] > b[i])	return 0;
	return 1;
}

void Release(int allocated[],int work[])
{
	for (int i = 0; i < m; ++i)
		work[i] += allocated[i];
}

int Done(int finish[]){
	for (int i = 0; i < n; ++i)
		if(finish[i] == 0)	return 0;
	return 1;
}

void Allocate(int available[],int request[],int allocated[],int need[])
{
	for (int i = 0; i < m; ++i)
	{
		available[i] -= request[i];
		allocated[i] += request[i];
		need[i] -=  request[i];
	}
}

int SafetyAlgo(int available[],int allocated[][m],int need[][m],int flag)
{
	int work[m],finish[n];

	for(int i = 0;i < m; ++i)
		work[i] = available[i];
	
	for (int i = 0; i < n; ++i)
		finish[i] = 0;

	int counter = 0;
	for (int i = 0;Done(finish) == 0 && counter < n; i = (i+1)%n)
	{
		if(finish[i] == 0 && CanStart(need[i],work) == 1)
		{
			if(flag == 0)
				printf("\n%d done.\n",i);
			finish[i] = 1;
			Release(allocated[i],work);
			counter = 0;
		}
		else 
			counter++;
	}
	if(Done(finish) == 0){
		if(flag == 0)
			printf("Not Safe state. %d\n",counter);
		else
			return -1;
	}
	return 1;
}


void ResRequest(int available[],int allocated[][m],int need[][m])
{
	int request[m];
	int i;
	printf("Enter process:\n");
	scanf("%d",&i);
	printf("Enter request:\n");
	for (int j = 0; j < m; ++j)
		scanf("%d",&request[j]); 
	if(CanStart(request,need[i]) == 1)
	{
		if(CanStart(request,available) == 1)
		{
			Allocate(available,request,allocated[i],need[i]);
			int t = SafetyAlgo(available,allocated,need,1);
			if(t == -1){
				for (int j = 0; j < m; ++j)
				{
					available[j] += request[j];
					allocated[i][j] -= request[j];
					need[i][j] +=  request[j];
				}
				printf("Resources cant be allocated immediately.\n");
			}
			else
				printf("Resources allocated.\n");
		}
		else
			printf("Request must wait as resources not available.\n");
	}
	else
		printf("Request larger than need.\n");
	

}


void main()
{
	printf("Enter no. of processes:\n");	scanf("%d",&n);
	printf("Enter no. of resources:\n");	scanf("%d",&m);
	
	int available[m];
	int max[n][m];
	int allocated[n][m];
	int need[n][m];
	

	printf("Enter no. of instances:\n");
	for (int i = 0; i < m; ++i)
		scanf("%d",&available[i]);

	printf("Enter MAX:\n");
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d",&max[i][j]);
	
	printf("Enter allocated:\n");
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d",&allocated[i][j]);

	for (int i = 0; i < n; ++i)
		for(int j = 0; j < m;++j){
			need[i][j] = max[i][j] - allocated[i][j];
			available[j] = available[j] - allocated[i][j];
		}
	

	printf("\n\nNEED MATRIX\n");
	for (int i = 0; i < n; ++i){
		for(int j = 0; j < m;++j)
			printf("%d\t",need[i][j]);
		printf("\n");
	}

	printf("\n\nSafety Algorithm.\n\n");
	int t = SafetyAlgo(available,allocated,need,0);

	printf("\n\nResource Allocation Algorithm.\n");
	for (int i = 0; i < 3; ++i)
		ResRequest(available,allocated,need);
}