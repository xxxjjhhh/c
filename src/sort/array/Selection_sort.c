#include <stdio.h>

void sort(int *A, int len){
	
	int i = 0, j = 0;
	
	for(i = 0; i<len; ++i){
		for(j = i+1; j<len; ++j)
		
			if(A[i]>A[j]){
				
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
	}
}


int main(){
	
	int A[] = {5,4,3,2,1};
	int len = sizeof(A)/sizeof(int);
	
	
	printf("%d\n", A[0]);
	sort(A, len);
	printf("%d\n", A[0]);
}
