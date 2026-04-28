# https://cses.fi/problemset/task/1069
# CSES 1083 - Repetitions

"""
n = int(input())
nums = input() #[int(i) for i in input().split()]
 
arr = list()
 
"""
 
#CSES 1069
 
seq = input()
curr = ""
count = max_c = 1
 
for i in seq:
    if curr == i:
        count += 1
        if max_c < count:
            max_c = count            
    else:
        count = 1
        curr = i
 
print(max_c)
