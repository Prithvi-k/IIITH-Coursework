.global get_sum

get_sum:
    # %rdi -> arr
    # %rsi -> n

    movq $0, %rax           # Initialise a variable for sum
    movq $3, %rbx           # Initialise a variable for dividend
    movq $0, %rcx           # Variable to store sum

    cmpq $0, %rsi           # Check if input length is 0
    je .L4
    
    #
    # Loop through array
    #
    .L2:
        cmpq $0, %rsi       # Check if number of elements is 0
        jle .L4
        movq $0, %rdx       # Variable to store remainder

        movq (%rdi), %rax   # Move value at index of array to register
        idivq %rbx          # Divide by 3
        cmpq $0, %rdx       # Compare remainder with 0
        je .L3              # Jump if remainder = 0 (i.e. divisible by 3)

        addq $8, %rdi       # Increment pointer by 8 
        subq $1, %rsi       # Decrease count by 1
        jmp .L2             # Continue loop

    #
    # If number id divisible by 3
    #
    .L3:
        addq (%rdi), %rcx   # Add value of number to sum
        addq $8, %rdi       # Increment pointer by 8 
        subq $1, %rsi       # Decrease count by 1
        cmpq $0, %rsi       # Checked if reached end of array
        je .L4              # If yes, go to .L4 (return)
        jmp .L2             # Else, jump to loop

    .L4:
        movq %rcx, %rax     # Move calculated sum to %rax to return
        ret

