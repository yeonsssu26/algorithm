#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int n, m, ans = INT_MAX;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

vector<vector<char>> mat; // ����
vector<pair<int, int>> coin; // ���� ��ǥ

bool out_of_board(int x, int y) { // ���� ������ ������ ���������� Ȯ��
	if (x < 0 || y < 0 || x >= m || y >= n) return true; // ��
	else return false; // ��
}

void move(int x1, int y1, int x2, int y2, int cnt, int dirc) { // dirc : ���⺤���� �ε���
	if (ans < cnt) { // ������ Ƚ������ �� ���� ��ư�� ������ �ʿ����
		return;
	}
	if (cnt > 10) {

		//���ؾȵ�
		//ans = min(ans, cnt); // Ƚ���� 10���� �Ѿ��µ� �� ��������?

		return;
	}

	int nx1 = x1 + dx[dirc];
	int ny1 = y1 + dy[dirc];
	int nx2 = x2 + dx[dirc];
	int ny2 = y2 + dy[dirc];

	if (out_of_board(nx1, ny1) && out_of_board(nx2, ny2)) { // �� ���� ��� �������ٸ� 
		return; // ����
	}
	else if (out_of_board(nx1, ny1) && !out_of_board(nx2, ny2)) { // 1�� ������ �������ٸ�
		ans = min(ans, cnt); // ����
		return; // ����
	}
	else if (!out_of_board(nx1, ny1) && out_of_board(nx2, ny2)) { // 2�� ������ �������ٸ�
		ans = min(ans, cnt); // ����
		return; // ����
	}


	// ������ ���� ���� ��� ������ ������ �� ����
	// ���ؾȵ� : if���� 2�� �δ� �� �ƴ϶� ||�� ó���ؾ� �ϴ� �� �ƴ�?
	//if (mat[nx1][ny1] == '#') {
	//	nx1 = x1; ny1 = y1; // rollback
	//}
	//if (mat[nx2][ny2] == '#') {
	//	nx2 = x2; ny2 = y2; // rollback
	//}
	if (mat[nx1][ny1] == '#' || mat[nx2][ny2] == '#') {
		nx1 = x1; ny1 = y1; // rollback
		nx2 = x2; ny2 = y2; // rollback
	}

	// ���� ����������� �̵�
	for (int i = 0; i < 4; i++) {
		move(nx1, ny1, nx2, ny2, cnt + 1, i);
	}

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		vector<char> row;
		for (int j = 0; j < m; j++) {
			char cell; cin >> cell; row.push_back(cell);

			if (cell == 'o') { // ���� ��ǥ
				coin.push_back(make_pair(i, j));
			}
		}
		mat.push_back(row);
	}

	for (int i = 0; i < 4; i++) { // �������� 4����
		// ������ǥ ����
		int x1 = coin[0].first;
		int y1 = coin[0].second;
		int x2 = coin[1].first;
		int y2 = coin[1].second;

		// �̵�
		move(x1, y1, x2, y2, 1, i);
	}

	// result
	if (ans > 10) ans = -1;
	cout << ans;

	return 0;
}

// ref : https://yabmoons.tistory.com/61