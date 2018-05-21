#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<fstream>
#include<vector>

using namespace std;

float f(float x, float y);

float f(float x, float y, float x2, float y2)
{
    return ((x-x2)*(x-x2))+((y-y2)*(y-y2));
}

int main(){

vector <double> X,Y;
double x,y;

// import data
ifstream data("Canal_ionico.txt");
while (data>>x>>y)
{
X.push_back(x);
Y.push_back(y);
}

  srand(time(NULL));

  int n;
  n=10000;

  float* listax;
  float* listay;
  listax = new float[n];
  listay = new float[n];
  float* listar;
  listar = new float[n];

  listax[0]= ((rand()%(2000)) /100.0 )-5.0;
  listay[0]= ((rand()%(2000))/100.0 )-5.0;

//llenar el primer guess de r
float rmin=f( listax[0], listay[0],  X[0], Y[0]);

for(int i=0; i<Y.size();i++)
{
 float rmin1=f( listax[0], listay[0], X[i], Y[i]);
 if(rmin>rmin1)
{
rmin = rmin1;
}
}
listar[0]=sqrt(rmin);

float xnuevo;
float ynuevo;

//rellena la lista de la funcion inicial
for(int i=1; i<n;i++)
{
float xnuevo =( (rand()%(2000)) / 100.0 )-5;
float ynuevo =( (rand()%(2000)) / 100.0 )-5;
rmin=f( xnuevo, ynuevo, X[0], Y[0]);
for(int t=0; t<Y.size();t++)
{
 float rmin1=f( xnuevo, ynuevo, X[t], Y[t]);
if(rmin>rmin1)
{
rmin = rmin1;
}
}
rmin=sqrt(rmin);

float alph = rmin/listar[i-1];

if(alph>=1.0)
{
listar[i]=rmin;
listax[i]=xnuevo;
listay[i]=ynuevo;
}

else
{
float beta=(rand()%100)/100.0;

if(beta<=alph)
{
listar[i]=rmin;
listax[i]=xnuevo;
listay[i]=ynuevo;
}

else
{
listar[i]=listar[i-1];
listax[i]=listax[i-1];
listay[i]=listay[i-1];
}

}
cout<<" "<<listar[i]<<" "<<listax[i]<<" "<<listay[i]<<" "<<endl;
}
  return 0;
}



