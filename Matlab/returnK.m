function [K] = returnK(tabC, d1, d2, d3)
% funkcja returnK
%   Zwraca wektor współrzędnych efektora, obliczany na podstawie kinematyki
K(1)=(cos(tabC(1))*cos(tabC(2))*d2)+(d3*cos(tabC(1))*cos(tabC(2)+tabC(3)));
K(2)=(sin(tabC(1))*cos(tabC(2))*d2)+(d3*sin(tabC(1))*cos(tabC(2)+tabC(3)));
K(3)=d1+(d2*sin(tabC(2)))+(d3*sin(tabC(3)+tabC(2)));
K=K';
end

