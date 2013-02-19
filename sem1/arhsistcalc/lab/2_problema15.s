.data
target: .word 13
sum: .word 0
endl: .byte 10

.text
main:
	lw		$t0, target
	li		$t1, 0		# $t1 = 0, suma bitilor de pana acum
	
begin_loop:
	beqz	$t0, end_loop
	
	andi	$t2, $t0, 1
	add		$t1, $t1, $t2		# $t1 = $t1 + $t2
	
	srl		$t0, $t0, 1
	
	b begin_loop
	
end_loop:
	sw		$t1, sum
	
	li		$v0, 1		# system call #1 - print int
	lw		$a0, sum
	syscall					# execute
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, endl
	syscall					# execute
	
	li		$v0, 10		# $v0 = 10
	syscall	
