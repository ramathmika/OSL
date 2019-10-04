#include <stdio.h>

void firstFit(int memArr[], int procArr[], int mSize, int pSize) {
	int i, j, mTemp[mSize], mAllocated[mSize], pAllocated[pSize];


	for(i=0;i<mSize;i++){
		// mAllocated[i] = 0;
		pAllocated[i] = 0;
		mTemp[i] = memArr[i];
	}
	i = j = 0;

	for(;i<pSize;){
		if((procArr[i]<=mTemp[j])){
			printf("Process of memory %d given memory parition of %d\n",procArr[i], mTemp[j]);
			mAllocated[j] = pAllocated[i] = 1;
			mTemp[j] -= procArr[i];
			i++;
			j = 0;
		}
		else if(j == mSize-1)
			i++;
		else
			j = (j+1)%mSize;
	}

	for(i=0;i<pSize;i++)
		if(!pAllocated[i])
			printf("No memory allocated for process with memory %d\n", procArr[i]);
	
}


void bestFit(int memArr[], int procArr[], int mSize, int pSize) {
	int i, j, mTemp[mSize], min, mini, mAllocated[mSize], pAllocated[pSize], flag;

	for(i=0;i<mSize;i++){
		// mAllocated[i] = 0;
		pAllocated[i] = 0;
		mTemp[i] = memArr[i];
	}
	i = j = 0;

	for(;i<pSize;){
		flag = 0;
		min = 99999;
		for(j=0;j<mSize;j++)
			if((procArr[i]<=mTemp[j]) && (mTemp[j]<min)){
				flag = 1;
				mini = j;
				min = mTemp[j];
			}

		if(!flag)
			i++;

		else {
			printf("Process of memory %d given memory parition of %d\n",procArr[i], mTemp[mini]);
			mAllocated[mini] = pAllocated[i] = 1;
			mTemp[mini] -= procArr[i];
			i++;
		}
	}

	for(i=0;i<pSize;i++)
		if(!pAllocated[i])
			printf("No memory allocated for process with memory %d\n", procArr[i]);

}


void worstFit(int memArr[], int procArr[], int mSize, int pSize) {
	int i, j, mTemp[mSize], max, maxi, mAllocated[mSize], pAllocated[pSize], flag;

	for(i=0;i<mSize;i++){
		// mAllocated[i] = 0;
		pAllocated[i] = 0;
		mTemp[i] = memArr[i];
	}
	i = j = 0;

	for(;i<pSize;){
		flag = 0;
		max = 0;
		for(j=0;j<mSize;j++)
			if((procArr[i]<=mTemp[j]) && (mTemp[j]>max)){
				flag = 1;
				maxi = j;
				max = mTemp[j];
			}

		if(!flag)
			i++;

		else {
			printf("Process of memory %d given memory parition of %d\n",procArr[i], mTemp[maxi]);
			mAllocated[maxi] = pAllocated[i] = 1;
			mTemp[maxi] -= procArr[i];
			i++;
		}
	}

	for(i=0;i<pSize;i++)
		if(!pAllocated[i])
			printf("No memory allocated for process with memory %d\n", procArr[i]);

}


void main() {
	int mSize, pSize, i;
	printf("Enter the number of memory paritions: ");
	scanf("%d",&mSize);
	int memory[mSize];
	printf("Enter the size of each parition: ");
	for(i=0;i<mSize;i++)
		scanf("%d",&memory[i]);
	printf("Enter the number of memory processes: ");
	scanf("%d",&pSize);
	int process[pSize];
	printf("Enter the size of each process: ");
	for(i=0;i<pSize;i++)
		scanf("%d",&process[i]);

	printf("\n\nFirst fit: \n");
	firstFit(memory,process,mSize,pSize);

	printf("\nBest fit: \n");
	bestFit(memory,process,mSize,pSize);

	printf("\nWorst fit: \n");
	worstFit(memory,process,mSize,pSize);

	printf("\nBest fit makes efficient use of memory.\n\n");
}