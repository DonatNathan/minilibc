section .bss

section .text
global memcpy

memcpy:
	xor rcx, rcx ;Set cmpt to 0
	mov al, [rsi + rcx] ;Get actual char
	cmp al, 0
	je .empty

.loop:
	mov al, [rsi + rcx] ;Get actual char
	cmp al, 0
	je .endset
	cmp rcx, rdx ;If end of cmpt
	je .endset
	mov [rdi + rcx], al ;Set value of second arg
	inc rcx ;Inc cmpt
	jmp .loop

.endset:
	mov rax, rdi ;Return string
	ret

.empty:
	cmp byte [rdi + rcx], 0
	je .endset
	mov byte [rdi + rcx], 0
	inc rcx
	jmp .empty

section .data