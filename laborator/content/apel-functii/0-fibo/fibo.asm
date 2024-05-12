%include "../utils/printf32.asm"

%define NUM_FIBO 10

section .text

extern printf
global main
main:
    mov ebp, esp

    ; TODO - replace below instruction with the algorithm for the Fibonacci sequence
    sub esp, NUM_FIBO * 4

    mov dword [esp], 1
    mov dword [esp + 4], 1

    mov ecx, NUM_FIBO
    sub ecx, 2

    xor edx, edx

fibo:
    cmp edx, ecx
    je print
    mov eax, dword [esp + edx * 4]
    inc edx
    add eax, dword [esp + edx * 4]
    inc edx
    mov dword [esp + edx * 4], eax
    dec edx
    jmp fibo
print:
    mov eax, dword [esp + (ecx - 1) * 4]
    PRINTF32 `%d \x0`, eax
    dec ecx
    cmp ecx, 0
    ja print

    PRINTF32 `\n\x0`
    mov esp, ebp
    xor eax, eax
    ret
