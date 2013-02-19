# III.1) (puncte - vezi in text) (*)
# b) (1 punct)
#   Acelasi lucru ca la (a) dar cu retur prin stiva.
.data
x: .word 20
rezultat: .space 4
endl: .byte 10

.text
sign:
	subu	$sp, 4
	sw 		$fp, 0($sp)
	addi 	$fp, $sp, 4
	lw 		$t0, 0($fp)
	beq		$t0, $0, zero
	bgt		$t0, $0, unu
	blt		$t0, $0, minusunu

zero:
	li 		$t0, 0
	sw 		$t0, 0($fp)
	lw 		$fp, 0($sp)
	addiu $sp, 4
	jr 		$ra
unu:
	li 		$t0, 1
	sw 		$t0, 0($fp)
	lw 		$fp, 0($sp)
	addiu $sp, 4
	jr 		$ra
minusunu:
	li 		$t0, -1
	sw 		$t0, 0($fp)
	lw 		$fp, 0($sp)
	addiu $sp, 4
	jr 		$ra

main:
	subu 	$sp, 4
	lw 		$t0, x
 	sw 		$t0, 0($sp)
 	jal sign
 	lw 		$t1, 0($sp)
 	sw 		$t1, rezultat
 	addiu $sp, 4
	
	li		$v0, 1		# system call #1 - print int
	lw		$a0, rezultat
	syscall
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, endl
	syscall				# execute
	
end:
 	li 		$v0, 10
 	syscall