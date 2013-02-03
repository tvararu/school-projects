#III.11) (puncte - vezi in text) (*)
#a) (3 puncte) 
#  Procedura pentru sortarea unui vector de word prin metoda Bubble sort;
#   procedura primeste ca parametri adresa de inceput a vectorului si numarul 
#   elementelor sale. Program ilustrativ

.data
v: .word 3 2 5 2 1
n: .word 0
i: .space 4
x: .space 4
endl:	.byte 10

.text
procedura:
	subu 	$sp, 4
	sw 		$fp, 0($sp)
	addi 	$fp, $sp, 4
	lw 		$t2, 4($fp)

BubbleSort:
	lw 		$t1, 0($fp) #t1 = va
	li 		$t0, 1   		#t0 = i = 1
	li 		$t3, 1   		#t3 = ok

for:
	bge		$t0, $t2, verifica
	lw		$t4, 0($t1)
	lw		$t5, 4($t1)		
		
	bge		$t5, $t4, continua
	li		$t3, 0
	sw		$t5, 0($t1)
	sw		$t4, 4($t1)
		
	continua:
	addu	$t1, $t1, 4	
	addi	$t0, $t0, 1		
	j for		

verifica:
	addi	$t2, $t2, -1
	beq 	$t3, $0, BubbleSort

	lw 		$fp, 0($sp)
	addiu	$sp, 4
	jr		$ra

main:
	subu 	$sp, 4
	lw 		$t0, n
 	sw 		$t0, 0($sp)
 	subu 	$sp, 4
	la 		$t0, v
 	sw 		$t0, 0($sp)
	jal		procedura
	addiu $sp, 8
	
	li		$t0, 0
	lw		$t0, v($t0)
	sw		$t0, x
	
	lw		$t0, n
	beqz	$t0, end
	
	li		$v0, 1		# system call #4 - print string
	lw		$a0, x
	syscall				# execute
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, endl
	syscall				# execute
	
print_vector:
	lw		$t0, i
	addi	$t0, $t0, 1			# $t0 = $t0 + 1
	sw		$t0, i
	
	lw		$t1, n
	bge		$t0, $t1, end	# if $t0 >= $t1 then end
	
	add		$t0, $t0, $t0		# $t0 = $t0 + $t0
	add		$t0, $t0, $t0		# $t0 = $t0 + $t0
	
	lw		$t0, v($t0)
	sw		$t0, x
	
	li		$v0, 1		# system call #1 - print int
	lw		$a0, x
	syscall				# execute
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, endl
	syscall				# execute
	
	j print_vector
	
end:
	li		$v0, 10
	syscall