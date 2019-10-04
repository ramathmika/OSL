#include <stdio.h>

void main() {
	int m;
	printf("Enter the number of segments: ");
	scanf("%d",&m);
	printf("Enter the limit and base address for each segment: \n");
	int segmentTable[m][2], i, j;
	for(i=0;i<m;i++){
		printf("Segment %d:\n", i);
		printf("Limit: ");
		scanf("%d",&segmentTable[i][0]);
		printf("Base address: ");
		scanf("%d",&segmentTable[i][1]);
	}

	int s,d, ch;
	do{
		printf("\nCalculate?: (0/1)");
		scanf("%d",&ch);
		if(ch==0)
			break;
		printf("\nEnter the logical address--segment-number, offset: ");
		scanf("%d %d",&s, &d);
		if(d<=segmentTable[s][0]){
			printf("Physical address is: %d\n",segmentTable[s][1]+d);
		}
		else{
			printf("Offset greater than limit.\n");
		}
	}while(ch!=0);
}