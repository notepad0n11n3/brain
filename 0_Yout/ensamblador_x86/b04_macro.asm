
MANGO equ 4
GORO equ 1

SAPO db 0xA


%macro mango 4
  mov eax, %1
  mov ebx, %2
  mov ecx, %3
  mov edx, %4
  int 0x80
%endmacro


section .data
  msg1 db 0x9,0x9,"neee..."
  len1 equ $-msg1


section .bss


section .text
  global _start
  _start:

    mango MANGO, GORO, SAPO, GORO
    
    mango MANGO, GORO, msg1, len1

    mango MANGO, GORO, SAPO, GORO

    mov eax, 1
    int 0x80
