.global findNearest

findNearest:
    # rdi -> array
    # rsi -> answer array
    # rdx -> array length

    # Function prelude
    pushq   %rbp                        # save base pointer
    movq    %rsp, %rbp                  # set base pointer

    cmpq    $0, %rdx                    # if array length is 0
    #   TODO

    movq    $1, %rcx                    # variable to store number of indices in stack
    pushq   $0                          # push 0 to stack
    movq    $1, %rax                    # set index to 0

    .iterate_through_array:
        cmpq    %rdx, %rax              # if index == array length
        je      .end                    # end loop
        movq    (%rdi, %rax, 8), %r8    # get current element
        popq    %r9                     # get top of stack
        cmpq    (%rdi, %r9, 8), %r8     # if current element < top of stack
        jg     .add_to_answer_array     # add current index to answer array
        pushq   %r9
        pushq   %rax
        incq    %rcx                    # increment number of indices in stack
        incq    %rax                    # increment index
        jmp     .iterate_through_array  # continue loop
    
    .add_to_answer_array:
        movq    %r8, (%rsi, %r9, 8)     # push current value to answer array
        decq    %rcx                    # decrement number of indices in stack
        cmpq    $0, %rcx                # if number of indices in stack == 0
        jle     .empty_stack
        jmp     .iterate_through_array  # continue loop

    .empty_stack:
        pushq   %rax                    # push current index to stack
        incq    %rcx                    # increment number of indices in stack
        incq    %rax                    # increment index
        jmp     .iterate_through_array  # continue loop


    .end:
        cmpq    $0, %rcx                # if number of indices in stack == 0
        jg      .stack_not_empty    
        jmp     .end_function
    
    .stack_not_empty:
        cmpq    $0, %rcx                # if number of indices in stack == 0
        jle     .end_function
        popq    %r9                     # get top of stack
        movq    $-1, (%rsi, %r9, 8)    # push current value to answer array
        decq    %rcx                    # decrement number of indices in stack
        jmp     .stack_not_empty        # continue loop

    .end_function:
        movq    %rbp, %rsp              # restore stack pointer
        popq    %rbp                    # restore base pointer
        ret                             # return

