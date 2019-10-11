#include <stdio.h>

int search(int arr[], int n, int key){
	for(int i=0;i<n;i++)
		if(arr[i] == key)
			return i;
	return -1;
}

int find(int arr[], int s, int e, int key){
	for(int i=s;i<=e;i++)
		if(arr[i] == key)
			return i;
	return -1;
}

int max(int arr[], int n){
	int maxi=0,i;
	for(i=1;i<n;i++)
		if(arr[i]>arr[maxi])
			maxi = i;
	return i;
}

void fifo(int page[],int n,int slot[],int p){
	int fault = 0, hit = 0,i, j=0;
	for(i=0;i<n;i++){
		if(search(slot,p,page[i]) != -1)
			hit++;
		else{
			fault++;
			slot[j] = page[i];
			j = (j+1)%p;
		}
	}
	printf("Faults: %d\nHits: %d\n",fault,hit);
}

void optimal(int page[],int n,int slot[],int p){
	int fault = 0, hit = 0, i, id, j, maxi, k=0, ind;
	for(i=0;i<n;i++){
		maxi=0;
		if(search(slot,p,page[i]) != -1)
			hit++;
		else{
			fault++;
			for(j=0;j<p;j++){
			ind = find(page,i,n,slot[j]);
			if(ind>=maxi && ind!=-1)
				maxi = ind;
			}
			if(maxi!=-1)
				slot[maxi] = page[i];
			else
				slot[k++] = page[i];
			
		}
	}
	printf("Faults: %d\nHits: %d\n",fault,hit);
}


void lru(int page[],int n,int slot[],int p){
	int fault = 0, hit = 0,i, j=0, rec[p], ind;
	for(i=0;i<p;i++)
		rec[i] = 0;
	for(i=0;i<n;i++){
		ind = search(slot,p,page[i]);
		if(ind != -1)
			hit++;
		else{
			fault++;
			ind = max(rec,p);
			slot[ind] = page[i];
		}
		rec[ind] = 0;
		for (int j = 0; j < p; j++)
			rec[j]++;
	}
	printf("Faults: %d\nHits: %d\n",fault,hit);
}

void main(){
	int n, i, p;
	printf("Enter number of pages: ");
	scanf("%d",&n);
	int page[n];
	printf("Enter the pages: ");
	for(i=0;i<n;i++)
		scanf("%d",&page[i]);
	printf("Enter number of page slots: ");
	scanf("%d",&p);
	int slot[p];
	for(i=0;i<p;i++)
		slot[i] = -1;

	printf("\nFIFO:\n");
	fifo(page,n,slot,p);

	for(i=0;i<p;i++)
		slot[i] = -1;

	printf("\nOptimal\n");
	optimal(page,n,slot,p);

	for(i=0;i<p;i++)
		slot[i] = -1;

	printf("\nLRU\n");
	lru(page,n,slot,p);
	
}