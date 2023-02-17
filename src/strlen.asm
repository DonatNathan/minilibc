section .bss

section .data

section .text
global strlen

strlen:
	xor rcx,rcx ;Set cmpt to 0

.loop:
	mov al,[rdi + rcx] ;Get char
	cmp al,0 ;If end of string
	je .return
	add rcx,1 ;Inc cmpt
	jmp .loop

.return:
	mov rax,rcx ;Return cmpt
	ret

