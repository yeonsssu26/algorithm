#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int n, startScore = 0, linkScore = 0, diff = INT_MAX; // �ο���, ��ŸƮ�� ����, ��ũ�� ����, ������
vector<vector<int>> mat; // 2���� ��� (Sij)
vector<bool> visited; // ��ŸƮ������ ���õ� ����

void DFS(int curr, int cnt);

int main() {
	cin >> n; // �ο��� �Է�

	for (int i = 0; i < n; i++) { // 2���� ��� �Է�
		vector<int> row;
		for (int i = 0; i < n; i++) {
			int tmp; cin >> tmp; row.push_back(tmp);
		}
		mat.push_back(row);
		row.clear();
	}

	for (int i = 0; i < n; i++) visited.push_back(false);

	DFS(0, 0);
	cout << diff;

	return 0;
}

void DFS(int curr, int cnt) { // curr�� ������ ��ŸƮ���� �̴´�, cnt : ���� ���

	if (cnt == n / 2) { // n/2���� ��ŸƮ������ �̾����� ������ �������� ���

		vector<int> start, link; // ��ŸƮ�� ����, ��ũ�� ����

		for (int i = 0; i < n; i++) { // ������ ���� ����
			if (visited[i]) start.push_back(i);
			else link.push_back(i);
		}

		for (int i = 0; i < start.size(); i++) { // ��ŸƮ�� ����
			for (int j = 0; j < start.size(); j++) {
				if (start[i] != start[j]) {
					startScore += mat[start[i]][start[j]];
				}
			}
		}

		for (int i = 0; i < link.size(); i++) { // ��ũ�� ����
			for (int j = 0; j < link.size(); j++) {
				if (link[i] != link[j]) {
					linkScore += mat[link[i]][link[j]];
				}
			}
		}

		int res = abs(startScore - linkScore); // ������ (����)
		diff = min(diff, res); // ���� ������ ����
	}

	for (int i = curr + 1; i < n; i++) { // ��ŸƮ�� ���� ���ϱ� // �� curr "+1"����????
		if (!visited[i]) {
			visited[i] = true;
			DFS(i, cnt + 1);
			visited[i] = false;
		}
	}
}