#include <GL/glut.h>
#include <iostream>
/*  Miembros:
Bryan Valencia Guzmán
Jorge Alonso Marin Martell
Sergio Andre Nomberto Salazar
Gandalf
Chavarria Mujica Pedro Antonio
*/
// Bryan
float angCuello=0;
float angCabeza=0;
float cola=0;
float ojos=0;
float sentar=0;
float sentarP=0;
float pDelIz=0;
// -------------------------
//INICIO (Reusche)
// Teclas para mover:
// a w s d q e
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
//FIN (Reusche)

//INICIO(Sergio)
float angTronco1 = 0;
float angTronco2 = 0;
float angcabeza = 0;
float angBrazo1 = 0;
float angBrazo2 = 0;
float angPuntaAntena = 0;
float caminarx = -13;
float caminary = 4;
float dab[] = {65,115,0,0,0,0,0,1,0.42,0.42,0.42};
bool brazo1bool = false;
bool brazo2bool = false;
bool caminarbool = false;

float ejeX=50;
float ejeY=50;
float ejeZ=50;
//FIN(Sergio)

//INICIO (Gandalf)

float angTronco = 0;

float escalarX = 1;
float escalarY = 1;
float escalarZ = 1;
float girar1 = 0;
float moverse = 0;

//VARIABLES PIERNAS
int estadoPiernas = 0;
float anguloPierna1 = 0;
float anguloRodilla1 = 0;
float anguloPierna2 = 0;
float anguloRodilla2 = 0;

//FIN (Gandalf)

//INICIO Variables - Pedro
//----------------------------------------------------------------
float movX = 0;
float movY = 0;
float movZ = 0;
float cabeza = 0;
float varRotar = 360;

///---------------------------------------------------------------
///PARTE IZQUIERDA


float conexionBi = 360;

float brazoIz = 360;

float brazoIz2 = 360;

///----------------------------------------------------------------
///PARTE DERECHA

float conexionBe = 360;

float brazoDe = 360;

float brazoDe2 = 360;


//FIN Variables - Pedro

//INICIO Vriables Jorge

float anguloGarra=0;

static int mover = -5;
static int mover1 = 17;
static int girar = 0;

static int angulop1 = 0;
static int angulop2 = 120;
static int angulop3 = 300;

//FIN Variables  Jorge

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
    glBegin(GL_QUADS);
        glColor3ub(128,64,0);
        glVertex3f(-10,-10,-10);
        glVertex3f(40,-10,-10);
        glVertex3f(40,-10,40);
        glVertex3f(-10,-10,40);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(254,210,129);
        glVertex3f(-10,-10,-10);
        glVertex3f(40,-10,-10);
        glVertex3f(40,40,-10);
        glVertex3f(-10,40,-10);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(180,190,129);
        glVertex3f(-10,-10,-10);
        glVertex3f(-10,40,-10);
        glVertex3f(-10,40,40);
        glVertex3f(-10,-10,40);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(0,0,0);
        glVertex3f(-5,-5,-5);
        glVertex3f(-5,20,-5);
        glVertex3f(-5,20,20);
        glVertex3f(-5,-5,20);
    glEnd();
}
void reusche(){
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
}

