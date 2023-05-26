.global special_op

special_op:
    # Function prelude
    pushq   %rbp                        # save base pointer
    movq    %rsp, %rbp                  # set base pointer

    movq    16(%rbp), %r10              # rax = 7th argument
    movq    24(%rbp), %r11              # r11 = 8th argument

    movq    %rdi, %rax                  # x = 1st argument

    addq    %rsi, %rax                  # x += 2nd argument
    addq    %rdx, %rax                  # x += 3rd argument
    addq    %rcx, %rax                  # x += 4th argument
    addq    %r8, %rax                   # x += 5th argument
    addq    %r9, %rax                   # x += 6th argument
    addq    %r10, %rax                  # x += 7th argument
    subq    %r11, %rax                  # x -= 8th argument

    # Function conclude
    movq    %rbp, %rsp              # restore stack pointer 
    popq    %rbp                    # restore base pointer
    ret

