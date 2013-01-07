.data
x: .word 1
y: .word 2
newline: .asciiz "\n"

.text
main:
	la		$t2, x
	lw		$t0, 0($t2)
	lw		$t1, 4($t2)
	sw		$t0, 4($t2)
	sw		$t1, 0($t2)
	
	li		$v0, 1 # switch to print_int mode
	lw		$a0, x
	syscall
	
	li		$v0, 4
	la		$a0, newline
	syscall
	
	li		$v0, 1
	lw		$a0, y
	syscall
	
	li		$v0, 4
	la		$a0, newline
	syscall
	
	j 		end				# jump to end
	
end:
	li $v0, 10
	syscall
	