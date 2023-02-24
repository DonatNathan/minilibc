section .bss

section .text
global memcpy

;Gestion des null
;Pas de \0

memcpy:
	xor rcx, rcx ;Set cmpt to 0

.loop:
	mov al, [rsi + rcx] ;Get actual char
	cmp rcx, rdx ;If end of cmpt
	je .endset
	mov [rdi + rcx], al ;Set value of second arg
	inc rcx ;Inc cmpt
	jmp .loop

.endset:
	mov rax, rdi ;Return string
	ret

.empty:
	cmp byte rcx, rdx
	je .endset
	mov byte [rdi + rcx], 0
	inc rcx
	jmp .empty

section .data