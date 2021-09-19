#include <iostream>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int minX = (x > w - x) ? w - x : x;
	int minY = (y > h - y) ? h - y : y;

	int min = (minX > minY) ? minY : minX;

	cout << min;

	return 0;
}