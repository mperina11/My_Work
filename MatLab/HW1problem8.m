%% Problem 8
%density and temperature plot

Tc = 1:100;
P = (5.5289*10.^-8)*(Tc).^3 - (8.5016*10.^-6)*(Tc).^2 + (6.5622*10.^-5)*(Tc) + 0.99987
plot(P,Tc)


