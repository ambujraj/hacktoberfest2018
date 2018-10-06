.data
exitcondition : .asciiz "You wont get here"
crash : .asciiz "Crashed"

.text
main:
li $t0, 1 # load 1 into t0
beq $t0, 0 , exit
li $v0, 4 
la $a0, crash
syscall
j main

exit : 
li $v0, 4 # system call code for printing string = 4
la $a0, exitcondition # load address of string to be printed into $a0
syscall
