
#include "Form1.h"

#include <glew.h>
#include <glut.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "Point.h"
#include "fichiers.h"
#include "structure.h"
#include "cameraGL.h"


#define PI 3.1415926535

using namespace std;
using namespace System;
using namespace System::Windows::Forms;


vector<Point> vPoints;
bool autoriserAnim = false;
GLfloat xRotated, yRotated, zRotated;
double camX = 5.0, camY = 4.0, camZ = 3.0, cibleX = 0.0, cibleY = 0.0, cibleZ = 0.0;
double vitesseZoom = 0;                           //0.1;
double vitesseRotation = 0;                   //0.01
double vitesseTranslation = 0;                 //0.5
int fenetreX;
int fenetreY;
int mouseButton;
int oldX, newX, oldY, newY;
bool rotaetAxixX = false;
double rotateAngle = 0.0;
double depth;
int numeroPoint = 0;
int windowWidth = GLUT_WINDOW_X;
int windowHeight = GLUT_WINDOW_Y;
//variables sph�re - d�placement
double sphX = 0, sphY = 0, sphZ = 0;
long time = 0, startTime = 0;
bool go = false;//on enclenche le d�placement
bool pause = true;

long pAct = 0;//point actuel
long pPause = 0;

void processSpecialKeys(int key, int x, int y);
void processNormalKeys(unsigned char key, int x, int y);//peut-�tre � changer. https://www.opengl.org/discussion_boards/showthread.php/183072-Cube-using-OpenGL-and-rotating-it-using-mouse-events
void mouseEvent(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void checkState(int state, int x, int y);
void Draw();
//void dessinerBouton();
void Reshape(int x, int y);
void animation();
bool fermer3D = false;


//m�thode bizarre pour convertir un String^ en string 
void MarshalString(String ^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

  [STAThread]
int  main(int argc, char *argv[])
{
	Wally01::Form1 fenetreMain;
	cout << "start..." << endl;

	cout << camX << " " << camY << " " << camZ << " " << cibleX << " " << cibleY << " " << cibleZ << endl;
	

	


		string stdText1;
		
	//liste points du circuit
		
	
	

	//liste points du circuit
	//Application::EnableVisualStyles();
	//on d�clare la fen�treMain

	//afficher la fen�tre, on demande � l'application de lanc� la fen�tre 
	//le % permet de prendre une information , ici l'application prend la fenetreMain 
	//pour la lancer.



	
	//Wally01::Form1 form;


	/*cout << "Entrer le num�ro du point dont vous souhaitez obtenir les informations: ";
	cin >> numeroPoint;
	cout << "Information acc�l�ration :  " << "Ax :  " << vPoints[numeroPoint].getAx() << " Ay: " << vPoints[numeroPoint].getAy() << " Az: " << vPoints[numeroPoint].getAz();*/

	//d�marrage OpenGL
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	
	int WindowName = glutCreateWindow("Projet Walibi");
	
	cout << "Width" << fenetreX;
	

	//glutFullScreen();	//Optionnel

	
	
	glutHideWindow();
	Application::Run(%fenetreMain);

	if (fenetreMain.flag == 1)
	{
		cout << "ici";
		MarshalString(fenetreMain.path, stdText1);
		cout << "voici le fichier " << stdText1;
		loadData(vPoints, stdText1);
		for (double i = 0.0; i < 50.0; i += 0.01)
		{
			vPoints.push_back(Point(i, 0, 5.0 * cos(i)));
		}

		//r�cup�rer les champs rotation,translation et zoom du menu 
		vitesseRotation = Convert::ToDouble(fenetreMain.contenuTextbox3);
		vitesseTranslation = Convert::ToDouble(fenetreMain.contenuTextbox4);
		vitesseZoom = Convert::ToDouble(fenetreMain.contenuTextbox5);
					
		glutShowWindow();
		glutMouseFunc(mouseEvent);
		glutSpecialFunc(processSpecialKeys);
		glutKeyboardFunc(processNormalKeys);

		glutMotionFunc(mouseMotion);
		glutReshapeFunc(Reshape);
		glutDisplayFunc(Draw);
		//glutDisplayFunc(dessinerBouton);
		glutIdleFunc(animation);
		
	}
	glutMainLoop();
	

	

	


	//liste points du circuit


	cout << "Entrer le num�ro du point dont vous souhaitez obtenir les informations: ";
	cin >> numeroPoint;
	cout << "Information acc�l�ration :  " << "Ax :  " << vPoints[numeroPoint].getAx() << " Ay: " << vPoints[numeroPoint].getAy() << " Az: " << vPoints[numeroPoint].getAz();

}


void processNormalKeys(unsigned char key, int x, int y)
{
	double dx, dy;

	if (key == 27)
	{
		Application::Restart();
		exit(0);
	}
	else if (key == 90 || key == 122)//z haut
	{
		camZ += vitesseTranslation;
		cibleZ += vitesseTranslation;
	}
	else if (key == 83 || key == 115)//s bas
	{
		camZ -= vitesseTranslation;
		cibleZ -= vitesseTranslation;
	}
	else if (key == 81 || key == 113)//q gauche
	{
		dx = vitesseTranslation * cos(atan((cibleY - camY) / (cibleX - camX)) + PI / 2);
		dy = vitesseTranslation * sin(atan((cibleY - camY) / (cibleX - camX)) + PI / 2);

		//	cout << dx << " " << dy << endl;

		camX -= dx;
		cibleX -= dx;

		camY -= dy;
		cibleY -= dy;
	}
	else if (key == 68 || key == 100)//d droite
	{
		dx = vitesseTranslation * cos(atan((cibleY - camY) / (cibleX - camX)) + PI / 2);
		dy = vitesseTranslation * sin(atan((cibleY - camY) / (cibleX - camX)) + PI / 2);

		camX += dx;
		cibleX += dx;

		camY += dy;
		cibleY += dy;
	}
	else if (key == 79 || key == 111)//o afficher sph�re
	{
		if (go)
		{
			go = false;
		}
		else
		{
			go = true;
			pAct = 0;
			pPause = 0;
			sphX = vPoints.at(0).getX();
			sphY = vPoints.at(0).getY();
			sphZ = vPoints.at(0).getZ();
		}
	}
	else if (key == 80 || key == 112)//p pause
	{
		if (pause)
		{
			pause = false;
			startTime = time;
			pPause = pAct;
		}
		else
		{
			pause = true;
		}
	}

	//cout << camX << " " << camY << " " << camZ << " " << cibleX << " " << cibleY << " " << cibleZ << endl;

}

void dessinerBouton()
{
	

}
void rendreVisible()
{
	glutShowWindow();
}

void processSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
	{
		std::cout << "zoom in" << endl;
		autoriserAnim = true;
		camX -= vitesseZoom*(camX - cibleX);
		camY -= vitesseZoom*(camY - cibleY);
		camZ -= vitesseZoom*(camZ - cibleZ);
		//time = glutGet(GLUT_ELAPSED_TIME);
		//cout << time << endl;
		break;
	}

	case GLUT_KEY_DOWN:
	{
		std::cout << "zoom out" << endl;
		autoriserAnim = true;
		camX += vitesseZoom*(camX - cibleX);
		camY += vitesseZoom*(camY - cibleY);
		camZ += vitesseZoom*(camZ - cibleZ);
		break;
	}

	

	}
	//cout << camX << " " << camY << " " << camZ << " " << cibleX << " " << cibleY << " " << cibleZ << endl;
}

