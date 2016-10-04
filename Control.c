#include <stdio.h>
#include <stdlib.h>
#include "InCircle.c"
#include "WriteASCII.c"
#include "Structures.c"


/*====================================================================================================*/

int main() {

  int i,j;
  int n_points=10;
  int empty[100];
  int a,b,c;
  int triangles[100][3];
  float allpoints[n_points][2];
  float triangle1[8][2];

  for(i=0;i<n_points;i++) {
    allpoints[i][0] = getrandomfloat();
    allpoints[i][1] = getrandomfloat();
  }

  WriteASCII2D(n_points,allpoints,"all_points.txt");

  for(i=0;i<100;i++) {
    empty[i]=1;
    for(j=0;j<3;j++)
      triangles[i][j] = -1;
  }

  a = (int)(n_points*getrandomfloat());
  b = (int)(n_points*getrandomfloat());
  c = (int)(n_points*getrandomfloat());

  AddTriangle(empty,a,b,c,triangles);

  /*for(i=0;i<100;i++) {
    if(empty[i]==0){
      printf("%d %d %d \n",triangles[i][0],triangles[i][1],triangles[i][2]);
      printf("%f %f %f %f %f %f \n",allpoints[a][0],allpoints[a][1],allpoints[b][0],allpoints[b][1],allpoints[c][0],allpoints[c][1]);
    }
  }*/

  triangle1[0][0]=allpoints[a][0];
  triangle1[0][1]=allpoints[a][1];
  triangle1[1][0]=allpoints[b][0];
  triangle1[1][1]=allpoints[b][1];
  triangle1[2][0]=allpoints[c][0];
  triangle1[2][1]=allpoints[c][1];
  triangle1[3][0]=allpoints[a][0];
  triangle1[3][1]=allpoints[a][1];

  WriteASCII2D(4,triangle1,"triangles.txt");

}
