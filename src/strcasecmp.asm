section .bss

section .text
global strcasecmp

strcasecmp:
	xor rcx, rcx ;Set cmpt to 0

.loop:
    mov al, [rsi + rcx]
    cmp byte [rdi + rcx], al
    jl .stop_less
    jg .stop_greater
    cmp byte [rdi + rcx], 0
    je .stop
    cmp al, 0
    je .stop_less
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

section .data