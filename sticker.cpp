#include <iostream>
#include <algorithm>
using namespace std;

int D[2][100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		D[0][0] = 0;
		D[1][0] = 0;

		for (int i = 1; i <= N; i++)
			cin >> D[0][i];

		for (int i = 1; i <= N; i++)
			cin >> D[1][i];

		for (int i = 2; i <= N; i++) {
			D[0][i] = max(D[1][i - 1], D[1][i - 2]) + D[0][i];
			D[1][i] = max(D[0][i - 1], D[0][i - 2]) + D[1][i];
		}
		cout << max(D[0][N], D[1][N]) << '\n';
	}

	return 0;
}