## B
$\text{ans} = \sum_{i=1}^{m-1} f(s_i, s_{i+1}) + m + f(s_m, n) +  \text{div\_int}(n - s_m, d) + \begin{cases} 0, \ s_1 = 1\\ 1 + f(1, s_1), s_1 \neq 1 \end{cases} $

其中 $f(l, r) = \lceil (r - l)/ d\rceil - 1$.

$\text{div\_int}(x, d) = \begin{cases} 1, &x \% d =0\\ 0, &x \% d\neq 0\end{cases}$.

依次考虑删除$s_i$时对答案的影响即可。
