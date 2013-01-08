.data
num: .word 0
sir: .asciiz "stristr trsttr"
subsir: .asciiz "str"
endl: .byte 10

.text
main:
	li		$t0, 0		# $t0 = 0
	
strstr:
	li		$v0, 4		# system call #4 - print string
	la		$a0, sir($t0)
	syscall				# execute
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, endl
	syscall				# execute
	
end_strstr:
	
end:
	li		$v0, 10		# $v0 = 10
	syscall
	