Although I didn't come up with the solution during the contest, I thought I understood why we should try to add elements after reading the editorial. I'll try to explain it here.

For convenience, let's call the set that satisfies the conditions a "good" set.

On the one hand, according to the conditions, if $S$ is a good set, then every subset of $S$ is also a good set. As a result, we can reach every good set from some smaller good sets (i.e. its proper subsets). To make the problem more solvable, it's obvious that we should extend a good set of size $n$ to some good sets of size $n+1$.

On the other hand, for a good set $S$, it's necessary that there aren't two or more non-empty subsets $T$ of $S$ that the XOR of the elements in $T$ is zero. (it's easy to prove if you understand the editorial, so the proof is omitted) Combined with the Pigeonhole principle, the size of a good set must be $O(N)$. After exploring the properties of good sets, we can find that only the size of a good set is small enough to be a DP state, so that we should try to define $dp_i$ as the number of good sets of size $i$.