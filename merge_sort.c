#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define N 10
#define MAX_ELEMENT_VALUE 50

void Merge_sort(int[],int);
void Merge_sort_recursive(int[], int[], int, int);

int main(int argc,char** argv){
	
	int i,RawData[N];
	
	srand(time(NULL));
	
	printf("Raw Data:\n");
	for(i=0;i<N;i++){
		RawData[i] = rand() % MAX_ELEMENT_VALUE;
		printf("%d\t",RawData[i]);
	}
		
	Merge_sort(RawData,N);
	
	printf("\n\nMegre Sort:\n");
	for(i=0;i<N;i++){
		printf("%d\t",RawData[i]);
	}	

	return 0;
}

void Merge_sort_recursive(int arr[], int reg[], int start, int end) {
    
	if (start >= end) return;
    
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    
    Merge_sort_recursive(arr, reg, start1, end1);
    Merge_sort_recursive(arr, reg, start2, end2);
    
	int k = start;
    
	while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    
	while (start1 <= end1)
        reg[k++] = arr[start1++];
    
	while (start2 <= end2)
        reg[k++] = arr[start2++];
    
	for (k = start; k <= end; k++)
        arr[k] = reg[k];
}

void Merge_sort(int arr[], const int len) {
    int reg[len];
    Merge_sort_recursive(arr, reg, 0, len - 1);
}
