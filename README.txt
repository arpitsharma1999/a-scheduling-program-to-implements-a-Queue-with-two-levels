1. Operating system concept-
Description: 

Multilevel Feedback Queue Scheduling (MLFQ) (In this given problem we have two level)keep analyzing the behavior (time of execution) of processes and according to which it changes its priority.



Level 1 : Fixed priority preemptive Scheduling
Level 2 : Round Robin Scheduling
For a Fixed priority pre-emptive scheduling if one process P1 is scheduled and running and another process P2 with higher priority comes. The New process with high priority process P2 preempts currently running process P1 and process P1 will go to second level queue. Time for which process will strictly execute must be considered in the multiples of 2.
All the processes in second level queue will complete their execution according to round robin scheduling.
In this program Queue 2 will be processed after Queue 1 becomes empty and Priority of Queue 2 has lower priority than in Queue 1.


2. Algorithm:

In this problem we are using two type of scheduling algorithm –
1. Multilevel queue Scheduling
2. Round Robin 

Algorithm for Multilevel queue scheduling-


1.	When a process starts executing then it first enters queue 1.
2.	In queue 1 process executes for 4 unit and if it completes in this 4 unit or it gives CPU for I/O operation in this 4 unit than the priority of this process does not change and if it again comes in the ready queue than it again starts its execution in Queue 1.
3.	If a process in queue 1 does not complete in 4 unit then its priority gets reduced and it shifted to queue 2.
4.	Above points 2 and 3 are also true for queue 2 processes but the time quantum is 4 unit. In a general case if a process does not complete in a time quantum than it is shifted to the lower priority queue.
5.	In the last queue, processes are scheduled in FCFS manner.
6.	A process in lower priority queue can only execute only when higher priority queues are empty.
7.	A process running in the lower priority queue is interrupted by a process arriving in the higher priority queue.
Algorithm for Round Robin-


1- Create an array rem_bt[] to keep track of remaining
   burst time of processes. This array is initially a 
   copy of bt[] (burst times array)
2- Create another array wt[] to store waiting times
   of processes. Initialize this array as 0.
3- Initialize time : t = 0
4- Keep traversing the all processes while all processes
   are not done. Do following for i'th process if it is
   not done yet.

a-  If rem_bt[i] > quantum
(i)  t = t + quantum
(ii) bt_rem[i] -= quantum;
c- Else // Last cycle for this process
(i)  t = t + bt_rem[i];
           (ii) wt[i] = t - bt[i]
           (ii) bt_rem[i] = 0; // This process is over
