.global calculate

calculate:
    # %rdi -> a
    # %rsi -> x
    # %rdx -> b
    # %rcx -> y

    movq %rdi, %rax
    movq %rdx, %rbx

    cmpq $0, %rsi
    jge .x_pos
    negq %rsi
    jmp .x_neg

    .x_pos:
        salq $1, %rax
        decq %rsi
        cmpq $0, %rsi
        jg .x_pos
        cmpq $0, %rcx
        jge .y_pos
        negq %rcx
        jmp .y_neg

    .x_neg:
        sarq $1, %rax
        decq %rsi
        cmpq $0, %rsi
        jg .x_neg
        cmpq $0, %rcx
        jge .y_pos
        negq %rcx
        jmp .y_neg  

    .y_pos:
        salq $1, %rbx
        decq %rcx
        cmpq $0, %rcx
        jg .y_pos
        jmp .end

    .y_neg:
        sarq $1, %rbx
        decq %rcx
        cmpq $0, %rcx
        jg .y_neg
        jmp .end

    .end:
        addq %rbx, %rax
        ret

