.text
.global rand
.text
.global srand
.text
.global time
.text
.global main
main:
PUSHQ %rbp
MOVQ %rsp, %rbp
SUBQ $32, %rsp
PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15
##############
MOVQ $20, %rbx
MOVQ %rbx, -8(%rbp)
MOVQ $20, %rbx
MOVQ %rbx, -16(%rbp)
MOVQ $0, %rbx
MOVQ %rbx, %rdi
PUSHQ %r10
PUSHQ %r11
CALL time
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
MOVQ %rbx, %rdi
PUSHQ %r10
PUSHQ %r11
CALL srand
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
MOVQ $0, %rbx
MOVQ %rbx, -32(%rbp)
.L1:
MOVQ -32(%rbp), %rbx
MOVQ -16(%rbp), %r10
CMP %rbx, %r10
JG .L3
MOVQ $0, %rbx
JMP .L4
.L3:
MOVQ $1, %rbx
.L4:
CMP $0, %rbx
JE .L2
MOVQ $0, %rbx
MOVQ %rbx, -24(%rbp)
.L5:
MOVQ -24(%rbp), %rbx
MOVQ -8(%rbp), %r10
CMP %rbx, %r10
JG .L7
MOVQ $0, %rbx
JMP .L8
.L7:
MOVQ $1, %rbx
.L8:
CMP $0, %rbx
JE .L6
PUSHQ %r10
PUSHQ %r11
CALL rand
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
MOVQ $2, %r10
MOVQ %rbx, %rax
CQO
IDIVQ %r10
MOVQ %rdx, %rbx
MOVQ $1, %r10
CMP %rbx, %r10
JE .L9
MOVQ $0, %rbx
JMP .L10
.L9:
MOVQ $1, %rbx
.L10:
CMP $0, %rbx
JE .L11
MOVQ $47, %rbx
MOVQ %rbx, %rdi
CALL print_character
JMP .L12
.L11:
MOVQ $92, %rbx
MOVQ %rbx, %rdi
CALL print_character
.L12:
MOVQ -24(%rbp), %rbx
INCQ %rbx
MOVQ %rbx, -24(%rbp)
JMP .L5
.L6:
.data
.L13: .string "\n"
.text
LEAQ .L13, %rbx
MOVQ %rbx, %rdi
CALL print_string
MOVQ -32(%rbp), %rbx
INCQ %rbx
MOVQ %rbx, -32(%rbp)
JMP .L1
.L2:
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
