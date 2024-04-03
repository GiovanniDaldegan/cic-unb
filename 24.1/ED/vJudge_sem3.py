# A ("Wrong Answer")

input()
arr1 = [int(i) for i in input().split()]
input()
arr2 = [int(i) for i in input().split()]
missing = []

arr1.sort()
arr2.sort()

i = j = 0
while j < len(arr1):
    if arr2[i] != arr1[j] and missing.count(arr2[i]) == 0:
        missing.append(arr2[i])
    else:
        j += 1
    
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
