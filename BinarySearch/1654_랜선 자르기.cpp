#include <iostream>
#include <algorithm> 
#include <vector>
typedef long long ll; 
using namespace std; 

int k, n; // �ִ� 1��, 100�� 
ll arr[10001]; 
ll answer = 0; 

// x�� ���̰� �ʹ� ũ��, ������ n���� �� �Ѱ� 
// x�� ���̰� �ʹ� ������, ������ n���� ��½ �Ѵ´�. 
bool decision(int x){ 
	int sum = 0;
	for(int i = 0; i < k; i++){
		sum += arr[i] / x; 
	}

	if(sum >= n){ 
		return true;
	}else{
		return false; 
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n; 

	for(int i = 0; i < k; i++){ 
		cin >> arr[i];
	}

	ll left = 1; 
	ll right = *max_element(arr, arr + k); 

	// ���� Ž�� ���� 
	while(left <= right){
		ll mid = (left + right) / 2;

		// mid ���̷� �ڸ� ������ n�� �̻��̸�
		if(decision(mid)){
			// x�� �ִ� ����
			answer = max(answer, mid);

			// x�� ���̸� �� �÷���, ������ ���δ�.
			left = mid + 1; 
		}else{ 
			// �ڸ� ������ n�� �̸��̸� 
			// x�� ���̸� �� �ٿ���, ������ �ø���. 
			right = mid - 1;
		}
	}

	cout << answer; 

	return 0;
}
