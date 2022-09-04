#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;


vector <int> res;
bool isvisit[9][9];

bool isleg(int row, int col) {
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if ((isvisit[i][j] == true) && (row == i || col == j || abs(i - row) == abs(j - col))) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int row, int sum) {
	if (row == 9) {
		res.push_back(sum);
		return;
	}
	for (int col = 1; col <= 8; col++) {
		if (isvisit[row][col] == false && isleg(row, col)) {
			isvisit[row][col] = true;
			dfs(row + 1, sum * 10 + col);
			isvisit[row][col] = false;
		}
	}
}




int main() {
	int n;
	memset(isvisit, false, sizeof(isvisit));
	dfs(1,0);
	//for (int i = 0; i < res.size(); i++) {
	//	cout << res[i] << endl;
	//}
	while (cin >> n) {
		cout << res[n - 1];
	}
	return 0;
}