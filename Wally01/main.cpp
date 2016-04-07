
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
//variables sphère - déplacement
double sphX = 0, sphY = 0, sphZ = 0;
long time = 0, startTime = 0;
bool go = false;//on enclenche le déplacement


long pAct = 0;//point actuel


typedef struct coord coord;
struct coord
{
	GLdouble *x;
	GLdouble *y;
	GLdouble *z;
};

void processSpecialKeys(int key, int x, int y);
void processNormalKeys(unsigned char key, int x, int y);//peut-être à changer. https://www.opengl.org/discussion_boards/showthread.php/183072-Cube-using-OpenGL-and-rotating-it-using-mouse-events
void mouseEvent(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void checkState(int state, int x, int y);
void Draw();
//void dessinerBouton();
void Reshape(int x, int y);
void animation();
bool fermer3D = false;
//variable clic souris
long ptProche = 0;


bool pause = true;


long pPause = 0;

bool init = false;
int CTRLpress = 0;

//méthode bizarre pour convertir un String^ en string 
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
	//on déclare la fenêtreMain

	//afficher la fenêtre, on demande à l'application de lancé la fenêtre 
	//le % permet de prendre une information , ici l'application prend la fenetreMain 
	//pour la lancer.



	
	//Wally01::Form1 form;


	/*cout << "Entrer le numéro du point dont vous souhaitez obtenir les informations: ";
	cin >> numeroPoint;
	cout << "Information accélération :  " << "Ax :  " << vPoints[numeroPoint].getAx() << " Ay: " << vPoints[numeroPoint].getAy() << " Az: " << vPoints[numeroPoint].getAz();*/

	//démarrage OpenGL
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	
	//creation fenêtre 1 
	int Window_1 = glutCreateWindow(argv[0]);
	glutSetWindowTitle("Projet Walibi");
	glutSetWindowTitle("Fenêtre 2");
	
	
	//creation fenêtre 2
	int window_2 = glutCreateWindow(argv[1]);




	
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

		//récupérer les champs rotation,translation et zoom du menu 
		vitesseRotation = Convert::ToDouble(fenetreMain.contenudomaineUpDown3) / 2000.0;
		vitesseTranslation = Convert::ToDouble(fenetreMain.contenudomaineUpDown4)/20.0;
		vitesseZoom = Convert::ToDouble(fenetreMain.contenudomaineUpDown5)/200;
		
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


	cout << "Entrer le numéro du point dont vous souhaitez obtenir les informations: ";
	cin >> numeroPoint;
	cout << "Information accélération :  " << "Ax :  " << vPoints[numeroPoint].getAx() << " Ay: " << vPoints[numeroPoint].getAy() << " Az: " << vPoints[numeroPoint].getAz();

}


