.global divFunc
 
divFunc:
	# %rdi -> n
	# %rsi -> d
	movq %rdi, %rax
	movq $3, %rbx

	idivq %rax
	ret

