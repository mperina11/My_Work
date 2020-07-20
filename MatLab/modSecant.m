function [xr,ea,iter] = modSecant(func,xi,delta)
% HW10, mole fraction x of H2O that dissociates
% modSecant -> finds root of a given function using the modified secant
% method 
%--Inputs-- 
% func = the function
% xi = initial guess
% delta = distance between points, may need to try various #'s, 1,10,50,100
%--Outputs--
% xr = the estimated root
% ea = approximated error
% iter = number of iterations 

%errors
maxiter = 200;
iter=0; 
xr=xi; %xr as the lower bound
while iter < maxiter
    xrold = xr; % Do this to store old value before computations below
    xr = (xi-(delta)*(xi)*func(xi))/(func(xi+(delta)*(xi))-func(xi)) 
    
    % above is the only changed part from bisection
    iter= iter+1; %counter
    ea=abs((xr-xrold)/xr)*100; % relative percent error
            % sign check for new xr value
    if sign(func(xr))>0  % Determines which way to go with the new bracket
        xu=xr;    % Positive xr means xu is moved closer to zero
    else
        xl=xr; 
    end        
       
end
root=xr;
fx=func(xr);
iterationnumber= iter;
fprintf('%10.2f is the functions value at root=%10.2f, after %5.2f iterations. Relative percent error is %12.11f%', fx, root, iterationnumber,ea)
end







