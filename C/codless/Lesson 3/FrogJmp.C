int solution(int X, int Y, int D) {
	// write your code in C99 (gcc 4.8.2)

	int dist = Y-X;

	if (dist%D == 0) {
		return(dist/D);
	} else {
		return(1+dist/D);
	}

}
