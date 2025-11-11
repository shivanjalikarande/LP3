
#include <iostream>
using namespace std;

//Write a program non-recursive and recursive program to calculate Fibonacci numbers and analyze the time and space complexity.


//1. Recursive Code
int fibonacci_rec(int n)
{
    if(n <= 1) return n;
    return fibonacci_rec(n-1) + fibonacci_rec(n-2);
}

//2. Non - Recursive Code
int fibonacci_nonrec(int n)
{
    if(n <= 1)
    {
        return n;
    }
    int a = 0;
    int b = 1;
    int c = 0;
    while(n > 1)
    {
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;
}

int main()
{
    int choice = 0;
    char ans;
    do
    {
        int n;
        cout<<"\nEnter the value of n: ";
        cin>>n;
        if(n == 0 || n < 0)
        {
            cout<<"Enter non negative integer"<<endl;
            continue;
        }
        cout<<"\nEnter your choice: \n1.Recursive\n2.Non-recursive\n"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<n<<"th Fibonacci Number: "<<fibonacci_rec(n);
                break;
            case 2:
                cout<<n<<"th Fibonacci Number: "<<fibonacci_nonrec(n);
                break;
            default:
                cout<<"Enter valid choice!"<<endl;
                break;
        }
        cout<<"\nContinue(y/n)? : ";
        cin>>ans;
    }while(ans == 'y');

    cout<<"\n\n***** Thank You !! *****"<<endl;


    return 0;
}
