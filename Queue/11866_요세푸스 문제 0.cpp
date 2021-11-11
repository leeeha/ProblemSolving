#include <iostream>
#include <vector>
using namespace std;

/*
	일반적인 배열은 원소를 삭제하면 한칸씩 앞으로 당겨줘야 하는데
	이걸 자동으로 해주는 게 vector!! 이거 없으면 일일이 반복문으로 당겨야 함.
*/

int main() {
	int n, k;
	cin >> n >> k; // n은 최대 1,000개

	vector<int> v;
	for (int i = 0; i < n; i++)
		v.push_back(i + 1); // 1~n으로 초기화

	cout << "<";

	int cnt = 1;
	//vector<int>::iterator iter = v.begin();
	auto it = v.begin();

	while (!v.empty()) {
		// k번째 원소를 발견하면 삭제
		if (cnt == k) {
			cout << *it;
			it = v.erase(it);
			if (it == v.end())
				it = v.begin();

			// 아직 남은 원소가 있으면 콤마
			if (!v.empty()) cout << ", ";
			else {
				cout << ">";
				break;
			}

			cnt = 1;
		}
		else {
			if (++it == v.end())
				it = v.begin();
			cnt++;
		}
	}

	return 0;
}