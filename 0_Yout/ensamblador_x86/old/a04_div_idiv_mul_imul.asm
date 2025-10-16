                  ; la codificacion ascii mostrara el simbolo asiganado al resultado si sale del rango 0-9

section .data
  msg1 db 0xA,0xA,0x9,"La multiplicacion de 2 * 2 es: "
  len1 equ $ - msg1

  msg2 db 0xA,0xA,0x9,"La multiplicacion de -2 * -2 es: "
  len2 equ $ - msg2

  msg3 db 0xA,0xA,0x9,"La division de 4/2 es: "
  len3 equ $-msg3

  msg4 db 0xA,0xA,0x9,"La division de -4/-2 es: "
  len4 equ $-msg4

  msg_Jump db 0xA
  len5 equ $ - msg_Jump

section .bss
  extra_mango1 resb 1

section .text
  global _start
  _start:
    
    ;  imprime los mensajes ----------- multiplicacion naturales
    mov eax, 4
    mov ebx, 1
    mov ecx, msg1
    mov edx, len1
    int 0x80

    mov eax, 2
    mov ebx, 2

    mul ebx     ;  por defecto mul multiplica el parametro por 'eax'   eax = eax * ebx
    add eax, '0'
    mov [extra_mango1], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, extra_mango1
    mov edx, 1
    int 0x80

    ;  imprime los mensajes ----------- multiplicacion reales
    mov eax, 4
    mov ebx, 1
    mov ecx, msg2
    mov edx, len2
    int 0x80

    mov eax, -2
    mov ebx, 2     ; la codificacion en ascii solo muestra del 0 al 9, si pasa de ese rango mostrara el simbolo acorde a la posici[on  -4   o  14  etc...
                  ; la codificacion ascii mostrara el simbolo asiganado al resultado si sale del rango 0-9

    imul ebx
    add eax, '0'
    mov [extra_mango1], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, extra_mango1
    mov edx, 1
    int 0x80

    ;  imprime los mensajes ----------- division
    mov eax, 4
    mov ebx, 1
    mov ecx, msg3
    mov edx, len3
    int 0x80

    mov eax, 8
    mov ebx, 2
    mov edx, 0    ; por defecto el residuo se almacena aqu[i :3

    div ebx    ; div por defecto divide eax por el parametro('ebx') y el residuo va a edx.
    add eax, '0'
    mov [extra_mango1], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, extra_mango1
    mov edx, 1
    int 0x80

    ;  imprime los mensajes -----------  division
    mov eax, 4
    mov ebx, 1
    mov ecx, msg4
    mov edx, len4
    int 0x80

    mov eax, -4
    mov ebx, -2
    mov edx, 0    ; por defecto el residuo se almacena aqu[i :3

    idiv ebx      ; la codificacion ascii mostrara el simbolo asiganado al resultado si sale del rango 0-9
    add eax, '0'
    mov [extra_mango1], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, extra_mango1
    mov edx, 1
    int 0x80

    ; last 0xA
    mov eax, 4
    mov ebx, 1
    mov ecx, msg_Jump
    mov edx, len5
    int 0x80
    ; last 0xA


    mov eax, 1
    int 0x80
