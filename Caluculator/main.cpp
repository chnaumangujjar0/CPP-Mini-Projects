#include<iostream>
using namespace std;
class Calculator{
    public:
   
   double add(double a,double b){
    return a + b ;
   }

   double subtract(double a,double b){
    return a - b ;
   }

   double divide(double a,double b){
    if(b == 0){
       cout << "Error! Division by zero\n";
       return 0;
    }
    return a / b ;
   }

   double multiply(double a,double b){
    return a * b;
   }
};
// ==== Number 01 input
 double numberInput(){
     double num1;
     cout<<"\n Enter Number 01 : ";
     cin>>num1;
     return num1;
    }

int main(){
    Calculator c;
    double num1,num2;
    double result=0;
    cout<<"\n ==== CALCULATOR====";
    num1 = numberInput();
    while (true)
    {
     
      cout<<"\n Enter Number 02 : ";
      cin>>num2;
      int choice;
      cout<<"\n 1. Addition";
      cout<<"\n 2. Subtraction";
      cout<<"\n 3. Division";
      cout<<"\n 4. Multiplication";
      cout<<"\n 5. New Calculation ";
      cout<<"\n 6. Exit! ";
      cout<<"\n -------------------------";
      cout<<"\n Enter your Choice : ";
      cin>>choice;
      switch (choice)
      {
      case 1:
       result = c.add(num1,num2);
       cout<<"\n Result = "<<result;
       num1=result;
       cout<<"\n Number 1 = "<<num1;
        break;
      case 2:
      result = c.subtract(num1,num2);
      cout<<"\n Result = "<<result;
      num1=result;
      cout<<"\n Number 1 = "<<num1;
      break;
      case 3:
      result =c.divide(num1,num2);
      cout<<"\n Result = "<<result;
      num1=result;
      cout<<"\n Number 1 = "<<num1;
      break;
      case 4:
      result = c.multiply(num1,num2);
      cout<<"\n Result = "<<result;
      num1=result;
      cout<<"\n Number 1 = "<<num1;
      break;
      case 5: 
      cout<<"\n New calculation start";
      num1=numberInput();
      break;
      case 6:
      cout<<"\n Exited !";
      return 0;
      default:
      cout<<"\n Invalid Choice!";
        break;
      }

    }
    return 0;
}