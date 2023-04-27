section .data
    
    ;  reserbar espacio para almacenar dato en memoria
  ; db   1byte     8 bites
  ; dw   2bytes    16 bites
  ; dd   4bytes    32 bites
  ; dq   8bytes    64 bites
  ; ddq  16bytes   128 bites

  ; dt   10 bytes  80 bites

  variable01 db "Hola Mundo"
  len equ $-variable01

  variable02 db 'H','o','l',97,' ','M',"undo"       ; 97 == a   codigo ascii

section .bss
  var01 resb

      ; resb   b   1byte
      ; resw   w   2bytes... etc etc...

section .text
  global _start
  _start:
    
    mov eax, 4
    mov ebx, 1
    mov ecx, variable01
    mov edx, len
    int 0x80

    mov eax, 1
    mov ebx, 0
    int 0x80
