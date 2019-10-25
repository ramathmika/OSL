#include <stdio.h>
#include <math.h>
#include <limits.h>

int findClosest(int arr[], int n, int key, int serviced[]){
	int mdiff = INT_MAX,mini,i;
	for(i=0;i<n;i++)
		if(arr[i]!=key && !serviced[i] && (abs(arr[i]-key)<mdiff)){
			mini = i;
			mdiff = abs(arr[i]-key);
		}
	return mini;
}

void sort(int temp[], int n){
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(temp[j]>temp[j+1]){
				int t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
}


void main(){
	int n,current,m,i,total,ind,pind;
	printf("Enter number of cylinders: ");
	scanf("%d",&n);
	printf("Enter drive's current cylinder location: ");
	scanf("%d",&current);
	printf("Enter size of queue: ");
	scanf("%d",&m);
	int queue[m];
	printf("Enter the queue: \n");
	for(i=0;i<m;i++)
		scanf("%d",&queue[i]);


	printf("\nFCFS\n");
	total = 0;
	total += abs(queue[0]-current);
	for(i=0;i<m-1;i++)
		total += abs(queue[i+1]-queue[i]);

	printf("Total head movement: %d\n",total);


	printf("\nSSTF\n");
	total = ind = 0;
	int temp[m],serviced[m];
	for(i=0;i<m;i++){
		temp[i] = queue[i];
		serviced[i] = 0;
	}

	pind = findClosest(temp,m,current,serviced);
	total += abs(current-temp[pind]);
	serviced[pind] = 1;
	for(i=0;i<m-1;i++){
		ind = findClosest(temp,m,temp[pind],serviced);
		total += abs(temp[pind]-temp[ind]);
		serviced[ind] = 1;
		pind = ind;
	}
	printf("Total head movement: %d\n",total);


	printf("\nSCAN\n");
	total = 0;
	sort(temp,m);
	int n1,n2;
	for(i=0;i<m;i++)
		if(temp[i]>current){
			n1 = i-1;
			n2 = i;
			break;
		}
		total += abs(temp[n1]-current);
		for(i=n1;i>0;i--)
			total += abs(temp[i]-temp[i-1]);
		total += temp[0] + temp[n2];
		for(i=n2;i<m-1;i++)
			total += abs(temp[i+1]-temp[i]);
	printf("Total head movement: %d\n",total);


	printf("\nCSCAN\n");
	total = 0;
	total += abs(temp[n2]-current);
	for(i=n2;i<m-1;i++)
		total += abs(temp[i+1]-temp[i]);
	total += abs(n-1-temp[m-1]) + n-1 + temp[0];
	for(i=0;i<n1;i++)
		total += abs(temp[i+1]-temp[i]);
	printf("Total head movement: %d\n",total);

}