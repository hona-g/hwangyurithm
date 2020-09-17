// ���� nCr ���� ���ؼ� �ѽð� ���
// �������� �� 45�� �ҿ�
// ���װ�� ���Ҷ� !!�Ľ�Į�ǻﰢ��!! �̿�����

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 2000000000

typedef long long int INT;

/*
*** �߸��� combination ���� (overflow) ***

INT combination(int big, int small) {
	INT res = 1;
	int b = big;
	for (int i = 1; i <= small; i++) {
		INT prev_res = res;
		res *= b;
		if (res < prev_res) return MAX; // check overflow
		b--;
		res /= i;
	}
	return res;
}
*/

INT comb[201][201];

void prev_calc() {
	for (int i = 0; i <= 200; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = min((INT)MAX, comb[i - 1][j - 1] + comb[i - 1][j]);
		}
	}
}

string solve(int n, int m, INT k) {
	string ret = "";
	if (n == 0) return string(m, 'o'); // "oooooo...(n��)"
	// if (m == 0) return string(n, '-'); // m==0�� �ȵ��´ٴ� ������ �ֳ�?

	INT skip = comb[n + m - 1][m];

	if (k >= skip) {
		return 'o' + solve(n, m - 1, k - skip);
	}
	else {
		return '-' + solve(n - 1, m, k);
	}
}

int main() {
	int T; cin >> T;
	prev_calc();

	for (int test_case = 1; test_case <= T; test_case++) {
		int n, m, k; cin >> n >> m >> k;
		cout << solve(n, m, (INT)k-1) << endl; 
	}

	return 0;
}

