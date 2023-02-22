section .bss

section .text
global strcasecmp

strcasecmp:
	xor rcx, rcx ;Set cmpt to 0
    mov al, [rsi + rcx]
    mov r8b, byte [rdi + rcx]
    cmp r8b, 0
    je .empty_first
    cmp al, 0
    je .empty_second

.loop:
    mov al, [rsi + rcx]
    mov r8b, byte [rdi + rcx]
    cmp r8b, 0
    je .stop
    cmp al, 0
    je .stop_less
    cmp al, 'A'
    jge .snake_case_al

.continue_al:
    cmp r8b, 'A'
    jge .snake_case

.continue:
    cmp r8b, al
    jl .stop_less
    jg .stop_greater
    inc rcx ;Inc cmpt
    jmp .loop

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

.snake_case:
    cmp r8b, 'Z'
    jle .change_value
    jmp .continue

.change_value:
    add r8b, 32
    jmp .continue

.snake_case_al:
    cmp al, 'Z'
    jle .change_value_al
    jmp .continue_al

.change_value_al:
    add al, 32
    jmp .continue_al

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