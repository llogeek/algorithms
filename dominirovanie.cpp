#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

ofstream fout("output.txt");
ifstream fin("input.txt");

struct Team {
    int x;
    int y;
    int z;
    Team() : x(0), y(0), z(0) {}
    Team(int x1, int y1, int z1) : x(x1), y(y1), z(z1) {}
    void print() {
        cout << x << " " << y << " " << z << endl;
    }
};
bool comp(Team t1, Team t2) {
    if (t1.x != t2.x) return (t1.x < t2.x);
    else if (t1.y != t2.y) return (t1.y < t2.y);
    else return t1.z < t2.z;
}
bool compY(Team t1, Team t2) {
    return t1.y < t2.y;
}
int N;
int tree[400004];

void build_tree(int v, int leftBorder, int rightBorder) {
    if (leftBorder == rightBorder) tree[v] = INT_MAX;
    else {
        int mid = leftBorder + rightBorder;
        mid /= 2;
        build_tree(v * 2 + 1, leftBorder, mid);
        build_tree(v * 2 + 2, mid + 1, rightBorder);
        tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}
int get_min(int left, int right, int v, int leftBorder, int rightBorder) {
    if (left <= leftBorder && rightBorder <= right) return tree[v];
    if (rightBorder < left || right < leftBorder) return INT_MAX;
    int mid = leftBorder + rightBorder;
    mid /= 2;
    return min(get_min(left, right, v * 2 + 1, leftBorder, mid),
        get_min(left, right, v * 2 + 2, mid + 1, rightBorder));
}

void modify(int place, int new_value, int v, int leftBorder, int rightBorder) {
    if (place == leftBorder && rightBorder == place) {
        tree[v] = new_value;
        return;
    }
    if (rightBorder < place || place < leftBorder) return;
    int mid = leftBorder + rightBorder;
    mid /= 2;
    modify(place, new_value, v * 2 + 1, leftBorder, mid);
    modify(place, new_value, v * 2 + 2, mid + 1, rightBorder);
    tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
}

int main() {
    fin >> N;
    vector<Team> v(N);
    vector<int> y;
    int k = 0;
    while (fin.peek() != EOF) {
        fin >> v[k].x;
        fin >> v[k].y;
        fin >> v[k].z;
        k++;
    }
    sort(v.begin(), v.end(), compY);
    for (int i = 0; i < v.size(); i++){
        v[i].y = i;
    }
    sort(v.begin(), v.end(), comp);
    build_tree(0, 0, N);
    int count = 0;
    for (unsigned i = 0; i < N; i++) {
        int y1 = v[i].y;
        int z1 = v[i].z;
        if (get_min(0, y1, 0, 0, N) > z1)
            count++;
        modify(y1, z1, 0, 0, N);
    }
    cout << count;
}