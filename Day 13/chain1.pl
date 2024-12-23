% Facts

has_wings(robin).
has_wings(eagle).
has_wings(pigeon).
has_wings(penguin).  % Penguin does not have wings for the sake of this example

is_bird(robin).
is_bird(eagle).
is_bird(pigeon).
is_bird(penguin).

% Rules
can_fly(X) :-
    is_bird(X),         % X must be a bird
    has_wings(X).       % X must have wings

cannot_fly(X) :-
    is_bird(X),         % X must be a bird
    \+ has_wings(X).    % X does not have wings

% Forward chaining process to check flying ability of animals
forward_chaining :-
    % Iterate through all the birds and determine if they can fly
    (is_bird(X), (can_fly(X) ->
        format('~w can fly.~n', [X])
    ;   cannot_fly(X) ->
        format('~w cannot fly.~n', [X])
    ), fail).
% Backward chaining query to determine if X can fly
can_animal_fly(X) :-
    can_fly(X),         % Check if X can fly
    format('~w can fly.~n', [X]).

can_animal_fly(X) :-
    cannot_fly(X),      % Check if X cannot fly
    format('~w cannot fly.~n', [X]).
