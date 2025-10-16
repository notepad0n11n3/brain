section .data
;segment .data
  msg1 db 0xA,0xA,0x9,"La suma de 4 + 5: "
  len1 equ $ - msg1

  msg2 db 0xA,0xA,0x9,"La resta de 4 + 5: "
  len2 equ $ - msg2

  msg3 db 0xA,0xA,0x9,"El incremento de eax=5 es: "
  len3 equ $-msg3

  msg4 db 0xA,0xA,0x9,"El decremento de eax=5 es: "
  len4 equ $-msg4

  msg_Jump db 0xA
  len5 equ $ - msg_Jump

section .bss
  extra_mango1 resb 1

section .text
  global _start
  _start:
    
    ;  imprime los mensajes ----------- suma
    mov eax, 4
    mov ebx, 1
    mov ecx, msg1
    mov edx, len1
    int 0x80

    mov eax, 5
    mov ebx, 4

    add eax, ebx
    add eax, '0'
    mov [extra_mango1], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, extra_mango1
    mov edx, 1
    int 0x80

    ;  imprime los mensajes ----------- resta
    mov eax, 4
    mov ebx, 1
    mov ecx, msg2
    mov edx, len2
    int 0x80

    mov eax, 5
    mov ebx, 4

    sub eax, ebx
    add eax, '0'
    mov [extra_mango1], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, extra_mango1
    mov edx, 1
    int 0x80

    ;  imprime los mensajes ----------- incremento en 1
    mov eax, 4
    mov ebx, 1
    mov ecx, msg3
    mov edx, len3
    int 0x80

    mov eax, 5
    inc eax       ; incrementar en 1 eax
    add eax, '0'
    mov [extra_mango1], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, extra_mango1
    mov edx, 1
    int 0x80

    ;  imprime los mensajes -----------  decremento en 1
    mov eax, 4
    mov ebx, 1
    mov ecx, msg4
    mov edx, len4
    int 0x80

    mov eax, 5
    dec eax      ; decrementar en 1 eax
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
