#pragma warning (disable:4996)
#include <iostream>
#include <fstream>
using namespace std;
ifstream file("input.txt");
ofstream fout("output.txt");
long long MOD = 1000000007;
int main() {
	long long n;
	file >> n;
	if (n == 1) {
		fout << 1 << endl;
		return 0;
	}
	if (n == 2) {
		fout << 2 << endl;
		return 0;
	}
	long long temp1 = 1, temp2 = 2, curr = 0 ;
	for (int i = 2; i < n; i++) {
		curr = (temp1 + temp2) % MOD;
		temp1 = temp2;
		temp2 = curr;
	}
	fout << curr << endl;
}