function [root,fx,ea,iter] = falsePosition(func,xl,xu,es,maxiter)
%--This function will solve for the roots of a given function--
%--Inputs--------------------------------------------------
% func- the function being evaluated (must be formated @(x) f(x)
% xl- the lower guess
% xu- the upper guess
% es- the desired relative error (default 0.0001%)
% maxiter- the number of iterations desired (default 200)
%--Outputs-------------------------------------------------
% root- the estimated root location
% fx- the function evaluated at the root location
% ea- the approximate relative error (%)
% iter- hw many iterations were performed 

clear
clc

if nargin < 3  %check if not enough arguments
    error ('Not enough information')
end 

if nargin < 4 
    es = 0.0001;                               %default for es
    maxiter = 200;                             %default for maxiter
end 
if nargin < 5
    maxiter = 200;                             %default for maxiter 
end
if nargin > 5  %check if too many arguments 
    error ('Too much information')
end 

iter = 0;      %defining iter before start

%----------------------------------------------------------------------------------------------------------

if isempty(es) == 1 && isempty(maxiter) == 1   %if both es and maxiter were not specified, then the defaults are used
       while iter < maxiter || ea > es            %loop that allows es or maxiter to be the stopping criteria 
        root= xu - ((func(xu)*(xl-xu))/ (func(xl)-func(xu))); %solving for the root  
        
        
        %sign change
b = (xl+xu)/2;       %finding the middle bewtween the lower and upper bounds
if  func(xl) * func(b) < 0  %sign change for lower and middle guess
    xl = xl;         %assigning new lower bound
    xu = b;          %assigning new upper bound
end
if func(b) * func(xu) < 0  %sign change for middle and upper guess 
    xl = b;          %assigning new lower bound
    xu = xu;         %assigning new upper bound
     
end
ea = abs((xu - (func(xu)*(xl-xu)))/ ((func(xl)-func(xu))) - root)/ (xu -(func(xu)*(xl-xu))/ (func(xl)-func(xu)))* 100;%approximate error

iter = iter + 1;     % count of iterations
          %disp results 
       end 
else                                %if either es or maxiter (or both) were specified
    while iter < maxiter || ea > es %loop that allows es or maxiter to be the stopping criteria 
        root= xu - ((func(xu)*(xl-xu))/ (func(xl)-func(xu))); %solving for the root 
       
   %sign change
b = (xl+xu)/2;       %finding the middle between upper and lower guess
if func(xl) * f(uncb) < 0  %sign change for lower and middle guess
    xl = xl;         %assigning new lower bound
    xu = b;          %assigning new upper bound
end
if func(b) * func(xu) < 0  %sign change for middle and upper guess 
    xl = b;          %assigning new lower bound
    xu = xu;         %assigning new upper bound
end   
ea = abs((xu - (func(xu)*(xl-xu)))/ ((func(xl)-func(xu))) - root)/ (xu -(func(xu)*(xl-xu))/ (func(xl)-func(xu)))* 100;%approximate error


iter = iter + 1;     % count of iterations
        %disp results
    end 
end 
