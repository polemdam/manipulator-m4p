function [Co] = Cijk(M, i, j, q1, q2, q3)
%UNTITLED8 Summary of this function goes here
%   Detailed explanation goes here

syms Co;
Co=   (((diff(M(i, j), q1)+diff(M(1,1),q1)-diff(M(1,1),q1))/2)*diff(q1,t));%k=1
Co=Co+(((diff(M(1, 1), q2)+diff(M(1,2),q1)-diff(M(1,2),q1))/2)*diff(q2,t));%K=2
Co=Co+(((diff(M(1, 1), q3)+diff(M(1,3),q1)-diff(M(1,3),q1))/2)*diff(q3,t))%k=3
end

