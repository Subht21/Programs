vector<int> solution(vector<int> &A, int K) {
	// write your code in C++11 (g++ 4.8.2)

	int N = A.size();

	// Corner cases.
	if (N == 0 || N == 1)
		return A;

	int index2;
	vector<int> B;
	B.resize(N);

	K=K%N; // K can be grater than N.
	index2 = K;
	for (int index=0; index<N; index++) {
		B.at(index2) = A[index];
		index2 = (index2+1)%N;
	}
	return B;

}
