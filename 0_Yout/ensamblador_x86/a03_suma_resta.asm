section .data
  mensaje1 db 0xA,0xD,"La suma de 4+5 es: ",0xA,0xD
  len1 equ $ - mensaje1

  mensaje2 db 0xA,0xD,"La resta de 4-5 es: ",0xA,0xD
  len2 equ $ - mensaje2

  mensaje3 db 0xA,0xD,"El incremento en uno de eax es: ",0xA,0xD
  len3 equ $ - mensaje3

  mensaje4 db 0xA,0xD,"El decremento en uno de eax es: ",0xA,0xD
  len4 equ $ - mensaje4

section .bss
  resultado resb 1

section .text
  global _start
  _start:
    
    ;-------- imprime los mensajes --------
    mov eax, 4  ; llama al sistema (sys_write)
    ;eax = 4
    mov ebx, 1  ; stdout
    mov ecx, mensaje1   ; mensaje pantalla
    mov edx, len1    ; longitud del mensaje
    int 0x80    ; llamada al sistema de interrupciones

    ; SUMA de 4 y 5
    mov eax, 4
    mov ebx, 5

    add eax, ebx
    add eax, '0'
    mov [resultado], eax     ; .bss section       ;  []  contido de esa direccion, like a * en c :3

    mov eax, 4  ; llama al sistema (sys_write)
    ;eax = 4
    mov ebx, 1  ; stdout
    mov ecx, resultado   ; mensaje pantalla
    mov edx, 1    ; la longitud esta en .bss '1'
    int 0x80    ; llamada al sistema de interrupciones


    ;-------- imprime los mensajes --------
    mov eax, 4  ; llama al sistema (sys_write)
    ;eax = 4
    mov ebx, 1  ; stdout
    mov ecx, mensaje2   ; mensaje pantalla
    mov edx, len2    ; longitud del mensaje
    int 0x80    ; llamada al sistema de interrupciones

    ;-------- imprime los mensajes --------
    mov eax, 4  ; llama al sistema (sys_write)
    ;eax = 4
    mov ebx, 1  ; stdout
    mov ecx, mensaje3   ; mensaje pantalla
    mov edx, len3    ; longitud del mensaje
    int 0x80    ; llamada al sistema de interrupciones

    ;-------- imprime los mensajes --------
    mov eax, 4  ; llama al sistema (sys_write)
    ;eax = 4
    mov ebx, 1  ; stdout
    mov ecx, mensaje4   ; mensaje pantalla
    mov edx, len4    ; longitud del mensaje
    int 0x80    ; llamada al sistema de interrupciones

    mov eax, 1  ; sys_exit
    int 0x80

