section .data
  msg01 db 0xA,0xA,0x9,0x9,"::: "
  msg01_length equ $-msg01

section .bss
  resultado resb 1

section .text
  global _start
  _start:

    ; asignamos valores para jugar con IF
    mov eax, 5
    mov ebx, 9


    cmp eax, 3       ; if( eax == 5 ) 
    jz cuerpoIfTrue  ; si cmp retorna 0(true) salta a cuerpoIF:


    jmp saltoNee     ;si cmp retorna != 0 continuara linea a linea, salta el cuerpoIfTrue


    cuerpoIfTrue:
    mov ebx, 1


    saltoNee:

    add ebx, 48
    mov [resultado], ebx,

    mov eax, 4
    mov ebx, 1
    mov ecx, msg01
    mov edx, msg01_length
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, resultado
    mov edx, 1
    int 0x80

    mov eax, 1
    mov ebx, 0
    int 0x80
