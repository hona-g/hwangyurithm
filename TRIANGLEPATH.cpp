#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef vector<vector<int>> TRIANGLE;

// 19min
// *** ���� - ȣ��ɿ� �ΰ��� ������� ¥��
// 1. �Լ��� void�� �Ͽ� ������Ʈ�ϴ� ��� - 272ms
// 2. �Լ��� return int�� �Ͽ� ������Ʈ �ϴ� ��� - 52ms <- �̰� �³�!!!!!!!

// kakao intern 4�������� ��� �ؾߵ���? -> 1������ Ǯ������

/* // 1�� ���
void find_min_way(TRIANGLE& path, TRIANGLE& cache, int y = 0, int x = 0, int cost = 0) {
	if (y > path.size() - 1) return;
	
	int& ret = cache[y][x];
	int ncost = cost + path[y][x];

	if (ret > ncost) return;
	ret = ncost;

	find_min_way(path, cache, y + 1, x, ncost);
	find_min_way(path, cache, y + 1, x + 1, ncost);
}

int main() {
	int T; cin >> T;
	for (int test_num = 1; test_num <= T; test_num++) {
		int n; cin >> n;
		TRIANGLE path(n, vector<int>(n, 0));
		TRIANGLE cache(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)
				cin >> path[i][j];
		find_min_way(path, cache);

		int maxi = 0;
		for (int i = 0; i < n; i++) {
			int t = cache[n - 1][i];
			if (maxi < t) maxi = t;
		}

		cout << maxi << endl;
	}
	return 0;
}
*/

// 2�� ���
int find_min_way(TRIANGLE& path, TRIANGLE& cache, int y = 0, int x = 0) {
	int& ret = cache[y][x];
	if (ret > 0) return ret;
	if (y == path.size() - 1) return (ret=path[y][x]);

	int maxi = 0;
	int dm = find_min_way(path, cache, y + 1, x);
	int dr = find_min_way(path, cache, y + 1, x + 1);
	maxi = max(dm, dr);

	ret = path[y][x] + maxi;
	return ret;
}

int main() {
	int T; cin >> T;
	for (int test_num = 1; test_num <= T; test_num++) {
		int n; cin >> n;
		TRIANGLE path(n, vector<int>(n, 0));
		TRIANGLE cache(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)
				cin >> path[i][j];
		int ans = find_min_way(path, cache);
		cout << ans << endl;
	}
	return 0;
}