function [t,y] = Heun(dydt,tspan,y0,h,es,maxit)
% This function will determine the derivative of a function using the Heun 
% method with multiple iterations. This method is used instead of Euler's method
% because it is more accurate.
 

%--Inputs--
%-dydt - the differential equation (Enter in @(t,y) format)
%-tspan - the span the user wants to solve for within the equation
%-y0 - the initial condition
%-h - the step size
%-es - the error (defaulted to 0.001 if user does not specify)
%-maxit - the max number of iterations (defaulted to 50 iterations if user does not specify)
%--OUTPUTS--
%-t - the t value
%-y - the final derivative estimate of point t


if nargin < 4  %checking for number of inputs
    error('Not Enough Inputs')
end

if nargin == 4 % default for both es and maxit
    es = 0.001
    maxit = 50
end

if nargin == 5 % default for only maxit
    maxit = 50
end

iter = 0  % setting iter to zero to start loop
ea = 100  % setting ea to 100 to start loop 


while ea > es || iter < maxit  %stopping criteria  
    
    initial = y0 + h * dydt(t,y); 
    corrector = y0 + (h/2) * ( y0 + initial);
    ea = (abs(corrector - initial/ corrector)*100);  %error
    iter = iter +1; %counting iterations 
    y = corrector; %This has to be inserted into a y matrix HOW??
    
end

disp(y) %display y values
disp(t) %display t values 
plot(t,y,'b') %plot of variables t and y 
y0 = tspan + h  %counting y0



    
    
    
    
    
    
    
    
    
    
    