void checkState(int state, int x, int y)
{
	switch (state) {
	case GLUT_UP:
		//cout<<" UP"<<endl;
		break;
	case GLUT_DOWN:
		//cout<<" DOWN"<<endl;
		break;
	};
}

void mouseEvent(int button, int state, int x, int y)
{
	
	mouseButton = button;
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			oldX = x;
			oldY = y;
		}
		cout << "\nx";
		cout << x;
		cout << "\ny";
		cout << y;
		checkState(state, x, y);
		autoriserAnim = true;
		cout << "\nfeneteX";
		cout << fenetreX;
		cout << "\nFenetreY";
		cout << fenetreY;
		if (x == fenetreX - 1)
		{
			cout << "hello";
		}
		break;
	case GLUT_RIGHT_BUTTON:
		//cout<<"RIGHT";
		checkState(state, x, y);
		autoriserAnim = true;
		break;
	case GLUT_MIDDLE_BUTTON:
		//cout<<"MIDDLE";
		checkState(state, x, y);
		autoriserAnim = true;
		break;
	case 3: //zoom in !!!! Attention �a pourrait changer
		camX -= vitesseZoom*(camX - cibleX);
		camY -= vitesseZoom*(camY - cibleY);
		camZ -= vitesseZoom*(camZ - cibleZ);
		checkState(state, x, y);
		autoriserAnim = true;
		break;
	case 4: //zoom out !!! Attention �a pourrait changer
		camX += vitesseZoom*(camX - cibleX);
		camY += vitesseZoom*(camY - cibleY);
		camZ += vitesseZoom*(camZ - cibleZ);
		checkState(state, x, y);
		autoriserAnim = true;
		break;
	}
}

