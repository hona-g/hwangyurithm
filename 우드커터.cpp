// Lim Hwangyu
// http://codeforces.com/contest/545/problem/C

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int n; cin >> n;

	if (n <= 2) {
		cout << n << endl;
		return 0;
	}

	int prev_p, prev_h; cin >> prev_p >> prev_h;
	int p, h; cin >> p >> h;
	int next_p, next_h;
	int cnt = 2; // �糡�� ������ ������ (i=0, i=n-1)
	for (int i = 1; i < n-1; i++) {
		cin >> next_p >> next_h;
		if (p - prev_p > h) { // �������� �����߸��°� �����ϸ� �����߸���
			cnt++;
		}
		else if (next_p - p > h) { // ���������� �����߸��°� �����ϸ� �����߸���
			cnt++;
			p = p + h; // ���������� �������� ǥ��
		}
		prev_p = p;
		prev_h = h;
		p = next_p;
		h = next_h;
	}

	cout << cnt << endl;
	return 0;
}