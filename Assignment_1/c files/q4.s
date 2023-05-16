# long long int get_product_assembly(node *head);

.global get_product_assembly

get_product_assembly:
        # %rdi = head

        movq $1, %rax                   # product = 1

        testq %rdi, %rdi                # Check if head is NULL
        je .L2                          # If so, return 1

        movq $9223372036854775807, %r12 # Store LLONG_MAX in %r12

    #
    # Main function to calculate product
    #
    .L1:
        testq %rdi, %rdi                # Check if head is NULL
        je .L3                          # If so, go to .L3

        movq $0, %rdx                   # Clear %rdx
        imulq (%rdi), %rax              # product *= head->data

        cmpq $0, %rax                   # Check if product is 0
        je .L3                          # If so, go to .L3 (skips modulo)

        movq %rax, %rbx                 # Move product into %rbx
        movq $0, %rax                   # Clear %rax

        # Product modulo LLONG_MAX
        idivq %r12                      # product /= LLONG_MAX
        cmpq $0, %rdx                   # Check if remainder is 0
        je .L4                          # If not, go to .L4

        movq %rbx, %rax                 # Move product into %rax

    #
    # Traverse to next node, check if it's NULL
    #
    .L2:
        testq %rdi, %rdi                # Check if head is NULL
        je .L3                          # If so, go to .L3

        addq $8, %rdi                   # head = head->next
        movq (%rdi), %rsi               # move head->next into %rsi
        testq %rsi, %rsi                # Check if head->next is NULL
        je .L3                          # If so, go to .L3

        movq %rsi, %rdi                 # Move back to %rdi
        jmp .L1                         # Go to .L1

    #
    # Modulo function
    #
    .L4:
        movq %rbx, %rax                 # Move product into %rax
        idivq %r12                      # product /= LLONG_MAX
        movq %rdx, %rax                 # Move remainder into %rax
        jmp .L2                         # Go to .L2


    #
    # Return product
    #
    .L3:
        ret



