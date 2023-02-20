section .bss

section .data

section .text
global strchr

strchr:
    xor rcx, rcx ;Set cmpt to 0
    cmp sil, 0
    je .nothing

.loop:
    cmp byte [rdi + rcx], 0 ;If end of string
    je .return
    cmp byte [rdi + rcx], sil ;If char is found
    je .got
    inc rcx ;Inc cmpt
    jmp .loop

.got:
    lea rax, [rdi + rcx] ;Get end of string
    ret

.return:
    xor rax, rax ;Return null
    ret

.nothing:
    cmp byte [rdi], 0 ;If end of string
    je .other_return
    inc rdi
    jmp .nothing

.other_return:
    mov rax, rdi
    ret
