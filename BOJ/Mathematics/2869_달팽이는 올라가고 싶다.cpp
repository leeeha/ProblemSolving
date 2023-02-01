#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, V; 
	cin >> A >> B >> V;

	int day = (V-A) / (A-B); 

	if(day * (A-B) < V-A){
		day += 2; 
	}else {
		day += 1; 
	}

	cout << day; 
	
	return 0;
}