.globl add_integers
.type add_integers, @function

add_integers:
    push %ebp
    mov %esp, %ebp
    
    mov 8(%ebp), %eax   # Load first integer argument into eax
    add 12(%ebp), %eax  # Add second integer argument to eax
    
    mov %ebp, %esp
    pop %ebp
    ret
