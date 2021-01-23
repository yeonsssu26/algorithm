// 중복값이 존재하는 순열 (ex. 1,7,9,9)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void DFS(int level, int n, int r, vector<int> numbers, vector<int> orders) {
	if (level == r) {
		for (int i = 0; i < r; i++)
			cout << orders[i] << " ";
		cout << "\n";
		return;
	}

	int tmp = 0;									// tmp가 있을 때
	for (int i = 0; i < n; i++) {
		if (tmp != numbers[i]) {
			tmp = numbers.at(i); orders.push_back(tmp);
			DFS(level + 1, n, r, numbers, orders);
			orders.pop_back();
		}
	}

	/*for (int i = 0; i < n; i++) {					// tmp가 없을 때 (tmp가 있을 때랑 비교하면 이해하기 쉬움)
		orders.push_back(numbers.at(i));
		DFS(level + 1, n, r, numbers, orders);
		orders.pop_back();
	}*/
}

int main() {
	int n, r; cin >> n >> r;

	vector<int> numbers;	// 주어진 숫자카드 (input)
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp; numbers.push_back(tmp);
	}

	vector<int> orders;		// 중복순열 (output)
	sort(numbers.begin(), numbers.end());

	DFS(0, n, r, numbers, orders);

	return 0;
}