%% HW 4
%#1
% Finding the elapsed days in a year 
input('Days?')
da = ans
input('Month?')
mo = ans
input('Is it a leap year')
leap = ans

if mo == 1
   days = da;
elseif mo == 2
    days = 31 + da;
elseif mo == 3
     days = 31 + 28 + da;
elseif mo == 4
     days = 31 + 28 + 31 + da;
elseif mo == 5
     days = 31 + 28 + 31 + 30 + da;
elseif mo == 6
     days = 31 + 28 + 31 + 30 + 31 + da;
elseif mo == 7
     days = 31 + 28 + 31 + 30 + 31 + 30 + da;
elseif mo == 8
     days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + da;
elseif mo == 9
     days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + da;
elseif mo == 10
     days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + da;
elseif mo == 11
     days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + da;     
else mo = 12;
     days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + da;
end
 
%factoring in leap year
     if leap == 1
         days = days + 1
     else
         days = days
         
     end
     
disp(days)
