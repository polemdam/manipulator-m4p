function [Tform] = returnTform(tabC, d1, d2, d3)
%funkcja returnTform
%   zwraca macierz transformacji 4x4 dla efektora w manipulatorze 3R
% przyjmuje wartości katow i dlugosci przegubow
Tform(1,1)=cos(tabC(1))*cos(tabC(3)+tabC(2));
Tform(1,2)=-cos(tabC(1))*sin(tabC(3)+tabC(2));
Tform(1,3)=sin(tabC(1));
Tform(1,4)=(cos(tabC(1))*cos(tabC(2))*d2)+(d3*cos(tabC(1))*cos(tabC(2)+tabC(3)));%x
Tform(2,1)=sin(tabC(1))*(cos(tabC(3)+tabC(2)));
Tform(2,2)=-sin(tabC(1))*sin(tabC(3)+tabC(2));
Tform(2,3)=-cos(tabC(1));
Tform(2,4)=(sin(tabC(1))*cos(tabC(2))*d2)+(d3*sin(tabC(1))*cos(tabC(2)+tabC(3)));%Y
Tform(3,1)=sin(tabC(3)+tabC(2));
Tform(3,2)=cos(tabC(3)+tabC(2));
Tform(3,3)=0; %lub6.1232e-17
Tform(3,4)=d1+(d2*sin(tabC(2)))+(d3*sin(tabC(3)+tabC(2)));%z
Tform(4,1)=0;
Tform(4,2)=0;
Tform(4,3)=0;
Tform(4,4)=1;
end

