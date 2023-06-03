.global min_bacteria

min_bacteria:
    # %rdi -> number of bacteria

    movq %rdi, %rax
    movq $2, %rbx

    cqto
    idivq %rbx
    movq $1, %rax
    cmpq $0, %rdx
    je even_bacteria
    jmp odd_bacteria

    even_bacteria:
        ret

    odd_bacteria:
        addq $1, %rax
        ret
