.global gcd

gcd:
    # %rdi -> a
    # %rsi -> b

    cmpq $0, %rsi
    je .end

    movq %rdi, %rax
    cqto
    idivq %rsi
    movq %rsi, %rdi
    movq %rdx, %rsi
    call gcd
    ret

    .end:
        movq %rdi, %rax
        ret


