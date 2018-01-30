#include <sstream>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>    //einai gia to vector anti gia deiktes
#include <string.h>
#include <unistd.h>		//gia to sleep
#include <time.h>		//gia ti rand
#include <GL/gl.h>     // openGL header
#include <GL/glu.h>   // glut header
#include <GL/glut.h>   // glut header


#define WIDTH  800
#define HEIGHT 800
using namespace std;

float zpos=15.0f;
float spin=0.0f;
float spinx=0.0f;
bool fullscreen=false;
int flag3 , flag4, flag ;
GLUquadric *sphere;
int  SphereDList;
int o;
int k;
int d;
int meg;
int ***pinakas;
int fd;
int fd1;
int N;
int xprev;
int yprev;
int zprev;
int cs1,cs2,cs3;
int cc1,cc2,cc3;
int button = 2;
int butg = 1;
int speed = 1000000;
GLfloat lightPos[]={5.0,0.0f,0.0f,1.0};
GLfloat lightPos1[]={0.0,N,0.0f,1.0};//panw aristera
GLfloat lightPos2[]={N,N,0.0f,1.0};//panw deksia
GLfloat lightPos3[]={N,0.0f,0.0f,1.0};//katw deksia
GLfloat lightPos4[]={0.0,0.0f,0.0f,1.0};//katw aristera
GLfloat lightPos5[]={0.0,0.0f,N,1.0};//pisw katw aristera 
GLfloat lightPos6[]={0.0,N,N,1.0};//pisw panw aristera 
GLfloat lightPos7[]={N,0.0f,N,1.0};//pisw katw deksia

/*******functions********
void InitGL();
void display();
void plegma();
void Resize(int WIDTH, int HEIGHT);
void SetUpLight();
void special_keys(int keys,int x,int y);
void Draw_SphereCenter();
*/

class snakes
{
	public:
	int x,y,z,sxhma;
	vector<snakes> *fidi;
	snakes();
	snakes(int a,int b,int c,int d);
};

snakes :: snakes()
{
	x=y=z=0;
	sxhma= 0;

}

snakes:: snakes(int a,int b,int c,int d)
{
	x=a;
	y=b;
	z=c;
	sxhma=d;
}

vector <vector<snakes> > fidi;

void swma(int x,int y,int z,int fd1);
void swma1(int x,int y, int z,int fd1);
void new_times(int* xp, int* yp, int* zp);

void SetUpLight(){
	GLfloat ambientLight[] = {0.5f,0.1f,0.1f,0.1f};//rgba xrwmata
	GLfloat diffuseLight[] = {0.4f,0.3f,0.3f,1.0f};//rgba
	
	glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos); //xwris ayto fwtizetai mono sto kentro!!!!!!!!!!!!!!!!!!!!!
	glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_NORMALIZE);
}

