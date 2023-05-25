# CS163 - Program 4
***
#### by Cole Nemec

This is the source for my submission as Program 4 of PSU's CS163 course in Spring 2023. 

Portions of this code are based upon listings in chapters 3, 15 - 18 of Frank Carrano's "Data Abstraction & Problem Solving with C++: Walls and Mirrors".

*** 

## Notes on Interfaces & Implementaions:
In many interfaces, I follow the data abstraction model adopted by Carrano - where possible, interfaces are designed generically so that
they can be re-used at a later date. This means that, rather than placing recursive methods in the ``private`` field of a class, they're 
``protected`` so that they can be used by derived classses. I wonder if this may be discouraged in this course, so I'm very open to 
changing it.