void processNormalKeys(unsigned char key, int x, int y)
{
	double dx, dy, norme;

	if (key == 27)
	{
		Application::Restart();
		exit(0);
	}
	else if (key == 90 || key == 122)//z avant
	{
		dx = cibleX - camX;
		dy = cibleY - camY;
		norme = sqrt(pow(dx, 2) + pow(dy, 2));
		dx = dx / norme;
		dy = dy / norme;

		camX += dx*vitesseTranslation;
		camY += dy*vitesseTranslation;

		cibleX += dx*vitesseTranslation;
		cibleY += dy*vitesseTranslation;

	}
	else if (key == 83 || key == 115)//s arrière
	{
		dx = cibleX - camX;
		dy = cibleY - camY;
		norme = sqrt(pow(dx, 2) + pow(dy, 2));
		dx = dx / norme;
		dy = dy / norme;

		camX -= dx*vitesseTranslation;
		camY -= dy*vitesseTranslation;

		cibleX -= dx*vitesseTranslation;
		cibleY -= dy*vitesseTranslation;
	}
	else if (key == 81 || key == 113)//q gauche
	{
		dx = vitesseTranslation * cos(atan((cibleY - camY) / (cibleX - camX)) + PI / 2);
		dy = vitesseTranslation * sin(atan((cibleY - camY) / (cibleX - camX)) + PI / 2);

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
	else if (key == 79 || key == 111)//o afficher sphère
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
	else if (key == 17)
	{
		cout << "ctrl" << endl;
	}

	cout << camX << " " << camY << " " << camZ << " " << cibleX << " " << cibleY << " " << cibleZ << endl;
	cout << key << endl;

	if (GLUT_ACTIVE_CTRL)
		cout << "ok" << endl;
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
	case GLUT_KEY_UP://haut
	{
		autoriserAnim = true;
		camZ += vitesseTranslation;
		cibleZ += vitesseTranslation;
		break;
	}

	case GLUT_KEY_DOWN://bas
	{
		autoriserAnim = true;
		camZ -= vitesseTranslation;
		cibleZ -= vitesseTranslation;
		break;
	}

	}

	//touche control activée = CTRLpress
	int mod_key = glutGetModifiers();
	if (mod_key != 0)
	{
		if (mod_key == GLUT_ACTIVE_CTRL)
		{
			CTRLpress = 1;
		}
	}
	else if (CTRLpress)
	{
		CTRLpress = 0;
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
	double matModelView[16], matProjection[16];
	int viewPort[4];
	int mouseX = 0, mouseY = 0;
	coord m_start = { 0,0,0 }, m_end = { 0,0,0 };
	double winX, winY;
	GLdouble windX, windY, windZ;
	GLdouble startX = 0, startY = 0, startZ = 0;//début vecteur
	GLdouble endX = 0, endY = 0, endZ = 0;//fin vecteur
	double xv = 0, yv = 0, zv = 0;//vecteur direction
	double xc = 0, yc = 0, zc = 0;//point de parcours
	double xd = 0, yd = 0, zd = 0;//projection du point sur la droite
	double k = 0;
	double dist = 0;
	double distOpt = 0;

	mouseButton = button;
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			if (CTRLpress)
			{
				// get matrix and viewport:
				glGetDoublev(GL_MODELVIEW_MATRIX, matModelView);
				glGetDoublev(GL_PROJECTION_MATRIX, matProjection);
				glGetIntegerv(GL_VIEWPORT, viewPort);

				//window pos of mouse, Y is inverted on Windows
				winX = x;
				winY = viewPort[3] - y;

				// get point on the 'near' plane (third param is set to 0.0)
				//gluUnProject(winX, winY, 0.0, matModelView, matProjection, viewPort, &startX, &startY, &startZ);

				// get point on the 'far' plane (third param is set to 1.0)
				//gluUnProject(winX, winY, 1.0, matModelView, matProjection, viewPort, &endX, &endY, &endZ);

				// now you can create a ray from m_start to m_end

				//cout << winX << ", " << winY << "; " << startX << ", " << startY << ", " << startZ << "; " << endX << ", " << endY << ", " << endZ << ", " << endl;

				//distOpt = sqrt(pow(xd - vPoints[0].getX(), 2) + pow(yd - vPoints[0].getY(), 2) + pow(zd - vPoints[0].getZ(), 2));

				gluProject(vPoints[0].getX(), vPoints[0].getY(), vPoints[0].getZ(), matModelView, matProjection, viewPort, &windX, &windY, &windZ);
				windY = glutGet(GLUT_WINDOW_HEIGHT) - windY;
				distOpt = sqrt(pow(windX - x, 2) + pow(windY - y, 2));
				ptProche = 0;

				for (int i = 1; i < vPoints.size(); i++)
				{
					gluProject(vPoints[i].getX(), vPoints[i].getY(), vPoints[i].getZ(), matModelView, matProjection, viewPort, &windX, &windY, &windZ);
					windY = glutGet(GLUT_WINDOW_HEIGHT) - windY;
					dist = sqrt(pow(windX - x, 2) + pow(windY - y, 2));
					if (dist < distOpt)
					{
						distOpt = dist;
						ptProche = i;
					}
				}

				//cout << "mouse x, y: " << x << " " << y << "; point 0: " << windX << ", " << windY << ", " << windZ << endl;
				//cout << "point optimal: " << ptProche << endl;			
			}
		}
		else if (state == GLUT_UP)
		{
			init = false;
		}
		autoriserAnim = true;

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
	case 3: //zoom in !!!! Attention ça pourrait changer
		camX -= vitesseZoom*(camX - cibleX);
		camY -= vitesseZoom*(camY - cibleY);
		camZ -= vitesseZoom*(camZ - cibleZ);
		checkState(state, x, y);
		autoriserAnim = true;
		break;
	case 4: //zoom out !!! Attention ça pourrait changer
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
	double r = 0;//distance caméra-cible
	double v = 0;
	double u = 0;

	double uu = 0, vv = 0, xx = 0, yy = 0, zz = 0;

	int invertZ = 1;

	if (mouseButton == GLUT_LEFT_BUTTON)
	{
		if (!init)
		{
			oldX = x;
			oldY = y;
			init = true;
		}
		else
		{
			r = sqrt(pow(camX - cibleX, 2) + pow(camY - cibleY, 2) + pow(camZ - cibleZ, 2));
			v = acos((camZ - cibleZ) / r);

			if (sin(v) == 0)
			{
				cout << "sin(v) = 0" << endl;
			}
			else
			{
				if (camY >= cibleY)
				{
					u = acos((camX - cibleX) / (r*sin(v)));
				}
				else
				{
					u = -acos((camX - cibleX) / (r*sin(v)));
				}

				uu = u - vitesseRotation * (x - oldX);
				vv = v - vitesseRotation * (y - oldY);

				xx = r*cos(uu)*sin(vv);
				yy = r*sin(uu)*sin(vv);
				zz = r*cos(vv);

				camX = cibleX + xx;
				camY = cibleY + yy;
				camZ = cibleZ + zz;

				//cout << u << ", " << uu << endl ;

				//cout << r << ", " << v << ", " << u << "; " << vv << ", " << uu << "; " << xx << ", " << yy << ", " << zz << "; " << camX << ", " << camY << ", " << camZ << endl;

				oldX = x;
				oldY = y;
			}

		}
	}

	autoriserAnim = true;
}




