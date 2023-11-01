#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main() {
	long long n;
	fin >> n;
	if (n == 0) {
		fout << -1 << endl;
		return 0;
	}
	long long i = 0;
	while (n > 0) {
		if (n % 2 == 1)  fout << i << endl;
		n /= 2;
		i++;
	}
	return 0;
}