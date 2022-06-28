想了想还是要汇总方便补题 & 总结

## abc257 （GH 未补）

### 赛时情况

link：<https://atcoder.jp/contests/abc257>

[罚时巨多的提交记录](https://atcoder.jp/contests/abc257/submissions?f.Task=&f.LanguageName=&f.Status=&f.User=zag)

比赛时间：2022-06-25 20:00-21:40

比赛情况：通过 ABC，D 题口胡正确却没调出来，E 题直接口胡，没开后面题。

rank 2692  performance 887  rating 2 → 64 (+62) /kk

A 题一个简单题，然而我使用 $O(1)$ 算法，直到 11min 时才做出来 /kk（2022-06-25 20:10:39）

B 题简单小 % 你 （2022-06-25 20:17:19）

C 题简单二分，但是 `lower_bound` 什么的的边界总写错，调了半天才出来 （2022-06-25 20:56:50）一个 C 竟耗了 40min /kk /jk

D 题一眼二分答案，于是开始写 $O(n^3 \log n)$ 的  `check`。调到比赛结束还没调出来，反复 WA#3。

### 赛后

[MnZn 求助，D 总是 AC 39 WA 1，该怎么调？](https://www.luogu.com.cn/discuss/450917)

得到了 [dalao](https://www.luogu.com.cn/user/168223) 的私信指导后发现自己的代码十分臃肿，原因是强行套 Prim 板子。改了一下后改掉两个数组，仍然 WA。最后发现是 lr 的范围问题，开大了爆了 `long long` /kk

赛后一开 E 就发现远简单于 D。15min 后一发就过了。

F 是一个有趣的题，考虑把 $0$ 当成一个节点，然后就可以高效合并信息了。$dis_{1,n} = \min\{dis_{1,n},dis_{1,i}+dis_{0,n},dis_{1,0}+dis_{i,n}\}$。从 $0$ 和 $n$ 出发各跑一次 dij 即得。

G 是性质题。

[[str记录]abc254G Prefix Concatenation](https://www.cnblogs.com/purplevine/p/16415986.html)

总结：
- 第一场 at，速度偏慢，debug 时间过长。因为之前模拟赛时间充裕没注意这点。现在打这种快节奏的比赛，必须尽快调整状态。
- 死卡一道题，不知道换题。E 比 D 简单不少，却因为死卡 D 没开 E。F 还算显然，却因为时间问题甚至没开。LZY 打了 6 题，确实如果正常发挥 6 题也行（忽然想起上场 ABC 胡了 6 题 F 却一直调不出来）

开始盼下一场 ABC 了，为什么没有人一起打啊…… 求一起 vp /kel

## arc143（DEF 未补）

### 赛时：通过 AB

A 观察样例便得，耗时 9min ~~甚至短于昨天 abc A 的耗时~~

B 往反面想，要排除所有含有同时是列最大数和行最小数的数，开始一直在因式分解 $204516$ 和 $16!-204516$，在试图容斥时忽然发现每张方格表最多含有一个这样的数，大力枚举这是几，然后就做完了。

rank 969, performance 1344, rating 64 → 314 (+250)，总算开始步入正轨了……

### 赛后

C 赛时研究了很久都没想到可以直接膜 $x+y$，还是对博弈论理解不深。

DE 题解都没有，等有了来补吧……

B 提取问题本质的能力还是太差，应该想到这只是 arc 的 B，正解不会太复杂，早点发现性质

附：关于博弈论

> Unless the question is supposed to be for high rated people (GMs or higher) , which would require Grundy number/nimbers/mex and etc, many game theory problems could be solved analyzing the winning states and losing states. I first looked at a single pile game, and observed that in order for the first player to win, there has to be an integer k≥1, such that kx+(k−1)y≤a1, and kx+ky>a1. Let W denote a winning state and let L denote a losing state. It should be clear (with calculation) that W becomes L for the second player after the first player removes x stones, and L becomes W in a similar fashion. Now to generalize, consider the array as an array of Ls and Ws. The simple strategy of always handing the other person an array full of L (this should remind you of nim game if it doesn't I don't know why I wrote this), should be the optimal strategy. This solution is not possible if we have already have an array full of Ls to begin with and whatever move we make, there would be Ws in the resulting array. Now, it seems like if we have Ws to begin with, we can change all Ws to Ls and we are winning. However, there is one corner case, where we have x>y, and L for the first player is a W for the second player in some cases as shown above. If that is the case, the first player loses.

<https://codeforces.com/blog/entry/104216?#comment-926210>