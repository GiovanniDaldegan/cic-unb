# A

input()
arr1 = [int(i) for i in input().split()]
input()
arr2 = [int(i) for i in input().split()]
missing = []

arr1.sort()
arr2.sort()

i = j = 0
while i < len(arr2):
    if missing.count(arr2[i]) == 0:
        if j == len(arr1):
            missing.append(arr2[i])
        elif arr2[i] != arr1[j]:
            missing.append(arr2[i])
        else:
            j += 1
        
        i += 1
    else:
        i += 1

print(*missing)
# B

n = int(input())

for i in range(n):
    m = int(input())
    arr_s = input().split()

    arr = [0] * (m + 1)

    for j in range(1, m + 1):
        arr[j] = int(arr_s[j - 1]) + arr[j - 1]

    for j in range(1, m + 1):
        if arr[j - 1] == arr[-1] - arr[j]:
            print("YES")
            break
        if j == m:
            print("NO")

# C (incompleto)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r, m, k; cin >> n;
    bool done = 0;
    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    cin >> k;

    l = 0; r = n - 1;

    while (!done) {
        m = (r - l) / 2;

        cout << l << ' ' << r << '\n';

        if (l == r && v[l] != k) {
            cout << -1 << ' ' << -1 << ' ' << 0 << '\n';
            done = 1;
        }

        if (k < v[m]) {
            r = m;
        }
        else if (k > v[m]) {
            l = m;
        }
        else {
            while (v[m - 1] == k) {
                m--;
                l = m;
            }
            m = n / 2;
            
            while (v[m + 1] == k) {
                m++;
                r = m;
            }

            cout << l << ' ' << r << ' ' << r - l + 1 << '\n';
            done = 1;
        }
    }
    return 0;
}
