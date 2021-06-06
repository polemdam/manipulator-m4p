%dhparams - kolejnosc :(a, alfa, d, theta)
clc; clear;
q1=pi/4;
q2=0;
q3=0;
q4=0;
d1=0.3500;
d2=0.4000;
d3=0.2000;
%           a       alfa    d       theta           i 
dhparams = [0   	pi/2	d1   	q1;            %1
            d2      0       0       q2;            %2
            0   	pi/2	0       q3+pi/2;       %3
            0   	0   	d3      q4              ];
robot = rigidBodyTree;
body1 = rigidBody('body1');

jnt1 = rigidBodyJoint('jnt1','revolute');

setFixedTransform(jnt1,dhparams(1,:),'dh');
body1.Joint = jnt1;

addBody(robot,body1,'base')
body2 = rigidBody('body2');
jnt2 = rigidBodyJoint('jnt2','revolute');
body3 = rigidBody('body3');
jnt3 = rigidBodyJoint('jnt3','revolute');
body4 = rigidBody('body4');
jnt4 = rigidBodyJoint('jnt4','revolute');

setFixedTransform(jnt2,dhparams(2,:),'dh');
setFixedTransform(jnt3,dhparams(3,:),'dh');
setFixedTransform(jnt4,dhparams(4,:),'dh');

body2.Joint = jnt2;
body3.Joint = jnt3;
body4.Joint = jnt4;

addBody(robot,body2,'body1')
addBody(robot,body3,'body2')
addBody(robot,body4,'body3')

collisionObj = collisionCylinder(0.01,0.08);

for i = 1:robot.NumBodies
  
        addCollision(robot.Bodies{i},collisionObj)
    
end

showdetails(robot)

%show(robot);
show(robot); 
axis([-0.5,0.5,-0.5,0.5,-0.5,0.5])
axis on