void initSpot1(){
        	GLfloat ambientLight[] = {0.6f,0.1f,0.1f,1.0f};
		GLfloat diffuseLight[] = {0.7f,0.7f,0.7f,1.0f};
		glLightfv(GL_LIGHT1,GL_AMBIENT,ambientLight);
		glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuseLight);
		glLightfv(GL_LIGHT1,GL_POSITION,lightPos1);
		glEnable(GL_LIGHT1);
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_NORMALIZE);
}
void initSpot2(){
        	GLfloat ambientLight[] = {0.6f,0.1f,0.1f,1.0f};
		GLfloat diffuseLight[] = {0.7f,0.7f,0.7f,1.0f};
		glLightfv(GL_LIGHT2,GL_AMBIENT,ambientLight);
		glLightfv(GL_LIGHT2,GL_DIFFUSE,diffuseLight);
		glLightfv(GL_LIGHT2,GL_POSITION,lightPos2);
		glEnable(GL_LIGHT2);
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_NORMALIZE);

}
void initSpot3(){
        	GLfloat ambientLight[] = {0.6f,0.1f,0.1f,1.0f};
		GLfloat diffuseLight[] = {0.7f,0.7f,0.7f,1.0f};
		glLightfv(GL_LIGHT3,GL_AMBIENT,ambientLight);
		glLightfv(GL_LIGHT3,GL_DIFFUSE,diffuseLight);
		glLightfv(GL_LIGHT3,GL_POSITION,lightPos3);
		glEnable(GL_LIGHT3);
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_NORMALIZE);
}
void initSpot4(){
        	GLfloat ambientLight[] = {0.6f,0.1f,0.1f,1.0f};
		GLfloat diffuseLight[] = {0.7f,0.7f,0.7f,1.0f};
		glLightfv(GL_LIGHT4,GL_AMBIENT,ambientLight);
		glLightfv(GL_LIGHT4,GL_DIFFUSE,diffuseLight);
		glLightfv(GL_LIGHT4,GL_POSITION,lightPos4);
		glEnable(GL_LIGHT4);
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_NORMALIZE);
}
void initSpot5(){
        	GLfloat ambientLight[] = {0.6f,0.1f,0.1f,1.0f};
		GLfloat diffuseLight[] = {0.7f,0.7f,0.7f,1.0f};
		glLightfv(GL_LIGHT5,GL_AMBIENT,ambientLight);
		glLightfv(GL_LIGHT5,GL_DIFFUSE,diffuseLight);
		glLightfv(GL_LIGHT5,GL_POSITION,lightPos5);
		glEnable(GL_LIGHT5);
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_NORMALIZE);
}
void initSpot6(){
        	GLfloat ambientLight[] = {0.6f,0.1f,0.1f,1.0f};
		GLfloat diffuseLight[] = {0.7f,0.7f,0.7f,1.0f};
		glLightfv(GL_LIGHT6,GL_AMBIENT,ambientLight);
		glLightfv(GL_LIGHT6,GL_DIFFUSE,diffuseLight);
		glLightfv(GL_LIGHT6,GL_POSITION,lightPos6);
		glEnable(GL_LIGHT6);
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_NORMALIZE);
}
void initSpot7(){
       	 	GLfloat ambientLight[] = {0.6f,0.1f,0.1f,1.0f};
		GLfloat diffuseLight[] = {0.7f,0.7f,0.7f,1.0f};
		glLightfv(GL_LIGHT7,GL_AMBIENT,ambientLight);
		glLightfv(GL_LIGHT7,GL_DIFFUSE,diffuseLight);
		glLightfv(GL_LIGHT7,GL_POSITION,lightPos7);
		glEnable(GL_LIGHT7);
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_NORMALIZE);
}

void InitGL(){
      glClearColor(0,0,0,1);     //dinei sto parathiro mayro kai des forum
      glEnable(GL_DEPTH_TEST);
      glFrontFace(GL_CCW);
      glEnable(GL_CULL_FACE);
      glEnable(GL_LIGHTING);
      SetUpLight();
}

void Draw_SphereCenter(){
	int i, j, k1;
	int x;
	int y;
	int z;
	
	x = o;
	y = k;
	z = d;
	
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			for(k1=1;k1<=N;k1++){
				sphere = NULL;
				if(pinakas[i][j][k1]==2){
					if(sphere==NULL){
						sphere=gluNewQuadric();
						SphereDList=glGenLists(1); glViewport(0,0,WIDTH,HEIGHT);
						glNewList( SphereDList,GL_COMPILE);
						glPushMatrix();
						glTranslatef(i-0.5,j-0.5,-k1+0.5);
						glNormal3f(0.5f,1.5f,0.5f);		
						glColor3ub(cs1,cs2,cs3);
						gluSphere(sphere,0.5,50,50);
						
						glPopMatrix();
						glEndList();
					}
					glCallList(SphereDList);
				}
				
			}
		}	
	}    
}  //kleinei h sunarthsh

