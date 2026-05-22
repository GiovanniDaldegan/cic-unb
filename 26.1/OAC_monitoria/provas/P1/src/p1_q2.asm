# obs: converti os tabs pra espaços pra formatação ficar bonitinha

        li      a0, 44
        li      a1, 15

        csrr    s0, 3074        # contagem inicial de instruções

L1:     beq     a0, a1, L3      # programa
        bge     a0, a1, L2
        sub     a1, a1, a0
        jal     zero, L1
L2:     sub     a0, a0, a1
        jal     zero, L1
L3:     jal     zero, L4        #jalr    zero, ra, 0 (substituí pra poder rodar no RARS)

L4:     csrr    t0, 3074        # contagem final de instruções

        sub     s0, t0, s0      # s0: contagem de instr da exec de programa + 1
        addi    s0, s0, -1      # s0: contagem sem contabilizar o primeiro csrr

        li      a7, 10
        ecall
