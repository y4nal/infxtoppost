#include <iostream>

#include <string>

#include<stack> // STL stack (Standard template library) stack

using namespace std;


bool isOperator(char op){

if(op=='+' || op=='-' || op=='*' || op=='/' || op=='%' || op=='>')

return true;

else

return false;

}  


double eval(const string & postfix)

{

stack<double> d; // 235/-


for(int i =0 ; i< postfix.length(); i++)


{ 
        if(postfix[i] == ' ')continue;  
          
        
        else if (postfix[i]>='0'&&postfix[i]<='9')  
        {  
            double sum=0;  
              
          double no=0;
            while(postfix[i]>='0'&&postfix[i]<='9')   
            {  
				no=(postfix[i] - 48.0);
                sum = sum * 10 + no; 
                i++;  
				if(i>=postfix.length())break;
            }  
            i--;
              
       
            d.push(sum);  
        }  
          
        else
        {  
            double val1 = d.top();  
						d.pop();
            double val2 = d.top(); 
						d.pop();
            switch (postfix[i])  
            {  
            case '+': d.push( val2 + val1); break;  
            case '-': d.push( val2 - val1); break;  
            case '*': d.push( val2 * val1); break;  
            case '/': d.push( val2/val1); break;  
            case '%': d.push((int) val2 % (int) val1);break;
            }  
        }  
    }  
	double x=d.top();
  
		d.pop();  
		return x;
}  
  

	int Priority(char op) {
	if(op == '*' || op == '/' || op == '%')
		return 100;
	else if (op == '+' || op == '-')
		return 50;
	else if( op == '(')
		return 0;
	return -1;
}


	string infixToPost( const string & exp)
	{
		stack<char> s;
	string output;
		for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == ' ')
			continue;

		if (exp[i]>='0'&&exp[i]<='9') {
			while (exp[i] >= '0'&&exp[i] <= '9')
			{
				output += exp[i++];
				if(i>=exp.length())break;
			}
			
			output += " ";
			i--;
		}

		else if (exp[i] == '(')
			s.push('(');
		else if (exp[i] == ')') {
			while (s.top() != '(') {
				output += s.top();
				s.pop();
			}
			s.pop();
		}
		else {
			while (!s.empty() && Priority(exp[i]) <= Priority(s.top())) {
				output += s.top();
				s.pop();
			}
			s.push(exp[i]);
		}
	}

	while (!s.empty()) {
		output += s.top();
		s.pop();
	}
	return output;
	}

void menu()
{
	cout <<"What Would You Like To Do ?" << endl;
	cout << endl;
	cout << "1.infix to postfix conversion" << endl;
	cout << "2.Enter Infix  Expression to Evaluat it" << endl;
	cout << "3.Exit" << endl;
	
} 

int  main()
{

	int choice;
	do {
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
		string expression;
		cout << "Enter Expression : " << endl;
		cin >> expression;

		

		 infixToPost(expression);

		system("COLOR C");

		cout << "The Postfix of the Expression = " << infixToPost(expression) << endl;

		cout << "--------------------------------------" << endl;

		break; 
		}
		case 2:
			{
			string expression="12/3+(239%10)-50*3";
		cout << "Enter Expression :" << endl;
		cin >> expression;
		cout << "The Postfix of the Expression = " << infixToPost(expression) << endl;
		cout<< "The Expression Evaluation = " << eval(infixToPost(expression))<<endl;

		system("COLOR A");
			cout << "--------------------------------------" << endl;
			break;
			}

		case 3:

			       //////////          /////////////           /\                  \\       //
		         //						     ||	              /  \                  \\     //
	            //							 ||              /    \                  \\   //
   		         //////////                  ||             /      \                  \\ //
		                 //                  ||            /--------\                   //   AT HOME 
				         //                  ||           /          \                 //            
			   	         //                  ||          /            \               //
		      ///////////		             ||         /              \             //
		return 0;

		default: cout << "Error Choice " << endl;

		}

		
	} while (true);
	system("pause");
}
