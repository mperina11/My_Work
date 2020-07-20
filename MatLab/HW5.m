%% HW5

function Fmatrix = Fmatrix(n,m)
% Fmatrix returns a matrix that contains the first row is the number of the
% column, the first column is the nuber of the row, the rest of the element
% has a value equal to the sum of the element above it and to the left

n = input('number of rows')
m = input('number of columns')

tic
for k = 1:n %rows
    for h = 1:m %columns 
        if k == 1
        A(k,h) = h
        elseif h == 1
        A(k,h) = k
        else 
        A(k,h) = h + k
        end
    end
end
toc