-module (fibonacci).
-export ([fib/1]).

% a(2) = a(1) + a(0)
% a(n) = a(n-1) + a(n-2)
fib(N) when N =:= 1; N =:= 2 -> 1;
fib(N) -> fib(N, 2, 1, 1).

fib(N, Cur, An_1, An_2) when N =:= Cur -> An_2;
fib(N, Cur, An_1, An_2) -> fib(N, Cur + 1, An_2, An_1 + An_2).