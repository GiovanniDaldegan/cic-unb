# entrada:
#   mensagem cifrada
# saída:
#   triagramas com repetição em ordem alfabética, votos de cada tamando de
#   chave entre 2 e 12, tamanho mais provável

# explicação:
#   uma mensagem criptografada pela Cifra de Vigenère pode ter trechos
#   repetidos por consequência do alinhamento de caracteres contínuos da
#   mensagem com caracteres da palavra chave. então, é possível analisar as
#   distâncias (dist) entre trechos repetidos e seus comprimentos (|trecho|=d)
#   e considerar que a chave pode ter se repetido dist / d vezes nesse
#   intervalo. então rankeamos os melhores tamanhos candidatos de chave: quanto
#   mais ocorre que dist % d == 0, mais trechos são potencialmente compatíveis
#   com o tamanho d de chave, ou seja, mais votos o tamanho d tem

msg = input().replace(" ", "")
triagrams = dict()
# { key : ([occurs_indx], [dists]) }

voting = {i : 0 for i in range(2, 13)}

# detecção de triagramas
for i in range(len(msg) -2):
    tri = msg[i:i+3]

    if tri in triagrams.keys():
        triagrams[tri][0].append(i)
    else:
        triagrams[tri] = ([i], [])

# removendo triagramas sem repetição
for k, v in list(triagrams.items()):
    if len(v[0]) < 2:
        del triagrams[k]


# processamento de triagrama
for k, v in triagrams.items():
    if len(v[0]) == 1:
        continue

    for i in range(len(v[0]) -1):
        dist = v[0][i+1] - v[0][i]
        triagrams[k][1].append(dist)


# processamento de distância
for d in voting.keys():
    for k, v in triagrams.items():
        for dist in v[1]:
            if dist % d == 0:
                voting[d] += 1

"""
for it in sorted(triagrams.items(), key=lambda i: (len(i[1][1]), i[1][0][0]), reverse=True):
    print(f"{it[0]}: posicoes={it[1][0]} distancias={it[1][1]}")
"""

for it in sorted(triagrams.items(), key=lambda i: i[0]):
    print(f"{it[0]}: posicoes={it[1][0]} distancias={it[1][1]}")


for d in voting.keys():
    print(f"tamanho {d}: {voting[d]} votos")

opa = sorted(voting.items(), key=lambda v: v[1], reverse=True)
print(f"Tamanho de chave estimado: {opa[0][0]}")

