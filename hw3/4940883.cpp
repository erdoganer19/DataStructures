#include <iostream>
#include <queue>
#include <QStack.h>


using namespace std;

void QStack::push(int x)
{   
    int size;
    int temp;
    size=main.size();
     if(!main.empty()){
        main.push(x);
        for(int i=0;i<size;i++){
            temp=main.front();
            main.pop();
            main.push(temp);
        }
                      }
     else{
         main.push(x);
     }
}

void QStack::pop()
{
    if(main.empty()){
        cout<<"Stack is empty\n"<<endl;   
    }
    else{
        int front=main.front();
        cout<<front<<" is popped\n";
        main.pop();
    }

  
    
}

void QStack::printStack()
{
    if (main.empty())
        return;

    int x;
    for(unsigned long int i=0;i<main.size();i++)
    {
        x = main.front();
        main.pop();
        cout << x << ' ';
        main.push(x);
    }
}