%wersja 1.1
%zmienionotyp manipulatora na 3R
%robot składa się z mniejszej liczby elementow
%zmieniono Table D-H
%dhparams - kolejnosc :(a, alfa, d, theta)
clc; clear;
q1=0;
q2=0;
q3=0;
q4=0;
d1=0.2500;
d2=0.2000;
d3=0.2000;
%           a       alfa    d       theta           i 
dhparams = [0   	pi/2	d1   	q1;             %1
            d2      0       0       q2;             %2
            d3  	0     	0       q3;   ];        %3
        
%deklaracja zmiennej 'robot'        
robot = rigidBodyTree('MaxNumBodies', 2, 'DataFormat','column');
%deklaracja 
body1 = rigidBody('body1');
body2 = rigidBody('body2');
body3 = rigidBody('body3');
%body4 = rigidBody('body4');
%deklaracja przegubów, ich rodzaju
jnt1 = rigidBodyJoint('jnt1','revolute');
jnt2 = rigidBodyJoint('jnt2','revolute');
jnt3 = rigidBodyJoint('jnt3','revolute');
%jnt4 = rigidBodyJoint('jnt4','revolute');

%ustawienie transformacji na "tryb" D-H
setFixedTransform(jnt1,dhparams(1,:),'dh');
setFixedTransform(jnt2,dhparams(2,:),'dh');
setFixedTransform(jnt3,dhparams(3,:),'dh');
%setFixedTransform(jnt4,dhparams(4,:),'dh');

body1.Joint = jnt1;
body2.Joint = jnt2;
body3.Joint = jnt3;
%body4.Joint = jnt4;

addBody(robot,body1,'base');
addBody(robot,body2,'body1');
addBody(robot,body3,'body2');
%addBody(robot,body4,'body3')

%próba implementacji kolizji
collisionObj = collisionCylinder(0.02,0.08);
for i = 1:robot.NumBodies
  
        addCollision(robot.Bodies{i},collisionObj);
end
%wyswietlenie modelu robota
showdetails(robot)
figure(1);
%show(robot);
show(robot, homeConfiguration(robot)); 
axis([-0.5,0.5,-0.5,0.5,-0.5,0.5])
axis on; %title('q1+pi/2')

%tablica konfiguracji przegubów robota
tabConfig=[0; pi/4; -pi/4];%konfiguracja w formie wektora, pozwala to uzywac pewnych funkcji
%ConfTmp=ConfigManip(randomConfiguration(robot), tabConfig);%ta funkjca
%dziala dla domyslnego typu koniguracji
showdetails(robot)

figure(2);
show(robot, tabConfig); 
axis([-0.5,0.5,-0.5,0.5,-0.5,0.5])
axis on; %title('q1')