.global compute

compute:
    # %rdi -> array
    # %rsi -> size

    pushq %rbp
    movq %rsp, %rbp
    movq %rdi, %r15

    movq $1, %r10
    movq $3, %r8
    movq $5, %r9

    .loop:
        cmpq $0, %rsi
        jle .end

        movq %r10, %rax
        movq $0, %rdx
        idivq %r8
        cmpq $0, %rdx
        je .divisible_by_3

        movq %r10, %rax
        movq $0, %rdx
        idivq %r9
        cmpq $0, %rdx
        je .divisible_by_5

        movq %r10, (%rdi)
        addq $8, %rdi
        decq %rsi
        incq %r10
        jmp .loop

    .divisible_by_3:
        movq %r10, %rax
        movq $0, %rdx
        idivq %r9
        cmpq $0, %rdx
        je .divisible_by_15

        movq $-1, (%rdi)
        addq $8, %rdi
        decq %rsi
        incq %r10
        jmp .loop
    
    .divisible_by_5:
        movq %r10, %rax
        movq $0, %rdx
        idivq %r8
        cmpq $0, %rdx
        je .divisible_by_15

        movq $-2, (%rdi)
        addq $8, %rdi
        decq %rsi
        incq %r10
        jmp .loop
    
    .divisible_by_15:
        movq $-3, (%rdi)
        addq $8, %rdi
        decq %rsi
        incq %r10
        jmp .loop

    .end:
        movq %r15, %rdi
        movq %rbp, %rsp
        popq %rbp
        ret










