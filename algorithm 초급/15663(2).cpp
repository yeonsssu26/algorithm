#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> numbers;	// input
vector<int> orders;		// output
vector<bool> chk;		// 같은 level에서 동일한 수를 쓰지 않게 한다

void DFS(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++) cout << orders[i] << " ";
		cout << "\n"; return;
	}

	int visited = 0;	// 방문여부
	for (int i = 0; i < n; i++) {
		if (visited != numbers[i] && !chk[i]) {
			visited = numbers[i]; chk[i] = true;
			orders.push_back(numbers[i]);
			
			DFS(level + 1);
			
			orders.pop_back();
			chk[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp; numbers.push_back(tmp);
		chk.push_back(false);
	}
	sort(numbers.begin(), numbers.end());

	DFS(0);

	return 0;
}