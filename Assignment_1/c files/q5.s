.global get_address_smallest

get_address_smallest:
    # %rdi = arr
    # %rsi = size

    movq $0, %rax           # Initialise %rax to 0
    movq %rdi, %r8          # Initialise a register to store address of smallest element

    # Loop through array
    .L2:
        cmpq $0, %rsi       # Check if size is 0
        je .L3              # If size is 0, jump to .L3

        movq %rdi, %r8      # Store address of element
        movq (%r8), %r9     # Store value of smallest element in %r9
        cmpq (%rdi), %r9    # Compare current element with smallest element
        jle .L1             # If current element is greater than smallest element, jump to .L1

        movq %rdi, %r8      # Store address of current element in %r8

    .L1:
        addq $8, %rdi       # Increment address of array by 8
        decq %rsi           # Decrement size by 1
        jmp .L2             # Jump to .L2

    .L3:
        movq %r8, %rax      # Store address of smallest element in %rax
        ret                 # Return address of smallest element
