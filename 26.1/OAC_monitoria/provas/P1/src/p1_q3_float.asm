# obs: converti os tabs pra espaços pra formatação ficar bonitinha

.data
pi: .float 3.141592653589793238462 # 3.1415926535, 6.283185307

.text
MAIN: li a7,6
      ecall

      jal SENO
      
      li a7,2
      ecall
      
      li a7,10
      ecall


# Procedimento SENO
# Recebe um valor x em radianos e retorna seu seno aproximado
# 
# input:
# - fa0: x (float)
# output:
# - fa0: seno(x) (float)
SENO:
        li      t1, 1           # t1: n (contador)
        li      t6, 1           # t6: k (contador 2n+1)
        li      t2, 11          # t2: limite de n (10 iterações, soma de 11 termos)
        li      t3, 2
        
        # normalizar 0 <= x <= pi
        # importante, mas desnecessário para os testes da P1
        
        # ft0: somatório
        fmv.s   ft0, fa0        # ft0: x (inicial, n=1)
        
        # ft1: potência x^1, x^3, x^5, ..., x^21;
        fmv.s   ft1, fa0        # ft1: x (inicial, n=1)
        
        # ft2: fatorial  1!, 3!, 5!, ..., 21!
        li      t4, 1
        fcvt.s.w ft2, t4        # ft2: 1 (inicial, n=1)
        
loop_seno:
        bge     t1, t2, saida_seno
        
        rem     t4, t1, t3      # t4: t1 % 2
        bne     t4, zero, n_impar
        li      t4, 1           # t4: 1 (quando n par)
        jal     zero, calc
n_impar:
        li      t4, -1          # t4: -1 (quando n ímpar)
calc:
        fcvt.s.w ft3, t4        # ft3: (float) (-1)^n
        
        # cálculo fatorial (2n+1)! (fatorial anterior * n * (n+1))
        addi    t6, t6, 1       # t6: 2n
        fcvt.s.w ft4, t6        # ft4: (float) 2n
        fmul.s  ft2, ft2, ft4   # ft2: *= 2n
        
        addi    t6, t6, 1       # t6: 2n+1
        fcvt.s.w ft4, t6        # ft4: (float) 2n+1
        fmul.s  ft2, ft2, ft4   # ft2: *= 2n+1
        
        
        # cálculo potência x^(2n+1) (potência anterior * x^2)
        fmul.s  ft1, ft1, fa0   # ft1: x^(2n)
        fmul.s  ft1, ft1, fa0   # ft1: x^(2n+1)
        
        
        fdiv.s  ft4, ft1, ft2   # ft4: x^(2n+1) / fat(2n+1)
        fmul.s  ft4, ft4, ft3   # ft4: ft4 * (-1)^n

        fadd.s  ft0, ft0, ft4   # ft0: += x^(2n+1) / fat(2n+1) * (-1)^n
        
        addi    t1, t1, 1       # n += 1

        j       loop_seno

saida_seno:
        fmv.s   fa0, ft0
        ret
