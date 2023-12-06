.global is_balanced

is_balanced:
    # %rdi -> array length
    # %rsi -> array pointer

    # function prelude
    pushq   %rbp
    movq    %rsp, %rbp

    movq    $0, %r8                     # open parenthesis counter
    movq    $0, %r9                     # close parenthesis counter
    movq    $0, %r10                    # check if there is parenthesis in input
                                        # this handles cases where there is no parenthesis in input

    cmpq    $0, %rdi                    # if array length is 0
    je      .end

    .iterate_through_string:
        cmpq    $0, %rdi                # if array length is 0
        je      .end

        movq    (%rsi), %rcx             # load current character
        andq    $0xFF, %rcx              # mask to 8 bits

        # check if character is parenthesis
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

        incq    %rsi                    # increment array pointer
        decq    %rdi                    # decrement array length
        jmp     .iterate_through_string
    
    .open_parenthesis:
        movq    $1, %r10                # there is parenthesis in input
        pushq   %rcx                    # save current character
        incq    %r8                     # increment open parenthesis counter
        incq    %rsi                    # increment array pointer
        decq    %rdi                    # decrement array length
        jmp     .iterate_through_string

    .close_parenthesis:
        movq    $1, %r10                # there is parenthesis in input
        incq    %r9                     # increment close parenthesis counter
        cmpq    $0, %r8                 # if open parenthesis counter is 0
        je      .end
        popq    %rdx                    # load character from stack
        cmpq    $'(', %rdx              # if character is not open parenthesis
        jne     .end
        decq    %r8                     # decrement open parenthesis counter
        decq    %r9                     # decrement close parenthesis counter
        incq    %rsi                    # increment array pointer
        decq    %rdi                    # decrement array length
        jmp     .iterate_through_string

    .close_parenthesis_square:
        movq    $1, %r10                # there is parenthesis in input
        incq    %r9                     # increment close parenthesis counter
        cmpq    $0, %r8                 # if open parenthesis counter is 0
        je      .end
        popq    %rdx                    # load character from stack
        cmpq    $'[', %rdx              # if character is not open parenthesis
        jne     .end
        decq    %r8                     # decrement open parenthesis counter
        decq    %r9                     # decrement close parenthesis counter
        incq    %rsi                    # increment array pointer
        decq    %rdi                    # decrement array length
        jmp     .iterate_through_string

    .close_parenthesis_curly:
        movq    $1, %r10                # there is parenthesis in input
        incq    %r9                     # increment close parenthesis counter
        cmpq    $0, %r8                 # if open parenthesis counter is 0
        je      .end
        popq    %rdx                    # load character from stack
        cmpq    $'{', %rdx              # if character is not open parenthesis
        jne     .end
        decq    %r8                     # decrement open parenthesis counter
        decq    %r9                     # decrement close parenthesis counter
        incq    %rsi                    # increment array pointer
        decq    %rdi                    # decrement array length
        jmp     .iterate_through_string
    
    .end:
        cmpq    $0, %r8                 # if open parenthesis counter is 0
        je      .balanced
        jne     .not_balanced
    
    .balanced:
        cmpq    $0, %r9                 # if close parenthesis counter is 0
        jne     .not_balanced
        movq    $1, %rax                # return 1
        movq    %rbp, %rsp              # restore stack pointer 
        popq    %rbp                    # restore base pointer
        ret

    .not_balanced:
        cmpq    $0, %r10                # if there is parenthesis in input
        je     .balanced
        movq    $0, %rax                # return 0
        movq    %rbp, %rsp              # restore stack pointer 
        popq    %rbp                    # restore base pointer
        ret
