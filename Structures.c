/*====================================================================================================*/

void AddTriangle(int empty[100],int u,int v,int w,int triangles[100][3]) {
 
  int i;

  for(i=0;i<100;i++) {
    if(empty[i]==1) {
      triangles[i][0]=u;
      triangles[i][1]=v;
      triangles[i][2]=w;
      empty[i]=0;
      break;
    }
  }

  return ;
}

/*====================================================================================================*/

void DeleteTriangle(int empty[100],int u,int v,int w,int triangles[100][3]) {

  int i;

  for(i=0;i<100;i++) {
    if(triangles[i][0]==u && triangles[i][1]==v && triangles[i][2]==w) {
      /* triangles[i][0]=-1;
      triangles[i][1]=-1;
      triangles[i][2]=-1;
      triangles[i][3]=-1;
      triangles[i][4]=-1;
      triangles[i][5]=-1;*/
      empty[i]=1;
    }
  }

  return ;
}

/*====================================================================================================*/

void Adjacent(int u,int v,int w,int triangles[100][3]) {

  int i;

  for(i=0;i<100;i++) {
    if(triangles[i][0]==u && triangles[i][1]==v) {
      w=triangles[i][2];
    }
    if(triangles[i][1]==u && triangles[i][2]==v) {
      w=triangles[i][0];
    }
    if(triangles[i][2]==u && triangles[i][0]==v) {
      w=triangles[i][1];
    }
  }
  
  return ;

}
/*====================================================================================================*/

float Adjacent2Vertex(int u,int triangles[100][3],int adj_plus,int adj_neg) {

  int i;

  for(i=0;i<100;i++) {
    if(triangles[i][0]==u) {
      adj_plus = triangles[i][1];
      adj_neg = triangles[i][2];
    }
    if(triangles[i][1]==u) {
      adj_plus = triangles[i][2];
      adj_neg = triangles[i][0];

    }
    if(triangles[i][2]==u) {
      adj_plus = triangles[i][0];
      adj_neg = triangles[i][1];

    }
  }
  return ;
}


/*====================================================================================================*/

float getrandomfloat() {
  
  float randomfloat;

  randomfloat=(float)rand()/(float)RAND_MAX;

  return randomfloat;

}


