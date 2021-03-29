function [outputArg1] = ConfigManip(StructRobot, TabAng)
%ConfigManip Struct {JointName, JointPosition}, Tab[4]
%  Funcja zwraca configurację robota na podstawie parametrów z TabAng
%  gdzie kolejne elementy tablicy to wartości kątów dla kolejnych przegubów
%  obrotowych
%  Konieczne jest aby klasa robot miała domyślny tryb 'DataFormat'
for i=1:1:length(TabAng)
    StructRobot(i).JointPosition=TabAng(i);
end

outputArg1 = StructRobot;
end

