# A ("Runtime Error")

s = list(input())
chars, pairs, lens = [], [], [0]

for c in s:
    if chars.count(c) == 0:
        chars.append(c)

for i in range(len(chars)):
    for j in range(i + 1, len(chars)):
        pairs.append([chars[i], chars[j]])


for i in pairs:
    s1 = s[:]
    j = 0
    while j < len(s1):
        if i.count(s1[j]) != 0:
            s1.pop(j)
        else:
            j += 1

    j = 1
    while j < len(s1):
        if s1[j - 1] == s1 [j]: break

        if j == len(s1) - 1:
            lens.append(j + 1)

        j += 1

print(max(lens))
