#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[]) {

    int req_pid = atoi(argv[1]);
    int priority = atoi(argv[2]);

    printf("[user]set_priority called with pid %d and new_priority %d\n", req_pid, priority);

    int prev_priority = set_priority(req_pid, priority);

    return prev_priority;
}