#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define N 10
#define MAX_ELEMENT_VALUE 50
#define SWAP(x,y) {int tmp; tmp = x; x = y; y = tmp;} 

void Quick_sort(int[],int,int);

int main(int argc,char** argv){
	
	int i,RawData[N];
	
	srand(time(NULL));
	
	printf("Raw Data:\n");
	for(i=0;i<N;i++){
		RawData[i] = rand() % MAX_ELEMENT_VALUE;
		printf("%d\t",RawData[i]);
	}
		
	Quick_sort(RawData,0,N-1);
	
	printf("\n\nQuick Sort:\n");
	for(i=0;i<N;i++){
		printf("%d\t",RawData[i]);
	}	

	return 0;
}

int Partition(int list[], int left, int right) { 
    
	int i,j = left - 1; 

    for(i = left; i < right; i++) { 
        if(list[i] <= list[right]) { 
            j++; 
            SWAP(list[j], list[i]); 
        } 
    }
	 
    SWAP(list[j+1], list[right]); 
    
    return j+1; 
} 

void Quick_sort(int list[], int left, int right) { 
	if(left < right) { 
        int pivot = Partition(list, left, right); 
        Quick_sort(list, left, pivot-1); 
        Quick_sort(list, pivot+1, right); 
    }
} 
