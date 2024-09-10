section .data
    msg1 db "first input: "
    msg2 db "second input: "

section .text
    global main

main:
    
    push rbp
    mov rbp,rsp
    sub rsp, 0x20

    jmp FIRST_INPUT

FIRST_INPUT:

    xor rdi, rdi
    lea rsi, qword[rbp-0x8]
    mov rdx, 0x1
    mov rax, 0x0
    syscall

    mov rax, qword[rbp-0x8]
    and rax, 0x000000000000000f

    cmp rax, 0x0
    jbe FIRST_INPUT
    cmp rax, 0x9
    ja FIRST_INPUT

    jmp SECOND_INPUT


SECOND_INPUT:
    ;mov rax, 1
	;mov rdi, 1
	;mov rsi, msg2
	;mov rdx, 12
	;syscall

    xor rdi, rdi
    lea rsi, qword[rbp-0xc]
    mov rdx, 0x1
    mov rax, 0x0
    syscall

    mov rax, qword[rbp-0xc]
    and rax, 0x000000000000000f

    cmp rax, 0x0
    jbe SECOND_INPUT
    cmp rax, 0x9
    ja SECOND_INPUT

    mov rdi, 0x1
    mov rax,  [rbp-0x8]
    mov rsi,  [rbp-0xc]
    and rax, 0x000000000000000f
    and rsi, 0x000000000000000f
    add rax, rsi
    mov rsi, rax
    
    add rsi, 0xa30
    cmp rsi, 0xa3a
    jb  print
    sub rsi, 0xa
    shl rsi, 0x8
    add rsi, 0x31
    
    jmp print
print:

    mov [rbp-0x18], rsi
    mov rdx, 4
    mov rdi, 1
    lea rsi, [rbp-0x18]
    mov rax, 0x1
    syscall

    xor rax, rax
    mov rbx, 0
    leave
    ret