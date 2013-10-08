#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

const int SIZE = 10000;

void printTime()
{
      time_t rawtime;
      struct tm * timeinfo;

      time (&rawtime);
      timeinfo = localtime (&rawtime);
      printf ("Current local time and date: %s", asctime(timeinfo));
}

typedef struct Point
{
    double x;
    double y;
    Point()
    {
        x = (rand()%100000+1)/100000.0;
        y = (rand()%100000+1)/100000.0;
    }
    void print(){
        cout << "("<<x<<","<<y<<")"<<" ";
    }
}Point;

bool x_compare(Point p,Point q)
{
     return p.x<q.x;
}

bool y_compare(Point p,Point q)
{
     return p.y<q.y;
}

double dis(Point p,Point q)
{
    return sqrt(pow(p.x-q.x,2.0)+pow(p.y-q.y,2.0));
}

double minPair(Point *p,int n)
{     
     if(n==2)
     {
         //p[0].print();
         //p[1].print();
         //cout <<dis(p[0],p[1]) << endl;
         return dis(p[0],p[1]);
     }
     else if(n>2)
     {
         sort(p,p+n,x_compare);
         double mid = p[n/2].x;
         if(n%2==0)
             mid = (p[n/2-1].x+p[n/2].x)/2;
         double minLeft = 0;
         double minRight = 0;
         if(n%2==1)
         {
             minLeft = minPair(p,n/2+1);
             minRight = minPair(p+(n/2),n/2+1);
         }
         else
         {
             minLeft = minPair(p,n/2);
             minRight = minPair(p+(n/2),n/2);
         }
        
         double minDist = min(minLeft,minRight);
         sort(p,p+n,x_compare);
         int beg = 0;
         while(beg<n && p[beg].x<=mid-minDist)
             beg++;
         int end = beg;
         while(end<n && p[end].x<mid+minDist)
             end++;
         sort(p+beg,p+end,y_compare);
         double t = 10000.0;
         end--;
         for(int i = beg;i<=end;i++)
         {
             int j = i-6;
             while(j<beg)
                  j++;
             while(j!=i && j<=end && j<=i+6)
             {
                 double d = dis(p[j],p[i]);
                 if(d<t)
                 {
                     t = d;
                 }
                 j++;
             }
         }
         
         return min(min(minLeft,minRight),t);
     }
     
     
     
}

double minPair2(Point *p,int n)
{
    if(n<=1)
        return 0.0;
    else if(n==2)
        return dis(p[0],p[1]);
    else
    {   
        int a, b;
        double min = 100000.0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double t = dis(p[i],p[j]);
                if(t<min)
                {
                    a = i;
                    b = j;
                    min = t;
                }
            }
        }
        //p[a].print();
        //p[b].print();
        return min;
    }
}

int main()
{
    Point *p = new Point[SIZE];
    /*
    for(int i=0;i<SIZE;i++)
        p[i].print();
    cout << endl;
    */
    /*
    sort(p,p+SIZE,x_compare);
    for(int i=0;i<SIZE;i++)
        p[i].print();
    cout << endl;
    */
    
    time_t old,now;
    
    old = time(NULL);
    cout << old <<endl;
    double ret = minPair(p,SIZE);
    cout << ret << endl;
    now = time(NULL);
    cout << now <<endl;
    
    old = time(NULL);
    cout << old <<endl;
    double ret2 = minPair2(p,SIZE);
    cout << ret2 << endl;
    now = time(NULL);
     cout << now <<endl;
    
    getchar();
} 
