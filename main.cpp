#include <iostream>
#include <conio.h>  /* 70 = UP / 80 = DOWN / 75 = LEFT / 77 = RIGHT  */
#include <windows.h>
#include <ctime>
#include "arrayQueueType.h"
#include "arrayListType.h"
#include "arraystackType.h"
#include "linkedListType.h"
#include "orderedLinkedList.h"
#include "unorderedLinkedList.h"
#include "stackLinked.h"
#include <map>


using namespace std;

linkedStackType<int> linkedstack;
stackType<int> arrstack;

void pushRandomArrayLinked()
{
    int st,en,size;
    cout << "Enter the size you want: " ;
    cin >> size;
    cout << "Choose the range of the numbers: ";
    cin >> st >> en;

    for (int i = 0 ; i< size ; i++){
        int element= st+rand()%(en-st+1);
        linkedstack.push(element);
        arrstack.push(element);
    }
}

void pushArrayLinked()
{
    int element;
    cout <<"Enter element to be pushed: " << endl;
    cin >> element;
    linkedstack.push(element);
    arrstack.push(element);
}

void popArrayLinked()
{
    linkedstack.pop();
    arrstack.pop();
}

void popElementArrayLinked()
{
    int element;
    cout << "Enter the number of elements to delete: " << endl;
    cin >> element;
    linkedstack.popElments(element);
    arrstack.popElements(element);
}

void clearArrayLinked()
{
    linkedstack.initializeStack();
    arrstack.initializeStack();
}

void displayArrayLinked()
{
    linkedstack.print();
    arrstack.print();
}

void sorted()
{

}


// int main (){
//     pushArrayLinked(); 
//     pushArrayLinked();
//     pushArrayLinked();
//     pushArrayLinked();
//     pushArrayLinked();
//     popArrayLinked(); 
//     popElementArrayLinked();
//     displayArrayLinked(); 
//     arr.order();
// }

void Stack_Playground()
{
	// static bool creation_flage=0 ;
	// if(!creation_flage++)
	// {
	// 	color(5);
	// 	cout<<"An integer Array based list, a linked list, and a sorted linked list have been created."<<endl<<endl ;
	// }

	char choice ;
	do{
		// color(5);
		cout<<"What are the operations that you need to do ?"<<endl ;
		// color(); 
		
		cout<<"A. Push some random elements."<<endl
		    <<"B. Push an element."<<endl
    		<<"C. Pop an element."<<endl
	    	<<"D. Pop some elements."<<endl
		    <<"E. Clear stack."<<endl
    		<<"F. Display stacks"<<endl
	    	<<"G. Is Stack sorted"<<endl
		    <<"1. Main Menu"<<endl
		    <<"0. Exit application."<<endl<<endl
		    <<"Please make a selection: " ;

		cin>>choice ;
		
		if(choice>='a')	choice-=('a'-'A') ;			 
		switch(choice)
		{
			case 'A' : pushRandomArrayLinked() ;
			break ;
			
			case 'B' : pushArrayLinked() ;
			break ;
			
			case 'C' : 	popArrayLinked() ;
			break ;

            case 'D' : 	popElementArrayLinked() ;
			break ;

            case 'E' : 	clearArrayLinked() ;
			break ;

            case 'F' : 	displayArrayLinked() ;
			break ;

            case 'G' : 	sorted() ;
			break ;
		}
		
	}while(choice!='1' && choice!='0') ;
		
		
}

void selection()
{
    	char choice ;
	do{
		// color(5);
		cout<<"What are the operations that you need to do ?"<<endl ;
		// color(); 
		
		cout<<"A. Lists playground. "<<endl
		    <<"B. Stacks playground. "<<endl
    		<<"C. Queues playground. "<<endl
	    	<<"D. Hashes playground. "<<endl
		    <<"E. Phone directory application. "<<endl
    		<<"F. Show app calculations. "<<endl
		    <<"0. Exit application."<<endl<<endl
		    <<"Please make a selection: " ;

		cin>>choice ;
		
		if(choice>='a')	choice-=('a'-'A') ;			 
		switch(choice)
		{
			case 'A' : //Lists_playground() ;
			break ;
			
			case 'B' : Stack_Playground() ;
			break ;
			
			case 'C' : 	//Queue_playground() ;
			break ;

            case 'D' : 	//Hashes_playground() ;
			break ;

            case 'E' : 	//Phone_directory() ;
			break ;

            case 'F' : 	//show_app_calc() ;
			break ;

		}
		
	}while(choice!='1' && choice!='0') ;
}

int main(){
    selection();
}