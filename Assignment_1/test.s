.global get_sum
.global rem
.global alt_sum

get_sum:
    # %rdi -> arr
    # %rsi -> n

    movq $0, %rax # Initialise a variable for sum = 0
	movq $0, %rbx # Initialise a variable for i = 0
	movq $4, %rsi

	.L1: 
		leaq (%rdi, %rbx, 8), %r8
		movq (%r8), %rax
		idivq %rsi
		incq %rbx
		cmpq %rsi, %rbx
		jne .L1

	ret

rem:
	# %rdi -> n
	movq %rdi, %rax
	movq $2, %rbx

	idivq %rbx
	movq %rdx, %rax
	ret

alt_sum:

	movq $0, %rax
	
	.L2:
		cmpq $0, %rsi
		je .L4

		addq (%rdi), %rax
		addq $8, %rdi
		decq %rsi
		jmp .L2

	.L4:
		ret
