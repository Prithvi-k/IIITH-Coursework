.global main

main:
	movq $10, %rax
	#leaq %rax, %rbx
	leaq (%rax), %rbx
	ret