void Draw()
{

	double tailleSphere = 1;

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

	//affichage repère 3D
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

	//sphère
	if (go)
	{
		glTranslatef(sphX, sphY, sphZ);
		glColor3d(255, 0, 0);
		glutSolidSphere(tailleSphere, tailleSphere * 20, tailleSphere * 20);
		glTranslatef(-sphX, -sphY, -sphZ);

	}

	//déplacement
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

	//point clic

	glTranslatef(vPoints[ptProche].getX(), vPoints[ptProche].getY(), vPoints[ptProche].getZ());
	glColor3d(0, 255, 0);
	glutSolidSphere(tailleSphere, tailleSphere * 20, tailleSphere * 20);
	glTranslatef(-vPoints[ptProche].getX(), -vPoints[ptProche].getY(), -vPoints[ptProche].getZ());


	glutSwapBuffers();
}

void Reshape(int x, int y)
{
	fenetreX = GLUT_SCREEN_WIDTH;
	 fenetreY = GLUT_SCREEN_HEIGHT;
	//Peut prendre 3 paramètres ==> GL_PROJECTION,GL_TEXTURE,GL_MODELVIEW ou même GL_COLOR
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//angle de vue: 70, 
	gluPerspective(70.0, (GLdouble)x / (GLdouble)y, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);  //Use the whole window for rendering
	//cout << "Width" << fenetreX;
}


void animation()
{
	if (autoriserAnim == true)
	{
		autoriserAnim = false;
	}
	Draw();
}

