%% Test case to solve system of 4 linear equations
clear all
close all
clc

% rand('seed',123);
% randn('seed',456);
n = 4;
A = (rand(n,n)*100);            % Input matrix 
A =[   27.5070   80.4450    8.7077   93.9398;
   24.8629   98.6104   80.2091    1.8178;
   45.1639    2.9992   98.9145   68.3839;
   22.7713   53.5664    6.6946   78.3736 ];

A_cond = (cond(A));
disp(['condition of matrix  ', num2str(A_cond)]);
b = [5;4;8;9];                  

X = cheloskeyOutput(A,b);
X_inBuilt = A\b;                
disp('X and X_inbuilt')

[X X_inBuilt];
difference = (X-X_inBuilt);
SNR = 20*log10(sqrt(mean(difference.^2)))
%% test the equation 
output = [A(1,:)*X A(2,:)*X A(3,:)*X A(4,:)*X]
% diff
