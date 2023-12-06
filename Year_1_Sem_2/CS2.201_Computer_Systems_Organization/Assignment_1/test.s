.global test
.global alt_test

test:
    # %rdi -> n

    movq %rdi, %r12

    callq alt_test

    movq %r12, %rax

    ret

alt_test:
    movq %r12, %r9

    movq $14, %r12
                    
    ret


