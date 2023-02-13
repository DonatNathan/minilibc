section .bss

section .text
global strlen

strlen:
	xor rcx,rcx

.loop:
	mov al,[rdi + rcx]
	cmp al,0
	je .return
	add rcx,1
	jmp .loop

.return:
	mov rax,rcx
	ret

section .data
