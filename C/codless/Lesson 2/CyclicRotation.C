int *AI;

struct Results solution(int A[], int N, int K) {
	struct Results result;
	// write your code in C99 (gcc 4.8.2)

	// Corner cases.
	if (N == 0 || N == 1) {
		result.A = A;
		result.N = N;

		return(result);
	}

	int index2;
	AI = malloc(N*sizeof(int));

	K=K%N; // K can be grater than N.
	index2 = K;
	for (int index=0; index<N; index++) {
		AI[index2] = A[index];
		index2 = (index2+1)%N;
	}

	result.A = AI;
	result.N = N;

	return result;
}
