# Results

## First Come First Serve (FCFS)

- The creation time of every process is stored at the ctime variable at the struct proc.
- In the scheduler function, we implement FCFS by first going through all the processes and picking the process with the minimum creation time.
- Then we just run the process by calling the swtch call.

## Multi Level Feedback Queue (MLFQ)
- We add variables queue, process_run_time, total_process_run_time, wait_time.
- For each iteration, we choose the process with highest priority. In case of multiple processes, we prefer the one with largest wait time (FCFS).
- We run the chosen process.
- We use the total_process_run_time variable to keep track of the total time of process existence which is used to track aging. When it exceeds the set limit for aging (35 ticks), its priority is increased and it is run.