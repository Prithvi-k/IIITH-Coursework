# long long int get_product_assembly(node *head);

.global get_product_assembly

get_product_assembly:
    # %rdi = head

    movq $1, %rax           # product = 1

    testq %rdi, %rdi
    je .L2


    .L1:
        testq %rdi, %rdi
        je .L2

        addq $8, %rdi       # head = head->next
        imulq (%rdi), %rax  # product *= head->data
        movq (%rdi), %rdi   # head = head->next
        jmp .L1

    .L2:
        ret


