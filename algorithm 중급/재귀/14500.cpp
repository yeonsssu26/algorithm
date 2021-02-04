// 재귀로 접근하지 않음

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> mat;
vector<int> s1, s2, s3, s4, s5;
vector<int> max_sum; // 각각의 max값을 저장

void sum1() { // ㅁㅁㅁㅁ (가로, 세로 둘 다 해야함)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m - 4; j++) {
			int sum = 0;
			for (int k = j; k < j + 4; k++) {
				sum += mat[i][k];
			}
			s1.push_back(sum);
		}
	}

	for (int i = 0; i <= n - 4; i++) {
		for (int j = 0; j < m; j++) {
			int sum = 0;
			for (int k = i; k < i + 4; k++) {
				sum += mat[k][j];
			}
			s1.push_back(sum);
		}
	}
}

void sum2() { // ㅁㅁ
			  // ㅁㅁ
	for (int i = 0; i <= n - 2; i++) {
		int sum = 0;
		for (int j = 0; j <= m - 2; j++) {
			sum = mat[i][j] + mat[i][j + 1] + mat[i + 1][j] + mat[i + 1][j + 1];
		}
		s2.push_back(sum);
	}
}

void sum3() { // ㅁㅁㅁ + ㅁ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m - 3; j++) {
			if (i == 0) {
				for (int k = 0; k < 3; k++) {
					int sum = 0;
					sum = mat[i][j] + mat[i][j + 1] + mat[i][j + 2] + mat[i + 1][j + k];
					s3.push_back(sum);
				}
			}
			else if (i == n - 1) {
				for (int k = 0; k < 3; k++) {
					int sum = 0;
					sum = mat[i][j] + mat[i][j + 1] + mat[i][j + 2] + mat[i - 1][j + k];
					s3.push_back(sum);
				}
			}
			else {
				for (int k = 0; k < 3; k++) {
					int sum = 0;
					sum = mat[i][j] + mat[i][j + 1] + mat[i][j + 2] + mat[i + 1][j + k];
					s3.push_back(sum);
				}

				for (int k = 0; k < 3; k++) {
					int sum = 0;
					sum = mat[i][j] + mat[i][j + 1] + mat[i][j + 2] + mat[i - 1][j + k];
					s3.push_back(sum);
				}
			}
		}
	}
}

void sum4() { // ㅁ
	          // ㅁ
	          // ㅁ + ㅁ
	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j < m; j++) {
			if (j == 0) {
				for (int k = 0; k < 3; k++) {
					int sum = 0;
					sum = mat[i][j] + mat[i + 1][j] + mat[i + 2][j] + mat[i + k][j + 1];
					s4.push_back(sum);
				}
			}
			else if (j == m - 1) {
				for (int k = 0; k < 3; k++) {
					int sum = 0;
					sum = mat[i][j] + mat[i + 1][j] + mat[i + 2][j] + mat[i + k][j - 1];
					s4.push_back(sum);
				}
			}
			else {
				for (int k = 0; k < 3; k++) {
					int sum = 0;
					sum = mat[i][j] + mat[i + 1][j] + mat[i + 2][j] + mat[i + k][j + 1];
					s4.push_back(sum);
				}

				for (int k = 0; k < 3; k++) {
					int sum = 0;
					sum = mat[i][j] + mat[i + 1][j] + mat[i + 2][j] + mat[i + k][j - 1];
					s4.push_back(sum);
				}
			}
		}
	}
}

void sum5() { // 지렁이 모양
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			int sum = 0;
			sum = mat[i - 1][j + 1] + mat[i][j] + mat[i][j + 1] + mat[i + 1][j];
			s5.push_back(sum);
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int sum = 0;
			sum = mat[i][j + 1] + mat[i][j + 2] + mat[i + 1][j] + mat[i + 1][j + 1];
			s5.push_back(sum);
		}
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int sum = 0;
			sum = mat[i][j] + mat[i + 1][j] + mat[i + 1][j + 1] + mat[i + 2][j + 1];
			s5.push_back(sum);
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int sum = 0;
			sum = mat[i][j] + mat[i][j + 1] + mat[i + 1][j + 1] + mat[i + 1][j + 2];
			s5.push_back(sum);
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		vector<int> row;
		for (int j = 0; j < m; j++) {
			int num; cin >> num; row.push_back(num);
		}
		mat.push_back(row);
	}

	sum1();
	max_sum.push_back(*max_element(s1.begin(), s1.end()));

	sum2();
	max_sum.push_back(*max_element(s2.begin(), s2.end()));

	sum3();
	max_sum.push_back(*max_element(s3.begin(), s3.end()));

	sum4();
	max_sum.push_back(*max_element(s4.begin(), s4.end()));

	sum5();
	max_sum.push_back(*max_element(s5.begin(), s5.end()));

	cout << *max_element(max_sum.begin(), max_sum.end()); // result
	return 0;
}