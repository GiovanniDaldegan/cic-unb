# prova 24.1, questão 2

.data
v:      .word   0, 1, 2, 3, 4, 5, 6     # somax(v) = 9

.text
        la      a0, v           # a0: v[]
        li      a1, 7           # a1: k = 7

somax:                          # a0: v[], a1: k
        addi    t0, t0, 0       # t0 : soma
        addi    t1, t1, 0       # t1: i = 0
        addi    a1, a1, -1      # i deve ir de 0 a k-1

loop:   bge     t1, a1, saida   # se i >= k -1
        slli    t2, t1, 2       # t2: i * 4 (deslocamento em bytes)
        add     t3, a0, t2      # t3: v[] + i * 4 (posição atual no vetor)
        lw      t4, 0(t3)       # t4: v[i]
        andi    t5, t4, 1       # t5: t4 é impar?

        addi    t1, t1, 1       # i += 1

        beq     t5, zero, loop  # se t5 == 0 (v[i] par), próximo inteiro
        add     t0, t0, t4      # soma += v[i]
        j       loop

saida:  mv      a0, t0          # a0: resultado

        li      a7, 10
        ecall                   # syscall 10 (exit)
#       ret
