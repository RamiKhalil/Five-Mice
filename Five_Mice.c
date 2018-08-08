#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
//create a csv file called book 3 to write in it and do a scatter plot


double unitdirectionx (double [] , double [],int i); //first function prototype
double unitdirectiony (double [] , double [],int i); //second function prototype

int main(){ //start of main
	int i;
	double x[5]={0,-sin(2*PI/5), -sin(4*PI/5), -sin(6*PI/5), -sin(8*PI/5)} ; //initial ordinates
  double y[5]={1,cos(2*PI/5), cos(4*PI/5), cos(6*PI/5), cos(8*PI/5)} ; //initial coordinates

	FILE *file= fopen("book3.csv","w");//opening the csv file to write in it

	while(sqrt(pow(y[2]-y[1],2) + pow(x[2]-x[1],2))> 0.01){//loop breaks when the distance reaches 0.001
	 for(i=0;i<5;i++)
		 {
		 fprintf(file,"%lf,%lf\n", x[i], y[i]);//printing to the csv file
		 }
   for(i=0; i<5; i++)
	  {
		 x[i]=x[i]+0.01*unitdirectionx(x,y,i);//new position of x in the direction of the neighboring mouse
	   y[i]=y[i]+0.01*unitdirectiony(x,y,i);//new position of y in the direction of the neighboring mouse
    }
	}
 fclose(file);//closing the csv file
	return 0;} //end of main


double unitdirectionx(double x[], double y[],int i){
	double p=x[(i+1)%5]-x[i]/sqrt(pow((x[(i+1)%5]-x[i]),2)+pow((y[(i+1)%5]-y[i]),2));
  return p;
}
double unitdirectiony(double x[], double y[], int i){
	double z=y[(i+1)%5]-y[i]/sqrt(pow((x[(i+1)%5]-x[i]),2)+pow((y[(i+1)%5]-y[i]),2));
	return z;
}

