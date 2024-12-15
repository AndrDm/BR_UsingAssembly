.globl add_integers_intel
.type add_integers_intel, @function
.intel_syntax noprefix

add_integers_intel:
    push ebp
    mov ebp, esp
    
    mov eax, [ebp+8]    # Load first integer argument into eax
    add eax, [ebp+12]  # Add second integer argument to eax
    
    mov esp, ebp
    pop ebp
    ret
