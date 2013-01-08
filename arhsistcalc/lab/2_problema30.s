.data
buffer: .space 8
len: .space 4
endl: .byte 10

.text
main:
	li		$v0, 8		# $v0 = 8, read string code
	la		$a0, buffer
	li		$a1, 8		# $a1 = 64, max length of buffer
	syscall
	
	li		$v0, 4		# $v0 = 4, print string code
	la		$a0, buffer
	syscall
	
strlen:
	li		$t0, 0		# $t0 = 0
	lb		$t2, endl
		
len_loop:
	la		$t1, 0($a0)
	
	addi	$t0, $t0, 1			# $t0 = $t0 + 1
	
	beqz	$t1, len_loop
len_end:	
	sw		$t0, len
	
	li		$v0, 1		# system call #1 - print int
	lw		$a0, len
	syscall				# execute
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, endl
	syscall				# execute
	
end:
	li		$v0, 10		# $v0 = 10, end program code
	syscall