void DrawCube1(){	

	int x;
	int y;
	int z;
	
	int i, j, k1;
	
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			for(k1=1;k1<=N;k1++){	
				if(pinakas[i][j][k1]==1 || pinakas[i][j][k1] == 3){
					x = i-1;
					y = j-1;
					z = -k1+1;
					
					glPushMatrix();     //sthn arxh ths for gia ta sxhmata
		
					glDisable(GL_CULL_FACE);
					glColor3ub(cc1,cc2,cc3);
					glBegin(GL_QUADS);
					
					glVertex3f(x,y,z);  //    mprostinh edra
					glVertex3f(x,y+1,z);  
					glVertex3f(x+1,y+1,z);  
					glVertex3f(x+1,y,z);  
				
					glVertex3f(x,y,z);  //   aristerh edra
					glVertex3f(x,y+1,z);  
					glVertex3f(x,y+1,z-1);  
					glVertex3f(x,y,z-1); 
				
					glVertex3f(x, y, z);  //   katw edra
					glVertex3f(x+1, y, z);  
					glVertex3f(x+1, y, z-1);  
					glVertex3f(x, y, z-1);  
				
					glVertex3f(x+1,y,z);  //       deksia edra
					glVertex3f(x+1,y+1,z);  
					glVertex3f(x+1,y+1,z-1);  
					glVertex3f(x+1,y,z-1);  
				
					glVertex3f(x,y,z-1);  //      pisw edra
					glVertex3f(x,y+1,z-1);  
					glVertex3f(x+1,y+1,z-1);  
					glVertex3f(x+1,y,z-1);  
				
					glVertex3f(x,y+1,z);  //      panw edra
					glVertex3f(x+1,y+1,z);  
					glVertex3f(x+1,y+1,z-1);  
					glVertex3f(x,y+1,z-1);  
					glEnd();
													//kleinei h for gia kuvakia
					glPopMatrix();
				}
			}
		}
	}
	
}        //kleinei h sunarthsh

void plegma(){
	int x1,y1,y, x, z,z1, j,i,k1;
	x = N;
	y1 = x;
	x1 = x;
	z = x;
	for(x=0;x<=x1;x++){
		for(y=0; y<=y1; y+=1){           //DHMIOURGOUME TIS ORIZONTIES GRAMMES se 3D me z sta8ero	
			glColor3ub(255,0,0);
			glBegin(GL_LINES);
			
			glVertex3f(x, y, 0);  //shmeio ekkinhshs
			glVertex3f(x, y, -z);	 //shmeio termatismou grammhs
			glEnd();
		}
	}
	
	y = N;
	y1 = y;
	x = y;
	z1 = y;
	for(z=0; z>=-y1; z-=1){
		for(y=0; y<=y1; y+=1){           //DHMIOURGOUME TIS ORIZONTIES GRAMMES se 3D me x sta8ero
			glColor3ub(255,0,0);
			glBegin(GL_LINES);
			
			glVertex3f(0, y, z);  //shmeio ekkinhshs
			glVertex3f(x, y, z);	 //shmeio termatismou grammhs
			glEnd();
		}
		
	}
	
	x = N;
	x1 = x;
	y = x;
	z1 = x;
	for(z=0; z>=-x1; z-=1){
		for(x=0; x<=x1; x+=1){           //DHMIOURGOUME TIS KA8ETES GRAMMES se 3 D
			glColor3ub(255,0,0);
			glBegin(GL_LINES);
			
			glVertex3f(x, 0, z);  //shmeio ekkinhshs
			glVertex3f(x, y, z);	 //shmeio termatismou grammhs
			glEnd();
		}
	}	
	return;	
}	

void pinakas2(int fd1){
	int m;
	int x;
	int y;
	int z;
	x = o;
	y = k;
	z = -d;
	int i,j;
	/*EDW TOPOTHETEITAI TO KEFALI*/			
	if(pinakas[x][y][z]==0){
		pinakas[x][y][z] = 3;
		fidi[fd1].push_back(snakes(x,y,z,3));
	}
	else{
		fd1--;	
		return ;
	}
	/*EDW KALW TO SWMA*/
	swma(x,y,z,fd1);
}

