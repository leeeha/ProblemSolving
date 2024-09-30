#include <iostream>
using namespace std;

const int MAX = 1000001;
int n; 
int arr[MAX];

void quickSort(int start, int end) {
	// 더 이상 쪼갤 수 없으면 재귀 호출 종료 
	if (end - start <= 1) return; 
    
    // 피벗과 투포인터 세팅 
    int pivot = arr[start]; 
    int l = start + 1; 
    int r = end - 1; 
    
    // 피벗을 제자리로 보낸다. 
    while(true) {
    	while(l <= r && arr[l] <= pivot) l++; 
        while(l <= r && arr[r] >= pivot) r--; 
        if(l > r) break; 
        swap(arr[l], arr[r]); 
    }
    swap(arr[start], arr[r]);
    
    // 피벗을 기준으로 나뉜 두 배열을 재귀적으로 정렬한다. 
    quickSort(start, r);
    quickSort(r + 1, end);
}

int main() {
ios::sync_with_stdio(0); 
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    quickSort(0, n); 
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << "\n";
    }
}