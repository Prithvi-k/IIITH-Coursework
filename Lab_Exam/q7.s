.global compute_result

compute_result:
    # %rdi -> number of elements
    # %rsi -> size of sliding window
    # %rdx -> pointer to array

    movq    $0, %rax

    cmpq    $0, %rdi
    je      .end

    cmpq    $0, %rsi
    je      .end

    movq    $0, %r8         # %r8 -> current element
    movq    $0, %r9         # %r9 -> index of current element

    cmpq    %rdi, %rsi
    jge      .alt_elems

    movq    $0, %r10        # %r10 -> store max value
    movq    %rdi, %r11
    subq    %rsi, %r11
    movq    $0, %r12        # %r12 -> store prev value

    .initial_window:
        cmpq    %rsi, %r9
        jge     .loop_driver
        movq    (%rdx, %r9, 8), %r8
        addq    %r8, %r10
        incq    %r9
        jmp     .initial_window

    .loop_driver:
        movq    %r10, %r12
        movq    %rsi, %r13    # %r13 -> index of elem to be removed
        decq    %r13
        cmpq    %rsi, %r11
        jle     .small_array
        jmp     .larger_array

    .small_array:
        movq    %rdi, %r9
        subq    %r11, %r9
        jmp     .main_loop

    .larger_array:
        movq    %rdi, %r9
        subq    %rsi, %r9

        .main_loop:
            cmpq    %r9, %rdi
            jle     .loop_end
            subq    (%rdx, %r13, 8), %r12
            addq    (%rdx, %r9, 8), %r12
            decq    %r13
            incq    %r9
            cmpq    %r12, %r10
            jle     .new_value_greater
            jmp     .main_loop

        .new_value_greater:
            movq    %r12, %r10
            jmp     .main_loop
        
        .loop_end:
            movq    %r10, %rax
            ret

    .alt_elems:
        movq (%rdx, %r9, 8), %r8
        addq %r8, %rax
        incq %r9
        cmpq %r9, %rdi
        jle .end
        jmp .alt_elems

    .end:
        ret
