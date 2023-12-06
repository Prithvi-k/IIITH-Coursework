.global main

main:
    movq %rsp, %rbp
    push $2
    push $4
    push $10
    movq -8(%rbp), %rax     # rax = 2
    addq -16(%rbp), %rax    # rax = 2 + 4 = 6
    addq -24(%rbp), %rax    # rax = 6 + 10 = 16
    movq %rbp, %rsp
    ret


