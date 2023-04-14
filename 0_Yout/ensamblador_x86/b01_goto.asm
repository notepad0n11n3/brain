SYS_PRINT equ 4
SYS_SALIDA equ 1

SYS_LEE equ 3

SALTO_NEE db 0xA

section .data
;segment .data
  msg1 db "Ingrese numero 1: ",0xA
  len1 equ $-msg1

  jump_goto_msg db 0xA,0x9,"Goto en ensamblador :3",0xA
  jump_goto_msg_length equ $-jump_goto_msg

section .bss
;segment .bss
  num1 resb 2
  resultado resb 1

section .text
;segment .text
  global _start
  _start:
    jmp mango

    ; mensaje numero
    mov eax, 4
    mov ebx, 1
    mov ecx, msg1
    mov edx, len1
    int 0x80

    mango:
      mov eax, 4
      mov ebx, 1
      mov ecx, jump_goto_msg
      mov edx, jump_goto_msg_length
      int 0x80
    
    mov eax, 1
    int 0x80
