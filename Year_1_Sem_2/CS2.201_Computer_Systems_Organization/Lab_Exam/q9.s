.global first_missing_positive

first_missing_positive:
        # %rdi -> n
        # %rsi -> array

        cmpq    $0, %rdi
        jle     .pre_return

        jmp     .sort

        .completed_sort:    
            movq    $1, %r8
            movq    $0, %r9
            movq    $0, %r10

        .find_missing:
            cmpq    %r9, %rdi
            jle     .not_equal

            movq    (%rsi, %r9, 8), %r10
            cmpq    $0, %r10
            jg      .positive

        .increment:
            incq    %r9
            jmp     .find_missing

        .positive:
            cmpq    %r8, %r10
            jne     .not_equal
            incq    %r8
            jmp     .increment

        .not_equal:
            movq    %r8, %rax
            jmp     .end

        .pre_return:
            movq    $0, %rax
            ret


        .end:
            ret

.sort:
    # %rdi -> n
    # %rsi -> array

    movq    $0, %r8     # i = 0
    movq    $0, %r10    # arr[i]
    movq    $0, %r11    # arr[j] -> value to swap

    movq    %rdi, %r12  # n
    decq    %r12        # n - 1

    .sort_outer_loop:
        cmpq    %r8, %r12
        jle     .sort_outer_loop_end

        movq    %r8, %r9
        incq    %r9
        movq    $0, %r13    # temp
        movq    (%rsi, %r8, 8), %r10    # arr[i]
        movq    %r8, %rcx
        movq    (%rsi, %r8, 8), %r15

        .sort_inner_loop:
            cmpq    %r9, %rdi
            jle     .sort_inner_loop_end

            movq    (%rsi, %r9, 8), %r13    # arr[j]
            cmpq    %r10, %r13
            jge     .sort_inner_loop_next

            movq    %r13, %r10              # arr[i] = arr[j]
            movq    %r9, %rcx

            .sort_inner_loop_next:
                incq    %r9
                jmp     .sort_inner_loop
        
        .sort_inner_loop_end:
            movq    %r10, (%rsi, %r8, 8)    # arr[i] = arr[j]
            movq    %r15, (%rsi, %rcx, 8)
            incq    %r8
            jmp     .sort_outer_loop

    .sort_outer_loop_end:
        jmp     .completed_sort
