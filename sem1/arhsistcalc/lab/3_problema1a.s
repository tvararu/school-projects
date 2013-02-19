# III.1) (puncte - vezi in text) (*)
# a) (1 punct) 
#   Functie "sign" ce primeste un parametru word x si returneaza (prin $v0)
#    valoarea 1 daca x>0, 0 daca x=0, -1 daca x<0. Program ilustrativ.
.data
x: .word -20
rezultat: .space 4
endl: .byte 10

.text
sign:
	subu 	$sp, 4
	sw 		$fp, 0($sp)
	addi 	$fp, $sp, 4
	lw		$t0, 0($fp)
	beq		$t0, $0, zero
	bgt		$t0, $0, unu
	blt		$t0, $0, minusunu

zero:
	li 		$v0, 0
	lw 		$fp, 0($sp)
	addiu $sp, 4
	jr 		$ra
unu:
	li 		$v0, 1
	lw 		$fp, 0($sp)
	addiu $sp, 4
	jr 		$ra
minusunu:
	li 		$v0, -1
	lw 		$fp, 0($sp)
	addiu $sp, 4
	jr 		$ra

main:
	subu 	$sp, 4
	lw 		$t0, x
 	sw 		$t0, 0($sp)
 	jal 	sign
 	addiu $sp, 4
 	sw 		$v0, rezultat
	
	li		$v0, 1		# system call #1 - print int
	lw		$a0, rezultat
	syscall
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, endl
	syscall				# execute
	
end:
	li		$v0, 10
 	syscall
