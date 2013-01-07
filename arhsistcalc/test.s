.data
	str: .asciiz "something\n"
	
.text
main:
	
	# j end
	
label:
	li $v0, 4
	la $a0, str
	syscall
	
end:
	li $v0, 10
	syscall