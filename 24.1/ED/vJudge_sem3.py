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

# C

def bin_search(n, arr, left=0, right=0, freq=0, low=0, upper=0):
    l = len(arr[left:right]) // 2

    if n < arr[left:right][l]:
        return bin_search(n, arr, left=left, right=l)
    elif n > arr[left:right][l]:
        return bin_search(n, arr, left=l, right=right)
    else:
        arr.pop(l)
        return bin_search
