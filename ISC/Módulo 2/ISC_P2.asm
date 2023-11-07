.data
ESPACO:		.string " "
QUEBRA:		.string "\n"
STR_PRIMO:	.string " é primo!"
STR_TEM:	.string " tem "
STR_MULT:	.string " múltiplos acima de 2."


.text

# s0: n | t0: 2 | t1: count | t2: mult | t3: resto
	li a7, 5
	ecall
	mv s0, a0
	
	li t1, 2
	
LOOP:	bge t1, s0, DONE
	
	rem t3, s0, t1
	bne t3, zero, NEXT

	addi t2, t2, 1
	
	li a7, 1
	mv a0, t1
	ecall
	
	li a7, 4
	la a0, ESPACO
	ecall

NEXT:	addi t1, t1, 1
	j LOOP

DONE:	li a7, 4
	la a0, QUEBRA
	ecall
	
	li a7, 1
	mv a0, s0
	ecall

	li a7, 4

	beq t2, zero, PRIMO

	la a0, STR_TEM
	ecall
	
	li a7, 1
	mv a0, t2
	ecall
	
	li a7, 4
	la a0, STR_MULT
	ecall
	
	j END

PRIMO:	la a0, STR_PRIMO
	ecall
	
END:	li a7, 10
	ecall









#	li a7, 5
#	ecall
#	mv s0, a0
#	
#	ecall
#	mv s1, a0
#	
#	li t0, 4
#	
#LOOP:	blt s1, s0, DONE
#	
#	rem t1, s0, t0
#	beq t1, zero, NEXT
#	
#	add s2, s2, s0
#	
#NEXT:	addi s0, s0, 1
#	j LOOP
	
#DONE:	li a7, 1
#	mv a0, s2
#	ecall
	
#	li a7, 10
#	ecall
