//SYCOA8 Mansi Ahir
//Assignment 4
#include<iostream>  
#include<stack>  
using namespace std;  
 
bool IsOperator(char a) //Boolean function for operator
{
    if(a=='+' || a=='-' || a=='*' || a=='/' || a=='^')
    return true;
    else
    return false;
}
bool IsOperand(char a) //Boolean function for operand
{
    if(a>='A' && a<='Z')
    return true;
    else if(a>='a' && a<='z')
    return true;
    else if(a>='0' && a<='9')
    return true;
    else
    return false;
}
int precedence(char a) //Boolean function to define the precedence to the operator
{
    if(a=='+' || a=='-')
    return 1;
    if(a=='*' || a=='/')
    return 2;
    if(a=='^')
    return 3;
    else 
    return 0;
}

bool eqlOrhigher(char a, char b) //Boolean function to check the higher or equal precedence of the two operators in infix expression
{
    int p1=precedence(a);
    int p2=precedence(b);
    if(p1==p2)
    {
        if(a=='^')
        return false;
        else
        return true;
    }
    return (p1>p2 ? true:false);
} 

string convert (string infix) //Boolean function for string conversion
{
  int i;
  char ch;
  string postfix="";
  stack <char> expression;
  expression.push('(');
  infix+=')';
  for(i=0;i<infix.length();i++)
    {
      ch=infix[i];
      if(ch=='(')
        expression.push(ch);
      else if(IsOperand(ch))
        postfix+=ch;
      else if(IsOperator(ch))
      {
        while(!expression.empty() && eqlOrhigher(expression.top(),ch))
          {
            postfix+=expression.top();
            expression.pop();
          }
        expression.push(ch);
      }
      else if(ch==')')
      {
        while(!expression.empty() && expression.top()!='(')
          {
            postfix+=expression.top();
            expression.pop();
          }
        expression.push(ch);
      }
    }
  return postfix;
}

int main()  
{ 
  string infix_exp, postfix_exp;      
  cout<<"\nEnter an infix expression: ";  
  cin>>infix_exp;  
  postfix_exp=convert(infix_exp);  
  cout<<"\nInfix expression: "<<infix_exp;  
  cout<<"\nPostfix expression: "<<postfix_exp;   
  return 0;  
}  
