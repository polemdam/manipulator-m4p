syms q1(t) q2(t) q3(t) l1 l2 l3 m1 m2 m3 g1 g2 g3
g=[0 0 g3 0];
D=[g1; 2; 3];
Rotpi2=[1 0 0 0;
        0 0 -1 0;
        0 1 0 0;
        0 0 0 1];
A01=RotZ(q1)*TrZ(l1)*Rotpi2;
A12=RotZ(q2)*TrX(l2);
A02=A01*A12;
A23=RotZ(q3)*TrX(l3);
A03=A02*A23;
A03=simplify(A03);
q1p=diff(q1, t);
q2p=diff(q2, t);
q3p=diff(q3, t);
M(1,1)=trace(diff(A01, q1)*Ijk(l1,m1)*transpose(diff(A01, q1)))+trace(diff(A02, q1)*Ijk(l2,m2)*transpose(diff(A02, q1)))+trace(diff(A03, q1)*Ijk(l3,m3)*transpose(diff(A03, q1)));
M(1,2)=trace(diff(A01, q1)*Ijk(l1,m1)*transpose(diff(A01, q2)))+trace(diff(A02, q1)*Ijk(l2,m2)*transpose(diff(A02, q2)))+trace(diff(A03, q1)*Ijk(l3,m3)*transpose(diff(A03, q2)));
M(1,3)=trace(diff(A01, q1)*Ijk(l1,m1)*transpose(diff(A01, q3)))+trace(diff(A02, q1)*Ijk(l2,m2)*transpose(diff(A02, q3)))+trace(diff(A03, q1)*Ijk(l3,m3)*transpose(diff(A03, q3)));
M(2,1)=trace(diff(A01, q2)*Ijk(l1,m1)*transpose(diff(A01, q1)))+trace(diff(A02, q2)*Ijk(l2,m2)*transpose(diff(A02, q1)))+trace(diff(A03, q2)*Ijk(l3,m3)*transpose(diff(A03, q1)));
M(2,2)=trace(diff(A01, q2)*Ijk(l1,m1)*transpose(diff(A01, q2)))+trace(diff(A02, q2)*Ijk(l2,m2)*transpose(diff(A02, q2)))+trace(diff(A03, q2)*Ijk(l3,m3)*transpose(diff(A03, q2)));
M(2,3)=trace(diff(A01, q2)*Ijk(l1,m1)*transpose(diff(A01, q3)))+trace(diff(A02, q2)*Ijk(l2,m2)*transpose(diff(A02, q3)))+trace(diff(A03, q2)*Ijk(l3,m3)*transpose(diff(A03, q3)));
M(3,1)=trace(diff(A01, q3)*Ijk(l1,m1)*transpose(diff(A01, q1)))+trace(diff(A02, q3)*Ijk(l2,m2)*transpose(diff(A02, q1)))+trace(diff(A03, q3)*Ijk(l3,m3)*transpose(diff(A03, q1)));
M(3,2)=trace(diff(A01, q3)*Ijk(l1,m1)*transpose(diff(A01, q2)))+trace(diff(A02, q3)*Ijk(l2,m2)*transpose(diff(A02, q2)))+trace(diff(A03, q3)*Ijk(l3,m3)*transpose(diff(A03, q2)));
M(3,3)=trace(diff(A01, q3)*Ijk(l1,m1)*transpose(diff(A01, q3)))+trace(diff(A02, q3)*Ijk(l2,m2)*transpose(diff(A02, q3)))+trace(diff(A03, q3)*Ijk(l3,m3)*transpose(diff(A03, q3)));
M=simplify(M);
                %k=1                                                              k=2                                                                     k=3
C(1,1)=       (((diff(M(1, 1), q1)+diff(M(1,1),q1)-diff(M(1,1),q1))/2)*diff(q1,t));%k=1
C(1,1)=C(1,1)+(((diff(M(1, 1), q2)+diff(M(1,2),q1)-diff(M(1,2),q1))/2)*diff(q2,t));%K=2
C(1,1)=C(1,1)+(((diff(M(1, 1), q3)+diff(M(1,3),q1)-diff(M(1,3),q1))/2)*diff(q3,t));%k=3

C(1,2)=       (((diff(M(1, 2), q1)+diff(M(1,1),q2)-diff(M(2,1),q1))/2)*diff(q1,t));%k=1
C(1,2)=C(1,2)+(((diff(M(1, 2), q1)+diff(M(1,2),q2)-diff(M(2,2),q1))/2)*diff(q2,t));%K=2
C(1,2)=C(1,2)+(((diff(M(1, 2), q3)+diff(M(1,3),q2)-diff(M(2,3),q1))/2)*diff(q3,t));%k=3

