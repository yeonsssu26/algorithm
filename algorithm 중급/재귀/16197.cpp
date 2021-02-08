#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int n, m, ans = INT_MAX;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

vector<vector<char>> mat; // 보드
vector<pair<int, int>> coin; // 동전 좌표

bool out_of_board(int x, int y) { // 보드 밖으로 동전이 떨어졌는지 확인
	if (x < 0 || y < 0 || x >= m || y >= n) return true; // 밖
	else return false; // 안
}

void move(int x1, int y1, int x2, int y2, int cnt, int dirc) { // dirc : 방향벡터의 인덱스
	if (ans < cnt) { // 기존의 횟수보다 더 많이 버튼을 누르면 필요없음
		return;
	}
	if (cnt > 10) {

		//이해안됨
		//ans = min(ans, cnt); // 횟수가 10번이 넘었는데 왜 갱신하지?

		return;
	}

	int nx1 = x1 + dx[dirc];
	int ny1 = y1 + dy[dirc];
	int nx2 = x2 + dx[dirc];
	int ny2 = y2 + dy[dirc];

	if (out_of_board(nx1, ny1) && out_of_board(nx2, ny2)) { // 두 동전 모두 떨어졌다면 
		return; // 종료
	}
	else if (out_of_board(nx1, ny1) && !out_of_board(nx2, ny2)) { // 1번 동전만 떨어졌다면
		ans = min(ans, cnt); // 갱신
		return; // 종료
	}
	else if (!out_of_board(nx1, ny1) && out_of_board(nx2, ny2)) { // 2번 동전만 떨어졌다면
		ans = min(ans, cnt); // 갱신
		return; // 종료
	}


	// 동전이 벽에 막힌 경우 동전은 움직일 수 없다
	// 이해안됨 : if문을 2개 두는 게 아니라 ||로 처리해야 하는 거 아님?
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

	// 다음 진행방향으로 이동
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

			if (cell == 'o') { // 동전 좌표
				coin.push_back(make_pair(i, j));
			}
		}
		mat.push_back(row);
	}

	for (int i = 0; i < 4; i++) { // 동서남북 4방향
		// 동전좌표 대입
		int x1 = coin[0].first;
		int y1 = coin[0].second;
		int x2 = coin[1].first;
		int y2 = coin[1].second;

		// 이동
		move(x1, y1, x2, y2, 1, i);
	}

	// result
	if (ans > 10) ans = -1;
	cout << ans;

	return 0;
}

// ref : https://yabmoons.tistory.com/61