void swma1(int x, int y, int z, int fd1){	
	int i,j;
	int *xp, *yp, *zp;
	xp = &x;
	yp = &y;
	zp = &z;
	xprev = x;
	yprev = y;
	zprev = z;

	for(j= 1; j<=fidi[fd1].size()-1;){
		new_times(xp,yp,zp);
		if((abs(*xp - fidi[fd1][j].x) + abs(*yp - fidi[fd1][j].y) + abs(*zp - fidi[fd1][j].z)) == 1){
				fidi[fd1][j].x = *xp;
				fidi[fd1][j].y = *yp;
				fidi[fd1][j].z = *zp;
				j++;
		}
		else{
			fidi[fd1][j].x = xprev;
			fidi[fd1][j].y = yprev;
			fidi[fd1][j].z = zprev;
			j++;
		}
	}

}

void swma(int x, int y, int z, int fd1){
	int i;
	int *xp, *yp, *zp;
	
	xp = &x;
	yp = &y;
	zp = &z;
	
	for(i=1; i<=meg-1;){
		new_times(xp,yp,zp);
		
		if(flag3 != 22){
			fidi[fd1].push_back(snakes(*xp,*yp,*zp,1));
			i++;
		}
	}  
}

void new_times(int* xp, int* yp, int* zp) {
	int x = *xp, y = *yp, z = *zp, retry = 1;
		
	while(retry) {
		flag3 = (rand()/(RAND_MAX/18));
		x = *xp;
		y = *yp;
		z = *zp;
		

		switch(flag3){
			case 0:   //exw (x-1,y-1,z)
				x = x - 1;
				y = y - 1;
				break;
			case 1:   //exw (x-1, y+1,z)
				x = x - 1;
				y = y + 1;
				break;
			case 2:   //exw (x-1,y,z-1)
				x = x - 1;
				z = z - 1;
				break;
			case 3:   //exw (x-1, y, z+1)
				x = x - 1;
				z = z + 1;
				break;
			case 4:   //exw (x+1, y-1, z)
				x = x + 1;
				y = y - 1;
				break;
			case 5:   //exw (x+1, y+1, z)
				x = x + 1;
				y = y + 1;
				break;
			case 6:   //exw (x+1, y, z-1)
				x = x + 1;
				z = z - 1;
				break;
			case 7:   //exw (x+1, y, z+1)
				x = x + 1;
				z = z + 1;
				break;
			case 8:   //exw (x, y-1, z-1)
				y = y - 1;
				z = z - 1;
				break;
			case 9:   //exw (x, y-1, z+1)
				y = y - 1;
				z = z + 1;
				break;
			case 10:   //exw (x, y+1, z-1)
				y = y + 1;
				z = z - 1;
				break;
			case 11:   //exw (x, y+1, z+1)
				y = y + 1;
				z = z + 1;
				break;
			case 12:   //edw exw (x-2,y, z)
				x = x -2;
				break;
			case 13:   //edw exw (x+2,y, z)
				x = x + 2;
				break;
			case 14:   //exw (x, y-2, z)
				y = y - 2;
				break;
			case 15:   //exw (x, y+2, z)
				y = y + 2;
				break;
			case 16:   //exw (x, y, z-2)
				z = z - 2;
				break;
			case 17:   //exw (x, y, z+2)
				z = z + 2;
				break;
			default:
				break;
		}
		
		if(x>=1 && x<=N && y>=1 && y<=N && z>=1 && z<=N && pinakas[x][y][z] == 0)   //elegxw an eimai mesa sto plegma
		{
			retry = 0;
			flag4 = (rand()/(RAND_MAX/2));
			
			if(flag3==0){  //exw (x-1, y-1, z)
				if(flag4 == 0 && pinakas[x][y+1][z] == 0)
					pinakas[x][y+1][z] = 2;
				else if(flag4 == 1 && pinakas[x+1][y][z] == 0)
					pinakas[x+1][y][z] = 2;
				else                   
					retry = 1;
			} 
			
			else if(flag3==1){  //exw (x-1, y+1, z)
				if(flag4 == 0 && pinakas[x][y-1][z] == 0)
					pinakas[x][y-1][z] = 2;
				else if(flag4 == 1 && pinakas[x+1][y][z] == 0)
					pinakas[x+1][y][z] = 2;
				else                     
					retry = 1;
			}
			
			else if(flag3 ==2){//exw (x-1,y,z-1)
				if (flag4 == 0 && pinakas[x+1][y][z] == 0)
					pinakas[x+1][y][z] = 2;
				else if(flag4 == 0 && pinakas[x][y][z+1] == 0)
					pinakas[x][y][z+1] = 2;
				else                  
					retry = 1;
			}
			
			else if(flag3==3){  //exw (x-1, y, z+1) 
				if(flag4 == 0 && pinakas[x+1][y][z] == 0)
					pinakas[x+1][y][z] = 2;
				else if(flag4 == 1 && pinakas[x][y][z-1] == 0)
					pinakas[x][y][z-1] = 2;
				else                   
					retry = 1;
			}
			
			else if(flag3==4){  //exw (x+1,y-1,z)
				if(flag4 == 0 && pinakas[x-1][y][z] == 0)
					pinakas[x-1][y][z] = 2;
				else if(flag4 == 1 && pinakas[x][y+1][z] == 0)
					pinakas[x][y+1][z] = 2;
				else                    
					retry = 1;
			}
			
			else if(flag3==5){  //exw (x+1, y+1, z)
				if(flag4 == 0 && pinakas[x][y-1][z] == 0)
					pinakas[x][y-1][z] = 2;
				else if(flag4 == 1 && pinakas[x-1][y][z] == 0)
					pinakas[x-1][y][z] = 2;
				else                
					retry = 1;
			}
			
			else if(flag3==6){  //exw (x+1, y, z-1)
				if(flag4 == 0 && pinakas[x-1][y][z] == 0)
					pinakas[x-1][y][z] = 2;
				else if(flag4 == 1 && pinakas[x][y][z+1] == 0)
					pinakas[x][y][z+1] = 2;
				else                 
					retry = 1;
			}
			else if(flag3==7){  //exw (x+1, y, z+1)
				if(flag4 == 0 && pinakas[x][y][z-1] == 0)
					pinakas[x][y][z-1] = 2;
				else if(flag4 == 1 && pinakas[x-1][y][z] == 0)
					pinakas[x-1][y][z] = 2;
				else                 
					retry = 1;
			}
			else if(flag3==8){  //exw (x, y-1, z-1)
				if(flag4 == 0 && pinakas[x][y+1][z] == 0)
					pinakas[x][y+1][z] = 2;
				else if(flag4 == 1 && pinakas[x][y][z+1] == 0)
					pinakas[x][y][z+1] = 2;
				else                    
					retry = 1;
			}
			else if(flag3==9){  //exw {x,y-1,z+1)
				if(flag4 == 0 && pinakas[x][y+1][z] == 0)
					pinakas[x][y+1][z] = 2;
				else if(flag4 == 1 && pinakas[x][y][z-1] == 0)
					pinakas[x][y][z-1] = 2;
				else                    
					retry = 1;
			}
			
			else if(flag3==10){  //exw (x, y+1, z-1)
				if(flag4 == 0 && pinakas[x][y-1][z] == 0)
					pinakas[x][y-1][z] = 2;
				else if(flag4 == 1 && pinakas[x][y][z+1] == 0)
					pinakas[x][y][z+1] = 2;
				else                     
					retry = 1;
			}
			else if(flag3==11){  //y+1 ,z+1
				if(flag4 == 0 && pinakas[x][y-1][z] == 0)
					pinakas[x][y-1][z] = 2;
				else if(flag4 == 1 && pinakas[x][y][z-1] == 0)
					pinakas[x][y][z-1] = 2;
				else                     
					retry = 1;
			}
			
			else if(flag3==12){  //exw x-2
				if(pinakas[x+1][y][z] == 0)
					pinakas[x+1][y][z] = 2;
				else
					retry = 1;
			}
			else if(flag3==13){//exw x+2
				if(pinakas[x-1][y][z]==0)
					pinakas[x-1][y][z] = 2;
				else
					retry = 1;
			}
			else if(flag3==14){ // exw y-2
				if(pinakas[x][y+1][z] == 0)
					pinakas[x][y+1][z] = 2;
				else
					retry = 1;
			}
			else if(flag3==15){  //exw y+2
				if(pinakas[x][y-1][z]==0)
					pinakas[x][y-1][z] = 2;
				else
					retry = 1;
			}
			else if(flag3==16){ //exw z-2
				if(pinakas[x][y][z+1]==0)
					pinakas[x][y][z+1] = 2;		
				else
					retry = 1;
			}	
			else if(flag3 == 17){ //exw z+2
				if(pinakas[x][y][z-1] == 0)
					pinakas[x][y][z-1] = 2;		
				else
					retry = 1;
			}
		}
	}
	pinakas[x][y][z] = 1;
	
	
	*xp = x;
	*yp = y;
	*zp = z;
	
}

