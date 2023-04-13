SYS_SALIDA equ 1
SYS_LEE equ 3
SYS_PRINT equ 4
STDIN equ 0
STDOUT equ 1

SALTO_NEE db 0xA

section .data
  msg1 db "Ingrese numero 1: ",0xA
  len1 equ $-msg1

  msg2 db "Ingrese numero 2: ",0xA
  len2 equ $-msg2

section .bss
  num1 resb 2
  num2 resb 2
  res resb 1

section .text
  global _start
  _start:
    
    mov eax, 1
    int 0x80
