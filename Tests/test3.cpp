/*
 * <name>
 * <section>
 * <Team>
 * <date>
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


void calculate(double monthPay, double annualInterest, double initial){
  int months;
  months = (log(monthPay) - log(monthPay - (annualInterest/1200.0)*initial))/log(annualInterest/1200 + 1) + 0.5;

  cout<<months<<" months ";
  cout<<"("<<setprecision(2)<<months/12.0 <<" years)";
  cout<< " to pay off this debt with current monthly payment"<<"\n";
}

void calculateFurther(double monthPay, double annualInterest, double initial){
  //greaterMonthly represents a greater monthly pay
  //oriMonthly is the same calculation as the above method
  int oriMonthly = (log(monthPay) - log(monthPay - (annualInterest/1200.0)*initial))/log(annualInterest/1200 + 1) + 0.5;
  monthPay += 10;
  int greaterMonthly= (log(monthPay) - log(monthPay - (annualInterest/1200.0)*initial))/log(annualInterest/1200 + 1) + 0.5;

  cout<<"Did you know if you paid an additional $10 per month.";
  cout<<" You would pay off your loan "<<oriMonthly - greaterMonthly <<" months earlier?";
}

void calculateInterest(double monthPay, double interestRate, double initial){
  double dues = initial;
  double rate = interestRate / 100;
  double totalInterest;
  while(dues > 0){
    double interest = rate / 12 * dues;
    totalInterest += interest;
    dues -= monthPay;
    dues += interest;
  }
  //fixed is used because of werid scientific notation
  cout<<"The total interest paid is $"<<fixed<<trunc(totalInterest)<<" and the total amount you'll pay is $"<<fixed<<trunc(initial + totalInterest)<<endl<<"\n"; 
}


int main(){
  double starting;
  double yearlyInterest;
  double monthlyPay;

  cout<<"promt %: ./calculate2.out"<<endl<<"\n";
  cout<<"** Welcome to the CPSC 1071 Payment Calculator **"<<endl<<"\n";

  cout<<"Enter the principle amount:";
  cin>>starting;

  cout<<"Enter the annual interest rate (in %):";
  cin>>yearlyInterest;

  cout<<"Enter the monthly payment:";
  cin>>monthlyPay;

  cout<<endl;
  cout<<"Calculating..."<<endl<<"\n";

  calculate(monthlyPay, yearlyInterest, starting);
  cout<<"\n";
  calculateFurther(monthlyPay, yearlyInterest, starting);
  cout<<endl<<"\n";
  calculateInterest(monthlyPay, yearlyInterest, starting);
  cout<<"\n"
  cout<<"prompt %";
}
