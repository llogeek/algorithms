#pragma warning (disable:4996)
#include <iostream>
#include <fstream>
#include <string>
#include <bits.h> 
#include <windows.h>
#include <algorithm>
using namespace std;
ifstream file("input.txt");
ofstream fout("output.txt");

int main() {
	long long s;
	file >> s;
	long long* mas = new long long[s + 1];
	long long i = 2;
	file >> mas[0];
	file >> mas[1];
	long long temp, temp1;
	while (file >> temp) {
		file >> mas[i];
		i++;
	}
	long long** F = new long long* [s + 1];
	for (long long i = 0; i < s + 1; i++) F[i] = new long long[s + 1];
	for (long long i = 0; i < s + 1; i++) {
		F[i][i] = 0;
	}

	for (long long l = 2; l < s + 1; l++) {
		for (long long i = 1; i < s - l + 2; i++) {
			long long j = i + l - 1;
			F[i][j] = LLONG_MAX;
			for (long long k = i; k < j; k++) {
				F[i][j] = min(F[i][j], F[i][k] + F[k + 1][j] + mas[i - 1] * mas[k] * mas[j]);
			}
		}
	}
	fout << F[1][s];
	return 0;
}