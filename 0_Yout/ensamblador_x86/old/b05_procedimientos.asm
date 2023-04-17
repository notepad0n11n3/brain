
leeMango:
  mov eax, 3
  mov ebx, 2
  mov edx, 1
  int 0x80
ret          ; si el ret no regresara al la posici[on del call leeMango


section .data

section .bss
  user_data resb 1

section .text
  global _start
  _start:
    
    mov ecx, user_data;
    call leeMango

    mov eax, 4
    mov ebx, 1
    mov ecx, user_data
    mov edx, 1
    int 0x80
      
    mov eax, 1
    int 0x80
