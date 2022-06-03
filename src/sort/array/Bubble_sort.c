//가장 뒤로 정렬 noflag case
#include <stdio.h>

void sort(int *A, int len){
	
	int i = 0, j = 0;
	
	for(i = 1; i<len; ++i){
		for(j = i-1; j<len-i; ++j)
		
			if(A[j]>A[j+1]){
				
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
	}
}


int main(){
	
	int A[] = {5,4,3,2,1};
	int len = sizeof(A)/sizeof(int);
	
	
	printf("%d\n", A[4]);
	sort(A, len);
	printf("%d\n", A[4]);
}
