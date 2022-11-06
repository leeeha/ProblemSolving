#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n; // 재료의 개수 (최대 15,000)
	cin >> n; 

	int m; // 갑옷을 만드는 데 필요한 수
	cin >> m; 

	// 각 재료의 고유 번호 입력 
	vector<int> v(n); 
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	// 투 포인터 
	int left = 0, right = n - 1, cnt = 0;
	while(left < right){
		if(v[left] + v[right] > m) right--;
		else if(v[left] + v[right] < m) left++;
		else { cnt++; right--; }
	}
	
	cout << cnt << endl;
	
	return 0;
}