.global calculate

calculate:
    # %rdi -> a
    # %rsi -> x
    # %rdx -> b
    # %rcx -> y

    movq %rdi, %rax
    movq %rdx, %rbx
    
    .eval_x:
        cmpq $0, %rsi
        je .eval_y
        jg .x_pos
        negq %rsi
        jmp .x_neg

    .x_pos:
        salq $1, %rax
        decq %rsi
        cmpq $0, %rsi
        jg .x_pos
        jmp .eval_y

    .x_neg:
        sarq $1, %rax
        decq %rsi
        cmpq $0, %rsi
        jg .x_neg
        jmp .eval_y

    .eval_y:
        cmpq $0, %rcx
        je .end
        jg .y_pos
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

