.data
x: .word 0
y: .word 1
z: .word 1

n: .word 9
endl: .byte 10

.text
main:
	lw		$t0, n
	li		$t1, 1
	beq		$t0, $t1, end_loop
	li		$t1, 2
	beq		$t0, $t1, end_loop
	
	addi	$t0, $t0, -2			# $t0 = $t0 - 2
	sw		$t0, n
	
	
begin_loop:
	lw		$t0, y
	lw		$t1, z
	add		$t2, $t0, $t1		# $t3 = $t1 + $t2
	sw		$t0, x
	sw		$t1, y	
	sw		$t2, z
	
	lw		$t0, n
	addi	$t0, $t0, -1			# $t0 = $t0 - 1
	sw		$t0, n
	
	bnez	$t0, begin_loop
	
end_loop:
	
	li		$v0, 1		# system call #1 - print int
	lw		$a0, z
	syscall					# execute
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, endl
	syscall				# execute
	
end:
	li		$v0, 10		# $v0 = 10
	syscall
	