.data
	hello: .asciiz "Hello, world!\n"
	
.text
main:
	la $a0, hello
	li $v0, 4
	syscall
	j end
	
end:
	li $v0, 10
	syscall