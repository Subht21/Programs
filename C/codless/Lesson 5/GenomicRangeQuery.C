int *AI;

struct Results solution(char *S, int P[], int Q[], int M) {
	struct Results result;
	// write your code in C99 (gcc 4.8.2)

	int slen = strlen(S);
	int IMA[4][slen];
	for (int nidx=0; nidx<4; nidx++)
		for (int sidx=0; sidx<slen; sidx++)
			IMA[nidx][sidx] = -1;

	// Pupulate IMA for A, C, G & T (first index 0, 1, 2 & 3 respectively) based
	// on the occurences of A, C, G & T in the input string.

	// For first element.
	switch (S[0]) {
	case 'A': IMA[0][0] = 0; break;
	case 'C': IMA[1][0] = 0; break;
	case 'G': IMA[2][0] = 0; break;
	case 'T': IMA[3][0] = 0; break;
	}

	for (int sidx=1; sidx<slen; sidx++) {
		switch (S[sidx]) {
		case 'A':
			IMA[0][sidx] = sidx;
			IMA[1][sidx] = IMA[1][sidx-1];
			IMA[2][sidx] = IMA[2][sidx-1];
			IMA[3][sidx] = IMA[3][sidx-1];
			break;
		case 'C':
			IMA[0][sidx] = IMA[0][sidx-1];
			IMA[1][sidx] = sidx;
			IMA[2][sidx] = IMA[2][sidx-1];
			IMA[3][sidx] = IMA[3][sidx-1];
			break;
		case 'G':
			IMA[0][sidx] = IMA[0][sidx-1];
			IMA[1][sidx] = IMA[1][sidx-1];
			IMA[2][sidx] = sidx;
			IMA[3][sidx] = IMA[3][sidx-1];
			break;
		case 'T':
			IMA[0][sidx] = IMA[0][sidx-1];
			IMA[1][sidx] = IMA[1][sidx-1];
			IMA[2][sidx] = IMA[2][sidx-1];
			IMA[3][sidx] = sidx;
			break;
		}
	}


	AI = malloc(sizeof(int)*M);
	// Now just find if IMA for Q is greater than P.
	for (int kidx=0; kidx<M; kidx++) {
		if (IMA[0][Q[kidx]] >= P[kidx])
			AI[kidx] = 1;
		else if (IMA[1][Q[kidx]] >= P[kidx])
			AI[kidx] = 2;
		else if (IMA[2][Q[kidx]] >= P[kidx])
			AI[kidx] = 3;
		else if (IMA[3][Q[kidx]] >= P[kidx])
			AI[kidx] = 4;
	}

	result.A = AI;
	result.M = M;
	return result;
}
