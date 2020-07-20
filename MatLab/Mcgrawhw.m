t=3
x=t
fx= 55*(exp(-0.5625)) - ((80*9.8)/15)*(1-exp(-0.5625)) 
fx1=((80*9.8)/15)
root= x - (fx/fx1) 

%% HW12
a = [0 -7 5; 0 4 7; -4 3 -7]
c = [50; -30; 40]
b = a\c
z = transpose(a)
j = inv(a)

% part 2
A = [6 -1; 12 8; -5 4]
B = [4 0; 0.5 2]
C = [2 -2; 3 1]

AB = A*B
AC = A*C
BC = B*C
CB = C*B
CA = C*A %is not possible 



