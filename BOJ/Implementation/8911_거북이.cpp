#include <iostream>
#include <vector>
using namespace std; 

vector<pair<int, int>> coords; 
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

void saveAllVisitedCoords(string cmd){
	int nx = 0, ny = 0; // 초기 위치 원점 
	int nd = 0; // 초기 방향 북쪽 
	coords.push_back({nx, ny});

	for(int i = 0; i < cmd.size(); i++){
		char ch = cmd[i]; 

		// 방향 전환 
		if(ch == 'L' || ch == 'R'){
			if(ch == 'L'){
				nd = (nd + 3) % 4; 
			}else{
				nd = (nd + 1) % 4; 
			}
		}else{
			// 좌표 이동 
			if(ch == 'F'){
				nx += dx[nd]; 
				ny += dy[nd]; 
			}else{
				nx -= dx[nd]; 
				ny -= dy[nd]; 
			}
            
            // 좌표에 변화가 있을 때만 저장 
            coords.push_back({nx, ny}); 
		}
	}
}

int getWidth(){
	int min = 1e9, max = -1e9; 
	
	for(auto e: coords){ 
		int x = e.first; 
		if(x < min) min = x; 
		if(x > max) max = x; 
	}
	
	return max - min; 
}

int getHeight(){
	int min = 1e9, max = -1e9; 
	
	for(auto e: coords){
		int y = e.second;
		if(y < min) min = y;
		if(y > max) max = y; 
	}
	
	return max - min; 
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; 
	cin >> t; 

	while(t--){
		string cmd; 
		cin >> cmd;  

		saveAllVisitedCoords(cmd); 
		int area = getWidth() * getHeight();
		cout << area << "\n"; 

		coords.clear();
	}
	
	return 0; 
}