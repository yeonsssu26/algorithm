#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> numbers;
vector<int> vc;
vector<int> counts;

void DFS(int depth); // 부분수열의 경우의 수를 찾는다
int MIN(); // 부분수열의 합으로 나올 수 없는 가장 작은 자연수를 찾는다

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num; cin >> num; numbers.push_back(num);
	}

	for (m = 1; m <= n; m++) {
		DFS(0);
		vc.clear();
	}

	cout << MIN();
	return 0;
}

void DFS(int depth) {
	if (vc.size() == m) {
		int sum = 0;
		for (auto i : vc) sum += i;
		counts.push_back(sum);
	}

	for (int i = depth; i < n; i++) {
		vc.push_back(numbers[i]);
		DFS(i + 1);
		vc.pop_back();
	}
}

int MIN() {
	sort(counts.begin(), counts.end());
	//for (auto i : counts) cout << i << " "; // for check
	//cout << endl;

	if (counts[0] > 1) return 1;
	else {
		for (int i = 0; i < counts.size() - 1; i++) { // return값이 양수이어야 함
			if (i == counts.size() - 2) {
				if (counts[i + 1] - counts[i] <= 1) {
					if (counts[i + 1] <= 0) return 1;
					else return counts[i + 1] + 1;
				}
				else return counts[i] + 1;
			}
			else {
				if (counts[i + 1] - counts[i] > 1) {
					if (counts[i + 1] <= 0) continue;
					else return counts[i] + 1;
				}
			}
		}
	}
}