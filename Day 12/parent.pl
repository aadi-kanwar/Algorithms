p(a,b). %Parent & Grandparentp
p(b,c).

gp(X,Z):-p(X, Y), p(Y,Z).
