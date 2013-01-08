.data

len: .space 4
# buffer: .asciiz	"abadc"
buffer: .space 12
# prompt_len: .asciiz "Introduceti lungimea sirului: "
endl: .byte 10

.text
main:
	# li		$v0, 4		# system call #4 - print string
	# la		$a0, prompt_len
	# syscall
	# 
	# li		$v0, 5		# $v0 = 5, read int code
	# syscall
	# move 	$t0, $v0	# $t0 = $v0
	# sw		$t0, len
	
	li		$v0, 8		# $v0 = 8, read string code
	la		$a0, buffer
	li		$a1, 64		# $a1 = 64, max length of buffer
	syscall
	
	# # print first character of string
	# la		$t0, buffer + 4 # + n for other char
	# li		$v0, 11		# $v0 = 11
	# lb		$a0, ($t0)
	# syscall	
	
	# # get character from string and put it in some other part
	# lb		$t0, buffer
	# sb		$t0, buffer+1
strlen:
	li		$t0, 0		# $t0 = 0
	la		$t1, endl
len_loop:
	la		$t2, buffer($t0)
		
	addi	$t0, $t0, 1			# $t0 = $t0 + 1
	
	bne		$t1, $t2, len_loop	# if $t1 != $t2 then len_loop
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
