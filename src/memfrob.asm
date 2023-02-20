section .bss

section .text
global memfrob

memfrob:
    xor rcx, rcx
    
.loop:
    cmp byte [rdi + rcx], 0
    je .return
    cmp rcx, rdx
    je .return
    xor byte [rdi + rcx], 42
    inc rcx
    jmp .loop

.return:
    mov rax, rdi
    ret

section .data