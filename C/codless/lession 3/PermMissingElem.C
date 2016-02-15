
int solution(int A[], int N) {
	// write your code in C99 (gcc 4.8.2)

	// Missing element is the sum(1...N+1) - sum(A).
	double sum=0;
	for (int idx=0; idx<N; idx++) {
		sum+=A[idx];
	}

	// Range is 1 to N+1;
	double expsum = (double)(N+1)*(double)(N+2)/(double)2;
	int missing_elem = (int) (expsum-sum);

	return(missing_elem);

}
