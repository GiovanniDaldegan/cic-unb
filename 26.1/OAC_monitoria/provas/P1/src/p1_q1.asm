# obs: converti os tabs pra espaços pra formatação ficar bonitinha

.data
A: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
msg: .string "media="

.text
MAIN:
        li	t0, 0		# t0: i
        li	t4, 10		# t4: 10
        
loop_leitura:
        bge	t0, t4, saida_leitura
        
        la	t1, A		# t1: A
        slli	t2, t0, 2	# t2: i*4
        add	t2, t1, t2	# t2: A + i*4
        
        li	a7, 5
        ecall			# leitura inteiro k
        
        sw	a0, 0(t2)	# A[i] = k ou, usando ponteiros, *(A + i*4) = k
        
        addi	t0, t0, 1	# i++
        
        jal	zero, loop_leitura
        
saida_leitura:
        la	a0, msg
        li	a7, 4
        ecall			# print "media="
        
        la	a0, A
        li	a1, 10
        jal	ra, MEDIA       # chama procedimento MEDIA
        
        
        li	a7, 2
        ecall			# print float
        
        li	a7, 10
        ecall			# exit



# Procedimento MEDIA
# recebe o endereço de um vetor de inteiros e retorna a média aritmética (em
# float) dos valores
#
# input:
#  - a0: *v
#  - a1: n (tamanho do vetor)
# output:
#  - fa0: média resultante
MEDIA:
        li	t0, 0		# t0: i
        li	t1, 0		# t1: soma
loop_media:
        bge	t0, a1, saida_media
        
        slli	t2, t0, 2
        add	t2, a0, t2	# t2: A + i*4
        
        lw	t3, 0(t2)	# t3: A[i] ou *(A + i*4)
        
        add	t1, t1, t3	# t1: soma += A[i]

        addi	t0, t0, 1	# i++
        
        jal	zero, loop_media
        
saida_media:
        fcvt.s.w ft0, t1,	# ft0: (float) soma
        fcvt.s.w ft1, a1	# ft1: (float) n
        fdiv.s	fa0, ft0, ft1	# fa0: ft0 / ft1
        ret