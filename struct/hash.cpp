#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main() {
	int m, n, c, temp, h;
	fin >> m;
	fin >> c;
	fin >> n;
	int* hash = new int[m];
	for (int i = 0; i < m; i++) hash[i] = -1;
	int j = 0;
	bool fill = false;
	while(fin >> temp) {
		j = 0;
		fill = false;
		while (fill == false){
			h = ((temp % m) + c * j) % m;
			if (hash[h] == temp || hash[h] == -1) {
				hash[h] = temp;
				fill = true;
			}
			else j++;
		}
	}
	for (int i = 0; i < m; i++) fout << hash[i] << " ";

	return 0;
}