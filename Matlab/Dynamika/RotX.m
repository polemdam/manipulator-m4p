function [ Rz1] = RotX(q1)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
syms Rz1;
Rz1(1,1)=1;
Rz1(1,2)=0; 
Rz1(1,3)=0;
Rz1(1,4)=0;
Rz1(2,1)=0; 
Rz1(2,2)=cos(q1); 
Rz1(2,3)=-sin(q1);
Rz1(2,4)=0;
Rz1(3,1)=0; 
Rz1(3,2)=sin(q1); 
Rz1(3,3)=cos(q1);
Rz1(3,4)=0;
Rz1(4,1)=0; 
Rz1(4,2)=0; 
Rz1(4,3)=0;
Rz1(4,4)=1;
end

