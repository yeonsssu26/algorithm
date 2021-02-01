#include <iostream>
#include <vector>
using namespace std;

int n, m, s, cnt = 0;
vector<int> numbers;
vector<int> vc;

void DFS(int depth);

int main() {
	cin >> n >> s; // input n, s
	for (int i = 0; i < n; i++) { // input numbers
		int num; cin >> num; numbers.push_back(num);
	}

	for (m = 1; m <= n; m++) { // m : n가지
		DFS(0);
		vc.clear();
	}

	cout << cnt; // output result

	return 0;
}

void DFS(int depth) {
	if (vc.size() == m) {
		int sum = 0;
		for (auto i : vc) sum += i; // i : vc의 원소
		if (sum == s) {
			/*for (auto i : vc) cout << i << " "; // for check
			cout << endl;*/
			cnt++;
		}
		return;
	}

	for (int i = depth; i < n; i++) {
		vc.push_back(numbers[i]);
		DFS(i + 1);
		vc.pop_back();
	}
}