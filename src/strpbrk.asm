section .bss

section .text
global strpbrk

strpbrk:
	xor rcx, rcx

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
	jmp .loop


.got:
	mov rax, rdi
	ret

.return:
	xor rax, rax
	ret

section .data