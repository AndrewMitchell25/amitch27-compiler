.text
.global gfx_open
.text
.global gfx_point
.text
.global gfx_line
.text
.global gfx_color
.text
.global gfx_clear
.text
.global gfx_clear_color
.text
.global gfx_wait
.text
.global gfx_xpos
.text
.global gfx_ypos
.text
.global gfx_xsize
.text
.global gfx_ysize
.text
.global gfx_event_waiting
.text
.global gfx_flush
.text
.global usleep
.text
.global rand
.text
.global draw_box
draw_box:
PUSHQ %rbp
MOVQ %rsp, %rbp
PUSHQ %rdi
PUSHQ %rsi
PUSHQ %rdx
SUBQ $0, %rsp
PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15
##############
MOVQ $255, %rbx
MOVQ %rbx, %rdi
MOVQ $255, %rbx
MOVQ %rbx, %rsi
MOVQ $255, %rbx
MOVQ %rbx, %rdx
PUSHQ %r10
PUSHQ %r11
CALL gfx_color
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
MOVQ -8(%rbp), %rbx
MOVQ %rbx, %rdi
MOVQ -16(%rbp), %rbx
MOVQ %rbx, %rsi
MOVQ -8(%rbp), %rbx
MOVQ -24(%rbp), %r10
ADDQ %rbx, %r10
MOVQ %r10, %rdx
MOVQ -16(%rbp), %rbx
MOVQ %rbx, %rcx
PUSHQ %r10
PUSHQ %r11
CALL gfx_line
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
MOVQ -8(%rbp), %rbx
MOVQ -24(%rbp), %r10
ADDQ %rbx, %r10
MOVQ %r10, %rdi
MOVQ -16(%rbp), %rbx
MOVQ %rbx, %rsi
MOVQ -8(%rbp), %rbx
MOVQ -24(%rbp), %r10
ADDQ %rbx, %r10
MOVQ %r10, %rdx
MOVQ -16(%rbp), %rbx
MOVQ -24(%rbp), %r10
ADDQ %rbx, %r10
MOVQ %r10, %rcx
PUSHQ %r10
PUSHQ %r11
CALL gfx_line
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
MOVQ -8(%rbp), %rbx
MOVQ -24(%rbp), %r10
ADDQ %rbx, %r10
MOVQ %r10, %rdi
MOVQ -16(%rbp), %rbx
MOVQ -24(%rbp), %r10
ADDQ %rbx, %r10
MOVQ %r10, %rsi
MOVQ -8(%rbp), %rbx
MOVQ %rbx, %rdx
MOVQ -16(%rbp), %rbx
MOVQ -24(%rbp), %r10
ADDQ %rbx, %r10
MOVQ %r10, %rcx
PUSHQ %r10
PUSHQ %r11
CALL gfx_line
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
MOVQ -8(%rbp), %rbx
MOVQ %rbx, %rdi
MOVQ -16(%rbp), %rbx
MOVQ -24(%rbp), %r10
ADDQ %rbx, %r10
MOVQ %r10, %rsi
MOVQ -8(%rbp), %rbx
MOVQ %rbx, %rdx
MOVQ -16(%rbp), %rbx
MOVQ %rbx, %rcx
PUSHQ %r10
PUSHQ %r11
CALL gfx_line
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
##############
.draw_box_epilogue:
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
SUBQ $72, %rsp
PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15
##############
MOVQ $100, %rbx
MOVQ %rbx, -8(%rbp)
MOVQ $500, %rbx
MOVQ %rbx, -16(%rbp)
MOVQ $500, %rbx
MOVQ %rbx, -24(%rbp)
MOVQ -8(%rbp), %rbx
MOVQ -16(%rbp), %r10
MOVQ %rbx, %rax
IMULQ %r10
MOVQ %rax, %rbx
MOVQ $2, %r10
MOVQ %rbx, %rax
CQO
IDIVQ %r10
MOVQ %rax, %rbx
MOVQ %rbx, -32(%rbp)
MOVQ -8(%rbp), %rbx
MOVQ -24(%rbp), %r10
MOVQ %rbx, %rax
IMULQ %r10
MOVQ %rax, %rbx
MOVQ $2, %r10
MOVQ %rbx, %rax
CQO
IDIVQ %r10
MOVQ %rax, %rbx
MOVQ %rbx, -40(%rbp)
MOVQ -8(%rbp), %rbx
MOVQ $3, %r10
MOVQ %rbx, %rax
IMULQ %r10
MOVQ %rax, %rbx
MOVQ %rbx, -48(%rbp)
MOVQ -8(%rbp), %rbx
MOVQ $5, %r10
MOVQ $0, %r11
SUBQ %r10, %r11
MOVQ %rbx, %rax
IMULQ %r11
MOVQ %rax, %rbx
MOVQ %rbx, -56(%rbp)
MOVQ $100, %rbx
MOVQ %rbx, -64(%rbp)
MOVQ -16(%rbp), %rbx
MOVQ %rbx, %rdi
MOVQ -24(%rbp), %rbx
MOVQ %rbx, %rsi
.data
.L1: .string "Bounce!"
.text
LEAQ .L1, %rbx
MOVQ %rbx, %rdx
PUSHQ %r10
PUSHQ %r11
CALL gfx_open
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
.L2:
.data
.L4: .string "x: "
.text
LEAQ .L4, %rbx
MOVQ %rbx, %rdi
CALL print_string
MOVQ -32(%rbp), %rbx
MOVQ %rbx, %rdi
CALL print_integer
.data
.L5: .string " y: "
.text
LEAQ .L5, %rbx
MOVQ %rbx, %rdi
CALL print_string
MOVQ -40(%rbp), %rbx
MOVQ %rbx, %rdi
CALL print_integer
.data
.L6: .string " vx: "
.text
LEAQ .L6, %rbx
MOVQ %rbx, %rdi
CALL print_string
MOVQ -48(%rbp), %rbx
MOVQ %rbx, %rdi
CALL print_integer
.data
.L7: .string " vy: "
.text
LEAQ .L7, %rbx
MOVQ %rbx, %rdi
CALL print_string
MOVQ -56(%rbp), %rbx
MOVQ %rbx, %rdi
CALL print_integer
.data
.L8: .string "\n"
.text
LEAQ .L8, %rbx
MOVQ %rbx, %rdi
CALL print_string
PUSHQ %r10
PUSHQ %r11
CALL gfx_event_waiting
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
CMP $0, %rbx
JE .L9
PUSHQ %r10
PUSHQ %r11
CALL gfx_wait
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
MOVQ %rbx, -72(%rbp)
MOVQ -72(%rbp), %rbx
MOVQ $113, %r10
CMP %rbx, %r10
JE .L11
MOVQ $0, %rbx
JMP .L12
.L11:
MOVQ $1, %rbx
.L12:
CMP $0, %rbx
JE .L13
MOVQ $0, %rbx
MOVQ %rbx, %rax
JMP .main_epilogue
JMP .L14
.L13:
.L14:
PUSHQ %r10
PUSHQ %r11
CALL gfx_xpos
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
MOVQ -8(%rbp), %r10
MOVQ %rbx, %rax
IMULQ %r10
MOVQ %rax, %rbx
MOVQ %rbx, -32(%rbp)
PUSHQ %r10
PUSHQ %r11
CALL gfx_ypos
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
MOVQ -8(%rbp), %r10
MOVQ %rbx, %rax
IMULQ %r10
MOVQ %rax, %rbx
MOVQ %rbx, -40(%rbp)
MOVQ $5, %rbx
MOVQ -8(%rbp), %r10
MOVQ %rbx, %rax
IMULQ %r10
MOVQ %rax, %rbx
MOVQ %rbx, -48(%rbp)
JMP .L10
.L9:
.L10:
MOVQ -56(%rbp), %rbx
MOVQ $1, %r10
MOVQ -8(%rbp), %r11
MOVQ %r10, %rax
IMULQ %r11
MOVQ %rax, %r10
ADDQ %rbx, %r10
MOVQ %r10, -56(%rbp)
MOVQ -32(%rbp), %rbx
MOVQ $0, %r10
CMP %rbx, %r10
JG .L15
MOVQ $0, %rbx
JMP .L16
.L15:
MOVQ $1, %rbx
.L16:
MOVQ -48(%rbp), %r10
MOVQ $0, %r11
CMP %r10, %r11
JG .L17
MOVQ $0, %r10
JMP .L18
.L17:
MOVQ $1, %r10
.L18:
CMP $0, %rbx
JNE .L19
MOVQ $0, %r10
.L19:
CMP $0, %r10
JE .L20
MOVQ $9, %rbx
MOVQ $0, %r10
SUBQ %rbx, %r10
MOVQ -48(%rbp), %rbx
MOVQ %r10, %rax
IMULQ %rbx
MOVQ %rax, %rbx
MOVQ $10, %r10
MOVQ %rbx, %rax
CQO
IDIVQ %r10
MOVQ %rax, %rbx
MOVQ %rbx, -48(%rbp)
JMP .L21
.L20:
.L21:
MOVQ -32(%rbp), %rbx
MOVQ -16(%rbp), %r10
MOVQ -8(%rbp), %r11
MOVQ %r10, %rax
IMULQ %r11
MOVQ %rax, %r10
CMP %rbx, %r10
JL .L22
MOVQ $0, %rbx
JMP .L23
.L22:
MOVQ $1, %rbx
.L23:
MOVQ -48(%rbp), %r10
MOVQ $0, %r11
CMP %r10, %r11
JL .L24
MOVQ $0, %r10
JMP .L25
.L24:
MOVQ $1, %r10
.L25:
CMP $0, %rbx
JNE .L26
MOVQ $0, %r10
.L26:
CMP $0, %r10
JE .L27
MOVQ $9, %rbx
MOVQ $0, %r10
SUBQ %rbx, %r10
MOVQ -48(%rbp), %rbx
MOVQ %r10, %rax
IMULQ %rbx
MOVQ %rax, %rbx
MOVQ $10, %r10
MOVQ %rbx, %rax
CQO
IDIVQ %r10
MOVQ %rax, %rbx
MOVQ %rbx, -48(%rbp)
JMP .L28
.L27:
.L28:
MOVQ -40(%rbp), %rbx
MOVQ -24(%rbp), %r10
MOVQ -8(%rbp), %r11
MOVQ %r10, %rax
IMULQ %r11
MOVQ %rax, %r10
CMP %rbx, %r10
JL .L29
MOVQ $0, %rbx
JMP .L30
.L29:
MOVQ $1, %rbx
.L30:
MOVQ -56(%rbp), %r10
MOVQ $0, %r11
CMP %r10, %r11
JL .L31
MOVQ $0, %r10
JMP .L32
.L31:
MOVQ $1, %r10
.L32:
CMP $0, %rbx
JNE .L33
MOVQ $0, %r10
.L33:
CMP $0, %r10
JE .L34
MOVQ $9, %rbx
MOVQ $0, %r10
SUBQ %rbx, %r10
MOVQ -56(%rbp), %rbx
MOVQ %r10, %rax
IMULQ %rbx
MOVQ %rax, %rbx
MOVQ $10, %r10
MOVQ %rbx, %rax
CQO
IDIVQ %r10
MOVQ %rax, %rbx
MOVQ %rbx, -56(%rbp)
JMP .L35
.L34:
.L35:
MOVQ -32(%rbp), %rbx
MOVQ -48(%rbp), %r10
MOVQ -64(%rbp), %r11
MOVQ %r10, %rax
IMULQ %r11
MOVQ %rax, %r10
MOVQ -8(%rbp), %r11
MOVQ %r10, %rax
CQO
IDIVQ %r11
MOVQ %rax, %r10
ADDQ %rbx, %r10
MOVQ %r10, -32(%rbp)
MOVQ -40(%rbp), %rbx
MOVQ -56(%rbp), %r10
MOVQ -64(%rbp), %r11
MOVQ %r10, %rax
IMULQ %r11
MOVQ %rax, %r10
MOVQ -8(%rbp), %r11
MOVQ %r10, %rax
CQO
IDIVQ %r11
MOVQ %rax, %r10
ADDQ %rbx, %r10
MOVQ %r10, -40(%rbp)
PUSHQ %r10
PUSHQ %r11
CALL gfx_clear
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
MOVQ -32(%rbp), %rbx
MOVQ -8(%rbp), %r10
MOVQ %rbx, %rax
CQO
IDIVQ %r10
MOVQ %rax, %rbx
MOVQ %rbx, %rdi
MOVQ -40(%rbp), %rbx
MOVQ -8(%rbp), %r10
MOVQ %rbx, %rax
CQO
IDIVQ %r10
MOVQ %rax, %rbx
MOVQ %rbx, %rsi
MOVQ $25, %rbx
MOVQ %rbx, %rdx
PUSHQ %r10
PUSHQ %r11
CALL draw_box
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
PUSHQ %r10
PUSHQ %r11
CALL gfx_flush
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
MOVQ -64(%rbp), %rbx
MOVQ -8(%rbp), %r10
MOVQ %rbx, %rax
IMULQ %r10
MOVQ %rax, %rbx
MOVQ %rbx, %rdi
PUSHQ %r10
PUSHQ %r11
CALL usleep
POPQ %r11
POPQ %r10
MOVQ %rax, %rbx
JMP .L2
.L3:
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
