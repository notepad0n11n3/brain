section .data
;segment .data
  intro_number db 0xA,0xA,0x9,0x9,"Ingrese un numero: "
  intro_number_length equ $ - intro_number

section .bss
;segment .bss
  extraNumber resb 5

section .text
;segment .text
  global _start
  _start:
    mov eax, 4
    mov ebx, 1
    mov ecx, intro_number
    mov edx, intro_number_length
    int 0x80

    ; lectura de teclado

    mov eax, 3
    mov ebx, 2
    mov ecx, extraNumber
    mov edx, 5
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, extraNumber
    mov edx, 5
    int 0x80

    mov eax, 1
    int 0x80
