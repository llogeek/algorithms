#include <iostream>
#pragma comment(linker, "/STACK:16777216")
#include <queue>
#include <fstream>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	int m, n;
	fin >> n >> m;
	vector < vector < pair<int, int> > > g(n + 1);
	int u, v, w;
	while (fin.peek() != EOF) {
		fin >> u;
		fin >> v;
		fin >> w;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	int s = 1; // стартовая вершина
	vector<int> d(n + 1, INF), p(n + 1);
	d[0] = 0;
	d[s] = 0;
	vector < pair<int, int> > q;
	q.push_back(make_pair(0, 0));
	q.push_back(make_pair(0, s));
	int i = 1;
	while (!q.empty()) {
		int v = q[i].second, cur_d = -q[i].first;
		q.erase(q.begin() + i);
		i--;
		if (cur_d > d[v]) {
			continue;
		}
		for (size_t j = 0; j < g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push_back(make_pair(-d[to], to));
				i++;
			}
		}

	}
	fout << d[n] << endl;
	return 0;
}