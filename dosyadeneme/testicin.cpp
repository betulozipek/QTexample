#include <iostream>
using namespace std;
int main()
{
   setlocale(LC_ALL,"Turkish"); //Türkçe karakter
   int s1,s2,ort;
   cout<<"1. Sayıyı Girin : ";
   cin>>s1;
   cout<<"2. Sayıyı : ";
   cin>>s2;
   ort=(s1+s2)/2;
   cout<<"Sayıların Ortalaması : "<<ort;
}
