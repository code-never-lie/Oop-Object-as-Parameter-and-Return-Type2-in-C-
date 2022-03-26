OBject as Parameter to function

#include<iostream.h> 
#include<string.h> 

class Car {
private:
 int price;
public :
  Car() { }
  Car(int pr) {price=pr;}
  int getPrice() { return price;}
  void setPrice(int pr){price=pr;}

};


bool comparePrice (Car x,Car y) {
 if (x.getPrice()==y.getPrice())
      return true;
 else
      return false;

}
void paint(Car *p){
cout<<" Paint car \n";
int t=p->getPrice();
p->setPrice(t+(t*0.05));

}
void main (){
Car c1(1000);
Car c2(5000);
if (comparePrice(c1,c2))
    cout<<"Equal Price";
else
    cout<<"different price";
}
.............................................
Parameter Passing
1- by value
2- by reference

By Reference

void main (){
Car c1(1000);
cout<<"Before Paint Price="<<c1.getPrice()<<endl;
paint(&c1);
cout<<"After Paint Price="<<c1.getPrice();


}
............................................

_ In CS Community independent functions are highly 
 discourged
- Each function should belongs to some class
- Mixture of structured and OOP are not acceptable
...............................................
  Pure Object Oriented Code
#include<iostream.h> 
#include<string.h> 

class Car {
private:
 int price;
public :
  Car() { }
  Car(int pr) {price=pr;}
  int getPrice() { return price;}
  void setPrice(int pr){price=pr;}
  bool comparePrice(Car p) {
  if (price==p.getPrice())
      return true;
 else
      return false;
  
  }
  void paint( ) {
   cout<<" Paint car \n";
   //int t=getPrice();
   //setPrice(t+(t*0.05));
   price=price+(price*0.05);   
  }

};

void main(){
Car c1(1000);
Car c2(5000);
if (c1.comparePrice(c2))
    cout<<"Equal Price"<<endl;
else
    cout<<"different price"<<endl;

cout<<"Before Paint Price="<<c1.getPrice()<<endl;
c1.paint();
cout<<"After Paint Price="<<c1.getPrice()<<endl;
}

................................................
            OBject as Return Type
............................................
car f(){
  car c;
  return c;
}

................................................
Problem : A production Unit produce Cars

class ProductionUnit {
public:

Car produce(int price) {
   Car c(price);
   return c;
}
};

void main () {
ProductionUnit pu;

Car c=pu.produce(1000);

cout<<c.getPrice();

}
.............................................

Q - Develop yout own Integer Class
   with add Function

class MyInteger{
private : 
    int d;
public :
 MyInteger()  {}
 MyInteger(int d)  {this->d=d;}
 int getD() {return d;}
 void setD(int d){ this->d=d;}
 MyInteger add(MyInteger p ){
     int t=d +p.d;
     MyInteger temp(t);
     return temp;
}
};
void main () {
MyInteger v1(2),v2(3),v3;
v3=v1.add(v2);//  v3=v1+v2;;
cout<<v3.getD();//5
}
...............................................
Q Develop Matric class which will add and multiply Matrices
class Matrix {
private:
  int m[2][2];
public :
   Matrix( ) { 
         for (int row=0;row<2;row++)
           for (int col=0;col<2;col++)
                m[row][col]=0;
   }
void getData(){
      for (int row=0;row<2;row++)
           for (int col=0;col<2;col++)
                cin>>m[row][col];

}
void printData(){
      for (int row=0;row<2;row++){
           for (int col=0;col<2;col++)
                cout<<m[row][col]<<" ";
            
           cout<<endl;
       }
}
 Matrix add(Matrix p){
  Matrix temp;
  for (int row=0;row<2;row++)
   for (int col=0;col<2;col++)
    temp.m[row][col]=m[row][col]+p.m[row][col];
 return temp;
}
Matrix mul(Matrix p){
  Matrix temp;
  for (int row=0;row<2;row++)
   for (int col=0;col<2;col++)
     for (int com=0;com<2;com++)
    temp.m[row][col]=temp.m[row][col]+m[row][com]*p.m[com][col];
 return temp;
}
};

void main(){
Matrix  a,b; 
a.getData();
b.getData();
Matrix sum;
sum=a.add(b);
sum.printData();

}
..............................................
                  Matrix Multiply
..............................................
void main(){
Matrix  a,b; 
a.getData();
b.getData();
Matrix c;
c=a.mul(b);
c.printData();

}
...............................................
              How to Multiply Matices
...............................................
a=2x3       b=3 x4

c= 2x4    Total Multiplication= 2 x3 x4=24

     for i  1  to  row a
        for j 1 to  col b
           for k 1 to common(cola)
              c[i,j]=c[i,j]+a[i,k]*b[k,j]
                
