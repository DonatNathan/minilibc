section .bss

section .data

section .text
global strrchr

strrchr:
    xor rcx, rcx ;Set cmpt to 0
    mov rax, -1
    cmp sil, 0 ;If char is null
    je .return

.loop:
    cmp byte [rdi + rcx], 0 ;If end of string
    je .return
    cmp byte [rdi + rcx], sil ;If char is found
    je .set_cmpt
    inc rcx ;Inc cmpt
    jmp .loop

.set_cmpt:
    mov rax, rcx ;Get pos of char
    inc rcx
    jmp .loop

.got:
    lea rax, [rdi + rax] ;Get end of string
    ret

.return:
    cmp rax, -1 ;If char found
    jne .got
    xor rax, rax ;Return null
    ret
