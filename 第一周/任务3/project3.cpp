#include <iostream>
using namespace std; 

int Month1[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int Month2[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int MonthDays(int year,int month){
	if(year%4==0)
		return Month1[month-1];
	else return Month2[month-1];

} 

int main(int argc, char** argv) {
	int ndays,month,year;
	cout<<"Input:";
	cin>>year>>month;
	ndays=MonthDays(year,month);
	cout<<"Output:"<<ndays;
	return 0;
}
