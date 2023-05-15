# void divide(ll m, ll n, ll* arr);

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
        # Find remainder of m / n without idivq
        cmpq %rsi, %rdi
        jl .L4

        subq %rsi, %rdi
        addq $1, (%rdx)
        jmp .L2
    
    .L3:
        # Find remainder of m / n without idivq
        cmpq $0, %rdi
        jge .L4

        addq %rsi, %rdi
        subq $1, (%rdx)
        jmp .L3
    

    .L4:
        # Store quotient (%rdi) in arr[0] and remainder (%rdi) in arr[1]
        movq %rdi, 8(%rdx)
        ret

