#  a basic example in mips-assembler: hello world.
#  tested with xspim-7.0
   
	.text
	.globl main
	
main:
	li       $v0, 4            # call = 4 = print_string
	la       $a0, hello_string # set $a0 to point to the string
	syscall                    # print it.
	li       $v0, 10           # call = 10 = exit
	syscall                    # done.
	
	
	.data
	
hello_string:  .asciiz  "Hello World!\n"
