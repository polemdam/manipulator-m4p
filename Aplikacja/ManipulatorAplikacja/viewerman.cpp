#include "viewerman.h"
#include <iostream>
#include <math.h>
#include <SOIL/SOIL.h>

using namespace std;




#define HEIGHT__CHECK_BOARD 64
#define WIDTH__CHECK_BOARD  64
static GLubyte Image_CheckBoard1[HEIGHT__CHECK_BOARD][WIDTH__CHECK_BOARD][4];
static GLubyte Image_CheckBoard2[HEIGHT__CHECK_BOARD][WIDTH__CHECK_BOARD][4];
static GLuint Texture4Bg;
static GLuint Texture4Manip1;
static GLuint Texture4Manip2;


void MakeImage_CheckBoard(GLubyte      Red,
                          GLubyte      Green,
                          GLubyte      Blue,
                          GLubyte      Image_CheckBoard[HEIGHT__CHECK_BOARD][WIDTH__CHECK_BOARD][4]
                         )
{
 int Idx_Height, Idx_Width, Intensity;

 for (Idx_Height = 0; Idx_Height < HEIGHT__CHECK_BOARD; Idx_Height++) {
   for (Idx_Width = 0; Idx_Width < WIDTH__CHECK_BOARD; Idx_Width++) {
     Intensity = (((Idx_Height & 0x8)==0)^((Idx_Width & 0x8)==0)) ? 1 : 0;
     Image_CheckBoard[Idx_Height][Idx_Width][0] = Intensity ? 255 : Red;
     Image_CheckBoard[Idx_Height][Idx_Width][1] = Intensity ? 255 : Green;
     Image_CheckBoard[Idx_Height][Idx_Width][2] = Intensity ? 255 : Blue;
     Image_CheckBoard[Idx_Height][Idx_Width][3] = static_cast<GLubyte>(255);
   }
 }
}

void GLCreateCylinder(float radius,  float halfLength){

    glPushMatrix();
    int slices=16;
    for(int i=0; i< slices; i++) {
    float theta = ((float)i)*2.0*M_PI;
    float nextTheta = ((float)i+1)*2.0*M_PI;
    glBegin(GL_TRIANGLE_STRIP);
    /*vertex at middle of end */ glVertex3f(0.0, halfLength, 0.0);
    /*vertices at edges of circle*/ glVertex3f(radius*cos(theta), halfLength, radius*sin(theta));
                                              glVertex3f (radius*cos(nextTheta), halfLength, radius*sin(nextTheta));
    /* the same vertices at the bottom of the cylinder*/
     glVertex3f (radius*cos(nextTheta), -halfLength, radius*sin(nextTheta));
    glVertex3f(radius*cos(theta), -halfLength, radius*sin(theta));
    glVertex3f(0.0, -halfLength, 0.0);
    glEnd();
    glPopMatrix();
    }
}


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

   glRotatef( 90, 0.0, 0.0, 1.0 );

   glTranslatef( 0.0, 0.0, 0.1);

   GLCreateBox(0.1,0.1, 0.2); //wal silnika dolnego

   glTranslatef( 0.0, 0.0, 0.1);

   GLCreateBox(0.5, 0.7, 0.1);

   glTranslatef( 0.0, 0.1, 0.2);
   glRotatef( 90, 1.0, 0.0, 0.0 );
   glColor3f(0.32,0.32,0.30);
   gluCylinder(silnik,0.1f,0.1f,0.5f,32,32);
   glRotatef( -90, 1.0, 0.0, 0.0 );
   glColor3f(0.29,0.72,0.64);
   glTranslatef( 0.0, -0.2, -0.1);


   glTranslatef( 0.0, -0.35, 0.45 );
   GLCreateBox(0.5, 0.1, 1.0);

   glTranslatef( 0.0, 0.35, 0.45);
   GLCreateBox(0.5, 0.7, 0.1);

   glTranslatef( 0.0, -0.1, 0.2);
   glRotatef( -90, 1.0, 0.0, 0.0 );
   glColor3f(0.32,0.32,0.30);
   gluCylinder(silnik,0.1f,0.1f,0.5f,32,32);
   glColor3f(0.29,0.72,0.64);
   glRotatef( 90, 1.0, 0.0, 0.0 );
   glTranslatef( 0.0, 0.2, -0.2);

   glTranslatef( 0.0, 0.35, 0.40);
   GLCreateBox(0.5, 0.1, 0.7);

   glTranslatef( 0.0, -0.32, 0.35);
   GLCreateBox(0.5, 0.75, 0.1);



   glFlush();

}


void ViewerMan::init()
{
  // Restore previous viewer state.
  restoreStateFromFile();

  glClearColor (0.90, 0.82, 0.79, 1.0);
  glDisable(GL_LIGHTING);

  glDisable(GL_LIGHT0);
  glClear(GL_COLOR_BUFFER_BIT);
   glShadeModel(GL_FLAT);
   glEnable(GL_DEPTH_TEST);

   MakeImage_CheckBoard(0,0,0,Image_CheckBoard1);
   MakeImage_CheckBoard(0,10,255,Image_CheckBoard2);

   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);


   /*------------
    *  Tworzenie pierwszej tekstury
    */
   glGenTextures(1, &Texture4Manip1);
   glBindTexture(GL_TEXTURE_2D, Texture4Manip1);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
           GL_LINEAR); //GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST); // GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WIDTH__CHECK_BOARD,
                HEIGHT__CHECK_BOARD, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                Image_CheckBoard1);

   /*------------
    *  Tworzenie drugiej tekstury
    */
   glGenTextures(1, &Texture4Manip2);
   glBindTexture(GL_TEXTURE_2D, Texture4Manip2);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
           GL_LINEAR); //GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST); // GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WIDTH__CHECK_BOARD,
                HEIGHT__CHECK_BOARD, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                Image_CheckBoard2);

   silnik=gluNewQuadric();

}





