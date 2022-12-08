#include <iostream>
#include<math.h>
using namespace std;

double dist(double x1,double y1,double x2,double y2){
	double m=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	return sqrt(m);
}

int main(int argc, char** argv){
	double a,b,c,d; 
	cout<<"Input:";
	cin>>a>>b>>c>>d; 
	cout<<"Output:"<<dist(a,b,c,d);
	return 0;
}
