#include <iostream>
using namespace std;

int N, K;
int A[100];
int D[10000];	//K원 만드는 경우의 수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	D[0] = 1;	//동전을 사용하지 않는 경우
	for (int i = 1; i <= N; i++) {
		for (int j = A[i]; j <= K; j++)
			D[j] = D[j] + D[j - A[i]];
	}

	cout << D[K] << '\n';
	return 0;
}