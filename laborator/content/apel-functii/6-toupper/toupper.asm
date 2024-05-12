%include "../utils/printf32.asm"

section .data
    before_format db "before %s", 13, 10, 0
    after_format db "after %s", 13, 10, 0
    mystring db "abcdefghij", 0

section .text

extern printf
global main

toupper:
    push ebp
    mov ebp, esp

    mov eax, dword [ebp+8]
    xor ecx, ecx

change_characters:
    xor ebx, ebx
    mov bl, byte [eax + ecx]

    cmp ebx, 0
    je out_of_toupper

    sub bl, 0x20
    mov byte [eax + ecx], bl
    inc ecx
    jmp change_characters
    ; TODO

out_of_toupper:
    leave
    ret

main:
    push ebp
    mov ebp, esp

    push mystring
    push before_format
    call printf
    add esp, 8

    push mystring
    call toupper
    add esp, 4

    push mystring
    push after_format
    call printf
    add esp, 8

    leave
    ret