void gandalf() {

    glScalef(escalarX, escalarY, escalarZ);
    glRotatef(girar1, 0, 1, 0);
    glTranslatef(0, 0, moverse);
    glPushMatrix();
    //TORSO
    glColor3f(1, 0.4980, 0.1529);
    //glRotatef(angTronco,0,1,0);
    glTranslatef(0, 10, 0);
    glutSolidCube(5);

    //FIGURAS EXTRA
        //PECHO POLO
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 1);
    glVertex3f(2.51, 2.51, -2.51);
    glVertex3f(2.51, 0, 0);
    glVertex3f(2.51, 2.51, 2.51);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.9, 0.75, 0.57);
    glVertex3f(2.515, 2.51, -1.51);
    glVertex3f(2.515, 1, 0);
    glVertex3f(2.515, 2.51, 1.51);
    glEnd();
    glPopMatrix();

    //CABEZA
    glPushMatrix();
    glColor3f(0.9, 0.75, 0.57);
    glTranslatef(0, 5, 0);
    glutSolidSphere(3, 30, 30);

    //PECAS FRENTE
    glPushMatrix();
    glColor3f(1, 0.4980, 0.1529);
    glTranslatef(1.51, 2.5, 0.125);
    gluSphere(p, 0.1, 40, 40);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 0.4980, 0.1529);
    glTranslatef(1.51, 2.5, -0.125);
    gluSphere(p, 0.1, 40, 40);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 0.4980, 0.1529);
    glTranslatef(1.65, 2.4, 0.125);
    gluSphere(p, 0.1, 40, 40);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 0.4980, 0.1529);
    glTranslatef(1.65, 2.4, -0.125);
    gluSphere(p, 0.1, 40, 40);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 0.4980, 0.1529);
    glTranslatef(1.79, 2.3, 0.125);
    gluSphere(p, 0.1, 40, 40);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 0.4980, 0.1529);
    glTranslatef(1.79, 2.3, -0.125);
    gluSphere(p, 0.1, 40, 40);
    glPopMatrix();

    //OJOS
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(2.75, 0, 1);
    gluSphere(p, 0.175, 40, 40);
    //
    glPushMatrix();
    glTranslatef(-0.35, 0.18, 0);
    glScalef(1, 0.02, 1);
    gluSphere(p, 0.675, 40, 40);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(2.75, 0, -1);
    gluSphere(p, 0.175, 40, 40);
    glPushMatrix();
    glTranslatef(-0.35, 0.18, 0);
    glScalef(1, 0.02, 1);
    gluSphere(p, 0.675, 40, 40);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();

    //CORREA LAZO
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(0, -5, 0);
    glScalef(1, 0.2, 1);
    glutSolidCube(5.5);
    glPopMatrix();

    //CADERA
    glPushMatrix();
    glColor3f(1, 0.4980, 0.1529);
    glTranslatef(0, -5, 0);
    glutSolidCube(5);

    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 1);
    glVertex3f(2.51, -2.30, 2.30);
    glVertex3f(2.51, 0, 0);
    glVertex3f(2.51, -2.31, 1.01);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 1);
    glVertex3f(2.51, -2.31, -1.01);
    glVertex3f(2.51, 0, 0);
    glVertex3f(2.51, -2.30, -2.30);
    glEnd();
    glPopMatrix();
    //PIERNA 1 IZQUIERDA
    glPushMatrix();
    glColor3f(1, 0.4980, 0.1529);
    glTranslatef(0, -2.5, 0);
    glTranslatef(0, 0, -1.25);
    glRotatef(anguloPierna1, 0, 0, 1); // CAMBIAR
    glRotatef(90, 1, 0, 0);
    gluCylinder(p, 1.35, 1.35, 3, 40, 40);

    //CONEXION
    glPushMatrix();
    gluSphere(p, 1.35, 45, 45);
    glPopMatrix();
    //RODILLA

    glPushMatrix();
    glTranslatef(0, 0, 3);

    gluSphere(p, 1.35, 45, 45);
    glPopMatrix();

    //PIERNA 1.2 IZQUIERDA
    glPushMatrix();
    glColor3f(1, 0.4980, 0.1529);
    glTranslatef(0, 0, 3);
    glRotatef(anguloRodilla1, 0, 1, 0); //CAMBIAR/**********************
    gluCylinder(p, 1.35, 1.35, 3, 40, 40);

    //CONEXION PIERNA Y PIE
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0, 0, 3);
    gluSphere(p, 1.35, 45, 45);
    glPopMatrix();

    //PIE IZQUIERDO
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(0, 0, 4);
    glTranslatef(0.75, 0, 0);
    glScalef(2, 0.85, 1);
    glutSolidCube(2);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    //PIERNA 2 DERECHA
    glPushMatrix();
    glColor3f(1, 0.4980, 0.1529);
    glTranslatef(0, -2.5, 0);
    glTranslatef(0, 0, 1.25);
    glRotatef(anguloPierna2, 0, 0, 1); //CAMBIAR
    glRotatef(90, 1, 0, 0);
    gluCylinder(p, 1.35, 1.35, 3, 40, 40);

    //CONEXION
    glPushMatrix();
    glTranslatef(0, 0, 3);
    gluSphere(p, 1.35, 45, 45);
    glPopMatrix();

    //PIERNA 2.2 DERECHA
    glPushMatrix();
    glColor3f(1, 0.4980, 0.1529);
    glTranslatef(0, 0, 3);
    glRotatef(anguloRodilla2, 0, 1, 0);
    gluCylinder(p, 1.35, 1.35, 3, 40, 40);

    //CONEXION
    glPushMatrix();
    gluSphere(p, 1.35, 45, 45);
    glPopMatrix();

    //CONEXION PIERNA Y PIE
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0, 0, 3);
    gluSphere(p, 1.35, 45, 45);
    glPopMatrix();

    //PIE DERECHO
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(0, 0, 4);
    glTranslatef(0.75, 0, 0);
    glScalef(2, 0.85, 1);
    glutSolidCube(2);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();

    //HOMBRO DERECHO
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(0, 1.35, 3.85);
    gluSphere(p, 1.35, 45, 45);

    //BRAZO DERECHO 1
    glPushMatrix();
    glColor3f(0.9, 0.75, 0.57);
    glRotatef(90, 1, 1, 0);
    gluCylinder(p, 1.35, 1.35, 3, 40, 40);

    //CODO
    glPushMatrix();
    glTranslatef(0, 0, 3);
    gluSphere(p, 1.35, 40, 40);
    glPopMatrix();

    //BRAZO DERECHO 1.2
    glPushMatrix();
    glTranslatef(0, 0, 3);
    gluCylinder(p, 1.35, 1.35, 3, 40, 40);

    //CONEXION BRAZO Y MANO
    glPushMatrix();
    glTranslatef(0, 0, 3);
    gluSphere(p, 1.35, 40, 40);

    glPushMatrix();
    glColor3f(0, 0, 1);
    glScalef(1, 1, 0.5);
    gluSphere(p, 1.40, 40, 40);
    glPopMatrix();
    glPopMatrix();

    //MANO DERECHA
    glPushMatrix();
    glColor3f(0.9, 0.75, 0.57);
    glTranslatef(0, 0, 5);
    glRotatef(-90, 0, 0, 1);
    glutSolidCube(1.5);

    glPushMatrix();
    glTranslatef(0, 0.95, 0);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO DERECHA 1
    glPushMatrix();
    glTranslatef(0, 0.95, 0);
    gluCylinder(p, 0.2, 0.2, 1, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 1);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO DERECHA 1.1
    glPushMatrix();
    glTranslatef(0, 0, 1);
    gluCylinder(p, 0.2, 0.2, 0.5, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0.75);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO DERECHA 2
    glPushMatrix();
    glTranslatef(0, 0.42, 0.75);
    gluCylinder(p, 0.2, 0.2, 1, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 1);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO DERECHA 2.1
    glPushMatrix();
    glTranslatef(0, 0, 1);
    gluCylinder(p, 0.2, 0.2, 0.5, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0.75);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO DERECHA 3
    glPushMatrix();
    glTranslatef(0, 0, 0.75);
    gluCylinder(p, 0.2, 0.2, 1, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 1);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO DERECHA 3.1
    glPushMatrix();
    glTranslatef(0, 0, 1);
    gluCylinder(p, 0.2, 0.2, 0.5, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0.75);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO DERECHA 4
    glPushMatrix();
    glTranslatef(0, -0.42, 0.75);
    gluCylinder(p, 0.2, 0.2, 1, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 1);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO DERECHA 4.1
    glPushMatrix();
    glTranslatef(0, 0, 1);
    gluCylinder(p, 0.2, 0.2, 0.5, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();


    //HOMBRO IZQUIERDO
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(0, 1.35, -3.85);
    gluSphere(p, 1.35, 45, 45);

    //BRAZO IZQUIERDO 1
    glPushMatrix();
    glColor3f(0.9, 0.75, 0.57);
    glRotatef(90, 1, 1, 0);
    gluCylinder(p, 1.35, 1.35, 3, 40, 40);

    //CODO
    glPushMatrix();
    glTranslatef(0, 0, 3);
    gluSphere(p, 1.35, 40, 40);
    glPopMatrix();
    //BRAZO IZQUIERDO 1.2
    glPushMatrix();
    glTranslatef(0, 0, 3);
    gluCylinder(p, 1.35, 1.35, 3, 40, 40);

    //CONEXION BRAZO Y MANO
    glPushMatrix();
    glTranslatef(0, 0, 3);
    gluSphere(p, 1.35, 40, 40);

    glPushMatrix();
    glColor3f(0, 0, 1);
    glScalef(1, 1, 0.5);
    gluSphere(p, 1.40, 40, 40);
    glPopMatrix();
    glPopMatrix();

    //MANO IZQUIERDA
    glPushMatrix();
    glColor3f(0.9, 0.75, 0.57);
    glTranslatef(0, 0, 5);
    glutSolidCube(1.5);
    glPushMatrix();
    glTranslatef(0, 0.95, 0);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO IZQUIERDA 1
    glPushMatrix();
    glTranslatef(0, 0.95, 0);
    gluCylinder(p, 0.2, 0.2, 1, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 1);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO IZQUIERDA 1.1
    glPushMatrix();
    glTranslatef(0, 0, 1);
    gluCylinder(p, 0.2, 0.2, 0.5, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0.75);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO IZQUIERDA 2
    glPushMatrix();
    glTranslatef(0, 0.42, 0.75);
    gluCylinder(p, 0.2, 0.2, 1, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 1);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO IZQUIERDA 2.1
    glPushMatrix();
    glTranslatef(0, 0, 1);
    gluCylinder(p, 0.2, 0.2, 0.5, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0.75);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO IZQUIERDA 3
    glPushMatrix();
    glTranslatef(0, 0, 0.75);
    gluCylinder(p, 0.2, 0.2, 1, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 1);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO IZQUIERDA 3.1
    glPushMatrix();
    glTranslatef(0, 0, 1);
    gluCylinder(p, 0.2, 0.2, 0.5, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0.75);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO IZQUIERDA 4
    glPushMatrix();
    glTranslatef(0, -0.42, 0.75);
    gluCylinder(p, 0.2, 0.2, 1, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 1);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    //DEDO IZQUIERDA 4.1
    glPushMatrix();
    glTranslatef(0, 0, 1);
    gluCylinder(p, 0.2, 0.2, 0.5, 40, 40);
    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

}

