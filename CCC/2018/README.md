# CCC 2018

# Problem S1 | Voronoi Villages

Just look at the next three, figure out the distance and keep the minimum


# Problem S2 | Sunflowers

I had a function that rotated the matrix and checked if it worked for each rotation, to rotate a matrix just 
read the original matrix starting from the corner and put it on another.


# Problem S3 | RoboThieves

A straghtforward DFS with a bunch of edge cases. This problem is very easy to mess up or get caught on one of the many
edge cases they have built. 

One of the main issues I came accros was assuming that the DSF would always take the minimum path to a certain spot. This is
true normally but with the addition of elevators this is not true. To circumvent that I would only push something onto the queue
if it was a shorter distance to that spot than what had been previously recorded. 

# Problem S4 | Balanced Trees

Assuming you have the niave recursive solution down (which you should atleast have), the primary obersation that you need
to make is that you are continually re calculating numbers within a number.


Take example 10 and divide by numbers from 1 to 10


i

1  |  10

2  |  5

3  |  3

4  |  2

5  |  2

6  |  1

7  |  1

8  |  1

9  |  1

10 |  1


You see that when you niavely iterate through you are calculating 1, five times, 2, two times. You can skip this using division
so that you calculate these based on your current number, so you calculate the 5 ones when you are at 2, and calculate the two 2's 
when you are at 3. This takes a bit of thinking so I suggest running through this with pencil and paper and using the 100 as your example.


# Problem S5 | Maximum Strategic Savings

I don't have much to say except follow DMOJ's solution, theirs is pretty cohesive and as long as you take your time reading and process the 
entire thing you pretty much got it. For learning about kruskals with disjoint set just check out https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html.
Learning minimum spanning tree and especially disjoin set union will help out a ton.