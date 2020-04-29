For the problem, I used three program and a dummy header, made a Makefile with default, vectorized and unvectorized options, made a speed up comparison graph:![image-20200429001145850](/Users/victorfu/Library/Application Support/typora-user-images/image-20200429001145850.png)

The speedup is highest for ikj order around matrix size of 80-120, I guess that's because the cache spec happens to contain 80-120 size matrices at a time so the hit rate would be the highest. And the rise 

I think the speed is lower in jki order because two matrices using i as their row index, so it would be slow putting i in the innermost loop. But and since the other matrix uses k as its row index, putting k outside of j would turn out to be faster.

I've confused about the <0.1 speed up of the jki order. I've attached my Makefile and would you give me some feedback on my compiler instructions?

