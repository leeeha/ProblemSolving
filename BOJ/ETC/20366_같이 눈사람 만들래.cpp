#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n; // 최대 600 

	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i]; // 최대 1억 
	}

	// 눈덩이 크기 순으로 오름차순 정렬 
	sort(v.begin(), v.end());

	int answer = 1e9; // 두 눈사람의 키 차이 중 최솟값 구하기 
	for(int i = 0; i < n - 3; i++){
		for(int j = i + 3; j < n; j++){ // i와 최소 3칸 차이나도록 
			// i와 j 사이의 눈덩이를 가리키는 투 포인터
			int left = i + 1;
			int right = j - 1;
			
			while(left < right){
				int anna = v[i] + v[j]; 
				int elsa = v[left] + v[right]; 
				int diff = elsa - anna; 
				
				answer = min(answer, abs(diff));

				// 엘사가 안나보다 더 크다면 합을 줄이기 위해 왼쪽으로 이동
				if(diff > 0) right--; 
				// 엘사가 안나보다 더 작다면 합을 늘리기 위해 오른쪽으로 이동 
				else left++;
			}
		}
	}

	cout << answer << endl;
	
	return 0;
}

