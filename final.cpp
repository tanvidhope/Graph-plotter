#include <graphics.h>
#include <math.h>
#include<stdio.h>

float scale(float min,float max,float minval,float maxval,float value){// scaled the values from one range to another range
	float in = minval;
	float temp = maxval - minval;
	if(max - min == 0){
		return value;
	}
	temp = temp * (value - min);
	temp = temp / (max - min);
	in = in + temp;
	return in;
}

float getpolyval(float poly[], float val){// calculates polynomial value for an entered X
	float y = 0;
	for(int j = 0; j < 6; j++){
		y+=(poly[j] * pow(val,j));
	}
	return y;
}

void drawPoly(float poly[], float x1, float x2, float y1, float y2){
	float max = getmaxx();//screen width
  	float maxy = getmaxy();//screen height
  	float minval = getpolyval(poly,x1);//polynomial value based on min screen height
  	float maxval = getpolyval(poly,x2);// polynomial value based on max screen height
  	for(float i = x1; i < x2;i+=0.01){//running loop from negative width to positive width
  		float y = getpolyval(poly, i);
  		float scaledY = scale(y1, y2,maxy,0, y);//scaling down to screen height
  		float scaledX = scale(x1,x2 , 0, max, i);// scaling down to screen width
  		if(scaledY > 0 && scaledY < maxy)
			putpixel(scaledX,scaledY,RED);//if within screen, print
			setcolor(BLUE);
          float c=1.0;


          if(fmod(i,c)==0.);//to highlight coordinates with integral values of x
			{

			circle(scaledX,scaledY,1);
			}

  	}
  	//to draw axes
    setcolor(WHITE);
  	float scaledY = scale(y1, y2,maxy,0, 0);
  		float scaledX = scale(x1,x2 , 0, max, 0);
  	 line(scaledX,scaledY,scaledX,getmaxy());
  	 line(scaledX,scaledY,scaledX,0);
  	 line(scaledX,scaledY,0,scaledY);
  	 line(scaledX,scaledY,getmaxx(),scaledY);
}

int main() {
printf("enter degree of polynomial \t");
int n;
scanf("%d", &n);
  float poly[6];
  for( int i = 0; i <n+1; i++){
  	float temp;
  	printf("Enter coefficient of term with degree %d: ",i);
  	scanf("%f",&temp);
  	poly[i] = temp;
  }
  float x1,x2, y1,y2;
  printf("Enter x1 and x2 ;  y1 and y2( i.e for range you want to see on graph) \n ");
  scanf("%f %f %f %f",&x1,&x2,&y1,&y2);
  int gd = DETECT, gm;
  initgraph( & gd, & gm, "C:\\TurboC3\\BGI");// Initialize graph
  drawPoly(poly, x1, x2,y1, y2);// Draw from polynomial
  getch();
  closegraph();
  return 0;
}
