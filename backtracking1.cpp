#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> V;
bool visited[10];
int A[10];

void Backtracking(int level)
{
	if (level == M) {
		for (int i = 0; i < M; i++) {
			cout << A[i] << " ";
		}
		cout << '\n';
		return;
	}

	int dif = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[i] && V[i] != dif) {
			A[level] = V[i];
			dif = A[level];
			visited[i] = true;
			Backtracking(level + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	V.resize(N);
	for (int i = 0; i < N; i++)
		cin >> V[i];

	sort(V.begin(), V.end());
	Backtracking(0);
	return 0;
}