void manhattan1(int x, int y, int z, int fd1){               //------------kinhsh kefaliou-------------
	int flag5,i, retry = 1, tempx = x, tempy = y, tempz = z;
	
	while(retry) {
		
		x = tempx;
		y = tempy;
		z = tempz;
		flag5 = (rand()/(RAND_MAX/6));
			
		switch(flag5){	
			case 0:
				x = tempx - 1;
				break;
			case 1:
				x = tempx + 1;
				break;
			case 2:
				y = tempy - 1;
				break;
			case 3:
				y = tempy + 1;
				break;
			case 4:
				z = tempz + 1;
				break;
			case 5:
				z = tempz - 1;
				break;
			default:
				break;
		}
		
		if(x>=1 && x<=N && y>=1 && y<=N && z>=1 && z<=N && pinakas[x][y][z] == 0){
			pinakas[x][y][z] = 3;
			retry = 0;
		
			fidi[fd1][0].x = x;
			fidi[fd1][0].y = y;
			fidi[fd1][0].z = z;
			
			swma1(fidi[fd1][0].x,fidi[fd1][0].y,fidi[fd1][0].z, fd1);
		}
		
	}
}

void move(){
	
	int i,j,k1,s;
	int x,y,z;
	if(button%2==0)
		return;
	
	for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				for(k1=1;k1<=N;k1++)
					pinakas[i][j][k1] = 0;
			}	
	}
	for(fd1=0; fd1<fd; fd1++)
		manhattan1(fidi[fd1][0].x,fidi[fd1][0].y,fidi[fd1][0].z, fd1);
	
	
}

