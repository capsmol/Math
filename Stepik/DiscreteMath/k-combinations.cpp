#include <iostream>
#include <vector>

using namespace std;

vector<int> people;
vector<int> combination;

void pretty_print(const vector<int>& v) {
    static int count = 0;
    for (int i = 0; i < v.size(); ++i) { cout << v[i] << " "; }
    cout << endl;
}

void go(int offset, int k) {
    if (k == 0) {
        pretty_print(combination);
        return;
    }
    for (int i = offset; i <= people.size() - k; ++i) {
        combination.push_back(people[i]);
        go(i+1, k-1);
        combination.pop_back();
    }
}

int main() {
    int n, k;

    cin >> k >> n;

    for (int i = 0; i <= n - 1; ++i) { people.push_back(i); }
    go(0, k);

    return 0;
}