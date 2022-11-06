#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n; // 최대 100만 

	vector<int> v;
	vector<pair<int, int>> input;

	for(int i = 0; i < n; i++){
		int e, x;
		cin >> e >> x; // 입장, 퇴장 시각 
		input.push_back({e, x});
		v.push_back(e); 
		v.push_back(x); 
	}

	// 배열 압축 (오름차순 정렬한 뒤에 중복되는 원소 제거) 
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int size = v.size();
	vector<int> rev(size), sum(size);
	for(auto& p: input){
		// lower_bound? key 값과 같거나 더 큰 숫자가 
		// 배열의 몇번째 인덱스에 처음 등장하는지 이진 탐색 
		int idx1 = lower_bound(v.begin(), v.end(), p.first) - v.begin();
		int idx2 = lower_bound(v.begin(), v.end(), p.second) - v.begin();
		rev[idx1] = p.first; 
		rev[idx2] = p.second; 
		sum[idx1]++; 
		sum[idx2]--; 
	}

	// 누적합 구하기 
	for(int i = 1; i < sum.size(); i++){
		sum[i] += sum[i - 1];
	}

	int result = 0;
	for(auto& e: sum){
		result = max(result, e); 
	}
	cout << result << endl;

	int em, xm;
	bool flag = false;
	for(int i = 0; i < sum.size(); i++)
	{
		if(!flag && sum[i] == result){
			flag = true; 
			em = rev[i]; 
		}

		if(flag && sum[i] != result){
			xm = rev[i];
			break;
		}
	}

	cout << em << " " << xm << endl;
	
	return 0;
}
