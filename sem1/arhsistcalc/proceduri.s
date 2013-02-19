.data

endl: .asciiz "\n"

.text
main:
	jal		newline
	jal		newline
	jal		newline
	jal		newline
	jal		newline
	jal		newline
	jal		newline
	
end:
	li		$v0, 10
	syscall
	
newline:
	subu	$sp, 8
	sw		$v0, 4($sp)
	sw		$a0, 0($sp)
	li		$v0, 4
	la		$a0, endl
	syscall
	lw		$a0, 0($sp)
	lw		$v0, 4($sp)
	addu	$sp, 8
	jr		$ra