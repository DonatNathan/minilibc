section .bss

section .text
global memcpy

memcpy:
	xor rcx, rcx ;Set cmpt to 0

.loop:
	cmp rcx, rdx ;If end of cmpt
	je .endset
	mov al, [rsi + rcx] ;Get actual char
	cmp al, 0
	je .endset
	mov [rdi + rcx], al ;Set value of second arg
	inc rcx ;Inc cmpt
	jmp .loop

.endset:
	mov rax, rdi ;Return string
	ret

section .data