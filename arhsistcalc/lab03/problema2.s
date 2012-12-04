.data
 x: .word 111
 y: .word 222
 z: .word 3

.text
main:
	lw $t0, x
	lw $t1, y
	lw $t2, z
	
	blt		$t0, $t1, x_lt_y	# if $t0 < $t1 then x_lt_y
	j y_lt_x
	
x_lt_y:
	blt		$t0, $t2, x_lt_z	# if $t0 < $t2 then x_lt_z
	j z_lt_x
	
y_lt_x:
	blt		$t1, $t2, x_lt_z	# if $t0 < $t2 then x_lt_z
	j z_lt_x
	
	
x_smaller_than_y:
	blt $t1, $t2, echoZ
	j echoY
	
x_greater_than_y:
	blt $t0, $t2, echoZ
	j echoX

echoZ:
	la $a0, messageZ
	li $v0, 4
	syscall
	j end

end:
	li $v0, 10
	syscall