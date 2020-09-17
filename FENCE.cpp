#include <iostream>
#include <algorithm>
using namespace std;

// 30min
// �־��� O(N*N)��... ����Ǯ�̿� �������� ����
// Ǯ�̴� O(N log N)�� Ǯ����

int find_max_rect(int* fence, int l, int r) { // [l,r)
	if (l >= r) return 0;
	if (r - l == 1) return fence[l];
	int min_pos = min_element(fence + l, fence + r) - fence;
	int left_max = find_max_rect(fence, l, min_pos);
	int right_max = find_max_rect(fence, min_pos+1, r);
	int cross_max = (r - l) * fence[min_pos];
	int max_v = max(max(left_max, right_max), cross_max);
	return max_v;
}

int main() {
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int n; cin >> n;
		int fence[20010];
		for (int i = 0; i < n; i++) {
			cin >> fence[i];
		}
		int res = find_max_rect(fence, 0, n);
		cout << res << endl;
	}
	return 0;
}