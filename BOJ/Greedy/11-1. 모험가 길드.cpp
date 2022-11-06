#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	vector<int> v;

	int n;
	cin >> n;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	/*  나의 첫번째 풀이에서 잘못된 점: 공포도가 높은 사람을 반드시 포함시킬 필요가 없다.
	    
		// 내림차순 정렬
		sort(v.begin(), v.end(), greater<int>());

		int i = 0, cnt = 0;
		do{
			cnt++; // 그룹 수 카운트
			i += v[i]; // 그룹의 인원 수가 공포도 x를 넘지 않도록 그룹 결성 (그룹 수 최대화)
		}while(i < n); // 인덱스 범위 검사

		cout << cnt << '\n';
	*/

	// 공포도가 낮은 사람부터 최소한의 인원으로 그룹을 결성하면, '최대한 많은 그룹' 생성됨. (그리디)
	// 반드시 모든 사람이 모험을 나가야 하는 건 아니다. 
	// 공포도가 x인데 모험가를 x명 이상 모집할 수 없으면 그대로 마을에 남아 있게 한다.
	// 즉, 공포도가 낮은 사람일수록 여러 사람 몫을 하는 것이다. 공포도가 높은 사람은 여러 사람이 모여야만 모험을 나갈 수 있다.

	int result = 0; // 총 그룹의 수
	int count = 0; // 현재 그룹에 포함된 모험가의 수

	for (int i = 0; i < n; i++) { // 공포도를 낮은 것부터 하나씩 확인하며
		count += 1; // 현재 그룹에 해당 모험가를 포함시키기

		if (count >= v[i]) { // 현재 그룹에 포함된 모험가의 수가 현재의 공포도 이상이라면, 그룹 결성
			result++; // 총 그룹의 수 증가시키기
			count = 0; // 현재 그룹에 포함된 모험가의 수 초기화
		}
	}

	cout << result << '\n'; // 총 그룹의 수 출력

	return 0;

}