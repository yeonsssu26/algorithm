// greedy code
#include <iostream>
#include <stack>
using namespace std;
int main() {
	int N, K; cin >> N >> K;	// N:����, K:��
	stack<int> s;
	for (int i = 0; i < N; i++) {
		int a; cin >> a; s.push(a);
	}
	
	int res = 0;
	while (!s.empty()) {
		res += K / s.top();		// �����⸦ �̿��ؼ� Ƚ���� ���� ����,
		K %= s.top();			// K�� %�����ڸ� �̿��� ���� ����
		s.pop();
	}
	cout << res;
	return 0;
}