void mouseMotion(int x, int y)
{
	if (mouseButton == GLUT_LEFT_BUTTON)
	{
		//rajouter fonctions rotation autour d'un point
	}

	autoriserAnim = true;
}




void Draw()
{
	glMatrixMode(GL_MODELVIEW);

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	//translation selon z (temporaire)
	glTranslatef(0.0, 0.0, 0.0);

	//rotation selon les trois axes
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	glRotatef(zRotated, 0.0, 0.0, 1.0);

	/*if (rotaetAxixX == true)
	glRotatef(rotateAngle, 1.0, 0.0, 0.0);
	else
	glRotatef(rotateAngle, 0.0, 1.0, 0.0);*/

	glMatrixMode(GL_MODELVIEW);

	//(pos. cam), (pos. cible), (vect. vert.)
	gluLookAt(camX, camY, camZ, cibleX, cibleY, cibleZ, 0, 0, 1);

	//affichage rep�re 3D
	glBegin(GL_LINES);
	glColor3d(255, 0, 0);
	glVertex3i(0, 0, 0); glVertex3i(0, 1, 0);
	glColor3d(0, 255, 0);
	glVertex3i(0, 0, 0); glVertex3i(1, 0, 0);
	glColor3d(0, 0, 255);
	glVertex3i(0, 0, 0); glVertex3i(0, 0, 1);
	glColor3d(255, 255, 255);
	glEnd();

	//affichage grille XY
	repereXY(20);

	afficherParcours(vPoints);


	
	

	

	//sph�re
	if (go)
	{
		double tailleSphere = 1;
		glTranslatef(sphX, sphY, sphZ);
		glColor3d(255, 0, 0);
		glutSolidSphere(tailleSphere, tailleSphere * 20, tailleSphere * 20);
		glTranslatef(-sphX, -sphY, -sphZ);

	}

	//d�placement
	time = glutGet(GLUT_ELAPSED_TIME);

	if (!pause)
	{
		pAct = (time - startTime) / 100;
		pAct += pPause;

		if (pAct >= vPoints.size())
		{
			pause = true;
		}
		else
		{
			sphX = vPoints.at(pAct).getX();
			sphY = vPoints.at(pAct).getY();
			sphZ = vPoints.at(pAct).getZ();
		}

	}

	//cout << time << ", " << startTime << ", " << pAct << endl;

	glutSwapBuffers();
}

void Reshape(int x, int y)
{
	fenetreX = GLUT_SCREEN_WIDTH;
	 fenetreY = GLUT_SCREEN_HEIGHT;
	//Peut prendre 3 param�tres ==> GL_PROJECTION,GL_TEXTURE,GL_MODELVIEW ou m�me GL_COLOR
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//angle de vue: 70, 
	gluPerspective(70.0, (GLdouble)x / (GLdouble)y, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);  //Use the whole window for rendering
	cout << "Width" << fenetreX;
}


void animation()
{
	if (autoriserAnim == true)
	{
		autoriserAnim = false;
	}
	Draw();
}

void motion(vector<Point> vPoints, double t, Point point)
{

}