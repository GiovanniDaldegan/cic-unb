
# B
t = int(input())

for i in range(t):
    n, f, k = [int(j) for j in input().split()]
    cubos = [int(j) for j in input().split()]
        
    v_f = cubos[f - 1]
    cubos.sort(reverse=True)
    
    print(cubos)
    
    f_antes = v_f in cubos[:len(cubos) - k]
    f_depois = v_f in cubos[len(cubos) - k:]
    
    if f_antes and f_depois:
        print("MAYBE")
    elif not f_depois:
        print("NO")
    elif not f_antes:
        print("YES")
