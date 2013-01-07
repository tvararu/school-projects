.data
v: .word 1, 234, 3, 4, 5
n: .word 5
i: .space 4
max: .space 4

newline: .asciiz "\n"

.text
main:
	li		$t0, 0
	sw		$t0, i
	
	lw		$t0, v
	sw		$t0, max
	
#loop
begin:	
	lw		$t0, i
	addi	$t0, $t0, 1			# $t0 = $t0 + 1
	sw		$t0, i
	
	lw		$t1, n
	bge		$t0, $t1, end	# if $t0 >= $t1 then end
	
	add		$t0, $t0, $t0		# $t0 = $t0 + $t0
	add		$t0, $t0, $t0		# $t0 = $t0 + $t0
	
	lw		$t0, v($t0)
	lw		$t1, max
	ble		$t0, $t1, begin	# if $t0 <= $t1 then begin
	sw		$t0, max
	
	j begin
	
end:
	li		$v0, 1		# system call #1 - print int
	lw		$a0, max
	syscall				# execute
	
	li		$v0, 4		# system call #4 - print string
	la		$a0, newline
	syscall				# execute
	
	li		$v0, 10
	syscall
	