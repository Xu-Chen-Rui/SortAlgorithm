#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define N 10
#define MAX_ELEMENT_VALUE 50

#define SWAP(x, y) int tmp = x; x = y; y = tmp;

void Heap_sort(int[],int);

int main(int argc,char** argv){
	
	int i,RawData[N];
	
	srand(time(NULL));
	
	printf("Raw Data:\n");
	for(i=0;i<N;i++){
		RawData[i] = rand() % MAX_ELEMENT_VALUE;
		printf("%d\t",RawData[i]);
	}
		
	Heap_sort(RawData,N);
	
	printf("\n\nHeap Sort:\n");
	for(i=0;i<N;i++){
		printf("%d\t",RawData[i]);
	}	

	return 0;
}

void max_heapify(int arr[], int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { 
        if (son + 1 <= end && arr[son] < arr[son + 1]) 
            son++;
        if (arr[dad] > arr[son]) 
            return;
        else { 
            SWAP(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void Heap_sort(int arr[], int len) {
    int i;
    for (i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);

    for (i = len - 1; i > 0; i--) {
        SWAP(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}
