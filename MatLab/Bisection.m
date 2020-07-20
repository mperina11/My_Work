function [xr,ea,iter] = Bisection(func,xl,xu)
% HW10, mole fraction x of H2O that dissociates
% Bisection -> finds the root of a given function 
%--Inputs-- 
% func = the function
% xl = initial guess lower 
% xu = initial guess upper 
%--Outputs--
% xr = the estimated root
% ea = approximated error
% iter = number of iterations 

%errors
if nargin < 3
    error('Not enough Arguements')
end 
if nargin > 3
    error('Too many arguemets')
end 

%setting up loop 
maxiter = 200;
iter=0; 
xr=xl; 
while iter < maxiter %loop to run for 200 iterations 
    xrold = xr;     % store old value before computations below
    xm = (xl+xu)/2; % finding middle between bounds
    xr = func(xm);  % Finding funciton value at xm
    
   
    iter= iter+1;   % counting number of iterations 
    ea=abs((xr-xrold)/xr)*100; % approximate percent error
   
    if func(xu)*func(xm) < 0 % checking for sign change to assign new bounds 
        xl = xm;
        xu = xu;
    else 
        xl = xl;
        xu = xm;
        
    
    end
    if iter == 200
        disp(['Answer is: ', num2str(xm)]) % displays answer once 200 iterations are complete 
        fplot(func) % plots the function
        title('Plot of Function') 
    end     
    
end
% I couldn't figure out how to fix the warning about vectorizing the
% function in order to improve plotting it. 

% Answer when "Bisection(@(xi)((xi/(1-xi))*(sqrt((2*3)/(2+xi)))-0.05),0,1)"
% is inputed = 0.028249