void display(){    //kanei draw to parathiro.soy zwgrafizei oti theleis

	int i,j, k1;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		//clear screen
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);	
	//glNormal3f(0.5f,0.5f,0.5f);//edw fwtizei kai to plegma kai ton kubo!
	if(butg%2==0)
		plegma();
	DrawCube1();
	Draw_SphereCenter();
	if(button%2!=0){
		move();
		usleep( speed );
	}
	glutSwapBuffers();	
}

void Resize(int width, int height){ 
	
	width=WIDTH;
   	height=HEIGHT;	 
    
   	float ratio=1.0*(width/height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();                    //FORTWNEI TO MONADIAIO PINAKA     
    gluPerspective(40,ratio,1,1000);    		
	glMatrixMode(GL_MODELVIEW);          //METAKINEI TA ANTIKEIMENA STHN OTHONH
	glLoadIdentity();
	float pos = ((N*1.0)/2.0);
	gluLookAt(pos,pos,zpos,       //THESI
       		 pos,pos,0.0,           //POU KOITAZEI H KAMERA
	  		 0.0,1.0,0.0);          //PERISTROFH KAMERAS
	  
   	glRotatef(spin,0.0,1.0,0.0);     //PERISTROFH GURW APO TON AKSONA Y
	glRotatef(spinx,1.0,0.0,0.0);     //PERISTROFH GURW APO TON AKSONA X			
}

void special_keys(int keys,int x,int y){
	switch(keys){

       case GLUT_KEY_F1: 
       	fullscreen=!fullscreen;
       
       	if(fullscreen)
			glutFullScreen();
       else
			glutReshapeWindow(WIDTH,HEIGHT);
       break;
      case GLUT_KEY_UP :	//zoom in
       zpos++;
       break;

      case GLUT_KEY_DOWN : //zoom out
       	 zpos--;
         break;
      case GLUT_KEY_LEFT:	//rotate left
	   	 spin++;
		 break;
      case GLUT_KEY_RIGHT:  //rotate right
	  	 spin--;	  	 
		 break;
	  case GLUT_KEY_F2:	  //rotate down
	     spinx++;
		 break;
      case GLUT_KEY_F3:		//rotate up
		 spinx--;
		 break;
	  case GLUT_KEY_F5:
		 initSpot1();
	  	 break;
	  case GLUT_KEY_F6:
		 initSpot2();
	  	 break;
	  case GLUT_KEY_F7:
		 initSpot3();
	  	 break;
  	  case GLUT_KEY_F8:
		 initSpot4();
	  	 break;
	  case GLUT_KEY_F9:
		 initSpot5();
	  	 break;
	  case GLUT_KEY_F10:
		 initSpot6();
	  	 break;
	  case GLUT_KEY_F11:
		 initSpot7();
	  	 break;										  
       default: break;
       
	}
	Resize(WIDTH,HEIGHT);
	display();
}

void idle(){
	display();
}
void processNormalKeys(unsigned char key, int x, int y) {
	int count;
	count = 100;
	if (key == 27)//einai to esc
	exit(0);
	
    if(key == 32)//einai to space
	{	
		button++;
		idle();
	}
	if(key == 103)//se emas einai to =(kanonika einai to +)
		speed -= 150000 ;	
	
	if(key == 45)//einai to -
		speed += 150000;
	
	if(key == 'g')
		butg++;
	Resize(WIDTH,HEIGHT);
	display();
}


int main(int argc, char **argv) {   
	srand(time(NULL));
	int len = 0;
	int i,j,k1;
	cout<<"dwse to megethos tou plegmatos:"<<endl;
	cin>>N;
	/*Dhmiourgoume ton pinaka pou 8a exei 0,1,2 sumfwna me to N tou plegmatos*/
	pinakas = new int**[N+1];

	for(i=0;i<N+1;i++){
		pinakas[i] = new int*[N+1];	
		for(j=0;j<N+1;j++)
			pinakas[i][j] = new int[N+1];

	}

	for(i=0;i<N+1;i++){
		for(j=0;j<N+1;j++){
			for(k1=0;k1<N+1;k1++)
				pinakas[i][j][k1] = 0;
		}
	}

	cout<<"Dwse ton arithmo twn fidiwn:"<<endl;
	cin>>fd;
	fidi.resize(fd);
	cs1 = (rand()/(RAND_MAX/255));//dialegei tuxaia xrwmata gia tis sfaires
	cs2 = (rand()/(RAND_MAX/255));
	cs3 = (rand()/(RAND_MAX/255));
	cc1 = (rand()/(RAND_MAX/255));//dialegei tuxaia xrwmata gia tous kubous
	cc2 = (rand()/(RAND_MAX/255));
	cc3 = (rand()/(RAND_MAX/255));

	for(fd1=0; fd1<fd; fd1++){	
		cout<<"dwse to megethos tou "<<fd1+1<<"ou fidiou:"<<endl;
		cin>>meg;
		while (len!=1){
			cout<<"dwse to o(---x---)"<<endl;
			cin>>o;
			cout<<"dwse to k(---y---)"<<endl;
			cin>>k;
			cout<<"dwse to d(---d---)"<<endl;
			cin>>d;
			len = 1;
			if (o <= 0 || k <= 0 || d >= 0 || o>N || k>N || d<-N){
				cout<<"oi suntetagmenes einai lathos!!!"<<endl;
				len = 0;
			}
		}		
		len = 0;
		pinakas2(fd1);
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT); 
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Homework 1");
	InitGL(); 
	
	//glutDisplayFunc(display1);		
	glutDisplayFunc(display);
  	glutReshapeFunc(Resize);
	glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(special_keys);
	glutIdleFunc(idle);
  	glutMainLoop();  
  	return 0;
}
