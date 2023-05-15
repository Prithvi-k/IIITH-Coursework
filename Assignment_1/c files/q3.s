.global divide

divide:
    # %rdi = m
    # %rsi = n
    # %rdx = arr

    .L1:
        # If m > 0, then go to .L2 else go to .L3
        movq $0, (%rdx)
        cmpq $0, %rdi
        jge .L2
        jmp .L3
    
    .L2:
        # If m > 0
        
        cmpq $0, %rsi
        # If n < 0, then go to .L5 else continue
        jl .L5

        cmpq %rsi, %rdi
        jl .L4

        subq %rsi, %rdi
        addq $1, (%rdx)
        jmp .L2
    
    .L3:
        # When m < 0

        cmpq $0, %rsi
        # If n < 0, then go to .L6 else continue
        jl .L6

        cmpq $0, %rdi
        jge .L4

        addq %rsi, %rdi
        subq $1, (%rdx)
        jmp .L3
    
    .L5:
        # m > 0, n < 0
        movq %rsi, %r9
        negq %r9
        cmpq %r9, %rdi
        jl .L4

        addq %rsi, %rdi
        subq $1, (%rdx)
        jmp .L5
    
    .L6:
        # m < 0, n < 0
        cmpq $0, %rdi
        jge .L4

        subq %rsi, %rdi
        addq $1, (%rdx)
        jmp .L6

    .L4:
        # Store quotient (%rdi) in arr[0] and remainder (%rdi) in arr[1]
        movq %rdi, 8(%rdx)
        ret

