# Travelling Salesman Problem
# PROBLEM DESCRIPTION
Travelling salesman problem describes a salesman must travel N cities, each city exactly once such that he returns to the city from where he started in order to minimize the total cost of the path. It is very often called TSP. It is an NP-hard problem. So to solve this problem an approximate solution is required for larger N. This document provides one such implementation of the algorithm. The coordinates of N cities are given with the distances between each pair of cities in a file. The output of the program is the best/shortest path available.

# METHODOLOGY
One such algorithm to find the approximate solution is Simulated Annealing. This process is inspired by metallurgy process name Annealing. Annealing is the process in which the randomness of molecules in metals or glasses is increased by heating and allowed to cool slowly in order to remove stress and toughens it. In a similar manner in Simulated Annealing the randomness of the selecting a neighbouring city is high and slowly the variable similar to Temperature is allowed to decrease so as to get the tighter bound of cost along the path. This probabilistic technique is used to find the global optimum of a given function. The probability function used is (where f is cost function):      *p = 1/(1 + e^(-delta(f)/T))
          
# SOLUTION
To solve the given problem the Simulated Annealing is modified using a reverse operator to move to the next neighbour. This operator inverses the path between randomly selected indices ‘i’ and ‘j’. And then the probability function is used to find the probability of selecting the move. As temperature decreases, we come closer to the optimal solution required.

# RESULT
Results are displayed in table:

TestCase                   Distance

Euc_100:                    1652.24651291062

Euc_250:                    2730.00507528521

Euc_500:                    3781.05805703443

NonEuc_100:                 5324.57794986620

NonEuc_250:                 13012.4409655095

NonEuc_500:                 25656.5499723088
