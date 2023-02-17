section .bss

section .text
global memset

memset:
	xor rcx, rcx ;Set cmpt to 0

.loop:
	cmp byte [rdi + rcx], 0 ;If end of string
	je .return
	cmp rcx, rdx ;If end of cmpt
	je .endset
	mov [rdi + rcx], sil ;Set value of second arg
	inc rcx ;Inc cmpt
	jmp .loop

.endset:
	mov rax, rdi ;Return string
	ret

.return:
	mov rax, rax ;Return null
	ret

section .data