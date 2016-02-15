int solution(int A[], int N) {
	// write your code in C99 (gcc 4.8.2)
	int residue = 0;

	// Exor all the elements of array A. All the paired elements will zero out.
	// Unpaired element it the final exor value.
	for (int index = 0; index < N; index++) {
		residue ^= A[index];
	}

	return(residue);
}
