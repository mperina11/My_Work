%% Problem 8
%density and temperature plot

Tc = 1:100;
P = (5.5289*10.^-8)*(Tc).^3 - (8.5016*10.^-6)*(Tc).^2 + (6.5622*10.^-5)*(Tc) + 0.99987
plot(P,Tc)


%% Problem 9
%time (t) and charge (qt) plot 
%from t = 0 to 0.8

qo = 10;
R = 60;
L = 9;
C = 0.00005;
t = 0:0.01:0.8;
qt = ((qo).*exp(-R.*t/2.*L) ).* (cos(sqrt((1/L.*C) - ((R/2.*L).^2) .*t)));
plot(t,qt)
disp(t)
disp(qt)

%% Problem 10 
% bell shpaed curve, z (x axis) and f (y axis)

z = -5:0.1:5
fz = (1/sqrt(2.*pi) ) .* exp((-z.^2)/2) 
plot(z,fz)
disp('need to label axis')







