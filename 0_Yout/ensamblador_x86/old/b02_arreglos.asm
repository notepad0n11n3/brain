;;  INCOMPLETO....!!!!
segment .data
;section .data
  msg1 db 0xA,0x9,"ingrese cinco numeros y presione enter: "
  leng1 equ $-msg1


  msg3 db 0xA,0x9,"el mayor de esto numeros es: "
  len3 equ $-msg3

  mango_array db 0,0,0,0,0
  la equ $-mango_array

section .bss
;segment .bss
  resultado resb 2    ; reserbamos 2 bytes 
  

segment .text
;section .text
  global _start
  _start:

    mov eax, 4
    mov ebx, 1
    mov ecx, msg1
    mov edx, leng1
    int 0x80


    mov esi, mango_array
    mov edi, 0

    lee:
    mov eax, 3
    mov ebx, 2
    mov ecx, resultado
    mov edx, 2
    int 0x80

    salir:
    mov eax, 1
    int 0x80