.................................................

Q Improved Matrix Class

Matrix a(2,3);
to be continue in next class
......................................

                 Assignment

Develop Rational class with sum and multiply functions

   a=3/2    b=4/2

  c=a+b;
 
  c=7/2


void main () {
Rational a(2,3),b(7,2),c;
c=a.add(b);
c.print();

}
..............................................

Q Improved Matrix Class
- All array are physically flatened
- Two dimesion is only logical view
- Acccesed through Mapping function
- Array name is constant pointer, pointed to       base address of array

int a[2][3];

  0    1   2       Logical View
0 10   20  30
 
1 40   50  60
             Physical View
a
0     1    2      3    4    5  

10     20   30     40  50   60
100    104  108   112  116  120
.........................................
One D
BA+i*sizeofType
..........................................
 a[i][j]        n=3
  a[1][2]=60    n is total no. of cols
   BA+(i*n+j)*sizeofInteger=
      100 +(1*3+2)*4=120
 a[0][0]=10
    Ba+(i*n+j)*size= 100+(0*3+0)*4=100
    
       


 void assign(int row, int col, int value){
     int *p;
     p=a+(row*col+n)*sizeof(int);
     *p=value;

 }
............................................
               Sum Function using Two D
int sum(int a[][3],int r,int c){
int s=0;
  for (int i=0;i<r;i++)
     for (int j=0;j<c;j++)
         s=s+a[i][j]; // error
 return s;
}

void main() {
int a[2][3]={ {10,20,30}
              {40, 50,60}};

int y=sum(a,2,3);
cout<<y;
}
............................................
               Sum Function using One D
   
int sum(int a[],int size){
int s=0;
  for (int i=0;i<size;i++)
              s=s+a[i];
 return s;
}

void main() {
int a[2]={ 10,20}
 

int y=sum(a,2);
cout<<y;
}
.......................................
           Two   Array  Class
.......................................

class TwoDArray {
private :
  int row;
  int col;
  int size;
  int *a;
public :
   TwoDArray(int r, int c){
          row=r;
          col=c;
          size=row*col;
          a=new int[size];
   
   }          
void set(int i, int j , int value){
     //int *p= a+(i*col+j)*sizeof(int);
      a[i*col+j]=value;
     
}
int get(int i, int j){
 return a[i*col+j];
}
Matrix add(Matrix p){
  Matrix temp(row,col);
  for (int i=0;i<row;i++)
   for (int j=0;j<col;j++){
         int t;
        t=get(i,j)+p.get(i,j);                temp.set(i,j,t);
    }
 return temp;
}
Matrix mul(Matrix p){
  Matrix temp;
  for (int i=0;i<row;i++)
   for (int j=0;j<p.col;j++)
     for (int com=0;com<p.row;com++){
               int t;
t=temp.get(row,col)+get(row,com)*p.get(com,col);        temp.set(row,col,t);
 return temp;
}

};

void main () {
TwoDArray ar(2,3);
ar.assign(0,0,10);//a[0]
ar.assign(0,1,20);//a[1]
ar.assign(1,1,50);
cout<<ar.get(1,1);

}
........................................
   Add  two Matrices
...................................

void main(){
class TwoDArray {
private :
  int row;
  int col;
  int size;
  int *a;
public :
   TwoDArray(int r, int c){
          row=r;
          col=c;
          size=row*col;
          a=new int[size];
   
   }          
void assign(int i, int j , int value){
     //int *p= a+(i*col+j)*sizeof(int);
      a[i*col+j]=value;
     
}
int get(int i, int j){
 return a[i*col+j];
}

};

void main () {
TwoDArray ar(2,3);
ar.assign(0,0,10);//a[0]
ar.assign(0,1,20);//a[1]
ar.assign(1,1,50);
cout<<ar.get(1,1);

}
...........................................
             Sum of Two D array
...........................................
void main () {
int row=2;
int col=3;
int value=10;
int sum=0;
TwoDArray ar(row,col);
for(int i=0;i<row;i++)
  for(int j=0;j<col;j++){
        ar.assign(i,j,value);
        sum=sum+ar.get(i,j);
        value=value+10;
   }
cout<<sum<<endl;      

}
...................................
  Improved  Matrix Logic
...................................
class Matrix {
private :
  int row;
  int col;
  int size;
  int *a;
public :
   Matrix(int r, int c){
          row=r;
          col=c;
          size=row*col;
          a=new int[size];
   
   }          
void assign(int i, int j , int value){
     //int *p= a+(i*col+j)*sizeof(int);
      a[i*col+j]=value;
     
}
int get(int i, int j){
 return a[i*col+j];
}

};

void main () {

}






























