.global selection_sort

selection_sort:
    # %rdi -> array
    # %rsi -> n

    movq $-9223372036854775808, %r8         # register to keep minimum value
    movq $0, %r9                            # regiter to keep minimum index
    movq $0, %r10                           # register to keep index
    movq %rsi, %r15                         # register to keep n
    decq %r15                               # decrement n

    .loop:
        cmpq %r10, %r15
        jle .end

        movq $0, %r11                       # register to check if min value is changed
        movq (%rdi, %r10, 8), %rax          # load value from array
        movq (%rdi, %r10, 8), %r14          # load value from array

        movq %r10, %r12                     # register to keep index
        movq %r10, %r13                     # register to keep index
        incq %r12                           # increment index

        .inner_loop:
            cmpq %r12, %rsi
            jle .inner_loop_end

            movq (%rdi, %r12, 8), %rbx      # load value from array
            cmpq %rbx, %rax                 # compare values
            jg .inner_loop_swap
            jle .inner_loop_continue

            .inner_loop_swap:
                movq %rbx, %rax             # swap values
                movq %r12, %r9              # swap indexes
                movq $1, %r11               # set flag to 1

            .inner_loop_continue:
                incq %r12                   # increment index
                jmp .inner_loop

        .inner_loop_end:
            cmpq $0, %r11                   # check if min value is changed
            je .loop_continue

            movq %rax, (%rdi, %r13, 8)      # swap values
            movq %r14, (%rdi, %r9, 8)       # swap indexes

        .loop_continue:
            incq %r10                       # increment index
            jmp .loop

    .end:
        ret




