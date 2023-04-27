%macro mango 2
  mov eax, 4
  mov ebx, 1
  mov ecx, %1
  mov edx, %2
  int 0x80
%endmacro

section .data
  mango01 db 0xA,0xA,0x9,0x9,"Loading...",0xA
  mango01_length equ $-mango01

section .bss
  user_data resb 1

section .text
  global _start
  _start:

    exit:
    mov eax, 1
    mov ebx, 0
    int 0x80
