/*====================================================================================================*/

float DeterminantCalc(float sqarray3[3][3]) {

  int i,j;
  float det=0.0;

  for(i=0;i<3;i++)
    det = det + (sqarray3[0][i]*(sqarray3[1][(i+1)%3]*sqarray3[2][(i+2)%3]-sqarray3[1][(i+2)%3]*sqarray3[2][(i+1)%3]));

  return det;

}

/*====================================================================================================*/

int Orient2D(float a[2],float b[2],float c[2]) {

  float orientarray[3][3];
  float det;
  
  orientarray[0][0]=a[0];
  orientarray[0][1]=a[1];
  orientarray[0][2]=1.0;

  orientarray[1][0]=b[0];
  orientarray[1][1]=b[1];
  orientarray[1][2]=1.0;

  orientarray[2][0]=c[0];
  orientarray[2][1]=c[1];
  orientarray[2][2]=1.0;

  det=DeterminantCalc(orientarray);

  if(det<0.0) {
    printf("Negative\n");
    return -1;
  }
  if(det==0.0) {
    printf("Collinear\n");
    return 0;
  }
  if(det>0.0) {
    printf("Positive\n");
    return 1;
  }
}

/*====================================================================================================*/

int InCircleTest(float a[2],float b[2],float c[2],float d[2]){

  int i;
  float circlearray1[4][4];
  float circlearray2[3][3];
  float det;

  circlearray1[0][0]=a[0];
  circlearray1[0][1]=a[1];
  circlearray1[0][2]=(a[0]*a[0]+a[1]*a[1]);
  circlearray1[0][3]=1.0;

  circlearray1[0][0]=b[0];
  circlearray1[0][1]=b[1];
  circlearray1[0][2]=(b[0]*b[0]+b[1]*b[1]);
  circlearray1[0][3]=1.0;

  circlearray1[0][0]=c[0];
  circlearray1[0][1]=c[1];
  circlearray1[0][2]=(c[0]*c[0]+c[1]*c[1]);
  circlearray1[0][3]=1.0;

  circlearray1[0][0]=d[0];
  circlearray1[0][1]=d[1];
  circlearray1[0][2]=(d[0]*d[0]+d[1]*d[1]);
  circlearray1[0][3]=1.0;

  for(i=0;i<3;i++) {
    circlearray2[i][0]=circlearray1[i][0]-circlearray1[3][0];
    circlearray2[i][1]=circlearray1[i][1]-circlearray1[3][1];
    circlearray2[i][2]=circlearray2[i][0]*circlearray2[i][0]+circlearray2[i][1]*circlearray2[i][1];
  }
  
  det=DeterminantCalc(circlearray2);

  if(det<0.0) {
    printf("Outside Circle\n");
    return -1;
  }
  if(det==0.0) {
    printf("On Circle\n");
    return 0;
  }
  if(det>0.0) {
    printf("Inside Circle\n");
    return 1;
  }
}

/*====================================================================================================*/

