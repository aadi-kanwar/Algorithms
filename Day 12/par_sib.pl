p(a,b).
p(b,c).
p(c,h).
p(c,i).
p(b,d).
p(d,e).
p(e,f).
p(e,g).

gp(X,Z):- p(X,Y), p(Y,Z).
s(X,Y):- p(Z,X),p(Z,Y), X\=Y.

print_all_grandparent_pairs :-
    write('All Grandparent Pairs:'), nl,
    findall((X, Y), gp(X, Y), GP),
    print_pairs(GP).


% Query to find and print all sibling pairs
print_all_sibling_pairs :-
    write('All Sibling Pairs:'), nl,
    findall((A, B), s(A, B), SP),
    print_pairs(SP).

% Helper predicate to print pairs from a list
print_pairs([]).
print_pairs([(X, Y)|Tail]) :-
    format('~w and ~w~n', [X, Y]),
    print_pairs(Tail).

% Main query to print all grandparent and sibling pairs
print_all_pairs :-
    print_all_grandparent_pairs,
    nl,
    print_all_sibling_pairs.
