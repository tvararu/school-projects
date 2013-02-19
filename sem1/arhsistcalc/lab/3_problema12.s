# III.12) (1.5 puncte) (*)
#  Functie recursiva ce returneaza (in $v0) suma cifrelor in baza 10 ale unui
# word dat ca parametru.
#  Ideea recursiei: s(0) = 0, altfel s(n) = n mod 10 + s(n div 10).
#  Program ilustrativ.
.data
n: .word 23201
endl: .byte 10

.text
sum:
	#	a0 = n
	# if( n == 0 ) return 0;
	# return n%10 + sum(n/10)
	addi 	$sp, $sp, -16
	sw 		$fp, 12($sp)
	sw 		$ra, 8($sp)
	sw 		$s0, 4($sp)
	sw 		$s1, 0($sp)

	addu 	$fp, $sp, 12

	lw 		$s0, 4($fp)
	beq 	$s0, $zero, return0


	li 		$s1, 10
	div 	$s0, $s1
	mfhi 	$s1
	mflo 	$s0
	
	subu 	$sp, 4
	sw 		$s0, 0($sp)
	jal sum
	addu 	$sp, 4

	add 	$v0, $v0, $s1
	
exitsum:	
	lw 		$fp, 12($sp)
	lw 		$ra, 8($sp)       
	lw 		$s0, 4($sp)
	lw 		$s1, 0($sp)
	addi 	$sp, $sp, 16       
	jr 		$ra

return0:
 	li 		$v0, 0
 	j exitsum

main:
	
	subu 	$sp, 4
	lw 		$t0, n
	sw 		$t0, 0($sp)
	jal 	sum
	addu 	$sp, 4
	
	add 	$a0, $v0, $zero
	li 		$v0, 1
	syscall
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, endl
	syscall				# execute
	
end:
	li 		$v0, 10
	syscall