void sergio(){
    gluQuadricDrawStyle(p,GLU_FILL);
    graficarEjes();
    glPushMatrix();

    //Tronco1
    glPushMatrix();//1
        glColor3f(dab[8],dab[9],dab[10]);
        glTranslatef(caminarx,14.5,caminary);
        glRotatef(dab[4],0,0,1);
        glRotatef(angTronco1,0,2,0);
        glutSolidCube(6);

        //brazo 1
            glPushMatrix();//2
            //glColor3f(0.42,0.42,0.42);
            glTranslatef(0,2.4,2.3);
            glRotatef(dab[0],1,0,0);
            glRotatef(angBrazo1,0,1,0);
            gluCylinder(p, 1, 1, 7, 16, 16);

            //mano 1
            glPushMatrix();//3
            glTranslated(0,0,7);
            glutSolidSphere(1.2,16,16);
            glPopMatrix();//2
            glPopMatrix();//1


        //brazo 2
            glPushMatrix();//2
            //glColor3f(0.42,0.42,0.42);
            //glTranslatef(0,-4,-5.3);
            glTranslatef(1,2.4,-2.3);
            glRotatef(dab[1],1,0,0);
            glRotatef(dab[2],0,1,0);
            glRotatef(angBrazo2,0,1,0);
            gluCylinder(p, 1, 1, 7, 16, 16);


             //mano 2
            glPushMatrix();//3
            glTranslated(0,0,7);
            glutSolidSphere(1.2,16,16);
            glPopMatrix();//2
            glPopMatrix();//1

        //Tronco2
        glPushMatrix();//2
        //glColor3f(0.42,0.42,0.42);
        glTranslatef(0,-5,0);
        glRotatef(dab[5],0,0,1);
        glRotatef(angTronco2,0,2,0);
        glutSolidCube(5);

        //Tronco3
        glPushMatrix();//3
        glTranslated(0,-2.5,0);
        //glRotated(60,1,0,0);
        glutSolidSphere(2.6,16,16);

        //pierna 1
            glPushMatrix();//4
            //glColor3f(0.42,0.42,0.42);
            glTranslatef(0,-1.3,1.4);
            glRotatef(90,1,0,0);
            glRotatef(angBrazo2,0,1,0);
            gluCylinder(p, 1, 1, 7, 16, 16);

            //pie 1
            glPushMatrix();//5
            //glColor3f(0.42,0.42,0.42);
            glTranslatef(0,0,8);
            glutSolidCube(2);
            glPopMatrix();//4
            glPopMatrix();//3

        //pierna 2
            glPushMatrix();//4
            //glColor3f(0.42,0.42,0.42);
            glTranslatef(0,-1.3,-1.4);
            glRotatef(90,1,0,0);
            glRotatef(angBrazo1,0,1,0);
            gluCylinder(p, 1, 1, 7, 16, 16);

            //pie 2
            glPushMatrix();//5
            //glColor3f(0.42,0.42,0.42);
            glTranslatef(0,0,8);
            glutSolidCube(2);
            glPopMatrix();//4
            glPopMatrix();//3
            glPopMatrix();//2
            glPopMatrix();//1

        //Cuello
        glPushMatrix();//2
        //glColor3f(0.42,0.42,0.42);
        glTranslatef(0,3,0);
        //glRotatef(angCuello,0,2,0);
        glutSolidCube(2);
            //Cabeza
            glPushMatrix();//3
            glTranslated(0,3,0);
            glRotated(angcabeza,0,1,0);
            glRotated(dab[3],0,0,1);
            glutSolidSphere(2.3,16,16);

            //antena
            glPushMatrix();//4
            //glColor3f(0.42,0.42,0.42);
            glTranslatef(0,4,0);
            glRotatef(90,1,0,0);
            gluCylinder(p, 0.2, 0.2, 5, 16, 16);

            //punta de antena
            glPushMatrix();//5
            glTranslated(0,0,0);
            glRotated(angPuntaAntena,0,1,0);
            glutSolidSphere(0.4,16,16);
            glPopMatrix();//4
            glPopMatrix();//3

            //ojo1
            glPushMatrix();//4
            glColor3f(dab[6],0,dab[7]);
            glTranslated(2,0,1);
            glutSolidSphere(0.4,16,16);
            glPopMatrix();//3
            //ojo2
            glPushMatrix();//4
            glColor3f(dab[6],0,dab[7]);
            glTranslated(2,0,-1);
            glutSolidSphere(0.4,16,16);
            glPopMatrix();//3
            glPopMatrix();//2
            glPopMatrix();//1
            glPopMatrix();
            glPopMatrix();


}

