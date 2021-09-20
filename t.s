

        .data
msg:   .asciiz "Enter the value"
	.extern foobar 4

        .text
        .globl main
main:   
        li $v0, 4
        la $a0, msg
        syscall

        li $v0, 5
        syscall
        move $s0, $v0

        li $v0, 1
        move $a0, $s0
        syscall

        li $v0, 10
        syscall




li $v0, 4       # syscall 4 (print_str)
        la $a0, msg     # argument: string
        syscall         # print the string
        lw $t1, foobar
        
        jr $ra          # retrun to caller
