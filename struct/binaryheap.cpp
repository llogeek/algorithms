#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main() {
	int n, i = 1;
	fin >> n;
	int* mas = new int[n + 1];
	while (i <= n) {
		fin >> mas[i];
		i++;
	}
	bool is_heap = true;
	int mid;
	for (int i = 1; i <= n / 2; i++) {
		if (2 * i <= n && mas[i] > mas[2 * i]) {
			is_heap = false;
			break;
		}
		if (2 * i + 1 <= n && mas[i] > mas[2 * i + 1]){
			is_heap = false; 
			break;
		}
	}
	if (is_heap == true)
		fout << "Yes";
	else
		fout << "No";
	return 0;
}