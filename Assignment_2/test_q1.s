.global is_balanced
is_balanced:
    # Function prologue
    pushq   %rbp
    movq    %rsp, %rbp

    # Arguments
    mov 8(%ebp), %ecx   # n (number of characters)
    mov 12(%ebp), %esi  # input (string pointer)

    # Local variables
    sub $4, %esp        # Allocate 4 bytes on the stack for parentheses stack
    mov %esp, %ebx      # Parentheses stack pointer
    xor %eax, %eax      # Counter for open parentheses

    # Iterate through the string
loop_start:
    movb (%esi), %dl    # Load byte at [ESI] into DL
    test %dl, %dl       # Check if the byte is null (end of string)
    jz loop_end         # If null, jump to loop_end

    cmpb $'(', %dl      # Compare byte in DL with '('
    je push_stack       # If equal, jump to push_stack
    cmpb $'{', %dl      # Compare byte in DL with '{'
    je push_stack       # If equal, jump to push_stack
    cmpb $'[', %dl      # Compare byte in DL with '['
    je push_stack       # If equal, jump to push_stack

    cmpb $')', %dl      # Compare byte in DL with ')'
    je pop_stack        # If equal, jump to pop_stack
    cmpb $'}', %dl      # Compare byte in DL with '}'
    je pop_stack        # If equal, jump to pop_stack
    cmpb $']', %dl      # Compare byte in DL with ']'
    je pop_stack        # If equal, jump to pop_stack

    # If the character is not any of the parentheses, handle the error or additional checks here
    # ...
    # Your code here

    jmp next_iteration  # Jump to next_iteration to continue iterating

push_stack:
    cmp $2, %eax        # Check if the maximum nesting level is reached (2 opening parentheses)
    jge not_balanced    # If greater or equal, jump to not_balanced

    pushq %rdx           # Push the opening parentheses onto the stack
    add $1, %eax       # Increment the counter for open parentheses

    jmp next_iteration  # Jump to next_iteration to continue iterating

pop_stack:
    cmp $0, %eax        # Check if there are any open parentheses on the stack
    jle not_balanced    # If less or equal, jump to not_balanced

    popq %rcx            # Pop the top parentheses from the stack
    sub $1, %eax       # Decrement the counter for open parentheses

    cmp %dl, %cl       # Compare the opening and closing parentheses
    jne not_balanced   # If not equal, jump to not_balanced

    jmp next_iteration  # Jump to next_iteration to continue iterating

next_iteration:
    add $1, %esi        # Increment the string pointer
    loop loop_start     # Loop until ECX becomes zero

loop_end:
    cmp $0, %eax        # Check if there are any open parentheses left on the stack
    jne not_balanced    # If not equal, jump to not_balanced

    # Balanced
    mov $1, %eax        # Set return value to 1 (true)
    jmp end_function

not_balanced:
    # Not balanced
    mov $0, %eax        # Set return value to 0 (false)
    jmp end_function

end_function:
    # Function epilogue
    movq %rbp, %rsp
    popq %rbp
    ret

