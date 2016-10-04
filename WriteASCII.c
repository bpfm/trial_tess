/*====================================================================================================*/

void WriteASCII2D(int n_points,float allpoints[n_points][2],char filename[]) {

  int i;
  FILE *fp;

  fp = fopen(filename,"w");

  for(i=0;i<n_points;i++) {
    fprintf(fp,"%f %f\n",allpoints[i][0],allpoints[i][1]);
  }  
  fclose(fp);
}

/*====================================================================================================*/
