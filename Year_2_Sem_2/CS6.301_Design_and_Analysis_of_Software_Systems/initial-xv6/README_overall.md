# Report

## Modified Priority-Based Scheduler in xv-6

#### Introduction

This project involves the implementation of a preemptive priority-based scheduler in the xv-6 operating system. The scheduler selects processes for execution based on their priority, with ties broken using scheduling history and start time. There are two types of priorities: Static Priority (SP) and Dynamic Priority (DP). SP is user-defined, ranging from 0 to 100, with lower values indicating higher priority. The default SP is set to 50. DP is determined by the SP and a Recent Behavior Index (RBI), a weighted sum of Running Time (RTime), Sleeping Time (STime), and Waiting Time (WTime). The DP is used for scheduling processes.

#### Implementation

- Priority Calculation

  The DP is calculated using the formula:
  \[ DP = \min(SP + RBI, 100) \]

  Where RBI is calculated as:
  \[ RBI = \max\left(\text{int}\left(\frac{3 \times RTime - STime - WTime}{RTime + WTime + STime + 1} \times 50\right), 0\right) \]
- System Call: ``set_priority()``
  To allow users to set the SP of a process, a new system call ``set_priority()`` has been introduced. The function signature is:

  ``int set_priority(int pid, int priority)``

  This system call allows users to change the SP of a process identified by pid to the new priority new_priority.
- Process Attributes
  New attributes have been added to each process to support the modified scheduler. These attributes include:

  ``RTime:`` Total time the process has been running since it was last scheduled.
  ``STime:`` Total time the process has spent sleeping.
  ``WTime:`` Total time the process has spent waiting in the ready queue.

  These attributes are incremented at each tick, and once a process is scheduled, they are reset to 0.
- Scheduling Algorithm
  The scheduling algorithm selects the process with the highest DP for execution. In case of a tie, the number of times a process has been scheduled and its start time are considered. Processes with lower start times are scheduled first.

#### Results and Analysis

The modified scheduler aims to improve task execution by considering both SP and recent behavior. The ``set_priority()`` system call provides users with control over the SP of their processes.

The SP allows users to set a base priority, reflecting the inherent importance of a process. On the other hand, the RBI, derived from RTime, WTime, and STime, introduces a dynamic element to the prioritization. By considering recent behavior, the scheduler becomes responsive to a process's current state, adjusting its priority accordingly. This approach ensures that processes exhibiting varying levels of activity, sleep, and waiting times are appropriately prioritized based on their real-time characteristics.

The combination of SP and RBI allows for a nuanced and context-aware prioritization scheme. Processes with lower SP values are assigned higher priority, reflecting their criticality, while the RBI introduces adaptability by considering recent behavior. This dual mechanism enhances the scheduler's ability to allocate resources efficiently, responding dynamically to the evolving requirements of the system.

Running schedulertest:

| Scheduler | CPUS | Average rtime | Average wtime |
| :-------: | :--: | :-----------: | :-----------: |
|    RR    |  1  |      11      |      146      |
|    RR    |  2  |      14      |      125      |
|    PBS    |  1  |      12      |      140      |
|    PBS    |  2  |       7       |      120      |
