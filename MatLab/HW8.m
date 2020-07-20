%% Problem 1
% Using third-order Taylor Series Expansion to 
% predict f(3) for f(x) = 25x^3 + (-6)*x^2 + 7x -88
% using x=1 as the base point 
% Algorithm below  compute the true percent relative error 
% for each approximation 
syms x 
f(x) = 25*x^3 + (-6)*x^2 + 7 * x - 88;
f1(x)= 75*x^2 + 12 * x + 7;
f2(x) = 150*x + 12;
f3 = 150;
%--------------------------------------------------------------------------
% Zero Order
fzero = f(3)
% fzero = 554
%--------------------------------------------------------------------------
% First Order
fone = f(3) + f1(3) *(3 - 1) 
% fone = 1990
%--------------------------------------------------------------------------
% Second Order
ftwo = f(3) + f1(3) * (3 - 1) + (((f2(3))/(factorial(2))) * ((3 - 1)^2))
% ftwo = 2914
%--------------------------------------------------------------------------
% Third Order
fthree = f(3) + f1(3) * (3 - 1) + ((f2(3))/(factorial(2))) * ((3 - 1)^2) + ((f3)/(factorial(3))) * ((3 - 1)^3)
% fthree= 3114
%% Problem 2
% Using forward and backward difference approximation 
% O(h) and centered difference appr. of O(h^2)
% to estimate the first derivative of the function 
% in problem 1. Will evaluate the derivative at x=2 
% using a step size of h=0.25, and will compare
% results with the true value of the derivative.
% Will interpret your results on the basis of the remainder
% term of the Taylor series expansion. 
%--------------------------------------------------------------------------
% Forward Difference Approximation 
% 2 + 0.25 (the step size) = 2.25
F = (f(2.25) - f(2))/0.25
% F= 320.5625
%--------------------------------------------------------------------------
% Backward Difference Approximation 
% 2 - 0.25 (the step size) = 1.75
B = (f(2) - f(1.75))/0.25
% B= 248.5625
%--------------------------------------------------------------------------
% Centered Difference Approximation
% forward (2.25) and backward (1.75) 
C = ((f(2.25) - f(1.75))/4) * (0.25^2) 
% C= 2.223  