#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

class Book {
    private: 
        char *author;
        char *title;
        char *pub;
        int *year;
        float *price;
        int *stock;
    public:
        Book() {
            author = new char[20];
            title = new char[20];
            pub = new char[20];
            year = new int;
            price = new float;
            stock = new int;
        }
        void registerBook() {
            cin.ignore();
            cout << "\nEnter Author Name: "; cin.getline(author,20);
            cout << "\nEnter title: "; cin.getline(title, 20);
            cout << "\nENter pub: "; cin.getline(pub, 20);
            cout << "\n Year of publishing: "; cin >> *year;
            cout << "\nEnter price: "; cin >> *price;
            cout << "\nEnter stock: "; cin >> *stock;
            /*ofstream bookfile;
            bookfile.open("books.txt");
            bookfile << author << " " << title << " " << pub << " " << year << " " << stock << endl;
            bookfile.close();*/
        }
        void editBook() {
            int c;
            cout << "\n1****Change Author Name: ";
            cout << "\n2****Change title: "; //cin.getline(title, 20);
            cout << "\n3****Change publisher: "; //cin.getline(pub, 20);
            cout << "\n4****Change Year of publishing: "; //cin >> *year;
            cout << "\n5****Change price: "; //cin >> *stock;
            cout << "\nYour choice: ";
            //int c;
            cin >> c;
            switch(c) {
                case 1:
                    cout << "\nNew author: ";
                    cin.getline(author, 20);
                    break;
                case 2:
                    cout << "\nNew title: ";
                    cin.ignore();
                    cin.getline(title, 20);
                    break;
                case 3:
                    cout << "\nNew publisher: ";
                    cin.getline(pub, 20);
                    break;
                case 4:
                    cout << "\nNew year: ";
                    cin >> *year;
                    break;
                case 5:
                    cout << "New price: ";
                    cin >> *price;
                    break;
                default:
                    cout << "\nInvalid choice";
                    break;
            }
            
        }
        void displaydata() {
            cout << "\nAuthor's Name: " << author;
            cout << "\nTitle: " << title;
            cout << "\nPublisher: " << pub;
            cout << "\nPrice: " << *price;
            cout << "\nStock: " << *stock;
        }
        bool searchdata(char authorfind[20], char titlefind[20]) {
            if((strcmp(authorfind, author) == 0) && (strcmp(titlefind, title) == 0)) {
                return true;
            } else {
                return false;
            }
        }
        void buybook() {
            int count;
            cout << "\nEnter the number of books to buy: ";
            cin >> count;
            if (count <= *stock) {
                *stock = *stock - count;
                cout << "\nBooks have been bought successfully";
                cout << "\nAmount to be paid: " << (*price) * count; 
            } else {
                cout << "\nNot enough number of books available";
            }
        }

};

int main()	{
	Book *B[20];
    int choice;
    int i = 0;
    int s = sizeof(B)/sizeof(B[0]);
	//int i=0,r,t,choice;
	char titlebuy[20],authorbuy[20];
	while(1) {
		cout << "\n\n\t\tMENU"
		<<"\n1. Entry of New Book"
		<<"\n2. Buy Book"
		<<"\n3. Search For Book"
		<<"\n4. Edit Details Of Book"
		<<"\n5. Exit"
		<<"\n\nEnter your Choice: ";
		cin >> choice;
		
		switch(choice)	{
			case 1:	
                /*B[i] = new Book;
				B[i]->registerBook();
				i++;*/
                int q;
                cout << "\nHow many books would you like to register: "; cin >>	q;
                for (int a = 0; a < q; a++) {
                    B[a] = new Book;
                    B[a]->registerBook();
                }
                break;
				
			case 2: 
                cin.ignore();
				cout << "\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout << "Enter Author Of Book: ";  cin.getline(authorbuy,20);
                
				for(int t = 0; t < s; t++)	{
					if(B[t]->searchdata(authorbuy, titlebuy))	{
                        cout << "\nBook available";
						B[t]->buybook();
                        break;
					} else {
                        cout << "\nThis book is not in stock";
                    }
				}
				/*if(t == 1)
				    cout<<"\nThis Book is Not in Stock";*/
				
				break;
			case 3: 
                cin.ignore();
				cout << "\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout << "Enter Author Of Book: ";  cin.getline(authorbuy,20);
				
				for(int t = 0; t < s; t++)	{
					if(B[t]->searchdata(authorbuy,titlebuy)) {
						cout << "\nBook Found Successfully";
						B[t]->displaydata();
						break;
					} else {
                        cout << "\nThis book is not in stock";
                    }
				}
				/*if(t == i)
				cout << "\nThis Book is Not in Stock";*/
				break;
			
			case 4: 
                cin.ignore();
				cout << "\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout << "Enter Author Of Book: ";  cin.getline(authorbuy,20);
				
				for(int t = 0; t < s; t++)	{
					if(B[t]->searchdata(authorbuy, titlebuy))	{
						cout << "\nBook Found Successfully";
						B[t]->editBook();
                        B[t]->displaydata();
						break;
					} else {
                        cout << "\nThis book is not in stock";
                    }
				}
				/*if(t==i)
				cout<<"\nThis Book is Not in Stock";*/
				break;
			
			case 5: 
                exit(0);
                break;

			default: 
                cout<<"\nInvalid Choice Entered";
			
		}
	}
	
	
	
	
	return 0;
}