void bryan()
{

    glTranslated(6,0.3,-5);
    glRotated(45,0,1,0);
    ///TRONCO
    glPushMatrix(); ///*****
        glColor3f(1,0.3,0);
        glRotatef(sentar,1,0,0); ///DAR ANGULO
        gluCylinder(p, 1, 1, 4, 16, 16);

        ///CABEZAAAA
        glPushMatrix(); ///****
            glTranslatef(0,0,0.1);
            glRotatef(angCuello,1,0,0); ///DAR ANGULO
            glColor3f(1,0.3,0);
            glutSolidSphere(1,16,16);
            ///CUELLO
            glPushMatrix();///***
                glTranslatef(0,0,-1.2);
                glColor3f(1,0.3,0);
                gluCylinder(p, 0.4, 0.7, 0.5, 16, 16);
                glPushMatrix();///**
                    glTranslatef(0,0,0);
                    glRotatef(angCabeza,0,1,0); ///DAR ANGULO
                    glColor3f(1,0.3,0);
                    glutSolidSphere(0.6,16,16);
                    ///Cabeza
                    glPushMatrix(); ///*
                        glTranslatef(0,0,-0.7);
                        glColor3f(1,0.3,0);
                        glutSolidSphere(1,16,16);

                        ///OjoD
                        glPushMatrix(); ///
                            glTranslatef(0.5,0.2,-0.7);
                            glRotatef(ojos,0,1,0); ///DAR ANGULO
                            glColor3f(0,1,0);
                            glutSolidSphere(0.3,16,16);
                            ///Pupila
                            glPushMatrix(); ///-
                                glTranslatef(0,0.1,-0.3);
                                glColor3f(0,0,0);
                                glutSolidSphere(0.1,16,16);
                            glPopMatrix(); ///-
                        glPopMatrix();///

                        ///OjoI
                        glPushMatrix(); ///
                            glTranslatef(-0.5,0.2,-0.7);
                            glRotatef(ojos,0,1,0); ///DAR ANGULO
                            glColor3f(0,1,0);
                            glutSolidSphere(0.3,16,16);
                            ///Pupila
                            glPushMatrix(); ///-
                                glTranslatef(0,0.1,-0.3);
                                glColor3f(0,0,0);
                                glutSolidSphere(0.1,16,16);
                            glPopMatrix(); ///-
                        glPopMatrix();///

                        ///OrejaD
                        glPushMatrix(); ///
                            glTranslatef(0.5,1.5,0);
                            glRotatef(90,1,0,0); ///DAR ANGULO
                            glColor3f(1,0.3,0);
                            gluCylinder(p, 0, 0.3, 0.9, 16, 16);
                        glPopMatrix(); ///

                        ///OrejaI
                        glPushMatrix(); ///
                            glTranslatef(-0.5,1.5,0);
                            glRotatef(90,1,0,0); ///DAR ANGULO
                            glColor3f(1,0.3,0);
                            gluCylinder(p, 0, 0.3, 0.9, 16, 16);
                        glPopMatrix(); ///

                        ///Hocico
                        glPushMatrix(); ///
                            glTranslatef(0,-0.1,-1);
                            glColor3f(0,0,0);
                            glutSolidSphere(0.3,16,16);
                        glPopMatrix(); ///
                    glPopMatrix();///*
                glPopMatrix();///**
            glPopMatrix(); ///***
        glPopMatrix(); ///****

        ///PataDelD
        glPushMatrix(); ///****
            glTranslatef(1,-0.2,0.2);
            glColor3f(1,1,0);
            glutSolidSphere(0.3,16,16);
            ///Brazo
            glPushMatrix(); ///***
                glTranslatef(0,0,0);
                glRotatef(65,1,0,0); ///DAR ANGULO
                glColor3f(1,0.3,0);
                gluCylinder(p, 0.3, 0.3, 1.5, 16, 16);
                ///ARTICULACION
                glPushMatrix(); ///**
                    glTranslatef(0,0,1.5);
                    glColor3f(1,1,0);
                    glutSolidSphere(0.3,16,16);
                    ///Antebrazo
                    glPushMatrix(); ///*
                        glTranslatef(0,0,0.1);
                        glRotatef(60,1,0,0); ///DAR ANGULO
                        glColor3f(1,0.3,0);
                        gluCylinder(p, 0.3, 0.3, 1.5, 16, 16);
                        ///PATITA
                        glPushMatrix();///
                            glTranslatef(0,0,1.5);
                            glColor3f(1,1,0);
                            glutSolidSphere(0.3,16,16);
                        glPopMatrix(); ///
                    glPopMatrix();///*
                glPopMatrix(); ///**
            glPopMatrix();///***
        glPopMatrix();///****

        ///PDelI
        glPushMatrix(); ///****
            glTranslatef(-1,-0.2,0.2);
            glRotatef(pDelIz,1,0,0); ///DAR ANGULO
            glColor3f(1,1,0);
            glutSolidSphere(0.3,16,16);
            ///Brazo
            glPushMatrix(); ///***
                glTranslatef(0,0,0);
                glRotatef(65,1,0,0); ///DAR ANGULO
                glColor3f(1,0.3,0);
                gluCylinder(p, 0.3, 0.3, 1.5, 16, 16);
                ///ARTICULACION
                glPushMatrix(); ///**
                    glTranslatef(0,0,1.5);
                    glColor3f(1,1,0);
                    glutSolidSphere(0.3,16,16);
                    ///Antebrazo
                    glPushMatrix(); ///*
                        glTranslatef(0,0,0.1);
                        glRotatef(60,1,0,0); ///DAR ANGULO
                        glColor3f(1,0.3,0);
                        gluCylinder(p, 0.3, 0.3, 1.5, 16, 16);
                        ///PATITA
                        glPushMatrix();///
                            glTranslatef(0,0,1.5);
                            glColor3f(1,1,0);
                            glutSolidSphere(0.3,16,16);
                        glPopMatrix(); ///
                    glPopMatrix();///*
                glPopMatrix(); ///**
            glPopMatrix();///***
        glPopMatrix();///****

        ///PTraD
        glPushMatrix(); ///****
            glTranslatef(1,-0.2,3.2);
            glRotatef(sentarP,1,0,0); ///DAR ANGULO////
            glColor3f(1,1,0);
            glutSolidSphere(0.3,16,16);
            ///Brazo
            glPushMatrix(); ///***
                glTranslatef(0,0,0);
                glRotatef(115,1,0,0); ///DAR ANGULO
                glColor3f(1,0.3,0);
                gluCylinder(p, 0.3, 0.3, 1.5, 16, 16);
                ///ARTICULACION
                glPushMatrix(); ///**
                    glTranslatef(0,0,1.5);
                    glColor3f(1,1,0);
                    glutSolidSphere(0.3,16,16);
                    ///Antebrazo
                    glPushMatrix(); ///*
                        glTranslatef(0,0,0.1);
                        glRotatef(300,1,0,0); ///DAR ANGULO
                        glColor3f(1,0.3,0);
                        gluCylinder(p, 0.3, 0.3, 1.5, 16, 16);
                        ///PATITA
                        glPushMatrix();///
                            glTranslatef(0,0,1.5);
                            glColor3f(1,1,0);
                            glutSolidSphere(0.3,16,16);
                        glPopMatrix(); ///
                    glPopMatrix();///*
                glPopMatrix(); ///**
            glPopMatrix();///***
        glPopMatrix();///****

        ///PTraI
        glPushMatrix(); ///****
            glTranslatef(-1,-0.2,3.2);
            glRotatef(sentarP,1,0,0); ///DAR ANGULO////
            glColor3f(1,1,0);
            glutSolidSphere(0.3,16,16);
            ///Brazo
            glPushMatrix(); ///***
                glTranslatef(0,0,0);
                glRotatef(115,1,0,0); ///DAR ANGULO
                glColor3f(1,0.3,0);
                gluCylinder(p, 0.3, 0.3, 1.5, 16, 16);
                ///ARTICULACION
                glPushMatrix(); ///**
                    glTranslatef(0,0,1.5);
                    glColor3f(1,1,0);
                    glutSolidSphere(0.3,16,16);
                    ///Antebrazo
                    glPushMatrix(); ///*
                        glTranslatef(0,0,0.1);
                        glRotatef(300,1,0,0); ///DAR ANGULO
                        glColor3f(1,0.3,0);
                        gluCylinder(p, 0.3, 0.3, 1.5, 16, 16);
                        ///PATITA
                        glPushMatrix();///
                            glTranslatef(0,0,1.5);
                            glColor3f(1,1,0);
                            glutSolidSphere(0.3,16,16);
                        glPopMatrix(); ///
                    glPopMatrix();///*
                glPopMatrix(); ///**
            glPopMatrix();///***
        glPopMatrix();///****

        ///COLA
        glPushMatrix(); ///****
            ///ARTICULACION
            glTranslatef(0,0,3.7);
            glRotatef(cola,0,1,1); ///DAR ANGULO
            glColor3f(1,0.3,0);
            glutSolidSphere(1,16,16);
            ///Rabo
            glPushMatrix();
                glTranslatef(0,3.5,1.6);
                glRotatef(110,1,0,0); ///DAR ANGULO
                glColor3f(1,0.3,0);
                gluCylinder(p, 0, 0.2, 3, 16, 16);
            glPopMatrix();
        glPopMatrix(); ///****
    glPopMatrix();///*****

}

