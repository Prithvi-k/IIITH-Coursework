.global is_balanced

is_balanced:
    # %rdi -> array length
    # %rsi -> array pointer

    pushq   %rbp
    movq    %rsp, %rbp

    movq    $0, %r8                     # open parenthesis counter

    cmpq    $0, %rdi                    # if array length is 0
    je      .end

    .iterate_through_string:
        cmpq    $0, %rdi                # if array length is 0
        je      .end

        movq    (%rsi), %rcx             # load current character
        andq    $0xFF, %rcx              # mask to 8 bits

        cmpq    $'(', %rcx           
        je      .open_parenthesis

        cmpq    $'[', %rcx
        je      .open_parenthesis

        cmpq    $'{', %rcx
        je      .open_parenthesis

        cmpq    $')', %rcx
        je      .close_parenthesis

        cmpq    $']', %rcx
        je      .close_parenthesis_square

        cmpq    $'}', %rcx
        je      .close_parenthesis_curly
    
    .open_parenthesis:
        pushq   %rcx                    # save current character
        incq    %r8                     # increment open parenthesis counter
        incq    %rsi                    # increment array pointer
        decq    %rdi                    # decrement array length
        jmp     .iterate_through_string

    .close_parenthesis:
        cmpq    $0, %r8                 # if open parenthesis counter is 0
        je      .end
        popq    %rdx                    # load character from stack
        cmpq    $'(', %rdx              # if character is not open parenthesis
        jne     .end
        decq    %r8                     # decrement open parenthesis counter
        incq    %rsi                    # increment array pointer
        decq    %rdi                    # decrement array length
        jmp     .iterate_through_string

    .close_parenthesis_square:
        cmpq    $0, %r8                 # if open parenthesis counter is 0
        je      .end
        popq    %rdx                    # load character from stack
        cmpq    $'[', %rdx              # if character is not open parenthesis
        jne     .end
        decq    %r8                     # decrement open parenthesis counter
        incq    %rsi                    # increment array pointer
        decq    %rdi                    # decrement array length
        jmp     .iterate_through_string

    .close_parenthesis_curly:
        cmpq    $0, %r8                 # if open parenthesis counter is 0
        je      .end
        popq    %rdx                    # load character from stack
        cmpq    $'{', %rdx              # if character is not open parenthesis
        jne     .end
        decq    %r8                     # decrement open parenthesis counter
        incq    %rsi                    # increment array pointer
        decq    %rdi                    # decrement array length
        jmp     .iterate_through_string
    
    .end:
        cmpq    $0, %r8                 # if open parenthesis counter is 0
        je      .balanced
        movq    $0, %rax                # return 0
        movq    %rbp, %rsp              # restore stack pointer 
        popq    %rbp                    # restore base pointer
        ret
    
    .balanced:
        movq    $1, %rax                # return 1
        movq    %rbp, %rsp              # restore stack pointer 
        popq    %rbp                    # restore base pointer
        ret








