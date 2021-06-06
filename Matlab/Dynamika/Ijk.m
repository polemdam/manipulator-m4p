function [ I] = Ijk(l,m)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
syms I;
I(1,1)=(l^2*m)/3;
I(1,2)=0; 
I(1,3)=0;
I(1,4)=-(l*m)/2;
I(2,1)=0; 
I(2,2)=0; 
I(2,3)=0;
I(2,4)=0;
I(3,1)=0; 
I(3,2)=0; 
I(3,3)=0;
I(3,4)=0;
I(4,1)=-(l*m)/2; 
I(4,2)=0; 
I(4,3)=0;
I(4,4)=m;
end

