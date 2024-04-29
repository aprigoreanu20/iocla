%include "../utils/printf32.asm"

%define NUM 5
   
section .text

extern printf
global main
main:
    mov ebp, esp
    mov ecx, NUM
push_nums:
    sub esp, 4
    mov dword [esp], ecx
    loop push_nums

    sub esp, 4
    mov dword [esp], 0

    sub esp, 4
    mov dword [esp], "mere"

    sub esp, 4
    mov dword [esp], "are "

    sub esp, 4
    mov dword [esp], "Ana "

    lea esi, [esp]
    PRINTF32 `%s\n\x0`, esi

    ; TODO 2: print the stack in "address: value" format in the range of [ESP:EBP]
    ; use PRINTF32 macro - see format above
    mov eax, ebp
print_stack_label:
    cmp eax, esp
    je out_loop
    PRINTF32 `0x\x0`
    PRINTF32 `%x\x0`, eax
    PRINTF32 `: 0x\x0`
    PRINTF32 `%d\n\x0`, [eax]
    sub eax, 4
    jmp print_stack_label

out_loop:
    ; TODO 3: print the string
    mov eax, esp
    PRINTF32 `%s\n\x0`, eax

    ; TODO 4: print the array on the stack, element by element.
    mov eax, ebp
print_element_by_element:
    cmp eax, esp
    je exit_loop
    PRINTF32 `0x\x0`
    PRINTF32 `%x\x0`, eax
    PRINTF32 `: 0x\x0`
    PRINTF32 `%d\n\x0`, [eax]
    sub eax, 1
    jmp print_element_by_element

exit_loop:

    ; restore the previous value of the EBP (Base Pointer)
    mov esp, ebp

    ; exit without errors
    xor eax, eax
    ret
