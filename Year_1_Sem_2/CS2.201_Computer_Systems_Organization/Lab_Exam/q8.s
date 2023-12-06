.global compute_result

compute_result:
    # %rdi -> n
    # %rsi -> array

    jmp .bubble_sort

.completed_sort:
    # %rdi -> n
    # %rsi -> array (sorted)

    cmpq    $1, %rdi
    jle     .end

    movq $0, %r8    # i = 0
    movq $1, %r9    # i + 1
    movq $0, %r10   # arr[i]
    movq $0, %r11   # arr[i+1]

    movq $2, %r12
    movq %rdi, %rax
    andq $1, %rax
    cmpq $0, %rax
    jne .modify_for_odd
    jmp .main_loop

    .modify_for_odd:
        decq %rdi

    .main_loop:
        cmpq %r9, %rdi
        jle .end

        movq    (%rsi, %r8, 8), %r10
        movq    (%rsi, %r9, 8), %r11

        movq    %r10, (%rsi, %r9, 8)
        movq    %r11, (%rsi, %r8, 8)

        addq    $2, %r8
        addq    $2, %r9

        jmp .main_loop

    .end:
        ret


.bubble_sort:
    # %rdi -> n
    # %rsi -> array

    movq $0, %r8    # i = 0
    movq $0, %r11   # arr[j]
    movq $0, %r12   # arr[j+1]
    movq %rdi, %r13 # n
    decq %r13       # n - 1

    .outer_loop:
        cmpq    %r8, %r13
        jle     .end_sort

        movq $0, %r9    # j = 0
        movq $0, %r14   # j = 0
        movq $0, %r10   # swapped?

        .inner_loop:
            cmpq    %r9, %r13
            jle     .inner_loop_end

            movq    (%rsi, %r9, 8), %r11
            movq    %r9, %r14
            incq    %r14
            movq    (%rsi, %r14, 8), %r12
            cmpq    %r11, %r12
            jge     .inner_loop_end_one_iteration

            movq    %r11, (%rsi, %r14, 8)
            movq    %r12, (%rsi, %r9, 8)
            movq    $1, %r10

            .inner_loop_end_one_iteration:
                incq    %r9
                jmp     .inner_loop
        
        .inner_loop_end:
            cmpq   $0, %r10
            je     .end_sort
            incq   %r8
            jmp    .outer_loop

    .end_sort:
        jmp .completed_sort

