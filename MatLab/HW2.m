%% Problem 1     Martin Perina 
% #1 
subplot(2,2,1) 
qo = 10; R = 60; L = 9; C = 0.00005;
t = 0:0.01:0.8;
qt = qo.*exp((-R.*t)/(2.*L)).* cos(sqrt((1/(L.*C)) - (((R/(2.*L)).^2).*t))); 
plot(t,qt,'b')
title('With C=0.00005')
xlabel('Time')
ylabel('Charge on Capacitor') 
legend('C=0.00005')
% #2
subplot(2,2,2) 
qo = 10; R = 60; L = 9; C2 = 0.0005;
t = 0:0.01:0.8;
qt2 = qo.*exp((-R.*t)/(2.*L)).* cos(sqrt((1/(L.*C2)) - (((R/(2.*L)).^2).*t))); 
plot(t,qt2,'r')
title('With C=0.0005')
xlabel('Time')
ylabel('Charge on Capacitor') 
legend('C=0.0005')

%both plots
subplot(2,2,[3,4])
plot(t,qt,'b',t,qt2,'r') 
title('Both ')
xlabel('Time')
ylabel('Charge on Capacitor') 
legend('C=0.00005','C=0.0005')

% #3
% The charge on the capacitor (qt) increases as the capacitance (C)
% decreases. 


%% Problem 2
t = 10:10:60;
c = [3.4 2.6 1.6 1.3 1.0 0.5];
t2 = 0:10:70;
c2 = (4.84).*exp(-0.034 .*t2);

%data
subplot(2,2,1)
plot(t,c,'dr')
title('Data')
legend('data') 
xlabel('Time')
ylabel('Concentration') 

%function
subplot(2,2,2)
plot(t2,c2,'--g')
title('Function') 
legend('Function') 
xlabel('Time')
ylabel('Concentration') 

%both plots 
subplot(2,2,[3,4])
plot(t,c,'dr',t2,c2,'--g')
title('Both Data and Function')
legend('Data','Function') 
xlabel('Time')
ylabel('Concentration') 









