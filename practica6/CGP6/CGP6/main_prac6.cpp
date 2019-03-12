//Semestre 2019 - 2
/*Serrano Martinez Max Yael
  grupo 02
  visual studio 2017
  Practica 6
  
  
  
  
  
  
  */
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int mercurio = 0;
int mercuriot = 0;
int venus = 0;
int venust = 0;
int tierra = 0;
int tierrat = 0;
int luna1 = 0;
int luna1t = 0;
//
int marte = 0;
int martet = 0;
int luna2 = 0;
int luna2t = 0;
//
int jupiter = 0;
int jupitert = 0;
int luna3 = 0;
int luna3t = 0;
int luna4 = 0;
int luna4t = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
    
   glPushMatrix();//sistemas solar

     glPushMatrix();//sol
	   glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
	   glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
	   glutSolidSphere(1.9,12,12);  //Draw Sun (radio,H,V);//evitarnos el prisma
    glPopMatrix();//sol

	glPushMatrix();//mercurio
	   glRotatef(mercuriot, 0, 1, 0);//traslacion
	   glTranslatef(3, 0, 0);  
	   glColor3f(1, 0.458, 0.078);
	   glRotatef(mercurio, 0, 1, 0);//rotacion
	   glutSolidSphere(0.1, 12, 12);
	glPopMatrix();

	glPushMatrix();//venus
	   glRotatef(venust, 0, 1, 0);//traslacion
	   glTranslatef(4, 0, 0);  
	   glColor3f(0.9, 0.8, 0.4);
	   glRotatef(venus, 0, 1, 0);//rotacion
	   glutSolidSphere(0.3, 12, 12);
    glPopMatrix();//venus
	/////////////////////////////////////////////////////////
	glPushMatrix();//tierra

	
	    glPushMatrix();//tierra
			glRotatef(tierrat, 0, 1, 0);//traslacion
			 glTranslatef(5.5, 0, 0);
			glColor3f(0, 0, 1);
			glRotatef(tierra, 0, 1, 0);//rotacion
			glutSolidSphere(0.4, 12, 12);
		glPopMatrix();

	  glPushMatrix();//lunat
	      glRotatef(luna1t, 0, 1, 0);//traslacion
	      glTranslatef(6.2, 0, 0);
	      glColor3f(1, 1, 1);
	      glRotatef(luna1, 0, 1, 0);//rotacion
	      glutSolidSphere(0.05, 12, 12);

	    glPopMatrix();//luna1
		
    glPopMatrix();//tierra
////////////////////////////////////////////////////////////////////////////
	glPushMatrix();//marte


		glPushMatrix();//marte
			glRotatef(martet, 0, 1, 0);//traslacion
			glTranslatef(7.5, 0, 0);
			glColor3f(1, 0, 0);
			glRotatef(marte, 0, 1, 0);//rotacion
			glutSolidSphere(0.4, 12, 12);
		glPopMatrix();

		glPushMatrix();//luna2
			glRotatef(luna2t, 0, 1, 0);//traslacion
			glTranslatef(8.2, 0, 0);
			glColor3f(1, 1, 1);
			glRotatef(luna2, 0, 1, 0);//rotacion
			glutSolidSphere(0.05, 12, 12);
		glPopMatrix();//luna2

	glPopMatrix();//tierra
//////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
	glPushMatrix();//JUpiter


		glPushMatrix();//jupiter
			glRotatef(jupitert, 0, 1, 0);//traslacion
			glTranslatef(9.5, 0, 0);
			glColor3f(0.12, 0.5, 0.8);
			glRotatef(jupiter, 0, 1, 0);//rotacion
			glutSolidSphere(0.8, 12, 12);
		glPopMatrix();

		glPushMatrix();//luna3
			glRotatef(luna3t, 0, 1, 0);//traslacion
			glTranslatef(10.6, 0, 0);
			glColor3f(1, 1, 1);
			glRotatef(luna3, 0, 1, 0);//rotacion
			glutSolidSphere(0.05, 12, 12);
		glPopMatrix();//luna3

		glPushMatrix();//luna4
			glRotatef(luna4t, 0, 1, 0);//traslacion
			glTranslatef(10.6, .5, 0);
			glColor3f(1, 1, 1);
			glRotatef(luna4, 0, 1, 0);//rotacion
			glutSolidSphere(0.05, 12, 12);
		glPopMatrix();//luna4

	glPopMatrix();//jupiter
//////////////////////////////////////////////////////////////////////////////
	glPushMatrix();//Saturno


		glPushMatrix();//saturno
			glRotatef(jupitert, 0, 1, 0);//traslacion
			glTranslatef(9, 0, 0);
			glColor3f(0.12, 0.5, 0.8);
			glRotatef(jupiter, 0, 1, 0);//rotacion
			glutSolidSphere(0.4, 12, 12);
		glPopMatrix();

		glPushMatrix();//anillo1
			glRotatef(luna3t, 0, 1, 0);//traslacion
			glTranslatef(9.8, 0, 0);
			glColor3f(1, 1, 1);
			glRotatef(luna3, 0, 1, 0);//rotacion
			glutSolidSphere(0.05, 12, 12);
		glPopMatrix();//anillo1

		glPushMatrix();//anillo2
			glRotatef(luna4t, 0, 1, 0);//traslacion
			glTranslatef(9.2, .5, 0);
			glColor3f(1, 1, 1);
			glRotatef(luna4, 0, 1, 0);//rotacion
			glutSolidSphere(0.05, 12, 12);
		glPopMatrix();//anillo2

	glPopMatrix();//Saturno
	////////////////////////
   glPopMatrix();//sitema solar
glutSwapBuffers();
}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;

		mercurio = (mercurio - 10) % 360;
		mercuriot = (mercuriot - 8) % 360;

		venus = (venus - 10) % 360;
		venust = (venust + 6) % 360;

		tierra = (tierra - 10) % 360;
		tierrat = (tierrat + 4) % 360;

		luna1 = (luna1 - 10) % 360;
		luna1t = (luna1t + 2) % 360;

		dwLastUpdateTime = dwCurrentTime; //reinicia un ciclo
	}

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}
//cuidado, carga  }¡¡¡