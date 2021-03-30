#include <stdio.h>

double racineCarre(double x){
    double a,b,m,n;
  if(x==0.0) {
     return 0.0;
  } else {
     m=1.0;
     n=x;
     while(n>=2.0) {
        n=0.25*n;
        m=2.0*m;
     }
     while(n<0.5) {
        n=4.0*n;
        m=0.5*m;
     }
     a=n;
     b=1.0-n;
     do {
        a=a*(1.0+0.5*b);
        b=0.25*(3.0+b)*b*b;
     } while(b>=1.0E-15);
     return a*m;
  }
}

struct Point_s { // Un point en 2D
    double x;  // Sa coordonnée x
    double y;  // Sa coordonnée y
};

struct Segment_s {
    struct Point_s p1;
    struct Point_s p2;
};

struct Triangle_s {
    struct Point_s points[3];
};

void initialiserSegment(struct Segment_s *segment, double x1, double y1, double x2, double y2){
    segment->p1.x=x1;
    segment->p1.y=y1;
    segment->p2.x=x2;
    segment->p2.y=y2;
}

double longueurSegment(const struct Segment_s *segment){
   double l;
   double dx=segment->p2.x-segment->p1.x;
   double dy=segment->p2.y-segment->p2.y;
   l=racineCarre(dx*dx+dy*dy); 
   return l;
}

void initialiserTriangle(struct Triangle_s *triangle, double x1, double y1, double x2, double y2, double x3, double y3){
     triangle->points[0].x=x1;
     triangle->points[0].y=y1;
     triangle->points[1].x=x2;
     triangle->points[1].y=y2;
     triangle->points[2].x=x3;
     triangle->points[2].y=y3;
}

double perimetreTriangle(const struct Triangle_s *triangle) {
     double p=0;     
     struct Segment_s seg1={triangle->points[0],triangle->points[1]};
     struct Segment_s seg2={triangle->points[1],triangle->points[2]};
     struct Segment_s seg3={triangle->points[2],triangle->points[0]}; 
     p=longueurSegment(&seg1)+longueurSegment(&seg2)+longueurSegment(&seg3);
     return p;
}    

int main(void) {
     double x1=2.3, x2=4.4, y1=5.6, y2=1.7;
     struct Segment_s seg;
     initialiserSegment(&seg,x1, y1, x2, y2); 
     printf("%f\n", seg.p1.x);
     printf("%f\n", seg.p1.y);
     double l= longueurSegment(&seg);
     printf("%f\n", l);
     double x3=4.6 , y3=3.7;
     struct Triangle_s triangle;     
     initialiserTriangle(&triangle, x1, y1, x2, y2, x3, y3);
     printf("%f\n", triangle.points[2].x);
     printf("%f\n", triangle.points[2].y);
     double p=perimetreTriangle(&triangle);
     printf("%f\n", p);     
     return 0;
}
 
