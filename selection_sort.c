#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define N 10
#define MAX_ELEMENT_VALUE 50

#define SWAP(x, y) int tmp = x; x = y; y = tmp;

void Selection_sort(int[]);

int main(int argc,char** argv){
	
	int i,RawData[N];
	
	srand(time(NULL));
	
	printf("Raw Data:\n");
	for(i=0;i<N;i++){
		RawData[i] = rand() % MAX_ELEMENT_VALUE;
		printf("%d\t",RawData[i]);
	}
		
	Selection_sort(RawData);
	
	printf("\n\nSelection Sort:\n");
	for(i=0;i<N;i++){
		printf("%d\t",RawData[i]);
	}	

	return 0;
}

void Selection_sort(int arr[]) {
    int i,j;

	for (i = 0 ; i < N - 1 ; i++) {
		int min = i;
		for (j = i + 1; j < N; j++)
			if (arr[j] < arr[min]) min = j;
	   	SWAP(arr[min], arr[i]);
	}
}
