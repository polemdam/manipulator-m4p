#include "viewerman.h"
#include <iostream>
#include <math.h>
#include <SOIL/SOIL.h>

using namespace std;










void GLCreateBox( double Size_X,  double Size_Y,  double Size_Z )
{
 glPushMatrix();
 glScalef( Size_X, Size_Y, Size_Z );

  glBegin(GL_POLYGON);
   glTexCoord2f(0.0, 0.0); glVertex3f(  0.5, -0.5, 0.5 );
   glTexCoord2f(0.0, 1.0); glVertex3f(  0.5,  0.5, 0.5 );
   glTexCoord2f(1.0, 1.0); glVertex3f( -0.5,  0.5, 0.5 );
   glTexCoord2f(1.0, 0.0); glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();

  glBegin(GL_POLYGON);
   glTexCoord2f(0.0, 0.0); glVertex3f( 0.5, -0.5, -0.5 );
   glTexCoord2f(0.0, 1.0); glVertex3f( 0.5,  0.5, -0.5 );
   glTexCoord2f(1.0, 1.0); glVertex3f( 0.5,  0.5,  0.5 );
   glTexCoord2f(1.0, 0.0); glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();

  glBegin(GL_POLYGON);
   glTexCoord2f(0.0, 0.0); glVertex3f( -0.5, -0.5,  0.5 );
   glTexCoord2f(0.0, 1.0); glVertex3f( -0.5,  0.5,  0.5 );
   glTexCoord2f(1.0, 1.0); glVertex3f( -0.5,  0.5, -0.5 );
   glTexCoord2f(1.0, 0.0); glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glBegin(GL_POLYGON);
   glTexCoord2f(0.0, 0.0); glVertex3f(  0.5,  0.5,  0.5 );
   glTexCoord2f(0.0, 1.0); glVertex3f(  0.5,  0.5, -0.5 );
   glTexCoord2f(1.0, 1.0); glVertex3f( -0.5,  0.5, -0.5 );
   glTexCoord2f(1.0, 0.0); glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();

  glBegin(GL_POLYGON);
   glTexCoord2f(0.0, 0.0); glVertex3f(  0.5, -0.5, -0.5 );
   glTexCoord2f(0.0, 1.0); glVertex3f(  0.5, -0.5,  0.5 );
   glTexCoord2f(1.0, 1.0); glVertex3f( -0.5, -0.5,  0.5 );
   glTexCoord2f(1.0, 0.0); glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
  glPopMatrix();
}



ViewerMan::~ViewerMan()
{
    gluDeleteQuadric(silnik);
}

void ViewerMan::draw()
{

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f(0.2,0.1,0.60);

   glTranslatef( 0.0, 0.0, -0.5);
   drawAxis();

   glColor3f(0.29,0.72,0.64);
   // Tworzenie podstawy
   glTranslatef( 0.0, 0.25, 0.12);
   glScalef(0.5, 0.5, 0.5);
   glRotatef( 0, 0.0, 0.0, 0.0 );


   GLCreateBox(0.5,0.1,0.75); //Pierwszy bok
   glTranslatef( 0.0, -0.5, 0.0);
   glColor3f(0.32,0.32,0.30);
   gluCylinder(silnik,0.1f,0.1f,0.4f,32,32);
   glColor3f(0.292,0.723,0.642);
   glTranslatef( 0.0, -0.5, 0.0);


   GLCreateBox(0.5,0.1,0.75);  //Drugi bok
   glTranslatef( 0.0, 0.5, 0.4);
   GLCreateBox(0.5,1.1, 0.1);   //Góra

   glRotatef( -Angles[0], 0.0, 0.0, 1.0 );
   glColor3f(0.43,0.29,0.29);
   glTranslatef( 0.0, 0.0, 0.1);

   GLCreateBox(0.1,0.1, 0.2); //wal silnika dolnego

   glTranslatef( 0.0, 0.0, 0.1);

   GLCreateBox(0.5, 0.7, 0.1);

   glTranslatef( 0.0, 0.1, 0.2);
   glRotatef( 90, 1.0, 0.0, 0.0 );
   glColor3f(0.32,0.32,0.30);
   gluCylinder(silnik,0.1f,0.1f,0.5f,32,32);
   glRotatef( -90, 1.0, 0.0, 0.0 );
   glColor3f(0.43,0.29,0.29);
   glTranslatef( 0.0, -0.2, -0.1);
   glRotatef( 90, 0.0, 1.0, 0.0 );
   glRotatef( -Angles[1], 0.0, 1.0, 0.0 );


   glTranslatef( -0.1, -0.35, 0.45 );
   GLCreateBox(0.5, 0.1, 1.6);

   glTranslatef( 0.0, 0.35, 0.75);
   GLCreateBox(0.5, 0.7, 0.1);

   glTranslatef( 0.0, -0.1, 0.2);
   glRotatef( -90, 1.0, 0.0, 0.0 );
   glColor3f(0.32,0.32,0.30);
   gluCylinder(silnik,0.1f,0.1f,0.5f,32,32);
   glColor3f(0.0,0.0,1.0);
   glRotatef( 90, 1.0, 0.0, 0.0 );
   glRotatef( -Angles[2], 0.0, 1.0, 0.0 );
   glTranslatef( 0.0, 0.2, -0.2);
   glRotatef( 90, 0.0, 1.0, 0.0 );


   glColor3f(1.0,0.0,0.0);
   glTranslatef( -0.3, 0.35, 0.40);

   GLCreateBox(0.5, 0.1, 1.3);

   glTranslatef( 0.0, -0.32, 0.65);
   GLCreateBox(0.5, 0.75, 0.1);



   glFlush();

}


void ViewerMan::init()
{
  Angles[0]=0;
  Angles[1]=0;
  Angles[2]=0;
  // Restore previous viewer state.
  restoreStateFromFile();

  glClearColor (0.90, 0.82, 0.79, 1.0);
  glDisable(GL_LIGHTING);
  glDisable(GL_LIGHT0);
  glClear(GL_COLOR_BUFFER_BIT);
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);



  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);


   /*------------
    *  Tworzenie pierwszej tekstury
    */



   silnik=gluNewQuadric();

}

void ViewerMan::newAngles(Data newData)
{
    Angles[0]= newData.Angle1;
    Angles[1]= newData.Angle2;
    Angles[2]= newData.Angle3;
    update();
}








