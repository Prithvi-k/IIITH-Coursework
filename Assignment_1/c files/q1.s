.global get_sum

get_sum:
    # %rdi -> arr
    # %rsi -> n

    movq $0, %rax # Initialise a variable for sum = 0
    movq $3, %rbx # Initialise a variable for dividend
    movq $0, %rcx # Variable to store sum

    cmpq $0, %rsi
    je .L4
    
    .L2:
        cmpq $0, %rsi
        jle .L4
        movq $0, %rdx # Variable to store remainder

        movq (%rdi), %rax
        idivq %rbx
        cmpq $0, %rdx
        je .L3

        addq $8, %rdi
        subq $1, %rsi
        jmp .L2

    .L3:
        addq (%rdi), %rcx
        addq $8, %rdi
        subq $1, %rsi
        cmpq $0, %rsi
        je .L4
        jmp .L2

    .L4:
        movq %rcx, %rax
        ret

