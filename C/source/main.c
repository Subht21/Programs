
#include <stdio.h>
#include <math.h>

#include "utils.h"


int main ()
{
	int N=6;
	prime_factors(N);
	printf("\n");

	int A[] = {1, 3, 1, 4, 2, 3, 5, 4};
	bubble_sort(A, 8);
	for (int idx=0; idx<8; idx++) {
		printf("%d ", A[idx]);
	}
	printf("\n");

	merge_sort(A, 0, 7);
	for (int idx=0; idx<8; idx++) {
		printf("%d ", A[idx]);
	}

	return(1);
}

