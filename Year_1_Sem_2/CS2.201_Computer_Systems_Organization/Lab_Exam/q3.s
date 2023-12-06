.global is_palindrome

is_palindrome:
    # %rdi -> number

    pushq   %rbp
    movq    %rsp, %rbp
    movq    $0, %r10     # digit count
    movq    $10, %r11    # divisor
    movq    $2, %r12     # divisor (for checking even/odd)
    movq    %rdi, %rbx
    movq    %rdi, %rcx

    .count_digits:
        cmpq    $0, %rax
        je      .done_counting
        movq    $0, %rdx
        incq    %r10
        idivq   %r11
        jmp     .count_digits

    .done_counting:
        cmpq   $1, %r10
        je     .is_palindrome

        # %r10 -> digit count
        movq    %r10, %rax
        movq    $0, %rdx
        idivq   %r12
        cmpq    $0, %rdx
        je      .check_palindrome_even
        jmp     .check_palindrome_odd

    .check_palindrome_even:
        movq    %rax, %r13          # digit count / 2
        movq    %rcx, %rax

        .push_loop_even:
            cmpq    $0, %r13
            je      .pop_loop_even
            movq    $0, %rdx
            idivq   %r11
            pushq   %rdx
            decq    %r13
            decq    %r10
            jmp     .push_loop_even

        .pop_loop_even:
            cmpq    $0, %r10
            je      .is_palindrome
            movq    $0, %r13
            movq    $0, %rdx
            idivq   %r11
            popq    %r13
            cmpq    %rdx, %r13
            jne     .not_palindrome
            decq    %r10
            jmp     .pop_loop_even

    .check_palindrome_odd:
        movq    %rax, %r13          # digit count / 2
        movq    %rcx, %rax

        .push_loop_odd:
            cmpq    $0, %r13
            je      .mid_digit
            movq    $0, %rdx
            idivq   %r11            # get digit into %rdx and push it
            pushq   %rdx
            decq    %r13            # decrement digit count
            decq    %r10            
            jmp     .push_loop_odd

        .mid_digit:
            cmpq    $0, %r10
            je      .not_palindrome
            movq    $0, %rdx
            idivq   %r11            # get digit into %rdx and discard it
            decq    %r10

        .pop_loop_odd:
            cmpq    $0, %r10
            je      .is_palindrome
            movq    $0, %r13
            movq    $0, %rdx
            idivq   %r11            # get digit into %rdx and compare with popped digit
            popq    %r13
            cmpq    %rdx, %r13
            jne     .not_palindrome
            decq    %r10
            jmp     .pop_loop_odd


    .is_palindrome:
        movq    $1, %rax
        jmp     .done   
    
    .not_palindrome:
        movq    $0, %rax
        jmp     .done
    
    .done:
        movq    %rbp, %rsp
        popq    %rbp
        ret
