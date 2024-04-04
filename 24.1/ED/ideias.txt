# Sem 3 | ED vJudge | Sem 3 C - binary search | busca (bizarra) binária de um subarray
# (incompleto)

def bin_range_search(low=0, upper=-1):
    l = (upper - low) // 2
    aux_arr = arr[low:upper]

    print(aux_arr)

    if n < aux_arr[l]:
        return bin_range_search(low=low, upper=l)
    elif n > aux_arr[l]:
        return bin_range_search(low=l, upper=upper)
    else:
        found_before_l = bin_range_search(low=0, upper=l)
        found_after_l = bin_range_search(low=l, upper=-1)

        if low == 0 or aux_arr[upper] == arr[-1]:
            if aux_arr[low] == n and aux_arr[upper] == n:
                return [low, upper, upper - low + 1]
        else:
            # if low > 0 and arr[upper] < arr[-1]:

            if arr[low - 1] != aux_arr[low] and aux_arr[upper + 1] != arr[-1]:
                return [low, upper, upper - low + 1]
                
            else:
                if found_before_l[2] != 0:
                    low = found_before_l[0]
                if found_after_l[2] != 0:
                    upper = found_before_l[1]
                
                if 

input()
arr = [int(i) for i in input().split()]
n = int(input())

result = [i + 1 for i in bin_range_search()]
print(bin_range_search())#*result)
