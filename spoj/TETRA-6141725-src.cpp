#include <cmath>
#include <iostream>

using namespace std;
double aa(double a, double b, double c) {
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main() {
    int T;
    cin>>T;
    while (T--) {
        double a,b,c,d,e,f;
        scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f);
        double area = aa(a,b,d)+aa(a,c,e)+aa(b,c,f)+aa(d,e,f);
        a*=a;b*=b;c*=c;d*=d;e*=e;f*=f;
        double ans = a*f*(-a+b+c+d+e-f)+b*e*(a-b+c+d-e+f)+c*d*(a+b-c-d+e+f)-(a+f)*(b+e)*(c+d)/2.0;
        double a1 = ans -(a-f)*(b-e)*(c-d)/2.0;
        double a2 = ans +(a-f)*(b-e)*(c-d)/2.0;
        if (a1>0) ans=a1;
        if (a2>0) ans = a2;
        ans = sqrt(ans/144.0);
        // ans is the volume of the tetra
        printf("%.4f\n",3*ans/area);
    }
}
