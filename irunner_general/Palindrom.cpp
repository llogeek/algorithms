#pragma warning (disable:4996)
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
ifstream file("input.txt");
ofstream fout("output.txt");

int main() {
	string str;
	file >> str;
	if (str.size() == 1) {
		fout << 1 << endl << str;
		return 0;
	}
	else if (str.size() == 2 && str[0] == str[1]) {
		fout << 2 << endl << str;
	}
	else if (str.size() == 2 && str[0] != str[1]) {
		fout << 1 << endl << str[0];
	}
	else {
		string temp = str;
		reverse(temp.begin(), temp.end());
		long long size = str.size();
		size += 1;
		long long** F = new long long* [size];
		for (long long i = 0; i < size; i++) F[i] = new long long[size];
		for (int i = 0; i < size; i++) {
			F[0][i] = 0;
			F[i][0] = 0;
		}
		for (long long i = 1; i < size; i++) {
			for (int j = 1; j < size; j++) {
				if (str[i - 1] == temp[j - 1]) F[i][j] = F[i - 1][j - 1] + 1;
				else if (str[i - 1] != temp[j - 1]) F[i][j] = max(F[i - 1][j], F[i][j - 1]);
				cout << F[i][j] << " ";
			}
			cout << endl;
		}
		for (long long i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << F[i][j] << " ";
			}
			cout << endl;
		}
		string subSequence = "";
		fout << F[size - 1][size - 1] << endl;
		long long i = size - 1, j = size - 1;
		while (i > 0 && j > 0) {
			if (str[i - 1] == temp[j - 1]) {
				subSequence += str[i - 1];
				i -= 1;
				j -= 1;
				continue;
			}
			else if (str[i - 1] != temp[j - 1]) {
				if (F[i][j] == F[i - 1][j]) {
					i -= 1;
					continue;
				}
				else if (F[i][j] == F[i][j - 1]) {
					j -= 1;
					continue;
				}
			}
		}
		reverse(subSequence.begin(), subSequence.end());
		fout << subSequence;
	}
	return 0;
}