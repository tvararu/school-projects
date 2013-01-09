.data
v: .word 1, 28, 3, 4, 5
n: .word 5
i: .space 4
sum: .space 4
newline: .asciiz "\n"

.text
main:
	li		$t0, 0
	sw		$t0, i
	
	li		$t2, 0		# sum register
loop:
	
	lw		$t1, v($t0)
	add		$t2, $t2, $t1		# $t2 = $t2 + $t1
	
	lw		$t0, i
	addi	$t0, $t0, 1			# $t0 = $t0 + 1
	sw		$t0, i
	
	lw		$t1, n
	bge		$t0, $t1, end	# if $t0 >= $t1 then end
	
	add		$t0, $t0, $t0		# $t0 = $t0 + $t0
	add		$t0, $t0, $t0		# $t0 = $t0 + $t0
	
	j loop
	
end:
	sw		$t2, sum
	
	li		$v0, 1		# system call #1 - print int
	lw		$a0, sum
	syscall					# execute
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, newline
	syscall					# execute
	
	li		$v0, 10
	syscall
	