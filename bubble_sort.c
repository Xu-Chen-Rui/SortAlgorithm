#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define N 10
#define MAX_ELEMENT_VALUE 50

void Bubble_sort(int[]);

int main(int argc,char** argv){
	
	int i,RawData[N];
	
	srand(time(NULL));
	
	printf("Raw Data:\n");
	for(i=0;i<N;i++){
		RawData[i] = rand() % MAX_ELEMENT_VALUE;
		printf("%d\t",RawData[i]);
	}
		
	Bubble_sort(RawData);
	
	printf("\n\nBubble Sort:\n");
	for(i=0;i<N;i++){
		printf("%d\t",RawData[i]);
	}	

	return 0;
}

void Bubble_sort(int arr[]){
	
	int i,j,tmp;
	
	for(i=0; i < N-1; i++){
		for(j=0; j < N-i-1; j++){
			if(arr[j] > arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;	
			}
		}
	}
}
