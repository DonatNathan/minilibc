section .bss

section .text
global strncmp

strncmp:
	xor rcx, rcx ;Set cmpt to 0
    cmp rdx, 0
    je .stop_full

.loop:
    cmp rcx, rdx
    je .stop_full
    mov al, [rsi + rcx]
    mov r8b, byte [rdi + rcx]
    cmp r8b, 0
    je .empty_first
    cmp al, 0
    je .empty_second
    cmp r8b, al
    jl .stop_less
    jg .stop_greater
    inc rcx ;Inc cmpt
    jmp .loop

.stop_less:
    mov rax, -1
    ret

.stop_greater:
    mov rax, 1
    ret

.stop:
    cmp al, 0
    jne .stop_less
    mov rax, 0
    ret

.stop_full:
	mov rax, 0
	ret

.empty_first:
    cmp al, 0
    je .stop
    movzx rax, al
    mov r8, -1
    imul rax, r8
    ret

.empty_second:
    cmp r8b, 0
    je .stop
    movzx rax, r8b
    ret

section .data