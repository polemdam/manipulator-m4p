function [q] = CalculateInverseKinematics(Yd)
%funckja CalculateInverseKinematics
%   Funkcja realizuje odwrotne zadanie kinematyki dla manipulatora 3R;
%   Przyjmuje wektor położenia efektora w=(x, y, z)
%   Zwraca tablicę wartości kątów q

%wersja 1.0 konieczne jest dodanie asercji i określenie zakresu ruchu
%poszczególnych przegubów i ograniczenia związane z długościami przegubów
d1=0.50;
d2=0.25;
d3=0.25;

r2=Yd(1)^2+Yd(2)^2;
q1=atan2(Yd(2), Yd(1));
q3l=r2+(d1-Yd(3))^2-d2^2-d3^2;
q3m=2*d2*d3;
q3=acos(q3l/q3m);
if q3>0
    q3=-q3;
end
q2l=(d1-Yd(3))*(d2+d3*cos(q3))+sqrt(r2)*d3*sin(q3);
q2m=(d1-Yd(3))^2+r2;
q2=acos(q2l/q2m)


end

