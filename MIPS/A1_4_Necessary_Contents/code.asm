L1:
or $t1, $t1, $sp
ori $t2, $t2, 5
sub $t3, $t1, $t2
sll $t4, $t1, 2
add $t1, $t1, $t2
andi $t2, $t2, 3
and $t3, $t3, $t4
addi $t2, $t2, 5
srl $t4, $t4, 1
nor $t3, $t2, $t3
subi $t3, $t3, 3
sw $t3, 2($t2)
lw $t2, 2($t2)
or $t2, $t2, $zero
sw $t1, 5($t4)
lw $t3, 5($t4)
or $t3, $t3, $zero
add $t0, $zero, $zero
L2:
addi $t0, $t0, 4
beq $t0, $t1, L2
addi $t0, $t0, 4
L3:
subi $t0, $t0, 4
bneq $t0, $t1, L3
addi $t0, $t0, 4
sw $t4, 3($t0)
push $t0
push 3($t0)
pop $t0
add $t0, $t0, $zero
pop $t0
add $t0, $t0, $zero
j L1
