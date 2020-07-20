%% HW 3, Martin Perina 
%

prompt = ('What is the height of the water (ie the float) in meters?');
x = input(prompt);
h0 = 14; R = 23; r0 = 12.5; rw = ((x-19)*(R - r0)/h0);
if x >= 0 && x <= 33
    x = x;
    if x <=19
        %cylinder eq
        volumecyl = (pi)* ((25/2)^2)* (x)
        disp('meters cubed') 
    else
       %cylinder and cone eq 
       volumecylcone = ( (pi)* ((25/2)^2)* (19) ) + ( (pi)* (1/3)* (x - 19)* ( (rw)^2 + (rw)* R + R^2 )) 
       disp('meters cubed')
      
    end 
else 
    error('input doe not meet parameters (0 to 33m)') 
end
