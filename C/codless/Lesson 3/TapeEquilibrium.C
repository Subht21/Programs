int solution(int A[], int N) {
	// write your code in C99 (gcc 4.8.2)

	int sp1, sp2;

	// P ranges between 1 to N-1
	// Initial values.
	sp1=A[0];
	sp2=0;
	for (int idx=1; idx<N; idx++) {
		sp2+=A[idx];
	}

	int diff;
	diff = ((sp1-sp2)<0) ? (sp2-sp1) : (sp1-sp2);

	int tmpdiff;
	for (int pidx=1; pidx<N-1; pidx++)
	{
		// Both the parts are non empty so 0<pidx<N-1.
		sp1 += A[pidx]; sp2 -= A[pidx];
		tmpdiff = ((sp1-sp2)<0) ? (sp2-sp1):(sp1-sp2);

		if (tmpdiff<diff) diff = tmpdiff;
	}

	return(diff);
}
