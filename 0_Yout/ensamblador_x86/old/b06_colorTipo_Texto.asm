
;     CARACTERES DE ESCAPE  ANSI
;             Codigos de escape ANSI  'wikipedia.org'

section .data
;                       con 0x1b interpretara el codigo ANSI 'like bash'
  mango01 db 0x1b,"[44;31m","-*--*--*-",0xA,0x9,0x1b,"[3m","neeee",0xA,0xA,0x9,0x9,0x1b,"[40;33m","moooo"   
;             "[ backgroundColor; color m"           
  mango01_length equ $-mango01

section .bss

section .text
  global _start
  _start:
    
    mov eax, 4
    mov ebx, 1
    mov ecx, mango01
    mov edx, mango01_length
    int 0x80
      
    mov eax, 1
    int 0x80
