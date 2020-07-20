function I = Simpson(x,y) 
% Simpson's 1/3 rule approximates area of integral 
%---Inputs---
% x- of data
% y- of data
%---Ooutputs---
% I- area of integral 

clear 
close all

if nargin ~= 2
    error('incorrect number of inputs')
end 

a = x(1); 
h = (b-a)/n; 
i4 = 0;  %4*f(xi)
i2 = 0;  %2*f(xj)


if reamin ~= 0  %if segment is even
    i4 = i4 + 4*y(i);
end 

for i = 3:2:n-1   %for odd 
    i2 = i2 + 2*y(i); %new sum
end

int = (h/3)*(y(1)) + i4 + i2 + y(n)); %integral =  y of first added to i4,i2,and y of second

a2 = y(n-1);
b2 = y(n);
h2 = x*(n-1,1) - x*(n,1); % new height
areat = ((a2 + b2)*h2)/2; % area of trapeziod

I = int;
disp('area is');
disp(int);
end 






