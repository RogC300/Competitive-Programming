# CCC 2019



# Problem S1 | Flipper

Pretty straightforward, notice how the order of operations don't matter so you just and 
doing an operation twice does nothing, so just see if an operation happens an odd number
of times and flip accordingly.


# Problem S2 | Pretty Average Primes

Learn about what a sieve of eratosthanes is then iterate through checking every possible
combination of numbers.


# Problem S3 | Arithmetic Square

If you think about the number of possible test cases, their aren't that many. If 2 in a row are
filled you know the third. As such, any grid with 6 or more numbers should be instantly completed
as long as you have a fill function that figures out the third number based on the first two. Similiarly, 
their should exist cases with 4 since once filled is always becomes 5. This leaves cases (once filled) 1, 2, 3 
and 5 remaining. One is pretty self explanority, just fill with the number. 2 is tricky, if the two are in a 
row then it becomes case 3, but if its not you wanna figure out which direction the grid should be increasing
in based on the two numbers and fill accordingly. With 3 their can be the case where its in a line and not in the 
line, if its not then you take a similiar approach to 2 numbers and if it is a line you can just copy the line to
the rest of the grid.


This problem was really tedious for me to figure out how to fill the grid, many mistakes were made and I found this 
problem more difficult in execution rather than understanding the solution, however the solution still is difficult to
figure out in a short amount of time.


This passes the additional cases on DMOJ. 
The additional cases on DMOJ attack solutions with non-optimal solutions to the 2 cases. Since with the 2 case you could
have also just iterated through testing each number from -1 million to a million to you found one and be accepted on the 
CCC grader which is what I initially did before doing my search solution.


# Problem S4 | Tourism

This problem is build into 2 parts, the Range Max Query (RMQ) section, and the dynamic programming. I suggest learning about
RMQ before attempting this problem to learn how to do one. The options for RMQ usually use a segment tree, but since the array
is static I used a Sparse Table (just search it up) instead, since it does each operation in O(1). 


The dynamic programming part essentially becomes, based on the positions we can come from, find the max sum. If you think about it
, if you increase the starting position and the sum becomes lower, than we know we shouldnt continue since we know that the max query
isn't gonna increase if you decrease the length of query. This solutions passes the CCC grader however it does not pass the DMOJ cases
since in fact the temperary sum can decrease before increasing. A little bit complicated but here is the first case of the DMOJ addditional
case grader.


10 3

8 5 2 9 6 3 3 3 9 8


And heres the dp table

8 8 8 17 17 17 23 20 26 32

1 2 3 4  5  6  7  8  9  10

You can see in the 8th position it decreases, and breaks my code since it doesnt consider going from the 9nth position. 
However the additional DMOJ cases are also poor for a reason since changing a few characters not related to the dp
can still pass the additional cases. Which is what ill let you figure out. 


Overall a pretty difficult problem which I suggest going through slowly to understand the dynamic programming, especially
since DMOJ does not currently have an editorial for it.


# Problem S5 | Triangle: The Data Structure

My solution essentially followed the DMOJ solution which was by carefully using a binary indexed tree. Once you learn 
how a binary indexed tree works (aka fenwick tree https://cp-algorithms.com/data_structures/fenwick.html) and reading
what DMOJ wrote it becomes easy to understand the solution. However, my code only passes the CCC grader and I kept getting 
TLE on DMOJ. For the N^2 Log K solution just check out Aaron He's video as it is explained really well their.