void pedro()
{


    glPushMatrix();
    glTranslatef(8,0,8);
    glTranslatef(movX,movY,movZ);
    glRotatef(varRotar,0,1,0);

        ///tronco

        glColor3f(0,0,0); glutSolidSphere(3,32,32);
        glPushMatrix();
            ///cabeza
            glRotatef(cabeza,0,1,0);
            glTranslatef(0,4,0);
            glRotatef(90,1,0,0);
            glColor3f(1,0,0); gluCylinder(p, 0.5, 0.5, 2, 16, 16);
        glPopMatrix();

        glPushMatrix();
            ///Conexión BI
            glRotatef(conexionBi,1,0,0);
            glTranslatef(0,0,2);
            glutSolidSphere(1.5,32,32);
            glPushMatrix();
              ///Brazo IZ
              glRotatef(brazoIz,0,0,1);
              glTranslatef(0,0,1.5);
              glColor3f(0,0,0);
              gluCylinder(p, 0.7, 0.7, 6.0, 16, 16);
                  ///AI
                  glTranslatef(0,0,5.3);

                  glColor3f(1,0,0);
                  glutSolidCube(1.5);
                  glPushMatrix();
                    ///Brazo IZ2
                  glRotatef(brazoIz2,1,0,0);
                  glTranslatef(0,0,0.2);
                  glRotatef(90,0,1,0);
                  glColor3f(0,0,0); gluCylinder(p, 0.5, 0.5, 2.4, 16, 16);
                  glPushMatrix();
                    ///Mano
                   glTranslatef(0,0,4.3);
                   glRotatef(90,1,0,0);
                   glColor3f(1,0,0); glutSolidTorus(0.5,1.5,2,9);
                   glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
///--------------------------------------------------------------------------------------
        glPushMatrix();
            ///Conexión BD
            glRotatef(conexionBe,0,0,1);
            glTranslatef(2,0,0);
            glutSolidSphere(1.5,32,32);
            glPushMatrix();
              ///Brazo DE
              glRotatef(brazoDe,1,0,0);
              glTranslatef(1.5,0,0);
              glRotatef(90,0,1,0);
              glColor3f(0,0,0);
              gluCylinder(p, 0.7, 0.7, 6.0, 16, 16);
                  ///AD
                  glTranslatef(0,0,5.3);

                  glColor3f(1,0,0);
                  glutSolidCube(1.5);
                  glPushMatrix();
                    ///Brazo DE2
                  glRotatef(brazoDe2,1,0,0);
                  glRotatef(180,0,1,0);
                  glTranslatef(0,0,0.2);
                  glRotatef(90,0,1,0);
                  glColor3f(0,0,0); gluCylinder(p, 0.5, 0.5, 2.4, 16, 16);
                  glPushMatrix();
                    ///Mano
                   glTranslatef(0,0,4.3);
                   glRotatef(90,1,0,0);
                   glColor3f(1,0,0); glutSolidTorus(0.5,1.5,2,9);
                   glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void jorge(){
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glPushMatrix();
        ///tronco
        glTranslatef(mover,3,mover1);
        glColor3ub(178,178,168);
        glRotatef(girar,0,1,0);
        glutSolidCube(5);
        glPushMatrix();
            ///Brazo.p1
            glTranslatef(0,5,0);
            glColor3ub(178,178,168);
            glRotatef(90,1,angulop1,0);
            gluCylinder(p, 0.5, 0.5, 3, 100, 100);
            glPushMatrix();
                ///Conector1
                glTranslatef(0,0,0);
                glColor3ub(129,255,253);
                glutSolidSphere(1,32,32);
                glPushMatrix();
                    ///Brazo.p2
                    glTranslatef(0,0,0);
                    glColor3ub(178,178,168);
                    glRotatef(angulop2,0,1,0);
                    gluCylinder(p, 0.5, 0.5, 4, 100, 100);
                    glPushMatrix();
                        ///Conector2
                        glTranslatef(0,0,4);
                        glColor3ub(129,255,253);
                        glutSolidSphere(1,32,32);
                        glPushMatrix();
                            ///Brazo.p3
                            glTranslatef(0,0,0);
                            glColor3ub(178,178,168);
                            glRotatef(angulop3,0,1,0);
                            gluCylinder(p, 0.5, 0.5, 4, 100, 100);
                            glPushMatrix();
                                ///garra
                                glTranslatef(0,0,5.5);
                                glColor3ub(255,150,22);
                                glRotatef(180,0,1,0);
                                glRotatef(anguloGarra,0.5,0,4);
                                glutSolidCone(1.5,2,10,10);
                                glPopMatrix();
                            glPopMatrix();
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
            ///rueda1
            glPushMatrix();
            glTranslatef(2,-4,2);
            glRotated(a,0,0,1);
            glColor3ub(43,43,45);
            glutSolidTorus(0.5,0.5,30,30);
            glPopMatrix();
            ///rueda2
            glPushMatrix();
            glTranslatef(2,-4,-2);
            glRotated(a,0,0,1);
            glColor3ub(43,43,45);
            glutSolidTorus(0.5,0.5,30,30);
            glPopMatrix();
            ///rueda2
            glPushMatrix();
            glTranslatef(-2,-4,2);
            glRotated(a,0,0,1);
            glColor3ub(43,43,45);
            glutSolidTorus(0.5,0.5,30,30);
            glPopMatrix();
            ///rueda2
            glPushMatrix();
            glTranslatef(-2,-4,-2);
            glRotated(a,0,0,1);
            glColor3ub(43,43,45);
            glutSolidTorus(0.5,0.5,30,30);
            glPopMatrix();

        glPopMatrix();

}

void menearCola(int i)
{
    cola = cola + 10;
    glutPostRedisplay();
    glutTimerFunc(50,menearCola,1);
}

void graficar()
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(ejeX,ejeY,ejeZ, 0,0,0, 0,1,0);
    reusche();
    sergio();
    bryan();
    pedro();
    jorge();
    gandalf();

    glutSwapBuffers();
}


