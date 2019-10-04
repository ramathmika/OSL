#include <stdio.h>

void main() {
	int la, pg, pages, pSize;
	printf("Enter number of pages: ");
	scanf("%d",&pages);
	printf("Enter page size: ");
	scanf("%d",&pSize);
	printf("Enter the logical address: ");
	scanf("%d",&la);
	pg = (la/pSize) % pages;
	printf("Page number: %d\nOffset: %d\n",pg, (la%pSize));
}