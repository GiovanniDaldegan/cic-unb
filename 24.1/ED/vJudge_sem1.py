# problema A

input()
print(sum([int(i) for i in input().split()]))

# B

n = int(input())
arr = [int(i) for i in input().split()]

ratios = [0] * 3

for i in range(n):
    if arr[i] > 0: ratios[0] += 1
    elif arr[i] < 0: ratios[1] += 1
    else: ratios[2] += 1

for i in range(3):
    print(f"{(ratios[i] / n):.6f}")

# C ("Runtime Error")

time = input()

if time[-2:] == "PM":
    hour = int(time[:2]) + 12

    if hour < 10:
        hour = "0" + str(hour)

else:
    if time[:2] == 12:
        hour = "00"

print(f"{hour}{time[2:-2]}")
