main:
    la $a0, main
    li $v0, 1
    syscall
    li $a0, '\n'
    la $v0, 11
    syscall

    la $a0, text_data
    li $v0, 1
    syscall
    li $a0, '\n'
    la $v0, 11
    syscall
    la $a0, text_data_end
    li $v0, 1
    syscall
    li $a0, '\n'
    la $v0, 11
    syscall


    la $a0, align_text_data
    li $v0, 1
    syscall
    li $a0, '\n'
    la $v0, 11
    syscall
    la $a0, align_text_data_end
    li $v0, 1
    syscall
    li $a0, '\n'
    la $v0, 11
    syscall

exit:
    li $v0, 0
    jr $ra

  .word 1001
text_data:
  .space 4096
text_data_end:
  .word 1002

  .word 1003
align_text_data:
  .align 2
  .space 4096
align_text_data_end:
  .word 1004
