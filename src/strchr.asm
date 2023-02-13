section .bss

section .text
global strchr

strchr:
  push rbx
  push rdi
  push rsi
  mov rbx, rax
  mov rdi, rax
  mov rsi, 0

.loop:
  cmp byte [rdi], 0
  je .return
  inc rsi
  cmp byte [rdi], dl
  je .exist
  inc rdi
  jmp .loop

.exist:
  sub rdi, rbx
  mov rax, rdi
  jmp .return

.return:
  pop rsi
  pop rdi
  pop rbx
  ret

section .data