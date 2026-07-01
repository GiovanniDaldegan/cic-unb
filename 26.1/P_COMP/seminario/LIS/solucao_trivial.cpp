#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<ll> array (size), LIS (size,1);
    int longest = (size > 0);

    for (int i = 0; i < size; i++) {
        cin >> array[i];

        for (int j = 0; j < i; j++) {
            if (array[i] > array[j]) {
                LIS[i] = max(LIS[i], LIS[j]+1);

                if (longest < LIS[i])
                    longest = LIS[i];
            }
        }
    }
    cout << longest << endl;
    return 0;
}