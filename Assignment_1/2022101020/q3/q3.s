.global divide

divide:
    # %rdi = m
    # %rsi = n
    # %rdx = arr

    .L1:
        cmpq $0, %rsi           # Compare n with 0
        je .L7                  # Go to .L7, if n = 0
        movq $0, (%rdx)         # Initialise arr[0] to 0
        cmpq $0, %rdi           # Compare m with 0
        jge .L2                 # Go to .L2 (if m >= 0)
        jmp .L3                 # Go to .L3
    
    #
    # If m > 0
    #
    .L2:
        cmpq $0, %rsi           # If n < 0, then go to .L5 else continue
        jl .L5
        cmpq %rsi, %rdi         # If m < n, then go to .L4 else continue
        jl .L4
        subq %rsi, %rdi         # Subtract n from m
        addq $1, (%rdx)         # arr[0] = arr[0] + 1
        jmp .L2                 # Continue
    
    #
    # When m < 0
    #
    .L3:
        cmpq $0, %rsi           # If n < 0, then go to .L6 else continue   
        jl .L6
        cmpq $0, %rdi           # If m >= 0, then go to .L4 else continue
        jge .L4
        addq %rsi, %rdi         # Add n to m
        subq $1, (%rdx)         # arr[0] = arr[0] - 1
        jmp .L3                 # Continue
    
    #
    # When m > 0, n < 0
    #
    .L5:
        movq %rsi, %r12         # Store n in %r12
        negq %r12               # Negate n
    # Fall through to .L8
    .L8:
        cmpq %r12, %rdi         # If m < |n|, then go to .L4 else continue
        jl .L4
        addq %rsi, %rdi         # Add n to m
        subq $1, (%rdx)         # arr[0] = arr[0] - 1
        jmp .L8                 # Continue
    
    #
    # When m < 0, n < 0
    #
    .L6:
        cmpq $0, %rdi           # If m >= 0, then go to .L4 else continue
        jge .L4
        subq %rsi, %rdi         # Subtract n from m
        addq $1, (%rdx)         # arr[0] = arr[0] + 1
        jmp .L6                 # Continue

    #
    # When n = 0
    #
    .L7:
        movq $-1, (%rdx)        # Store -1 in arr[0]
        movq $-1, %rdi          # Store -1 in %rdi
        jmp .L4                 # Go to .L4

    #
    # Return
    #
    .L4:
        movq %rdi, 8(%rdx)      # Store remainder in arr[1]
        ret

