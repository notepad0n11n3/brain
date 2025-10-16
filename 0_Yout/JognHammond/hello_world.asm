; hellow world.asm

; XD,   esto esta mucho mejor.
  ;  ::: python3
  ;   python3:: 0xa   '10'  !=!=   python3:: chr(0xa)   '\n'
  ;   python3:: 0xd   '13'  !=!=   python3:: chr(0xd)   '\r'

  ; ::: locate unistd_32.h         ('asm... <- <3 <3 <3') .... <3 <3 <3 ... ! ! !
  ; ::: vim unistd_32.h

global _start

section .text
_start:
 mov eax, 0x4             ; use the write syscall 
 mov ebx, 1               ; use stdout as the fd `$(man 2 write)`
 mov ecx, message         ; use the message as the buffer
 mov edx, message_length  ; and supply the length
 int 0x80                 ; invoker the syscall

 ; now gracefully exit
 mov eax, 0x1
 mov ebx, 0
 int 0x80 

section .data
  message: db "Hello world!",0xA
  message_length: equ $-message

  mensaje2 db "segundo hello...",0xA
  mensaje2_length equ $ - mensaje2

