#include "processing.h"
#include <glut.h>

void display() {
	glClearColor(0.0f, 0.7f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	gamefield.drawField();
	gamefield.swapGems();
	gamefield.CheckCombinations();
	gamefield.BlowUP();
	gamefield.BonusReColor();

	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(800/2, 800/2, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, gamefield.getW(), 0, gamefield.getH());
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27: // ESC key
		exit(0);
		break;
	}
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		int gx = int(float(x) / 800 * gamefield.getW());
		int gy = gamefield.getH() - int(float(y) / 800 * gamefield.getH());

		if (gx >= 0 && gx < gamefield.getW() && gy >= 0 && gy < gamefield.getH()) {
			if (gamefield.getCell(gx, gy)->is[SELECT]) {
				gamefield.getCell(gx, gy)->is[SELECT] = false;
			}
			else {
				gamefield.getCell(gx, gy)->is[SELECT] = true;
			}
		}
	}
}

void idle() {
	glutPostRedisplay();
	Sleep(200);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("GEMS");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutIdleFunc(idle);

	glutMainLoop();

	return 0;
}

