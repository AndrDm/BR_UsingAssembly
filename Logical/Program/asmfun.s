.globl asmfun
asmfun:
	push %ebp
	mov %esp, %ebp
	sub $0x18, %esp
	mov 0x8(%ebp), %eax
	mov %ax, 0xfe(%ebp)
	movzwl 0xfe(%ebp), %eax
	inc %eax
	movswl %ax, %edx
	mov %edx, %eax
	lea 0x0(%esi), %esi
	leave 
ret 
