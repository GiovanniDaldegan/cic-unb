def check_rainhas(rainhas, nova_rainha):
    for r in rainhas:
        same_row = r[0] == nova_rainha[0]
        same_line = r[1] == nova_rainha[1]
        same_diagonal = abs(r[0] - nova_rainha[0]) == abs(r[1] - nova_rainha[1])

        if same_row or same_line or same_diagonal:
            return False

    return True

# print(check_rainhas([(2, 2)], (4, 4)))
# print(check_rainhas([(1, 3), (2, 1)], (3, 6)))

# print(check_rainhas([(1, 2), (7, 2)], (1, 8)))
#    1 2 3 4 5 6 7 8
# 1 | |X| | | | | |X|
# 2 | | | | | | | | |
# 3 | | | | | | | | |
# 4 | | | | | | | | |
# 5 | | | | | | | | |
# 6 | | | | | | | | |
# 7 | |X| | | | | | |
# 8 | | | | | | | | |