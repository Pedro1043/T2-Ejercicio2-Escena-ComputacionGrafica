#include <GL/glut.h>
#include <iostream>
//Ufas
float anguloGarra=0;

static int mover = 4;
static int mover1 = 2;
static int girar = 0;

static int angulop2 = 120;
static int angulop3 = 300;

static int pos_x = 0;
static int pos_y = 0;
static int pos_z = 0;

static int rot_x = 0;
static int rot_y = 0;

static int rot_hombro_izq = 0;
static int rot_hombro_der = 0;

static int pierna_izq = 0;
static int pierna_der = 0;

static bool flag_mpi = true;
static bool flag_mpd = true;

static int brazo_der = 0;
static int brazo_izq = 0;

static float mov_pier_izq = 0.5;
static float mov_pier_der = -0.5;

static float mano_izq = 0;
static float mano_der = 0;
static bool flag_mano_izq = true;
static bool flag_mano_der = true;


GLUquadricObj *p = gluNewQuadric();

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void inicializar()
{
    glClearColor(0.7,0.7,0.7,0.0);
    glEnable(GL_DEPTH_TEST);
    gluQuadricDrawStyle(p,GLU_LINE);
}

void graficarEjes()
{
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(50,0,0);

        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,50,0);

        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,50);
    glEnd();
}

void graficar()
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(25,25,25, 0,0,0, 0,1,0);

    gluQuadricDrawStyle(p,GLU_FILL);
    graficarEjes();
    glPushMatrix();
    //tronco (circulo central)
    glTranslatef(pos_x,pos_y+5,pos_z);
    glColor3ub(166,28,31);
    glutSolidSphere(3.5,32,32);
    glRotatef(rot_x,0,-1,0);
    glRotatef(rot_y,0,0,1);
        //hombro izq.
        glPushMatrix();
        glTranslatef(1,1.5,3.5);
        glRotatef(rot_hombro_der,0,0,1);
        glColor3ub(15,0,0);
        glutSolidCube(2);
        glPushMatrix();
            //antebrazo izq.
            glTranslatef(1,-0.5,0);
            glColor3ub(86,46,47);
            glRotatef(90,0.75,1,0);
            glRotatef(brazo_izq,1,1,0.75);
            gluCylinder(p, 1, 0.5, 3.5, 15, 15);
            glPushMatrix();
                //mano izq.
                glTranslatef(0,0,3);
                glColor3ub(58,21,80);
                glRotatef(mano_izq,0.1,0,1);
                glutSolidCone(1,2,5,1);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

        //hombro der.
        glPushMatrix();
        glTranslatef(1,1.5,-3.5);
        glRotatef(rot_hombro_izq,0,0,1);
        glColor3ub(15,0,0);
        glutSolidCube(2);
        glPushMatrix();
            //antebrazo der.
            glTranslatef(0.5,-0.5,0);
            glColor3ub(86,46,47);
            glRotatef(90,0.75,1,0);
            glRotatef(brazo_der,1,1,0.75);
            gluCylinder(p, 1, 0.5, 3.5, 15, 15);
            glPushMatrix();
                //mano izq.
                glTranslatef(0,0,3);
                glColor3ub(58,21,80);
                glRotatef(mano_der,0.1,0,1);
                glutSolidCone(1,2,5,1);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();


        //pierna izq.
        glPushMatrix();
        glTranslatef(1,-3,2);
        glRotatef(90,mov_pier_izq+0.75,-1,0);
        glColor3ub(233,58,237);
        gluCylinder(p, 1, 0.5, 3, 15, 15);
            //entrepierna izq.
            glPushMatrix();
            glTranslatef(0,0,2.5);
            glRotatef(90,0.25,0.25,0);
            glColor3ub(145,15,155);
            gluCylinder(p, 0.5, 1, 3, 15, 15);
                //pie izq.
                glPushMatrix();
                glTranslatef(0,0,3.5);
                glRotatef(90,-1,-1,5);
                glColor3ub(60,60,60);
                glutSolidCube(1.5);
                glTranslatef(0,-1.5,0);
                glutSolidCube(1.5);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

        //pierna der.
        glPushMatrix();
        glTranslatef(1,-3,-2);
        glColor3ub(233,58,237);
        glRotatef(90,mov_pier_der+0.75,-1,0);
        gluCylinder(p, 1, 0.5, 3, 15, 15);
            //entrepierna der.
            glPushMatrix();
            glTranslatef(0,0,2.5);
            glRotatef(90,0.25,0.25,0);
            glColor3ub(145,15,155);
            gluCylinder(p, 0.5, 1, 3, 15, 15);
                //pie der.
                glPushMatrix();
                glTranslatef(0,0,3.5);
                glRotatef(30,-1,-1,0);
                glColor3ub(60,60,60);
                glutSolidCube(1.5);
                glTranslatef(0,-1.5,0);
                glutSolidCube(1.5);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void redimensionar(int w, int h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(float)w/(float)h,1,100);

}

void rotarGarra(int i)
{
    if(flag_mano_izq)
        mano_izq += 3;
    if(flag_mano_der)
        mano_der -= 3;

    if(flag_mpi)
        mov_pier_izq+=0.02;
    else
        mov_pier_izq-=0.02;

    if(mov_pier_izq > 0.5)
        flag_mpi = false;
    if(mov_pier_izq < -0.5)
        flag_mpi = true;

    if(flag_mpd)
        mov_pier_der+=0.02;

    else
        mov_pier_der-=0.02;


    if(mov_pier_der > 0.5)
        flag_mpd = false;
    if(mov_pier_der < -0.5)
        flag_mpd = true;
    //std::cout<<mov_pier_izq<<std::endl;
    glutPostRedisplay();
    glutTimerFunc(30,rotarGarra,3);
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'x':
            std::cout<<"Hasta la proxima!"<<std::endl;
            exit(0);
            break;
        case 'a':
            pos_x--;
            break;
        case 'w':
            pos_y++;
            break;
        case 's':
            pos_y--;
            break;
        case 'd':
            pos_x++;
            break;
        case 'm':
            pos_z++;
            break;
        case 'n':
            pos_z--;
            break;
        case 'q':
            rot_x++;
            break;
        case 'e':
            rot_x--;
            break;
        case 'z':
            rot_y++;
            break;
        case 'c':
            rot_y--;
            break;
        case 'j':
            brazo_izq+=5;
            break;
        case 'k':
            brazo_der+=5;
            break;
        case 'o':
            flag_mano_der = !flag_mano_der;
            break;
        case 'u':
            rot_hombro_der++;
            break;
        case 'i':
            rot_hombro_izq++;
            break;
        case 'p':
            flag_mano_izq = !flag_mano_izq;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,400);
    glutInitWindowPosition(100,200);
    glutCreateWindow("*c duerme");
    inicializar();

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


    glutDisplayFunc(graficar);
    glutKeyboardFunc(key);
    glutReshapeFunc(redimensionar);

    rotarGarra(0);

    glutMainLoop();

    return 0;
}
