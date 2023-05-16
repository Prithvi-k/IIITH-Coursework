# long long int get_product_assembly(node *head);

.global get_product_assembly

get_product_assembly:
        # %rdi = head

        movq $1, %rax           # product = 1

        testq %rdi, %rdi        # Check if head is NULL
        je .L2                  # If so, return 1

    #
    # Main function to calculate product
    #
    .L1:
        testq %rdi, %rdi        # Check if head is NULL
        je .L3                  # If so, go to .L3

        imulq (%rdi), %rax      # product *= head->data

    #
    # Traverse to next node, check if it's NULL
    #
    .L2:
        testq %rdi, %rdi        # Check if head is NULL
        je .L3                  # If so, go to .L3

        addq $8, %rdi           # head = head->next
        movq (%rdi), %rsi       # move head->next into %rsi
        testq %rsi, %rsi        # Check if head->next is NULL
        je .L3                  # If so, go to .L3

        movq %rsi, %rdi         # Move back to %rdi
        jmp .L1                 # Go to .L1

    #
    # Return product
    #
    .L3:
        ret



