.global possible

possible:
    # %rdi -> n
    # %rsi -> req diff
    # %rdx -> array

    jmp .sort

    .driver_code:
        movq $1, %rax
        movq $0, %r8
        movq %rdi, %r9
        movq %rdi, %r10
        imulq $2, %r10

    .loop:
        cmpq %r9, %r10
        jle .end

        movq $0, %r11
        movq $0, %r12

        movq (%rdx, %r8, 8), %r11
        movq (%rdx, %r9, 8), %r12

        subq %r11, %r12
        cmpq %rsi, %r12
        jl .end_loop

        incq %r8
        incq %r9

        jmp .loop

    .end_loop:
        movq $0, %rax

    .end:
        ret
    
.sort:
    # %rdi -> n
    # %rsi -> req diff
    # %rdx -> array

    movq $0, %r8 # i
    movq $0, %r9 # arr[i]
    movq %rdi, %r15
    imulq $2, %r15

    .sort_outer_for_loop:
        cmpq %r8, %r15
        jle .end_sort_outer_for_loop

        movq (%rdx, %r8, 8), %r9    # arr[i]
        movq $0, %r10               # j
        movq $0, %r11               # j + 1
        movq %r8, %r10
        movq %r8, %r11
        decq %r10

        .inner_while_loop:
            cmpq $0, %r10
            jl .end_inner_while_loop

            movq $0, %r12
            movq (%rdx, %r10, 8), %r12  # arr[j]

            cmpq %r9, %r12
            jle .end_inner_while_loop

            movq %r12, (%rdx, %r11, 8)  # arr[j+1] = arr[j]
            decq %r10
            decq %r11

            jmp .inner_while_loop
        
        .end_inner_while_loop:
            movq %r9, (%rdx, %r11, 8)  # arr[j+1] = key
            incq %r8
            jmp .sort_outer_for_loop

    .end_sort_outer_for_loop:
        jmp .driver_code






