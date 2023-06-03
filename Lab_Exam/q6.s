.global compute_result

compute_result:
    # %rdi -> n
    # %rsi -> array

    movq $0, %r8        # sum
    movq $0, %r9        # index
    movq $2, %r12
    movq $3, %r13

    .loop:
        cmpq    $0, %rdi
        je      .end

        movq    (%rsi, %r9, 8), %rax
        movq    %rax, %r10
        movq    $0, %rdx
        idivq   %r12
        cmpq    $0, %rdx
        je      .divisible_by_3
        jne     .next


        .divisible_by_3:
            movq    %r10, %rax
            movq    $0, %rdx
            idivq   %r13
            cmpq    $0, %rdx
            je      .next
            jne     .add_to_sum
        
        .add_to_sum:
            addq    %r10, %r8
            jmp     .next
        
        .next:
            incq    %r9
            decq    %rdi
            jmp     .loop
    

    .end:
        movq    %r8, %rax
        ret
