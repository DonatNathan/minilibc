section .bss

section .text
global memcpy

;Gestion des null
;Pas de \0

memcpy:
	xor rcx, rcx ;Set cmpt to 0
	cmp rdx, 0
	je .empty

.loop:
	cmp rcx, rdx ;If end of cmpt
	je .endset
	mov al, [rsi + rcx] ;Get actual char
	mov [rdi + rcx], al ;Set value of second arg
	inc rcx ;Inc cmpt
	jmp .loop

.endset:
	mov rax, rdi ;Return string
	ret

.empty:
	cmp rcx, rdx
	je .endset
	mov byte [rdi + rcx], 0
	inc rcx
	jmp .empty

section .data