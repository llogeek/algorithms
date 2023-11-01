#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int INF = 1e9;
ifstream fin("input.in");
ofstream fout("output.out");
int N, p, k, s, t;
int matrix[300][300];
int flag[300];
int in[300];
int out[300];
int ff(int u, int flow) {
    if (u == t)
        return flow;
    flag[u] = true;
    for (int v = 0; v < N + 2; v++)
        if (flag[v] == false && matrix[u][v] > 0) {
            int result = ff(v, min(flow, matrix[u][v]));
            if (result > 0) {
                matrix[u][v] -= result;
                matrix[v][u] += result;
                return result;
            }
        }
    return 0;
}
int getFlow() {
    int res, answer = 0;
    while ((res = ff(s, INF)) > 0) {
        for (int i = 0; i < 300; i++) flag[i] = false;
        answer += res;
    }
    return answer;
}
int main() {

    fin >> N >> p >> k;
    int temp;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            fin >> temp;
            matrix[i][j] = temp;
        }
    }
    if (p != 1) {
        for (int i = 0; i < p; i++) {
            fin >> temp;
            in[i] = temp;
            matrix[0][temp] = 301;
            matrix[temp][0] = 301;
        }
    }
    else {
        fin >> temp;
        s = temp;
    }
    if (k != 1) {
        for (int i = 0; i < k; i++) {
            fin >> temp;
            out[i] = temp;
            matrix[N + 1][temp] = 301;
            matrix[temp][N + 1] = 301;
        }
        t = N + 1;
    }
    else {
        fin >> temp;
        t = temp;
    }
    fout << getFlow();
    return 0;
}