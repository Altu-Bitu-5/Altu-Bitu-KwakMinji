#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_set<string> S;

    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        S.insert(str);
    }

    int count = 0;

    for (int i = 0; i < M; ++i) {
        string str;
        cin >> str;
        if (S.find(str) != S.end()) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}