# D

def percorrer_labirinto(pos, caminho=''):
    espaco = labirinto[pos[0]][pos[1]]
    print(pos, espaco)
    if espaco == 'B':
        print(f'YES\n{len(caminho)}\n{caminho}')
        return f'YES\n{len(caminho)}\n{caminho}'
    elif espaco == '#' or (espaco == 'A' and caminho != ''):
        return


    opcoes = [[-1, 0, "L"], [1, 0, "R"], [0, -1, "U"], [0, 1, "D"]]

    for i in opcoes:
        tentativa = percorrer_labirinto([pos[0] + i[0], pos[1] + i[1]], caminho + i[2])
        if tentativa:
            return tentativa

    # if percorrer_labirinto([pos[0] - 1, pos[1] + 0], caminho + "L"):
    #     return f'YES\n{len(caminho)}\n{caminho + "L"}'
    # elif percorrer_labirinto([pos[0] - 1, pos[1] + 0], caminho + "R"):
    #     return f''



labirinto = []
inicio = [1, 1]
n, m = [int(i) for i in input().split()]

for i in range(n):
    linha = list(input())

    if 'A' in linha:
        inicio = [i, linha.index('A')]

    labirinto.append(linha)

print(percorrer_labirinto(inicio))
