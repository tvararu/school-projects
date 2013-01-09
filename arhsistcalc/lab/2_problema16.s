.data
# target: .word 3356426421
target: .word 1
result: .word 0
endl: .byte 10 

.text
main:
	lw		$t0, target
	li		$t1, 0		# $t1 = 0, in care construim rezultatul
	li		$t2, 32		# $t2 = 32, counter-ul pentru loop
	
begin_loop:
	
	sll		$t1, $t1, 1
	
	andi	$t3, $t0, 1
	add		$t1, $t1, $t3		# $t1 = $t1 + $t3
	
	srl		$t0, $t0, 1
	
	addi	$t2, $t2, -1			# $t2 = $t2 - 1
	
	bnez	$t2, begin_loop
	
end_loop:
	sw		$t1, result
	
	li		$v0, 1		# system call #1 - print int
	lw		$a0, result
	syscall					# execute
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, endl
	syscall					# execute
	
end:
	li		$v0, 10		# $v0 = 10
	syscall
	