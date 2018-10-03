factorial: addi $sp, $sp, −8 # make room on stack
0x94 sw $a0, 4($sp) # store $a0
0x98 sw $ra, 0($sp) # store $ra
0x9C addi $t0, $0, 2 # $t0 = 2
OxAO slt $t0, $a0, $t0 # n <= 1 ?
0xA4 beq $t0, $0, else # no: goto else
0xA8 addi $v0, $0, 1 # yes: return 1
OxAC addi $sp, $sp, 8 # restore $sp
OxBO jr $ra # return
0xB4 else: addi $a0, $a0, −1 #n = n − 1
0xB8 jal factorial # recursive call
OxBC Iw $ra, 0($sp) # restore $ra
OxCO Iw $a0, 4($sp) # restore $a0
0xC4 addi $sp, $sp, 8 # restore $sp
0xC8 mul $v0, $a0, $v0 # n * factorial(n−1)
OxCC jr $ra # return
