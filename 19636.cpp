#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int W0, I0, T, D, I, A;
    cin >> W0 >> I0 >> T;
    cin >> D >> I >> A;

    int weightWithoutMetabolismChange = W0 + (I - I0) * D;

    int metabolismChange = 0;
    int weightWithMetabolismChange = W0;
    for (int day = 1; day <= D; ++day) {
        int energyConsumption = I - (I0 + metabolismChange) + A;
        weightWithMetabolismChange += energyConsumption;
        if (abs(energyConsumption) > T) {
            metabolismChange += energyConsumption / 2;
        }
        if (weightWithMetabolismChange <= 0 || (I0 + metabolismChange) <= 0) {
            cout << "Danger Diet" << endl;
            return 0;
        }
    }

    cout << weightWithoutMetabolismChange << " " << I0 << endl;
    cout << weightWithMetabolismChange << " " << (I0 + metabolismChange) << " ";
    if (weightWithoutMetabolismChange > weightWithMetabolismChange) {
        cout << "YOYO" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
