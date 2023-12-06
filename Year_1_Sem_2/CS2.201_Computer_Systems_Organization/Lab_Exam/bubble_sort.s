.global bubble_sort

bubble_sort:
    # %rdi = array
    # %rsi = array length

    movq $0, %r8        # i = 0
    movq $0, %r9        # swapped = 0
    movq $0, %r10       # j = 0
    movq $0, %r11       # swapped = 0
    movq $0, %r12       # array[j]
    movq $0, %r13       # array[j + 1]
    movq %rsi, %r14     # length
    decq %r14           # length - 1

    .main_loop:
        cmpq %rsi, %r8
        jge .end

        movq $0, %r10       # j = 0
        movq $0, %r11       # swapped = 0

        .inner_loop:
            cmpq %r14, %r10
            jge .inner_loop_end

            movq    (%rdi, %r10, 8), %r12
            movq    %r10, %r11
            incq    %r11
            movq    (%rdi, %r11, 8), %r13
            cmpq    %r12, %r13
            jge     .inner_loop_one_iteration_end

            # swap
            movq    %r12, (%rdi, %r11, 8)
            movq    %r13, (%rdi, %r10, 8)
            movq $1, %r11

            .inner_loop_one_iteration_end:
                incq %r10
                jmp .inner_loop

        .inner_loop_end:
            cmpq $0, %r11
            je .end

            incq %r8
            jmp .main_loop
    
    .end:
        ret
    


