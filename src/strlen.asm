section .bss

section .text
global strlen

strlen:
	xor rcx,rcx ;Set rcx to 0, rcx is the counter 

.loop:
	mov al,[rdi + rcx] ;Copy the next character in al
	cmp al,0 ;Check if the character is null
	je .return ;If character is null, break the loop
	add rcx,1 ;We can replace by "inc rcx"
	jmp .loop ;Re-loop

.return:
	mov rax,rcx ;Move the len in rax
	ret ;Return the value of rax

section .data
