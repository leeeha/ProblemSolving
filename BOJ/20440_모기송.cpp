#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n; // �ִ� 100�� 

	vector<int> v;
	vector<pair<int, int>> input;

	for(int i = 0; i < n; i++){
		int e, x;
		cin >> e >> x; // ����, ���� �ð� 
		input.push_back({e, x});
		v.push_back(e); 
		v.push_back(x); 
	}

	// �迭 ���� (�������� ������ �ڿ� �ߺ��Ǵ� ���� ����) 
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int size = v.size();
	vector<int> rev(size), sum(size);
	for(auto& p: input){
		// lower_bound? key ���� ���ų� �� ū ���ڰ� 
		// �迭�� ���° �ε����� ó�� �����ϴ��� ���� Ž�� 
		int idx1 = lower_bound(v.begin(), v.end(), p.first) - v.begin();
		int idx2 = lower_bound(v.begin(), v.end(), p.second) - v.begin();
		rev[idx1] = p.first; 
		rev[idx2] = p.second; 
		sum[idx1]++; 
		sum[idx2]--; 
	}

	// ������ ���ϱ� 
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
