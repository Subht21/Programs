int solution(int A[], int B[], int N) {
	// write your code in C99 (gcc 4.8.2)

	// Stack of downstream fishes.
	int DFS[N];
	int dfsl = -1;

	int aliven = 0;

	for (int fn=0; fn<N; fn++) {

		if (B[fn] == 1) {
			// Push the downstream fish into the stack.
			DFS[++dfsl] = A[fn];
		} else {
			// This is an upstream fish.
			if(dfsl<0) { // Downstream fish stack is empty.
				aliven++;
			} else {
				int aif = 0;
				while(dfsl>=0) {
					if (DFS[dfsl] < A[fn]) {
						dfsl--;
						aif = 1;
					} else {
						// A[fn] is eaten and alive count doesn't increase.
						// Surviving fish is in the stack and later will be 
						// added to total survivor count.
						aif = 0;
						break;
					}
				}
				if(aif) {
					// A[fn] has survived.
					aliven++;
				}
			}
		}
	}

	return(aliven+dfsl+1);
}
