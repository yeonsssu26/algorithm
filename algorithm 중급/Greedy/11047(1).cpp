// this code is not using greedy algorithm
#include <iostream>
#include <stack>
using namespace std;
int main() {
	int N, K; cin >> N >> K; // N:а╬╥Ы, K:гу
	
	stack<int> s;
	for (int i = 0; i < N; i++) {
		int a; cin >> a; s.push(a);
	}
		
	int res = 0;
	while (K >= 0 && !s.empty()) {
		if (K >= s.top()) {
			K -= s.top();
			res++;
		}
		else {
			s.pop();
		}
	}
	cout << res;
	return 0;
}