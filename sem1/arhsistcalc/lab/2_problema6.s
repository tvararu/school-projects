.data
x: .word 1234
sum: .word 0
endl: .byte 10

.text
main:
	li		$t1, 10			# $t1 = 10

loop:
	lw		$t0, x
	beqz	$t0, end_loop
	
	div		$t0, $t1		# $t0 / $t1
	mflo	$t2					# $t2 = floor($t0 / $t1) 
	mfhi	$t3					# $t3 = $t0 mod $t1
	
	sw		$t2, x
	
	lw		$t0, sum
	add		$t0, $t0, $t3		# $t0 = $t0 + $t1
	sw		$t0, sum	
		
	j loop
	
end_loop:
	li		$v0, 1		# system call #1 - print int
	lw		$a0, sum
	syscall					# execute
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, endl
	syscall					# execute
	
end:
	li		$v0, 10
	syscall
	