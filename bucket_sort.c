#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MAX_ELEMENT_VALUE 50

void Bucket_sort(int[]);

int main(int argc,char** argv){

	int i,RawData[N];

	srand(time(NULL));

	printf("Raw Data:\n");
	for(i=0;i<N;i++){
		RawData[i] = rand() % MAX_ELEMENT_VALUE;
		printf("%d\t",RawData[i]);
	}

	Bucket_sort(RawData);

	printf("\n\nBucket Sort:\n");
	for(i=0;i<N;i++){
		printf("%d\t",RawData[i]);
	}

	return 0;
}

void Bucket_sort(int arr[]){

	int i,j,count[MAX_ELEMENT_VALUE]={0};

	for(i=0;i<N;i++){
		count[arr[i]]++;
	}
	for(i=0, j=0; i < MAX_ELEMENT_VALUE; i++){
		for(; count[i]>0; count[i]--){
			arr[j++] = i;
		}
	}
}
