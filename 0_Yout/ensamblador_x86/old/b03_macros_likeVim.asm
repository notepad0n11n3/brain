
%macro escribe 2
  mov eax, 4
  mov ebx, 1
  mov ecx, %1
  mov edx, %2
  int 0x80
%endmacro


section .data
  msg1 db 0xA,0x9,"Loading..."
  len1 equ $-msg1

segment .bss

segment .text
  global _start
  _start:

    
    escribe msg1, len1

    
    mov eax, 1
    int 0x80
