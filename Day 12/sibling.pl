p(a,b).
p(a,c).
p(d,e).
p(d,f).

s(X,Y) :- p(Z,X), p(Z,Y),X\=Y.
