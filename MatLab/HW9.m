%% HW 9
function falseposition = HW9(func,xl,xu,es,maxiter)  %estimates the root of the given funciton
%--Inputs--
% func- the function being evaluated
% xl- the lower guess
% xu- the upper guess
% es- the desired relative error (default 0.0001%)
% maxiter- the number of iterations desired (default 200)
%--Outputs--
% root- the estimated root location
% fx- the function evaluated at the root location
% ea- the approximate relative error (%)
% iter- hw many iterations were performed 
%% might be useful---------
% syms v --> function(v)????--------
clear
clc

if nargin < 3
    error ('Not enough information')
end 
if nargin > 5
    error ('Too much information')
end 

syms x 
f(x) = func;

rootold = 0; %defining rootold so that it is not used the first time 
iter = 0;   %defining iter before start


%----------------------------------------------------------------------------------------------------------

if isempty(es) == 1 && isempty(maxiter) == 1
    es = 0.0001;
    maxiter = 200;
    while iter < maxiter || ea > es 
        root= xu - ((f(xu)*(xl-xu))/ (f(xl)-f(xu)));
        if rootold ~= 0                      % if statement so that error isn't calc on first iteration because there is no previous (old) root
           ea = abs((root-rootold)/root) * 100;  %approximate error
        end 
   %sign change
b = (xl+xu)/2;
if f(xl) * f(b) < 0  %sign change for lower and middle guess
    xl = xl;
    xu = b;
end
if f(b) * f(xu) < 0  %sign change for middle and upper guess 
    xl = b;
    xu = xu;
end   
iter = iter + 1;  % count of iterations
rootold = root;   % saving this root to use for error in the next iteration 

        %disp ea vs es 
    end

else 
    while iter < maxiter || ea > es 
        root= xu - ((f(xu)*(xl-xu))/ (f(xl)-f(xu)));
        if rootold ~= 0                      % if statement so that error isn't calc on first iteration because there is no previous (old) root
           ea = abs((root-rootold)/root) * 100;  %approximate error
        end 
   %sign change
b = (xl+xu)/2;
if f(xl) * f(b) < 0  %sign change for lower and middle guess
    xl = xl;
    xu = b;
end
if f(b) * f(xu) < 0  %sign change for middle and upper guess 
    xl = b;
    xu = xu;
end   
iter = iter + 1;  % count of iterations
rootold = root;   % saving this root to use for error in the next iteration 

        %disp ea vs es 
    end 
end 