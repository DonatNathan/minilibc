section .bss

section .text
global strcmp

strcmp:
	xor rcx, rcx ;Set cmpt to 0

.loop:
    cmp byte [rdi + rcx], 0
    je .stop
    mov al, [rsi + rcx]
    cmp byte [rdi + rcx], al
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
    mov rax, 0
    ret

section .data