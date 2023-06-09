.global people

people:
    # %rdi -> n
    # %rsi -> arr
    # %rdx -> answer array

    movq $0, %rax       # index of answer array
    movq $0, %rcx       # left index of arr
    movq %rdi, %r8      
    decq %r8            
    movq %r8, %r10      # right index of arr
    movq $0, %r15       # track sum
    movq %rdx, %r13

    .initial_sum:
        cmpq %rcx, %rdi
        jle .end_initial_sum
        movq (%rsi, %rcx, 8), %r9
        cmpq $0, %r9
        je .initial_sum_zero
        addq %r8, %r15
        subq %rcx, %r15
        incq %rcx
        jmp .initial_sum

    .initial_sum_zero:
        addq %rcx, %r15
        incq %rcx
        jmp .initial_sum

    .end_initial_sum:
        movq $2, %rcx
        movq $0, %rdx
        movq %rdi, %rax
        idivq %rcx
        movq %rax, %r14         # mid index
        movq $0, %rcx
        movq $0, %rax
        movq %r13, %rdx
        movq $0, %r12           # left distance from end
        movq $0, %r13           # right distance from end
        jmp .main_loop       


    .main_loop:
        cmpq %rcx, %r14
        jle .right_main_loop

        movq (%rsi, %rcx, 8), %r9
        cmpq $0, %r9
        jne .right_main_loop

        cmpq %r12, %r13
        jl .right_main_loop_manager_v2

        .left_ko_change:
        addq %r8, %r15
        subq %rcx, %r15
        subq %rcx, %r15
        incq %r12
        incq %rcx
        jmp .update_answer

    .right_main_loop_manager_v2:
        cmpq %r10, %r14
        jge .left_ko_change

        movq (%rsi, %r10, 8), %r9
        cmpq $0, %r9
        je .left_ko_change
        jmp .right_ko_change

    .right_main_loop_manager:
        cmpq %rcx, %r14
        jle .right_main_loop
        jmp .main_loop

    .right_main_loop:
        cmpq %r10, %r14
        jge .end

        movq (%rsi, %r10, 8), %r9
        cmpq $1, %r9
        jne .right_main_loop_manager

    .right_ko_change:
        addq %r10, %r15
        incq %r13
        decq %r10
        jmp .update_answer

    .update_answer:
        movq %r15, (%rdx, %rax, 8)
        incq %rax
        jmp .main_loop

    .end:
        cmpq %rax, %rdi
        jg .fill_array

        ret

    .fill_array:
        cmpq %rax, %rdi
        jl .end

        movq %r15, (%rdx, %rax, 8)
        incq %rax
        jmp .fill_array






