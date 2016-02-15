int solution(int X, int A[], int N) {
	// write your code in C99 (gcc 4.8.2)

	int flag[X];
	for (int idx=0; idx<X; idx++) {
		flag[idx] = 0;
	}

	// Find the total integer sum till X. This is the case when all the leaves
	// are in place.
	double expsum = (double)(X)*(X+1)/2;
	double sum = 0;
	int fidx;
	for (int idx=0; idx<N; idx++) {
		fidx = A[idx];
		if (flag[fidx] != -1) {
			flag[fidx] = -1;
			sum += A[idx];
		}
		if (sum == expsum) {
			return(idx);
		}
	}
	return(-1);

}
