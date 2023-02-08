// Sol1. set 
#include <iostream>
#include <set> 
using namespace std;

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M; 
	cin >> N >> M; 

	set<int> A, B; 
	for(int i = 0; i < N; i++){
		int element; 
		cin >> element; 
		A.insert(element); 
	}

	for(int i = 0; i < M; i++){
		int element; 
		cin >> element; 
		B.insert(element); 
	}

	set<int> intersection; 
	for(auto element: B){ // M 
		auto it = A.find(element); // logN 
		if(it != A.end()){ 
			A.erase(it); 
			intersection.insert(*it); 
		}
	}

	for(auto ele: intersection){
		B.erase(ele); // logN 
	}

	cout << A.size() + B.size(); 
	
    return 0;
}

// Sol2. map 
#include <iostream>
#include <map> 
using namespace std;

map<int, bool> m; 

int main()
{
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N+M; i++){
		int element; 
		cin >> element; 
		
		if (!m[element]) // ������ ���� �����̸� �߰��Ѵ�.  
			m[element] = true; 
		else // �̹� �ִ� �����̸� �����Ѵ�. 
			m.erase(element);
	}
	
	cout << m.size(); // ���� map ����� ���

	return 0; 
}