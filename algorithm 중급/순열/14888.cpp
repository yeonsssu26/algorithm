#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> numbers;
int opers[4];

const int MAX = 1000000000 + 1;
int maxRes = -MAX, minRes = MAX;

void DFS(int curr, int res);

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp; numbers.push_back(tmp);
	}

	for (int i = 0; i < 4; i++) cin >> opers[i];

	DFS(1, numbers[0]);
	cout << maxRes << "\n" << minRes;

	return 0;
}

void DFS(int curr, int res) {
	if (curr == n) {
		maxRes = max(maxRes, res);
		minRes = min(minRes, res);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (opers[i] > 0) {
			opers[i]--;

			/*if (i == 0) DFS(++curr, res + numbers[curr]);
			else if (i == 1) DFS(++curr, res - numbers[curr]);
			else if (i == 2) DFS(++curr, res * numbers[curr]);
			else if (i == 3) DFS(++curr, res / numbers[curr]);*/

			/*if (i == 0) DFS(curr++, res + numbers[curr]);
			else if (i == 1) DFS(curr++, res - numbers[curr]);
			else if (i == 2) DFS(curr++, res * numbers[curr]);
			else if (i == 3) DFS(curr++, res / numbers[curr]);*/

			if (i == 0) DFS(curr + 1, res + numbers[curr]);
			else if (i == 1) DFS(curr + 1, res - numbers[curr]);
			else if (i == 2) DFS(curr + 1, res * numbers[curr]);
			else if (i == 3) DFS(curr + 1, res / numbers[curr]);

			opers[i]++;
		}
	}
	return;
}