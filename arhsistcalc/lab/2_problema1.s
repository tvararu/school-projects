.data
x: .word 0
y: .word 0
z: .word 1

n: .word 9
endl: .byte 10

.text
main:
	lb		$t0, n
	addi	$t0, $t0, -2			# $t0 = $t0 - 2
	sb		$t0, n
	
begin_loop:
	lb		$t0, y
	lb		$t1, z
	add		$t2, $t0, $t1		# $t3 = $t1 + $t2
	sb		$t0, x
	sb		$t1, y	
	sb		$t2, z
	
	lb		$t0, n
	addi	$t0, $t0, -1			# $t0 = $t0 - 1
	sb		$t0, n
	
	bnez	$t0, begin_loop
	
end_loop:
	
	li		$v0, 1		# system call #1 - print int
	lw		$a0, z
	syscall					# execute
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, endl
	syscall					# execute
	
end:
	li		$v0, 10		# $v0 = 10
	syscall
	