C(1,3)=       (((diff(M(1, 3), q1)+diff(M(1,1),q3)-diff(M(3,1),q1))/2)*diff(q1,t));%k=1
C(1,3)=C(1,3)+(((diff(M(1, 3), q2)+diff(M(1,2),q3)-diff(M(3,2),q1))/2)*diff(q2,t));%K=2
C(1,3)=C(1,3)+(((diff(M(1, 3), q3)+diff(M(1,3),q3)-diff(M(3,3),q1))/2)*diff(q3,t));%k=3

C(2,1)=       (((diff(M(2, 1), q1)+diff(M(2,1),q1)-diff(M(1,1),q2))/2)*diff(q1,t));%k=1
C(2,1)=C(2,1)+(((diff(M(2, 1), q2)+diff(M(2,2),q1)-diff(M(1,2),q2))/2)*diff(q2,t));%K=2
C(2,1)=C(2,1)+(((diff(M(2, 1), q3)+diff(M(2,3),q1)-diff(M(1,3),q2))/2)*diff(q3,t));%k=3

C(2,2)=       (((diff(M(2, 2), q1)+diff(M(2,1),q2)-diff(M(2,1),q2))/2)*diff(q1,t));%k=1
C(2,2)=C(2,2)+(((diff(M(2, 2), q2)+diff(M(2,2),q2)-diff(M(2,2),q2))/2)*diff(q2,t));%K=2
C(2,2)=C(2,2)+(((diff(M(2, 2), q3)+diff(M(2,3),q2)-diff(M(2,3),q2))/2)*diff(q3,t));%k=3

C(2,3)=       (((diff(M(2, 3), q1)+diff(M(2,1),q3)-diff(M(3,1),q2))/2)*diff(q1,t));%k=1
C(2,3)=C(2,3)+(((diff(M(2, 3), q2)+diff(M(2,2),q3)-diff(M(3,2),q2))/2)*diff(q2,t));%K=2
C(2,3)=C(2,3)+(((diff(M(2, 3), q3)+diff(M(2,3),q3)-diff(M(3,3),q2))/2)*diff(q3,t));%k=3


C(3,1)=       (((diff(M(3, 1), q1)+diff(M(3,1),q1)-diff(M(1,1),q3))/2)*diff(q1,t));%k=1
C(3,1)=C(3,1)+(((diff(M(3, 1), q2)+diff(M(3,2),q1)-diff(M(1,2),q3))/2)*diff(q2,t));%K=2
C(3,1)=C(3,1)+(((diff(M(3, 1), q3)+diff(M(3,3),q1)-diff(M(1,3),q3))/2)*diff(q3,t));%k=3

C(3,2)=       (((diff(M(3, 2), q1)+diff(M(3,1),q2)-diff(M(2,1),q3))/2)*diff(q1,t));%k=1
C(3,2)=C(3,2)+(((diff(M(3, 2), q2)+diff(M(3,2),q2)-diff(M(2,2),q3))/2)*diff(q2,t));%K=2
C(3,2)=C(3,2)+(((diff(M(3, 2), q3)+diff(M(3,3),q2)-diff(M(2,3),q3))/2)*diff(q3,t));%k=3

C(3,3)=       (((diff(M(3, 3), q1)+diff(M(3,1),q3)-diff(M(3,1),q3))/2)*diff(q1,t));%k=1
C(3,3)=C(3,3)+(((diff(M(3, 3), q2)+diff(M(3,2),q3)-diff(M(3,2),q3))/2)*diff(q2,t));%K=2
C(3,3)=C(3,3)+(((diff(M(3, 3), q3)+diff(M(3,3),q3)-diff(M(3,3),q3))/2)*diff(q3,t));%k=3
C=simplify(C)

V=m1*g*A01*[0; 0; l1/2; 1];
V=V+m2*g*A02*[0; 0; l1-2*cos(q2)*l2; 1];
V=-1*(V + m3*g*A03*[0;0 ; l1 + l2*sin(q2(t)) + l3*sin(q2(t)+ q3(t))/2 ; 1]);

D(1)=diff(V,q1);
D(2)=diff(V,q2);
D(3)=diff(V,q3);

D=simplify(D)

