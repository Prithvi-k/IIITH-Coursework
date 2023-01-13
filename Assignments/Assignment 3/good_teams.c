/* Problem Description

You are a coach and want to select a team of size K
. You have N players who have signed up to be on the team. Each player has a distinct skill which is described by the array A. That is, the ith element of array A denotes the skill of the ith

player.

You wonder what are the distinct teams of size K
. Two teams x,y are considered different if there is some player i who is included in x but not in y

.

Print all distinct teams of size K

in lexicographical order. Further, for each team, print the team in sorted increasing order of the skills of the players.

A team x
is lexicographically smaller than team y if at the first index that x and y differ in, say i, x[i]<y[i]

.
Input Format

The first line of input contains two space-separated integers N,K

that denote the total number of players and the size of the team respectively.

The second line contains N
distinct space-separated integers A1,A2,…,AN

that denote the skills of the players.

Note that the array A

is given in sorted increasing order.
Input constraints

    1≤K≤N≤105

1≤Ai≤109
It is guaranteed that the total number of distinct teams times the size of each time will not exceed 2×105

Output Format

Output the distinct teams of size K

each on a new line. Each team should internally be sorted in increasing order and the teams themselves should be printed in lexicographical order.
Sample Input
Copy

5 2
1 10 23 31 100

Sample Output
Copy

1 10
1 23
1 31
1 100
10 23
10 31
10 100
23 31
23 100
31 100 */