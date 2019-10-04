# include <stdio.h>

int m , n;

int CanStart(int a[],int b[])
{
	for (int i = 0; i < m; ++i)
		if(a[i] > b[i])	return 0;
	return 1;
}

void Release(int a[],int b[])
{
	for (int i = 0; i < m; ++i)
		b[i] += a[i];
}

int Done(int a[])
{
	for (int i = 0; i < n; ++i)
		if(a[i] == 0)	return 0;
	return 1;
}

void DetectionAlgorithm(int available[],int allocated[][m],int request[][m])
{
	int work[m],finish[n];

	for(int i = 0;i < m; ++i)
		work[i] = available[i];
	
	for (int i = 0; i < n; ++i)
		finish[i] = 0;

	int counter = 0;
	for (int i = 0;Done(finish) == 0 && counter < n; i = (i+1)%n)
	{
		if(finish[i] == 0 && CanStart(request[i],work) == 1)
		{
			Release(allocated[i],work);
			finish[i] = 1;
		}
		else 
			counter++;
	}
	if(Done(finish) == 0)
		printf("System in deadlock.\n");
	else
		printf("System safe.\n");
}

void main()
{
	printf("Enter no. of processes:\n");	scanf("%d",&n);
	printf("Enter no. of resources:\n");	scanf("%d",&m);
	
	int available[m];
	int allocated[n][m];
	int request[n][m];
	

	printf("Enter no. of instances:\n");
	for (int i = 0; i < m; ++i)
		scanf("%d",&available[i]);

	printf("Enter allocated:\n");
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d",&allocated[i][j]);

	printf("Enter Request:\n");
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d",&request[i][j]);

	DetectionAlgorithm(available,allocated,request);
}