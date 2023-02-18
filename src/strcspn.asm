section .bss

section .text
global strcspn

strcspn:
	xor rcx, rcx
	xor rdx, rdx

.loop:
	cmp byte [rdi], 0
	je .return
	mov al, [rsi + rcx]
	cmp al, 0
	je .reset
	cmp al, [rdi]
	je .got
	inc rcx
	jmp .loop

.reset:
	xor rcx, rcx
	inc rdi
	inc rdx
	jmp .loop

.got:
	mov rax, rdx
	ret

.return:
	mov rax, rdx
	ret

section .data