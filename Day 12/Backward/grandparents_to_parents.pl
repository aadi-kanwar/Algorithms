p(a,b).
p(b,c).
p(c,h).
p(c,i).
p(b,d).
p(d,e).
p(e,f).
p(e,g).

gp(X,Z):- p(X,Y), p(Y,Z).

find_parents(GP,Child):-
    gp(GP,Child),
    p(Par,Child),
    write(Parent), write('is parent of'), write(Child),n1.

