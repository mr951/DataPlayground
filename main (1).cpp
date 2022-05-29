#include <bits/stdc++.h>
#include <conio.h>  /* 70 = UP / 80 = DOWN / 75 = LEFT / 77 = RIGHT  */
#include <windows.h>
#include <ctime>
#include "arrayQueueType.h"
#include "arrayListType.h"
#include "arrayStackType.h"
#include "linkedListType.h"
#include "orderedLinkedList.h"
#include "unorderedLinkedList.h"
#include "stackLinked.h"

int color(int numColor=7)
{
    return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),numColor);
}


////////////////////////<<Lists playground>>/////////////////////////////

const int size = 100000 ;
arrayListType<int> arr(size) ;
unorderedLinkedList<int> unordered_linked ;
orderedLinkedList<int> ordered_Linked ;

calc_time(double arr_time_taken ,double ordered_linked_time_taken ,double unordered_linked_time_taken )
{
	color(10);
	cout<<endl<<"Operation Succeeded."<<endl;
	color(11);
	cout<<"Array based list time: "<<fixed<< arr_time_taken << setprecision(5)<<" sec " << endl;
	cout<<"Linked-list time: "<<fixed<< unordered_linked_time_taken << setprecision(5)<<" sec " << endl;
	cout<<"Sorted Linked-list time: "<<fixed<< ordered_linked_time_taken << setprecision(5)<<" sec " << endl;
	cout<<"Total Time Taken: "<<ordered_linked_time_taken+unordered_linked_time_taken+arr_time_taken<<" sec "<<endl ;
	cout<<"Press any key to go to the list menu " <<endl<<endl ;
	getch() ;
}
bool check()
{
	int max_append_size=arr.maxListSize()-arr.listSize() ;
	if(!max_append_size)
	{
		color(12);
		cout<<"Lists are Full , so can not insert any more."<<endl 
			<<"Try to delete some elements ."<<endl<<endl ;
		return 1 ;
	}
	return 0 ;
}
void Append_random_elements()
{
	color(1);
	cout<<endl<<"<<<<<<<<<<<<<<<<<<<Appending random elements>>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl ;
	color();
	if(check()) 	return ;
	
	int max_append_size=arr.maxListSize()-arr.listSize() ;
	cout<<"Please specificity the number of elements needed [1:"<<max_append_size<<"] :  ";
	int size;
	cin>>size;
	if(size>max_append_size)	
	{
		cout<<"Sorry ... You can append only "<<arr.maxListSize()-arr.listSize()<<" element MAX."<<endl;
		size=arr.maxListSize()-arr.listSize() ;
	}
		
	cout<<"Please specificity range:"<<endl;
	int st , en;
	cout<<"start = ";
	cin>>st;
	cout<<"End = ";
	cin>>en;
	
	clock_t start, end;
	
	start = clock();
	for(int i=0 ;i<size; i++)	
	{
		int element= (st+rand()%en)%en ;
		arr.insertEnd(element);
	}
	end = clock();
	double arr_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	
	start = clock();
	for(int i=0 ;i<size; i++)	
	{
		int element= (st+rand()%en)%en ;
		unordered_linked.insertLast(element) ;
	}
	end = clock();
	double unordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	
	
	start = clock();
	for(int i=0 ;i<size; i++)	
	{
		int element= (st+rand()%en)%en ;
		ordered_Linked.insert(element) ;
	}
	end = clock();
	double ordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	
	calc_time(arr_time_taken , ordered_linked_time_taken , unordered_linked_time_taken) ;
}

void Append_an_element() 
{
	color(1);
	cout<<endl<<"<<<<<<<<<<<<<<<<<<< Append an element >>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl ;
	color();
	if(check()) 	return ;
	
	int element ;
	cout<<"Enter an element to be appended to lists : " ;
	cin>>element ;
	
	clock_t start, end;
	
	start = clock();
	arr.insertEnd(element);
	end = clock();
	double arr_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	
	start = clock();
	unordered_linked.insertLast(element) ;
	end = clock();
	double unordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	
	start = clock();
	ordered_Linked.insert(element) ;
	end = clock();
	double ordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	
	
	calc_time(arr_time_taken , ordered_linked_time_taken , unordered_linked_time_taken) ;
	
}
void Insert_element_at() 
{
	color(1);
	cout<<endl<<"<<<<<<<<<<<<<<<<<<<Insert an element at a specific place>>>>>>>>>>>>>>>>>>>>>>>>"<<endl<<endl ;
	color();
	if(check())	return ;
	
	int element , position;
	cout<<"Enter an element to be appended to lists : " ;
	cin>>element ;
	cout<<"Enter position to be inserted at : ";
	cin>>position ;
	
	clock_t start, end;
	
	start = clock();
	arr.insertAt(position , element);
	end = clock();
	double arr_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	
	start = clock();
	unordered_linked.insertLast(element) ;
	end = clock();
	double unordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	
	start = clock();
	ordered_Linked.insert(element) ;
	end = clock();
	double ordered_linked_time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	
	
	calc_time(arr_time_taken , ordered_linked_time_taken , unordered_linked_time_taken) ;
	
	
	
	
}

void Lists_playground()
{
	static bool creation_flage=0 ;
	if(!creation_flage++)
	{
		color(5);
		cout<<"An integer Array based list, a linked list, and a sorted linked list have been created."<<endl<<endl ;
	}

	char choice ;
	do{
		color(5);
		cout<<"What are the operations that you need to do ?"<<endl ;
		color(); 
		
		cout<<"A. Append some random elements."<<endl
		<<"B. Append an element."<<endl
		<<"C. Insert an element at a specific place."<<endl
		<<"D. Delete an element from a specific place."<<endl
		<<"E. Delete a batch of elements."<<endl
		<<"F. Edit an element at a specific place."<<endl
		<<"G. Find an element."<<endl
		<<"H. Count the occurrence of an element."<<endl
		<<"I. Display lists"<<endl
		<<"J. Sort by Merge Sort (Bonus)"<<endl
		<<"1. Main Menu"<<endl
		<<"0. Exit application."<<endl<<endl
		<<"Please make a selection: " ;
		cin>>choice ;
		
		if(choice>='a')	choice-=('a'-'A') ;			 
		switch(choice)
		{
			case 'A' : Append_random_elements() ;
			break ;
			
			case 'B' : Append_an_element() ;
			break ;
			
			case 'C' : 	Insert_element_at() ;
			break ;
		}
		
	}while(choice!='1' && choice!='0') ;
		
		
}


//mohammad ramadan///////////////////////////////////////////////////////////////////////////


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

void Stack_Playground()
{
	static bool creation_flage=0 ;
	if(!creation_flage++)
	{
		color(5);
		cout<<"An integer Array based list, a linked list, and a sorted linked list have been created."<<endl<<endl ;
	}

	char choice ;
	do{
		color(5);
		cout<<"What are the operations that you need to do ?"<<endl ;
		color(); 
		
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

void mainmenu()
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
			case 'A' : Lists_playground() ;
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



//mohammad ramadan/////////////////////////////////////////////////////////////////////////////////////







//////////////////////////////////////////////////////////////////////////

int main()
{
	srand(time(0));


Lists_playground() ;
}










