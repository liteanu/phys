#include <iostream>
#include <cmath>


double factorial(int n)
{
    if(n>1)
        return n*factorial(n-1);
    else
        return 1;
}




using namespace std;

double nCr(double l, int k)

{ 
   double  val=1; 
    for (int i=0; i<k; ++i)
    {
        val*=(l-i);
    }
    double value=val/factorial(k); 
    return value;
}



double PCP(int l, int m, int k)
{
    double u= pow(-1,m) * pow(2,l) * factorial(k)/factorial(k-m)*nCr(l,k)*nCr(double(l+k-1)/2, l);    
    return u;
}




int main()
{
  int m=0;
  for (int l=0; l<10; l++) {
	for (int m=0; m<=l; m++) {
	    cout << "(1-x^2)^" << m << "/2 * ("; 
   	    for(int k = m; k <= l; k++) { 
     	      if (k>m) cout << "+ "; 
     	      cout << PCP(l, m, k) << "* x^" << k-m << " "; 
   	    } 
   	    cout << ")" <<  endl;  
 	} 
  }
} 


