.global min_bacteria

min_bacteria:
    # %rdi -> number of bacteria

    movq    $0, %rax        # count
    movq    $2, %rcx        # current power of 2
    movq    $2, %rdx        # previous power of 2

    .main_loop:
        cmpq    $0, %rdi
        je      .end

        cmpq    $1, %rdi
        je      .single_bacteria

        cmpq    %rcx, %rdi
        jl      .add_new_bacteria

        movq    %rcx, %rdx
        shlq    %rcx
        jmp     .main_loop

    .add_new_bacteria:
        subq    %rdx, %rdi
        incq    %rax
        movq    $2, %rcx
        movq    $2, %rdx
        jmp     .main_loop

    .single_bacteria:
        incq    %rax
        jmp     .end

    .end:
        ret
