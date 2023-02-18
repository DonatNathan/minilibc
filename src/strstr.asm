section .bss

section .text
global strstr

strstr:
	xor rcx, rcx

.loop:
	cmp byte [rdi], 0
	je .return
	mov al, [rsi]
	cmp byte [rdi], al
	je .first
	inc rdi
	jmp .loop

.compare:
	mov al, [rsi + rcx]
	cmp al, 0
	je .got
	cmp byte [rdi], al
	jne .failed
	inc rcx
	inc rdi
	jmp .compare

.first:
	mov rdx, rdi
	jmp .compare

.failed:
	xor rcx, rcx
	jmp .loop

.got:
	mov rax, rdx
	ret

.return:
	xor rax, rax
	ret

section .data