void redimensionar(int w, int h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(float)w/(float)h,1,100);

}

//Función para que el robot de Eduardo camine.
void caminarRobot(int i)
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
    glutTimerFunc(30,caminarRobot,3);
}

void rotarPuntaAntena(int i)
{
    angPuntaAntena = angPuntaAntena + 5;
    glutPostRedisplay();
    glutTimerFunc(30,rotarPuntaAntena,1);
}

// Mover Pierna izquierda y brazo derecho del Robot de Sergio
void rotarBrazo1(int i)
{
    if(angBrazo1==10)
        brazo1bool = true;
    if(angBrazo1==-10)
        brazo1bool = false;
    if(brazo1bool==false)
        angBrazo1 = angBrazo1 + 1;
    if(brazo1bool==true)
        angBrazo1 = angBrazo1 - 1;
    glutPostRedisplay();
    glutTimerFunc(30,rotarBrazo1,2);
}
// Mover Pierna derecha y brazo izquierdo del Robot de Sergio
void rotarBrazo2(int i)
{
    if(angBrazo2==10)
        brazo2bool = false;
    if(angBrazo2==-10)
        brazo2bool = true;
    if(brazo2bool==false)
        angBrazo2 = angBrazo2 - 1;
    if(brazo2bool==true)
        angBrazo2 = angBrazo2 + 1;
    glutPostRedisplay();
    glutTimerFunc(30,rotarBrazo2,3);
}
// Mover mano del robot de Jorge
void rotarGarra(int i)
{
    anguloGarra = anguloGarra + 10;
    glutPostRedisplay();
    glutTimerFunc(100,rotarGarra,3);
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

        //ZOOM
        case '+': ejeX = ejeX+1;
                ejeY = ejeY+1;
                ejeZ = ejeZ+1;
                break;
        case '-': ejeX = ejeX-1;
                ejeY = ejeY-1;
                ejeZ = ejeZ-1;
                break;

        //Movimiento Robot de Sergio
        case 'D': caminarx = caminarx + 1;
                caminarbool = true;
                break;
        case 'A': caminarx = caminarx - 1;
                caminarbool = true;
                break;
        case 'S': caminary = caminary + 1;
                caminarbool = true;
                break;
        case 'W': caminary = caminary - 1;
                caminarbool = true;
                break;
        //Movimiento robot de Eduardo
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
        case 'e':
            pos_z++;
            break;
        case 'q':
            pos_z--;
            break;
        //Hacer Dab
        case 'I':
                dab[0]=-40;
                dab[1]=-40;
                dab[2]=20;
                dab[3]=-20;
                dab[4]=-20;
                dab[5]=20;
                dab[6]=1;
                dab[7]=0;
                dab[8]=0.96;
                dab[9]=0.65;
                dab[10]=0.12;
                break;
        //Dejar de hacer Dab y T-pose
        case 'P':
                dab[0]=65;
                dab[1]=115;
                dab[2]=0;
                dab[3]=0;
                dab[4]=0;
                dab[5]=0;
                dab[6]=0;
                dab[7]=1;
                dab[8]=0.42;
                dab[9]=0.42;
                dab[10]=0.42;
                break;
        //T-pose
        case 'O':
                dab[0]=0;
                dab[1]=180;
                dab[6]=1;
                dab[7]=0;
                dab[8]=0.1;
                dab[9]=0.65;
                dab[10]=0.12;
                break;
       //EJES DE LA CAMARA
        case '1':
            ejeY = ejeY + 1;
            break;
        case '2':
            ejeY = ejeY - 1;
            break;
        case '3':
            ejeX = ejeX + 1;
            break;
        case '4':
            ejeX = ejeX - 1;
            break;
        case '5':
            ejeZ = ejeZ + 1;
            break;
        case '6':
            ejeZ = ejeZ - 1;
            break;
        //Movimiento Pedro
        case 'i':
            movX++;
            movZ++;
        break;
        case 'k' :
            movX--;
            movZ--;
        break;
        case 'o' :
            movY++;
        break;
        case 'u' :
            movY--;
        break;
        case 'j' :
            varRotar+=2.5;
        break;
        case 'l' :
            varRotar-=2.5;
        break;
        // Movimiento robot Jorge
        case 'N':
            mover++;
            break;
        case 'M':
            mover--;
            break;
        case 'J':
            girar=girar+5;
            break;
        case 'K':
            mover1++;
            break;
        case 'L':
            mover1--;
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
    glutTimerFunc(30,rotarPuntaAntena,1);
    glutTimerFunc(30,rotarBrazo1,2);
    glutTimerFunc(30,rotarBrazo2,3);
    caminarRobot(0);
    glutTimerFunc(100,rotarGarra,3);
    glutTimerFunc(50,menearCola,1);

    glutMainLoop();

    return 0;
}
