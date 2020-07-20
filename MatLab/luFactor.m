function[L, U, P] = luFactor(A)
% function luFactor determines the LU Factorization of a square matrix with
% partial pivoting 
%---Inputs---
% A- coefficient matrix
%---Outputs---
% L- lower triangle matrix
% U- upper trianlge matrix 
% P- pivot matrix



if nargin > 1 % checking for incorrect number of inputs 
    error('error: incorrect number of inputs')
end 

% setting up variables 
[n, n1] = size(A);
L=eye(n); % L starts as identity matrix of A
P=eye(n); % P starts as identity matrix of A
U=A;      % U starts as A 


for x = 1:n % stopping criteria 
  [pivot m] = max(abs(U(x:n, x)));    % pivot # 
  m = m+x-1;     
  
  if m ~= x
    U([m,x],:) =  U([x,m], :);   % interchange rows m and x in U
    P([m,x],:) =  P([x,m], :);   % interchange rows m and x in P
    if x >= 2;                  
      L([m,x],1:x-1) =  L([x,m], 1:x-1);   % interchange rows m and x in columns 1:x-1 of L
    end;
  end
  
  for y = x+1:n                           
    L(y, x) = U(y, x) / U(x, x);          % changing L
    U(y, :) =  U(y, :) - L(y, x)*U(x, :); % changing U 
  end
end
 

disp('L is') % displaying matrix L
disp(L)
disp('U is') % displaying matrix U
disp(U)
disp('P is') % displaying matrix P
disp(P)

check_PxA =P*A    % checking P*A
matlabluA = lu(A) % checking answer using matlab lu function 
check_LxU = L*U   % checking L*U

if check_LxU ~= check_PxA
    error('LU = PA is not true')
end 


