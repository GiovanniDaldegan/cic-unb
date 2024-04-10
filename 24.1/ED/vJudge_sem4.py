#A

arr = []

for i in range(int(input())):
    n = input()

    if i == 0:
        arr.append(n)
        continue

    for j in range(len(arr)):
        if len(n) > len(arr[j]):
            continue
        elif len(n) == len(arr[j]):
            if int(n[0]) > int(arr[j][0]):
                continue
            elif int(n[0]) < int(arr[j][0]):
                arr.insert(j, n)
                break
            else:
                k = 1
                while int(n[k]) == int(arr[j][k]) and k < len(arr[j]):
                    k += 1
                if int(n[k]) > int(arr[j][k]):
                    continue
                else:
                    arr.insert(j, n)
                    break
        else:
            arr.insert(j, n)
            break

        if j == len(arr) - 1:
            arr.append(n)


print(*arr)



# B

arr = [int(i) for i in input().split()]
arr.sort()

print(arr[int(len(arr) / 2)])
