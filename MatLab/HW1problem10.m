%% Problem 10 
% bell shpaed curve, z (x axis) and f (y axis)

z = -5:0.1:5
fz = (1/sqrt(2.*pi) ) .* exp((-z.^2)/2) 
plot(z,fz)