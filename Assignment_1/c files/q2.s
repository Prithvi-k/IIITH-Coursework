.global calculate

# Concept used:
#   - Multiplication by 2^n is the same as left shift by n
#   - Division by 2^n is the same as right shift by n
#       - round down a positive result but round up a negative one
#       - i.e is result id negative, we add 1
#

calculate:
    # %rdi -> a
    # %rsi -> x
    # %rdx -> b
    # %rcx -> y

    movq %rdi, %rax
    movq %rdx, %rbx

    #
    # Evaluates value of x and branches accordingly
    #
    .eval_x:
        
        cmpq $0, %rsi           # Compares x with 0
        je .eval_y              # If x is 0, we return a
        jg .x_pos               # If x is positive, we multiply a by 2^x (left shift by x)
        negq %rsi               # Negate x and right shift a by x (equivalent to division by 2^x)
        cmpq $0, %rax           # If a is negative, we divide a by 2^x and take care to round up
        jl .a_neg_x_neg         # Jump to .a_neg_x_neg
        jmp .x_neg              # Jump to .x_neg
    
    #
    # x > 0, we left shift a by x
    #
    .x_pos:
        salq $1, %rax           # Left shift a by 1
        decq %rsi               # Decrement x
        cmpq $0, %rsi           # Compare x with 0
        jg .x_pos               # If x is positive, we jump back to .x_pos
        jmp .eval_y             # Otherwise, we jump to .eval_y

    #
    # x < 0 (& a > 0), we right shift a by x
    #
    .x_neg:
        sarq $1, %rax           # Right shift a by 1 
        decq %rsi               # Decrement x
        cmpq $0, %rsi           # Compare x with 0
        jg .x_neg               # If x is positive, we jump back to .x_neg
        jmp .eval_y             # Otherwise, we jump to .eval_y

    #
    # x < 0 (& a < 0), we right shift a by x and add 1
    #
    .a_neg_x_neg:
        sarq $1, %rax           # Right shift a by 1
        decq %rsi               # Decrement x
        cmpq $0, %rsi           # Compare x with 0      
        jg .a_neg_x_neg         # If x is positive, we jump back to .a_neg_x_neg
        addq $1, %rax           # Otherwise, we add 1 to a (to round up)
        jmp .eval_y             # Jump to .eval_y

    #
    # Evaluates value of y and branches accordingly
    #
    .eval_y:
        cmpq $0, %rcx           # Compares y with 0
        je .end                 # If y is 0, we return b
        jg .y_pos               # If y is positive, we multiply b by 2^y (left shift by y)
        negq %rcx               # Negate y and right shift b by y (equivalent to division by 2^y)
        cmpq $0, %rbx           # If y is negative, we divide b by 2^y and take care to round up
        jl .b_neg_y_neg         # Jump to .b_neg_y_neg  
        jmp .y_neg              # Jump to .y_neg

    #
    # y > 0, we left shift b by y
    #
    .y_pos:
        salq $1, %rbx           # Left shift b by 1
        decq %rcx               # Decrement y
        cmpq $0, %rcx           # Compare y with 0
        jg .y_pos               # If y is positive, we jump back to .y_pos
        jmp .end                # Otherwise, we jump to .end

    #
    # y < 0 (& b > 0), we right shift b by y
    #
    .y_neg:
        sarq $1, %rbx           # Right shift b by 1
        decq %rcx               # Decrement y
        cmpq $0, %rcx           # Compare y with 0
        jg .y_neg               # If y is positive, we jump back to .y_neg
        jmp .end                # Otherwise, we jump to .end
    
    #
    # y < 0 (& b < 0), we right shift b by y and add 1
    #
    .b_neg_y_neg:
        sarq $1, %rbx           # Right shift b by 1
        decq %rcx               # Decrement y
        cmpq $0, %rcx           # Compare y with 0
        jg .b_neg_y_neg         # If y is positive, we jump back to .b_neg_y_neg
        addq $1, %rbx           # Otherwise, we add 1 to b (to round up)
        jmp .end                # Jump to .end

    #
    # Final step: we add each result and return
    #
    .end:
        addq %rbx, %rax         # Add value in %rbx to %rax
        ret                     # Return value in %rax
