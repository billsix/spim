# SPIM S20 MIPS simulator.
# A torture test for the SPIM simulator.
# Test assembler directives.
#
# Copyright (c) 2021, James R. Larus.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:
#
# Redistributions of source code must retain the above copyright notice,
# this list of conditions and the following disclaimer.
#
# Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation and/or
# other materials provided with the distribution.
#
# Neither the name of the James R. Larus nor the names of its contributors may be
# used to endorse or promote products derived from this software without specific
# prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
# GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#



    .data
saved_ret_pc:	.word 0		# Holds PC to return from main
m1:	.asciiz "Tests 1\n"
    .data
    .align 2
l1: .byte 0xff
l2: .half 0xffff
l3: .word 0xffff
l4: .float 1.0
l5: .double 1.0

m2:	.asciiz "Tests 2\n"
    .data
    .align 2
l12: .byte 0xff
l22: .half 0xffff
    .byte 0xff
l32: .word 0xffff
    .byte 0xff
l42: .float 1.0
    .byte 0xff
l52: .double 1.0

m3:	.asciiz "Tests 3\n"
    .data
    .align 0
l13: .byte 0xff
l23: .half 0xffff
l33: .word 0xffff
l43: .float 1.0
l53: .double 1.0

	.text
	.globl main
main:
	sw $31 saved_ret_pc
    

    li $v0 4	# syscall 4 (print_str)
	la $a0 m1
	syscall

    la $t0 l1
    and $t0 $t0 0x3
    bne $t0 0x0 fail

    la $t0 l2
    and $t0 $t0 0x3
    bne $t0 0x2 fail

    la $t0 l3
    and $t0 $t0 0x3
    bne $t0 0x0 fail

    la $t0 l4
    and $t0 $t0 0x3
    bne $t0 0x0 fail

    la $t0 l5
    and $t0 $t0 0x3
    bne $t0 0x0 fail


    li $v0 4	# syscall 4 (print_str)
	la $a0 m2
	syscall

    la $t0 l12
    and $t0 $t0 0x3
    bne $t0 0x0 fail

    la $t0 l22
    and $t0 $t0 0x3
    bne $t0 0x2 fail

    la $t0 l32
    and $t0 $t0 0x3
    bne $t0 0x0 fail

    la $t0 l42
    and $t0 $t0 0x3
    bne $t0 0x0 fail

    la $t0 l52
    and $t0 $t0 0x7
    bne $t0 0x0 fail


li $v0 4	# syscall 4 (print_str)
	la $a0 m3
	syscall

    la $t0 l13
    and $t0 $t0 0x3
    bne $t0 0x1 fail

    la $t0 l23
    and $t0 $t0 0x3
    bne $t0 0x2 fail

    la $t0 l33
    and $t0 $t0 0x3
    bne $t0 0x0 fail

    la $t0 l43
    and $t0 $t0 0x3
    bne $t0 0x0 fail

    la $t0 l53
    and $t0 $t0 0x3
    bne $t0 0x0 fail

# Done !!!
	.data
sm:	.asciiz "\nPassed all tests\n"
	.text
	li $v0 4	# syscall 4 (print_str)
	la $a0 sm
	syscall
	lw $31 saved_ret_pc
	jr $31		# Return from main


	.data
fm:	.asciiz "Failed test\n"
	.text
fail:	li $v0 4	# syscall 4 (print_str)
	la $a0 fm
	syscall
	li $v0, 10	# syscall 10 (exit)
	syscall

