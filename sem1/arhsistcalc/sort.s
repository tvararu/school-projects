.data
x: .word 3
y: .word 1
z: .word 2
newline: .asciiz "\n" 

.text
main:
	lw		$t0, x
	lw		$t1, y
	ble		$t0, $t1, et1	# if $t0 <= $t1 then et1
	
	sw		$t0, y
	sw		$t1, x
	
et1:
	lw		$t0, y
	lw		$t1, z
	ble		$t0, $t1, et2	# if $t0 <= $t1 then et2
	
	sw		$t0, z
	sw		$t1, y
	
et2:
	lw		$t0, x
	lw		$t1, y
	ble		$t0, $t1, et3	# if $t0 <= $t1 then et3
	
	sw		$t0, y
	sw		$t1, x

et3:
	li		$v0, 1		# system call #1 - print int
	lw		$a0, x
	syscall				# execute
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, newline
	syscall				# execute
	
	li		$v0, 1		# system call #1 - print int
	lw		$a0, y
	syscall				# execute
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, newline
	syscall				# execute
	
	li		$v0, 1		# system call #1 - print int
	lw		$a0, z
	syscall				# execute
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, newline
	syscall				# execute
	
	# end program
	li		$v0, 10		# $v0 = 10
	syscall
