#include <iostream>
using namespace std; 

const int MAX = 1000001;
int n; 
int arr[MAX];
int tmp[MAX]; // 추가적인 메모리 공간 필요 

void conquer(int start, int end) {
	int mid = (start + end) / 2; 
    int aidx = start; 
    int bidx = mid; 
    
    for(int i = start; i < end; i++){
    	if(bidx == end) tmp[i] = arr[aidx++];
        else if(aidx == mid) tmp[i] = arr[bidx++]; 
        else if(arr[aidx] <= arr[bidx]) tmp[i] = arr[aidx++]; 
        else tmp[i] = arr[bidx++];
    }
    
    for(int i = start; i < end; i++) arr[i] = tmp[i]; 
}

void divide(int start, int end) {
	// 더 이상 쪼갤 수 없을 때까지 재귀 호출 
	if(end - start == 1) return;
    
    // 배열을 두 개로 나눈다. 
    int mid = (start + end) / 2;
    divide(start, mid); 
    divide(mid, end); 
    
    // 정렬된 두 배열을 합친다. 
    conquer(start, end); 
}


int main() {
	ios::sync_with_stdio(0); 
    cin.tie(0);
    
    cin >> n; 
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    divide(0, n); 
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << "\n";
    }
}