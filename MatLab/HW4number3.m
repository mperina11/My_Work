%% HW4
% #3
clear
clc
global g
% set parameters
g=9.81;
r=8.65; % balloon radius
CD=0.47; % dimensionless drag coefficient
mP=265; % mass of payload
P=101300; % atmospheric pressure
Rgas=287; % Universal gas constant for dry air
TC=100; % air temperature
rhoa=1.2; % air density
zd=200; % elevation at which mass is jettisoned
md=100; % mass jettisoned
ti=0; % initial time (s)
tf=60; % final time (s)
vi=0; % initial velocity
zi=0; % initial elevation
dt=1.6; % integration time step
% precomputations
d = 2 * r; Ta = TC + 273.15; Ab = pi / 4 * d ^ 2;
Vb = pi / 6 * d ^ 3; rhog = P / Rgas / Ta; mG = Vb * rhog;
FB = Vb * rhoa * g; FG = mG * g; cdp = rhoa * Ab * CD / 2;
% compute times, velocities and elevations
[t,y] = Balloon(ti,vi,zi,tf,dt,FB,FG,mG,cdp,mP,md,zd);
% Display results
fprintf('      t(s)     v(m/s)     z(m/s)\n');
xx=[t y];
fprintf('%10.3f %10.3f %10.3f\n',xx');
% Plot results
subplot(2,1,1)
plot(t,y(:,1))
title('Velocity vs. time')
xlabel('time (s)'),ylabel('velocity (m/s)')
subplot(2,1,2)
plot(t,y(:,2))
title('Elevation vs. time')
xlabel('time (s)'),ylabel('elevation (m)')


function [tout,yout]=Balloon(ti,vi,zi,tf,dt,varargin)
% balloon
% function [tout,yout]=Balloon(ti,vi,zi,tf,dt,FB,FG,mG,cdp,mP,md,zd)
% Function to generate solutions of vertical velocity and elevation
% versus time with Euler’s method for a hot air balloon
% Input:
% FB = buoyancy force (N)
% FG = gravity force (N)
% mG = mass (kg)
% cdp=dimensional drag coefficient
% mP= mass of payload (kg)
% md=mass jettisoned (kg)
% zd=elevation at which mass is jettisoned (m)
% ti = initial time (s)
% vi=initial velocity (m/s)
% zi=initial elevation (m)
% tf = final time (s)
% dt=integration time step (s)
% Output:
% tout = vector of times (s)
% yout[:,1] = velocities (m/s)
% yout[:,2] = elevations (m)
% Code to implement Euler’s method to compute output
t = ti; y = [vi zi];
tout = t; yout = y;
while(1)
if t + dt > tf, dt = tf - t; end
dy=dydt(y,varargin{:});
y = y + dy' * dt;
t = t + dt;
tout = [tout; t]; yout = [yout; y];
if t >= tf, break, end
end
end

function [dy]=dydt(y,FB,FG,mG,cdp,mP,md,zd)
global g
if y(2) < zd
mP1 = mP;
else
mP1 = mP - md;
end
dy = [(FB - FG) / (mP1 + mG) - mP1 * g / (mP1 + mG) - ...
cdp / (mP1 + mG) * y(1) ^ 2; y(1)];
end

