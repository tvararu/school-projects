.data
x: .word 4
y: .word 4
eq: .asciiz " == "
neq: .asciiz " != " 
endl: .asciiz "\n"
	
.text
main:
	lw		$t0, x
	lw		$t1, y
	li		$v0, 1		# system call #1 - print int
	lw		$a0, x
	syscall				# execute
	beq		$t0, $t1, is_equal	# if $t0 == $t1 then is_equal
		# isn't equal goes here
		li		$v0, 4		# system call #4 - print string
		la		$a0, neq
		syscall				# execute
		j endif
	is_equal:
		li		$v0, 4		# system call #4 - print string
		la		$a0, eq
		syscall				# execute
endif:
	li		$v0, 1		# system call #1 - print int
	lw		$a0, y
	syscall				# execute
	li		$v0, 4		# system call #4 - print string
	la		$a0, endl
	syscall				# execute
	
end:
	li $v0, 10
	syscall