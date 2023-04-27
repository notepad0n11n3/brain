section .data

section .bss
  user_data resb 2

segment .text
  global _start
  _start:


                ; d = d + f      d += f       add  d, f

                ; d = d - f      d -= f       sub  d, f


    mov eax, 2
    mov ebx, 3

    add eax, ebx

    add eax, '0'  ; == add eax, 48      48 es 0 en codigo ASCII
    ;agregando el caracter '0'/48  a eax convierte a codigo ascci 

    mov [user_data], eax    ; mover el resultado a la variable no inicializada

    mov eax, 4
    mov ebx, 1
    mov ecx, user_data
    mov edx, 2
    int 0x80

    mov eax, 1
    mov ebx, 0
    int 0x80
