.data
v: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
n: .word 4
x: .word 0 # eticheta temp pentru printat la consola

endl: .byte 10

.text
main:
	lw		$t0, n
	li		$t1, 0		# $t1 = 0
	li		$t4, 4		# $t4 = 4, numarul de bytes intr-un word
	li		$t5, 0		# $t5 = 0, indicele in bytes pentru vector
	
	
begin_loop:
	lw		$t3, v($t5)
	sw		$t3, x
	
	li		$v0, 1		# system call #1 - print int
	lw		$a0, x
	syscall					# execute
	li		$v0, 4		# system call #4 - print string
	la		$a0, endl
	syscall					# execute
	
	addi	$t1, $t1, 1		# $t1 = $t1 + 1, sau i++
	
	bge		$t1, $t0, end_loop	# if $t1 >= $t0 then end_loop
	
	addi	$t2, $t0, 1		# $t2 = n + 1, pentru formula
	
	mult	$t1, $t2			# i * (n + 1)
	mflo	$t3						# rezultatul inmultirii
	mult	$t3, $t4			# (i * (n + 1)) * 4
	mflo	$t5						# rezultatul final, in $t5
	
	j begin_loop
	
end_loop:
	
end:
	li		$v0, 10		# $v0 = 10
	syscall
	