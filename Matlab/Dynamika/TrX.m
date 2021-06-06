function [ Tr] = TrX(l1)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
syms Tr;
Tr(1,1)=1;
Tr(1,2)=0; 
Tr(1,3)=0;
Tr(1,4)=l1;
Tr(2,1)=0; 
Tr(2,2)=1; 
Tr(2,3)=0;
Tr(2,4)=0;
Tr(3,1)=0; 
Tr(3,2)=0; 
Tr(3,3)=1;
Tr(3,4)=0;
Tr(4,1)=0; 
Tr(4,2)=0; 
Tr(4,3)=0;
Tr(4,4)=1;
end

