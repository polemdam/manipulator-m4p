function [J] = returnJacobi(tabC, d1, d2, d3)
% fukncja returnJacobi
%   Zwraca macierz 3x3 tzw. jakobian analityczny
%
J(1,1)=-sin(tabC(1))*(d1*cos(tabC(2))+d3*cos(tabC(2)+tabC(3)));
J(1,2)=-cos(tabC(1))*(d1*sin(tabC(2))+d3*sin(tabC(2)+tabC(3)));
J(1,3)=-d3*cos(tabC(1))*sin(tabC(2)+tabC(3));
J(2,1)=cos(tabC(1)*(d2*cos(tabC(2))+d3*cos(tabC(2)+tabC(3))));
J(2,2)=-sin(tabC(1))*(d2*sin(tabC(2))+d3*sin(tabC(2)+tabC(3)));
J(2,3)=-d3*sin(tabC(1))*sin(tabC(2)+tabC(3));
J(3,1)=0;
J(3,2)=d2*cos(tabC(2))+d3*cos(tabC(2)+tabC(3));
J(3,3)=d3*cos(tabC(2)+tabC(3));
end

