%% Problem 9
%time (t) and charge (qt) plot 
%from t = 0 to 0.8
%used increments of 0.01 for (t) to create a "better looking" bell curve 

qo = 10;
R = 60;
L = 9;
C = 0.00005;
t = 0:0.01:0.8;
qt = ((qo).*exp(-R.*t/2.*L) ).* (cos(sqrt((1/L.*C) - ((R/2.*L).^2) .*t)));
plot(t,qt)
disp(t)
disp(qt)
