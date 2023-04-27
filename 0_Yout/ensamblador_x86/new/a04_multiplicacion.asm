section .data

section .bss
  resultado resb 1

segment .text
  global _start
  _start:

    mov ax, 3
    mov cx, 2

    mul cx   ;  cx * ax   agarra ax de forma predeterminada

    add ax, 48    ; add ax, '0'

    mov [resultado], ax

    int 0x80


    ; mostrar resultado
    mov eax, 4
    mov ebx, 1
    mov ecx, resultado
    mov edx, 1
    int 0x80

    mov eax, 1
    int 0x80
