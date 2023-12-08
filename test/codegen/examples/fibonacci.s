.text
.global fib
fib:
PUSHQ %rbp
MOVQ %rsp, %rbp
PUSHQ %rdi
SUBQ $0, %rsp
PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15
##############
MOVQ -8(%rbp), %rbx
MOVQ $1, %r10
CMP %rbx, %r10
JG .L1
MOVQ $0, %rbx
JMP .L2
.L1:
MOVQ $1, %rbx
.L2:
CMP $0, %rbx
JE .L3
MOVQ $0, %rbx
MOVQ %rbx, %rax
JMP .fib_epilogue
JMP .L4
.L3:
MOVQ -8(%rbp), %rbx
MOVQ $2, %r10
CMP %rbx, %r10
JG .L5
MOVQ $0, %rbx
JMP .L6
.L5:
MOVQ $1, %rbx
.L6:
CMP $0, %rbx
JE .L7
MOVQ $1, %rbx
MOVQ %rbx, %rax
JMP .fib_epilogue
JMP .L8
.L7:
MOVQ -8(%rbp), %rbx
MOVQ $1, %r10
SUBQ %r10, %rbx
MOVQ %rbx, %rdi
PUSHQ %r10
PUSHQ %r11
CALL fib
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
MOVQ -8(%rbp), %r10
MOVQ $2, %r11
SUBQ %r11, %r10
MOVQ %r10, %rdi
PUSHQ %r10
PUSHQ %r11
CALL fib
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
ADDQ %rbx, %r10
MOVQ %r10, %rax
JMP .fib_epilogue
.L8:
.L4:
##############
.fib_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp
POPQ %rbp
RET
.text
.global main
main:
PUSHQ %rbp
MOVQ %rsp, %rbp
PUSHQ %rdi
PUSHQ %rsi
SUBQ $8, %rsp
PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15
##############
.data
.L9: .string "Table of Fibonnacci Numbers\n"
.text
LEAQ .L9, %rbx
MOVQ %rbx, %rdi
CALL print_string
MOVQ $0, %rbx
MOVQ %rbx, -24(%rbp)
.L10:
MOVQ -24(%rbp), %rbx
MOVQ $45, %r10
CMP %rbx, %r10
JG .L12
MOVQ $0, %rbx
JMP .L13
.L12:
MOVQ $1, %rbx
.L13:
CMP $0, %rbx
JE .L11
MOVQ -24(%rbp), %rbx
MOVQ %rbx, %rdi
CALL print_integer
.data
.L14: .string "\t"
.text
LEAQ .L14, %rbx
MOVQ %rbx, %rdi
CALL print_string
MOVQ -24(%rbp), %rbx
MOVQ %rbx, %rdi
PUSHQ %r10
PUSHQ %r11
CALL fib
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
MOVQ %rbx, %rdi
CALL print_integer
.data
.L15: .string "\n"
.text
LEAQ .L15, %rbx
MOVQ %rbx, %rdi
CALL print_string
MOVQ -24(%rbp), %rbx
MOVQ $1, %r10
ADDQ %rbx, %r10
MOVQ %r10, -24(%rbp)
JMP .L10
.L11:
MOVQ $0, %rbx
MOVQ %rbx, %rax
JMP .main_epilogue
##############
.main_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp
POPQ %rbp
RET
