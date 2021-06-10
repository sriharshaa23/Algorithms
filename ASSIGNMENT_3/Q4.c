#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point Point;

struct Point{
    int x,y;
};

float min(float x, float y)
{
    return (x < y)? x : y;
}

float dist(Point p1,Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}


float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

int compX(const void* a,const void* b)
{
     Point *p1 = ( Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compY(const void* a,const void* b)
{
     Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}


float closestPair(Point* p,int n)
{
        if (n <= 3)
        {
            return bruteForce(p, n);
        }
    int m = n/2;
    Point midpoint = p[m];

    float dleft = closestPair(p,m);
    float dright = closestPair(p+m,n-m);

    float mindist = min(dleft, dright);

    Point landr[n];
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(abs(p[i].x - midpoint.x) < mindist)
        {
            landr[k] = p[i],k++;

        }
    }
    float q = mindist;
    qsort(landr ,k,sizeof(Point),compY);

    for(int i=0;i<k;++i)
    {
        for(int j=i+1;j<k && (landr[j].y - landr[i].y)<q;++j)
        {
            if (dist(landr[i],landr[j]) < q)
            {
                q = dist(landr[i],landr[j]);
            }
        }
    }
    return min(mindist,q);
}

float closest(Point p[],int n)
{
    qsort(p, n, sizeof(Point), compX);
    return closestPair(p,n);
}





int main()
{
    Point p[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    float min = closest(p,6);
    printf("%f",min);
    return 0;
}
