section .data
;segment .data

  msg db "Welcome Back!!!",0xA,0xD
  ;mango db "Welcome Back!!!",0xA,0xD
  len equ $ - msg
  ;len equ $ - mango

section .text
;segment .text
  global _start
  _start:
    mov eax, 4      ;llama al sistema (sys_write)
    ;eax = 4

    mov ebx, 1      ;stdout
    mov ecx, msg    ;msg pantalla
  ; mov ecx, mango    

    mov edx, len    ;longitud del mensaje
    int 0x80        ;llamada al sistema de interrupciones

    mov eax, 1      ;(  system("pause") , exit , sys_exit  )
    int 0x80
