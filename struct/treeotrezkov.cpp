#include <iostream>
#include <fstream>
#include <locale>
#define INF 100000000000
#define MAX_N 100000
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int get_min(int* tree_min, int l, int r, int v, int tl, int tr) {
    if (l <= tl && tr <= r) {
        return tree_min[v];
    }
    if (tr < l || r < tl) {
        return INT_MIN;
    }
    int tm = (tl + tr) / 2;
    return min(get_min(tree_min, l, r, v * 2 + 1, tl, tm),
        get_min(tree_min, l, r, v * 2 + 2, tm + 1, tr));
}
int get_max(int* tree_max, int l, int r, int v, int tl, int tr) {
    if (l <= tl && tr <= r) {
        return tree_max[v];
    }
    if (tr < l || r < tl) {
        return INT_MIN;
    }
    int tm = (tl + tr) / 2;
    return max(get_max(tree_max, l, r, v * 2 + 1, tl, tm), 
        get_max(tree_max, l, r, v * 2 + 2, tm + 1, tr));
}
int get_sum(int* tree_sum, int* plus, int l, int r, int v, int tl, int tr) {
    if (l <= tl && tr <= r) {
        return tree_sum[v] + plus[v] * (r - l + 1);
    }
    if (tr < l || r < tl) {
        return 0;
    }
    int tm = (tl + tr) / 2;
    return get_sum(tree_sum, l, r, v * 2 + 1, tl, tm)+
        get_sum(tree_sum, l, r, v * 2 + 2, tm + 1, tr);
}

void update(int* tree_sum, int* tree_min, int* tree_max, int idx, int val, int v, int tl, int tr) {
    //вариант 1
    if (idx <= tl && tr <= idx) {
        tree_sum[v] = val;
        tree_min[v] = val;
        tree_max[v] = val;
        return;
    }

    //вариант 2
    if (tr < idx || idx < tl) {
        return;
    }

    //вариант 3
    int tm = (tl + tr) / 2;
    update(tree_sum,  tree_min, tree_max, idx, val, v * 2 + 1, tl, tm);
    update(tree_sum, tree_min, tree_max, idx, val, v * 2 + 2, tm + 1, tr);
    tree_sum[v] = tree_sum[v * 2 + 1] + tree_sum[v * 2 + 2];
    tree_min[v] = min(tree_min[v * 2 + 1], tree_min[v * 2 + 2]);
    tree_max[v] = max(tree_max[v * 2 + 1], tree_max[v * 2 + 2]);
}

void add(int* tree_sum, int* tree_min, int* tree_max, int v, int l, int r, int tl, int tr, int val) {
    if (l <= tl && tr <= r) {
        tree_sum[v] += val;
        tree_min[v] += val;
        tree_max[v] += val;
        return;
    }

    //вариант 2
    if (tr < l || r < tl) {
        return;
    }

    //вариант 3
    int tm = (tl + tr) / 2;
    add(tree_sum, tree_min, tree_max, v * 2 + 1, l, min(r, tm), tl, tm, val);
    add(tree_sum, tree_min, tree_max, v * 2 + 2, max(tm + 1, l), r, tm + 1, tr, val);
    tree_sum[v] += val * (r - l + 1);
    tree_min[v] = min(tree_min[v * 2 + 1], tree_min[v * 2 + 2]) + val;
    tree_max[v] = max(tree_max[v * 2 + 1], tree_max[v * 2 + 2]) + val;
}

int main() {
	int n, option, s, v, a, b;
	fin >> n;
	int* t_sum = new int[4 * MAX_N];
    int* t_min = new int[4 * MAX_N];
    int* t_max = new int[4 * MAX_N];
    int* plus = new int[4 * MAX_N];
    for (int i = 0; i < 4 * n; i++) {
        t_sum[i] = 0;
        t_max[i] = 0;
        t_min[i] = 0;
    }
	while (fin >> option) {
        if (option == 1) {
            fin >> s >> v;
            // установить значение s равным v
            update(t_sum, t_min, t_max, s, v, 0, 0, n - 1);
        }
        else if (option == 2) {
            fin >> a >> b >> v;
            // прибавить к каждому элементу с индексом из отрезка[a, b] число v
            add(t_sum, t_min, t_max, 0, 0, n - 1, a, b, v);
        }
        else if (option == 3) {
            fin >> a >> b;
            // найти сумму элементов с индексами из отрезка [a, b]
            cout << get_sum(t_sum, 0, n - 1, 0, a, b) << endl;

        }
        else if (option == 4) {
            fin >> a >> b;
            // найти минимум среди элементов с индексами из отрезка [a, b]
            cout << get_min(t_min, 0, n - 1, 0, a, b) << endl;
        }
        else if (option == 5) {
            fin >> a >> b;
            // найти максимум среди элементов с индексами из отрезка [a, b]
            cout << get_max(t_max,0, n - 1, 0, a, b) << endl;
        }
        else break;
	}

	return 0;
}