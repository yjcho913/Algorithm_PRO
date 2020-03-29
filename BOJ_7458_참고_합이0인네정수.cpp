/*
- 해시 함수 활용
- 기존 코드보다 약 4배 빠름
*/
#include <stdio.h>

const int MN = 4000;
const int KEY = 745;
const int MX = 1000000000;
const int SIZE = 20345677;
int A[MN], B[MN], C[MN], D[MN];
int hash[SIZE], sum[SIZE];

void insert(int x) {
	int t = x;
	x = (x + MX) % SIZE;
	while (hash[x] != MX && hash[x] != t)
		x = (x + KEY) % SIZE;
	hash[x] = t;
	sum[x]++;
}

int find(int x) {
	int t = x;
	x = (x + MX) % SIZE;
	while (hash[x] != MX && hash[x] != t)
		x = (x + KEY) % SIZE;

	if (hash[x] == MX) return 0;
	return sum[x];
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);

	for (int i = 0; i < SIZE; i++) hash[i] = MX;

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
			insert(A[i] + B[j]);
	}

	long long sol = 0;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
			sol += find(-(C[i] + D[j]));
	}

	printf("%lld", sol);

	return 0;
}