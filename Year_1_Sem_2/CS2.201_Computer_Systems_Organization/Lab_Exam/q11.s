.global selective_sort

selective_sort:
    # %rdi -> n
    # %rsi -> array

    movq $0, %r8                            # sum
    movq $0, %r9                            # index

    .sum_loop:
        cmpq %r9, %rdi
        jle .end_sum_loop

        movq $0, %r10                       # arr[i]
        movq (%rsi, %r9, 8), %r10           # load value from array
        addq %r10, %r8                      # sum += arr[i]
        incq %r9                            # increment index
        jmp .sum_loop

    .end_sum_loop:
        movq $0, %rax
        movq $0, %rdx
        movq $2, %rcx

        movq %r8, %rax
        divq %rcx

        cmpq $0, %rdx
        je .count
        jmp .sort

    .count:
        movq $0, %r8                        # count even numbers
        movq $0, %r9                        # count odd numbers
        movq $0, %r10                       # index
        movq $2, %r11                       # divisor

    .count_loop:
        cmpq %r10, %rdi
        jle .end_count_loop

        movq $0, %rax                       # arr[i]
        movq (%rsi, %r10, 8), %rax          # load value from array
        movq $0, %rdx
        divq %r11                           # arr[i] % 2

        cmpq $0, %rdx
        je .count_loop_even
        jmp .count_loop_odd

    .count_loop_even:
        incq %r8                            # count even numbers
        incq %r10                           # increment index
        jmp .count_loop

    .count_loop_odd:
        incq %r9                            # count odd numbers
        incq %r10                           # increment index
        jmp .count_loop

    .end_count_loop:
        cmpq $0, %r8
        je .end
        jne .some_even

    .some_even:
        cmpq $0, %r9
        je .end
        jmp .sort

    .end:
        ret

.sort:
    # %rdi -> n
    # %rsi -> array

    movq $-9223372036854775808, %r8         # register to keep minimum value
    movq $0, %r9                            # regiter to keep minimum index
    movq $0, %r10                           # register to keep index
    movq %rdi, %r15                         # register to keep n
    decq %r15                               # decrement n

    .loop:
        cmpq %r10, %r15
        jle .end_sort_loop

        movq $0, %r11                       # register to check if min value is changed
        movq (%rsi, %r10, 8), %rax          # load value from array
        movq (%rsi, %r10, 8), %r14          # load value from array

        movq %r10, %r12                     # register to keep index
        movq %r10, %r13                     # register to keep index
        incq %r12                           # increment index

        .inner_loop:
            cmpq %r12, %rdi
            jle .inner_loop_end

            movq (%rsi, %r12, 8), %rbx      # load value from array
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

            movq %rax, (%rsi, %r13, 8)      # swap values
            movq %r14, (%rsi, %r9, 8)       # swap indexes

        .loop_continue:
            incq %r10                       # increment index
            jmp .loop

    .end_sort_loop:
        jmp .end
