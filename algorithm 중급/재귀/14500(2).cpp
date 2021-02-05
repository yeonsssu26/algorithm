// DFS(���)�� ������

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; // ����, ����
int dx[4] = { 0,0,1,-1 }, dy[4] = { -1,1,0,0 }; // ���⺤��
vector<vector<int>> mat, visited;

int shape1(int y, int x, int depth) { // �Ǹ� ������ ��� // y : ����, x : ����
	int sum = 0;
	if (depth == 4) return mat[y][x];

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		 
		if (nx >= 0 && ny >= 0 && ny < n && nx < m && !visited[ny][nx]) {
			visited[ny][nx] = 1; // visit
			sum = max(sum, mat[y][x] + shape1(ny, nx, depth + 1));
			visited[ny][nx] = 0; // clear visit
		}
	}
	return sum;
}

int shape2(int y, int x) { // �� ���
	int sum = 0;
	if (y - 1 >= 0 && y + 1 < n && x + 1 < m) //��
		sum = max(sum, mat[y][x] + mat[y - 1][x] + mat[y + 1][x] + mat[y][x + 1]);
	if (y - 1 >= 0 && y + 1 < n && x + 1 < m) //��
		sum = max(sum, mat[y][x] + mat[y - 1][x + 1] + mat[y + 1][x + 1] + mat[y][x + 1]);
	if (y - 1 >= 0 && x - 1 >= 0 && x + 1 < m) //��
		sum = max(sum, mat[y - 1][x] + mat[y][x] + mat[y][x - 1] + mat[y][x + 1]);
	if (y + 1 < n && x - 1 >= 0 && x + 1 < m) //��
		sum = max(sum, mat[y][x] + mat[y][x - 1] + mat[y][x + 1] + mat[y + 1][x]);
	return sum;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		vector<int> row, v_init;
		for (int j = 0; j < m; j++) {
			int num; cin >> num;
			row.push_back(num);
			v_init.push_back(0);
		}
		mat.push_back(row);
		visited.push_back(v_init);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 1;

			ans = max(ans, shape1(i, j, 1)); // �� ��� ����
			ans = max(ans, shape2(i, j)); // �� ���

			visited[i][j] = 0; // ��Ʈ��ŷ
		}
	}

	cout << ans; // print result
	return 0;
}