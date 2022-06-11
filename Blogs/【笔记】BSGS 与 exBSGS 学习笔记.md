  
  
提前说明：里面有复制 [OI-wiki-BSGS](https://oi-wiki.org/math/number-theory/bsgs/) 内容  
### BSGS  
  
BSGS 是用于求解  
  
  
$$  
  a^x \equiv b \pmod p  
$$  
    
  
形式的问题，其中 $a \perp p$。  
  
因为幂函数取模的周期性，可以像双向搜索那样减少问题规模。  
  
令 $x = A \cdot t - B$，其中 $0\le A,B \le t$，则有 $a^{A \cdot t -B} \equiv b \pmod p$，稍加变换，则有 $a^{A \cdot t} \equiv ba^B \pmod p$。  
  
这样，就可以从两边同时搜索以减小枚举量了。复杂度 $O(t + \frac{p}{t})$。均值可证取 $t = \lceil \sqrt p \rceil$ 时，总复杂度最小。（不向下取整是为代码上可以只枚举到 $t$）。  
  
为什么要 $a \perp p$ 呢？  
  
注意到我们求出的是 $A,B$，我们需要保证从 $a^{A \cdot t} \equiv ba^B \pmod p$ 可以推回 $a^{A \cdot t -B} \equiv b \pmod p$，前式是后式左右两边除以 $a^B$ 得到，所以必须有 $a^B \perp p$ 即 $a\perp p$。  
  
~~想这段想了好久，想通后还开了个 [pr](https://github.com/OI-wiki/OI-wiki/pull/3885)，以此纪念自己的 pr 第一次被 merge！~~  
  
硕大的OI\-wiki，居然找不到一份BSGS代码。  
  
[代码 & 注意事项](https://www.luogu.com.cn/paste/1bl47t72)  
### exBSGS  
  
[这里我也不能推导得比 OI-wiki 更好，自己看推导吧](https://oi-wiki.org/math/number-theory/bsgs/#_8)  
  
[代码 & 注意事项](https://www.luogu.com.cn/paste/okpa15vo)  
<br>  
  

-----
分类：笔记