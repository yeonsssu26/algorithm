// greedy code
#include <iostream>
#include <stack>
using namespace std;
int main() {
	int N, K; cin >> N >> K;	// N:종류, K:합
	stack<int> s;
	for (int i = 0; i < N; i++) {
		int a; cin >> a; s.push(a);
	}
	
	int res = 0;
	while (!s.empty()) {
		res += K / s.top();		// 나누기를 이용해서 횟수를 구한 다음,
		K %= s.top();			// K는 %연산자를 이용해 값을 갱신
		s.pop();
	}
	cout << res;
	return 0;
}