.data
 x: .word 1
 y: .word 2
 z: .word 3
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
	blt $t1, $t2, echoZ
	j echoX

echoX:
	la $a0, messageX
	syscall
	j end
	
echoY:
	la $a0, messageY
	syscall
	j end
	
echoZ:
	la $a0, messageZ
	syscall
	j end

end:
	li $v0, 10
	syscall