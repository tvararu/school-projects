.data
 x: .word 111
 y: .word 222
 z: .word 333
 messageX: .asciiz "X este cel mai mare!\n"
 messageY: .asciiz "Y este cel mai mare!\n"
 messageZ: .asciiz "Z este cel mai mare!\n"

.text
main:
	lw $t0, x
	lw $t1, y
	lw $t2, z	
	
	
	
	blt $t0, $t1, x_smaller_than_y
	j x_greater_than_y
	
x_smaller_than_y:
	blt $t1, $t2, echoZ
	j echoY
	
x_greater_than_y:
	blt $t0, $t2, echoZ
	j echoX

echoX:
	la $a0, messageX
	li $v0, 4
	syscall
	j end
	
echoY:
	la $a0, messageY
	li $v0, 4
	syscall
	j end
	
echoZ:
	la $a0, messageZ
	li $v0, 4
	syscall
	j end

end:
	li $v0, 10
	syscall