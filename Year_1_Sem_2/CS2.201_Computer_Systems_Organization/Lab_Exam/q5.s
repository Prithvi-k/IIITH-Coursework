.global sort

sort:
    # %rdi -> number of elements
    # %rsi -> pointer to array
    # %rdx -> result pointer

    push %rbp
    mov %rsp, %rbp

    mov     %rdi, %r8
    mov     %rsi, %r9
    movq    $0, %r10        # Count zeros
    movq    $0, %r11        # Count ones
    movq    $0, %r12        # Index
    movq    $0, %r13        # Index

    .loop:
        cmpq    $0, %r8
        je      .compute_result
        movq    (%rsi, %r12, 8), %rax
        cmpq    $0, %rax
        je      .zero
        jmp     .one

        .zero:
            incq    %r10
            incq    %r12
            decq    %r8
            jmp     .loop
        
        .one:
            incq    %r11
            incq    %r12
            decq    %r8
            jmp     .loop
        
    .compute_result:
        cmpq    $0, %r10
        je      .add_ones

        .add_zeroes:
            cmpq    $0, %r10
            je      .add_ones
            movq    $0, (%rdx, %r13, 8)
            incq    %r13
            decq    %r10
            jmp     .add_zeroes
        
        .add_ones:
            cmpq    $0, %r11
            je      .end
            movq    $1, (%rdx, %r13, 8)
            incq    %r13
            decq    %r11
            jmp     .add_ones

    .end:
        movq    %rbp, %rsp
        pop     %rbp
        ret
