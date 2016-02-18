// Solution to codility demo sample test.

int solution(int A[], int N) {
	// write your code in C99 (gcc 4.8.2)

	int eqi = -1;

	// Empty input array.
	if (N==0) return(eqi);

	double sum = 0;

	for (int idx=0; idx<N; idx++) {
		sum+=A[idx];
	}

	// For corner cases.
	if (sum-A[0] == 0) return(0);
	if (sum-A[N-1] == 0) return(N-1);

	double lsum, rsum;
	int pivot;
	lsum = 0; rsum = sum-A[0]; pivot = A[0];
	for (int idx=1; idx<N-1; idx++) {
		lsum += pivot;
		pivot = A[idx];
		rsum -= A[idx];

		if (lsum == rsum) {
			eqi = idx;
			break;
		}
	}

	return(eqi);
}
