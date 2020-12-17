# CCC 2020

Problem S1 | Surmising a Sprinter’s Speed

Sort all the pairs by time and calculate every velocity between
every adjacent pair. Remember that c++'s vector sort alg for pairs sorts
by the first number in the pair then the second, like how it would 
sort for strings.

Problem S2 | Escape Room

It is essentially a breadth first search but you need to make an obersavation
to achieve full marks. Notice how the possible positions you can go is solely
dependant on your current number. This means that if you have exhausted a 
number once, you never need to go to that number again even though you might
encounter that number at a different position because regardless of the position
you find the number in, you don't need to recalculate it. So do a breadth first search
(BFS) but have way to check if you have been their, in my case I mapped the coordinate
pair with a bool.

Problem S3 | Searching for Strings

Concenptually understanding the solution is far easier than the solution. First, notice
that when you dont need to know every permutation of the substring and that you only need 
to compare if two strings have the same amount of each letter. The idea of the solution is
to roll through the full string and check if the substring has the same number of letters as
the original, this means that they are a permutation of one another. After this you want
to save the substring somewhere to make sure you don't add the same substring twice. The 
difficulty of this problem comes with implementing a rolling hash. I won't explain how to do 
it here but check out the Rabin-Karp algorithm to learn how to do it. On thing to note is that I
continually got WA (wrong answer) using 64bit hashes, so you need to either use a double hash 
(what I used)or perhaps use a 128bit modulo (haven't tested this out yet). For the double hash,
you need to use a standard binary search tree (std::set) rather than a hash map (std::unordered_set)
since hash maps don't allow pairs of numbers. This is theoretically much slower as retrieval becomes
O(log n) instead of O(1) however this difference should be negligable.

Problem S4 | Swapping Seats

If you want a more detailed explanation refer to https://dmoj.ca/problem/ccc20s4/editorial as 
this is essentially my solution.

The idea is that you want to test every possible starting position for A and you need to achieve 
this in O(1) since N can equal 1,000,000. The goal is to make is so the next # of letters are A,
the total number of A's, then B's, then C's. You then swap out all the non-A's in A and add that 
to a sum, then you do the same for the non-B's in the B section. But what about the A's in the B
section and B's in the A section? Well, thats why we add back the min of the two numbers, because
thats gonna be the swaps that aren't required after the first swapping. 

This question helps if their are examples. 
Take (this is just for calculating a certain starting point)

A B B C A B A C B C A A

We have 5 A's 4 B's and 3 C's, so the borders should be like

A B B C A | B A C B | C A A

With the first 5 for A's, second for B's third for C'same

Now lets swap out all the non-A's in A (lowecase for swap)

A a a a A | B b C B | C b c

so swaps = 3. 



Then swap the non-B's in B

A A A A A | B B b B | C C c

So now swaps = 4


The reason the formula guarentees that swapped letters are ideal
(meaning B's in A always try to go to B) is because we add back the
MINIMUM number of between the B's in A and A's in B. This means that atleast
those numbers are guarenteed to be able to be swapped directly between the two 
since their atleast that many in both areas.


Kinda confusing but refer to DMOJ's editorial for the more whole solution
while this here is me trying to fully explain why the solution works and any
questions that I had pop up when I was solving this.


Problem S5 | Josh’s Double Bacon Deluxe

Notice how it doesn't matter the position of a burger type chosen, only the 
burger type itself. The only position that matters is the last person eating 
that type of burger (since all previous people will still have an option since
the original pool of burgers only went down 1). This is a dynamic programming
problem where you need to continually build the probabilities of each consecutive
number. 


Take example 

1 2 3 1 1 2 4 5 3 | n = 9

0 1 2 3 4 5 6 7 8 | i


Lets say you he takes the first, 2. By the time person i = 1 decides he will always
take i = 5's burger since their is another 2 available, showing that it does not 
matter what unique burger is taken, just that it is taken. This is why we only consider
its last possible position as this is when another choice is made between the remaining
burgers. Now how do we calculate the probability of a number? Lets take the probability
to pick the number 2, because it's the first last number (not counting 1 cus they don't
matter) its probability to be chosen is just 1/n x 2 (because their are two of them). 
But after we choose 2 whats the probability that we choose, lets say, 4? Well after we
choose 2, which is 2/9 we have a 1 / 4 in choosing any of the remaining numbers. So when 
we get to the next last number, our probability to reach it is already calculated from 
the previous ones. 

A little bit confusing so I recommend going through this and manually running in on the
test case above with pencil and paper to understand whats going on. 


