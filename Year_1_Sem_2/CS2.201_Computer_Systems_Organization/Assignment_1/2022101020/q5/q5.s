.global get_address_smallest

get_address_smallest:
    # %rdi = arr
    # %rsi = size

    movq %rdi, %rax         # Initialise %rax with address of first element
    movq (%rdi), %rbx       # Initialise %rbx with value of first element
    
    # Since first element is already initialised, we can start at second element
    addq $8, %rdi           # Increment address
    decq %rsi               # Decrement size

    #
    # Loop through array
    #
    .L1:
        cmpq $0, %rsi       # Check if size is 0
        je .end             # If so, jump to .L2

        movq (%rdi), %rcx   # Load current element into %rcx
        cmpq %rcx, %rbx     # Compare current element with smallest
        jle .L2             # If current element is greater than smallest, jump to .L2

        # If current element is smaller than smallest, update smallest
        movq %rdi, %rax     # Update address of smallest
        movq (%rdi), %rbx   # Update value of smallest
        addq $8, %rdi       # Increment address
        decq %rsi           # Decrement size
        jmp .L1             # Jump to .L1

    #
    # Current element is greater
    #
    .L2:
        addq $8, %rdi       # Increment address
        decq %rsi           # Decrement size
        jmp .L1             # Jump to .L1

    #
    # Return
    #
    .end:
        ret

