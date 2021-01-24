#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int n, startScore = 0, linkScore = 0, diff = INT_MAX; // 인원수, 스타트팀 점수, 링크팀 점수, 점수차
vector<vector<int>> mat; // 2차원 행렬 (Sij)
vector<bool> visited; // 스타트팀으로 선택된 팀원

void DFS(int curr, int cnt);

int main() {
	cin >> n; // 인원수 입력

	for (int i = 0; i < n; i++) { // 2차원 행렬 입력
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

void DFS(int curr, int cnt) { // curr번 선수를 스타트팀을 뽑는다, cnt : 뽑은 명수

	if (cnt == n / 2) { // n/2명을 스타트팀으로 뽑았으면 각팀의 점수차를 계산

		vector<int> start, link; // 스타트팀 팀원, 링크팀 팀원

		for (int i = 0; i < n; i++) { // 각팀에 팀원 삽입
			if (visited[i]) start.push_back(i);
			else link.push_back(i);
		}

		for (int i = 0; i < start.size(); i++) { // 스타트팀 총점
			for (int j = 0; j < start.size(); j++) {
				if (start[i] != start[j]) {
					startScore += mat[start[i]][start[j]];
				}
			}
		}

		for (int i = 0; i < link.size(); i++) { // 링크팀 총점
			for (int j = 0; j < link.size(); j++) {
				if (link[i] != link[j]) {
					linkScore += mat[link[i]][link[j]];
				}
			}
		}

		int res = abs(startScore - linkScore); // 점수차 (절댓값)
		diff = min(diff, res); // 작은 값으로 갱신
	}

	for (int i = curr + 1; i < n; i++) { // 스타트팀 팀원 정하기 // 왜 curr "+1"하지????
		if (!visited[i]) {
			visited[i] = true;
			DFS(i, cnt + 1);
			visited[i] = false;
		}
	}
}