#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
bool visited[200001];	//방문 기록 여부
int T[200001];		//걸리는 시간

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;

	//초기화
	queue<int> q;
	visited[N] = true;
	T[N] = 0;
	q.push(N);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now - 1 >= 0) {
			if (visited[now - 1] == false) {
				q.push(now - 1);
				visited[now - 1] = true;
				T[now - 1] = T[now] + 1;
			}
		}

		if (now + 1 < 200000) {
			if (visited[now + 1] == false) {
				q.push(now + 1);
				visited[now + 1] = true;
				T[now + 1] = T[now] + 1;
			}
		}

		if (now * 2 < 200000) {
			if (visited[now * 2] == false) {
				q.push(now * 2);
				visited[now * 2] = true;
				T[now * 2] = T[now] + 1;
			}
		}
	}

	cout << T[K] << '\n';
	return 0;
}