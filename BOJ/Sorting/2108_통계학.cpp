#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath> 
using namespace std;

// -4000 ~ 4000 ������ ���ڰ� ���� ����� ���� ���� �迭 
// �ε����� ������ �� �� �����Ƿ� �ӽ÷� �ε����� 4000�� ���Ѵ�.
int counting[8001]; // 0���� �ʱ�ȭ 

int calcMode(){
	// �ϴ� counting �迭���� �ִ��� ������. 
	int maxCount = *max_element(counting, counting + 8001); 

	// �ش� ������ŭ �����ϴ� ���ڵ��� ���� �����Ѵ�. 
	vector<int> modeCandidate; 
	for(int i = 0; i < 8001; i++){
		if(counting[i] == maxCount){
			// ũ�Ⱑ ���� ������� ���Եȴ�. 
			modeCandidate.push_back(i - 4000); 
		}
	}

	if(modeCandidate.size() == 1){ 
		return modeCandidate[0]; 
	}

	// �ι�°�� ���� �� ���� 
	return modeCandidate[1]; 
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	cin >> n; // �ִ� 50�� (Ȧ��)

	vector<int> arr; 
	int sum = 0; 
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		arr.push_back(val);
		
		sum += val; 
		counting[val + 4000] += 1; 
	} 

	// �Ҽ��� ù° �ڸ����� �ݿø� �� ������ 
	float mean = sum / (float)n; 
	if(mean > -0.5 && mean < 0.0){ 
		mean = 0; 
	}else{
		mean = round(mean); 
	}
	cout << mean << "\n";

	// �߾Ӱ� 
	sort(arr.begin(), arr.end()); 
	cout << arr[n / 2] << "\n"; 

	// �ֺ� 
	cout << calcMode() << "\n"; 
	
	// ���� 
	cout << arr.back() - arr.front() << "\n"; 

    return 0;
}