
/*1 Black Jack*/
#include <iostream> 
#include <vector>
#include <set> 
//!-> #include <> and #include ""
#include <string> //This method is normally used to include standard library header files.
#include "Game.h" //This method is normally used to include programmer-defined header files.
//https://stackoverflow.com/questions/21593/what-is-the-difference-between-include-filename-and-include-filename

//!-> #include only .h
//!-> .hpp


using namespace std;
int main()
{
    cout << "\t\tWelcome to Blackjack!\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }

    vector<string> names;
    //set<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
        //names.insert(name);
    }
    cout << endl;

    // игровой цикл
    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }

    //!-> home task change for with iterrator to range base for

    //!-> templates in h


    return 0;
}


/*2 smat pointer unuque_ptr*/

//#include <iostream> 
//#include <memory>
//using namespace std;
//
//class Simple
//{
//private:
//	const int m_value;
//public:
//	Simple(int value) :
//		m_value(value) {
//		cout << "Constructor" << endl;
//	}
//
//	~Simple(){
//		cout << "Destructor" << endl;
//	}
//
//	void print() const
//	{
//		cout << "value=" << m_value <<endl;
//	}
//};
//
////void function(unique_ptr<Simple> s)
////{
////	cout << "print in function : ";
////	s->print();
////}
////
////void function2(unique_ptr<Simple>& s)
////{
////	cout << "print in function : ";
////	s->print();
////}
////https://stackoverflow.com/questions/30905487/how-can-i-pass-stdunique-ptr-into-a-function
//
////template <class T>
////class my_unique_ptr
////{
////private:
////	T* ptr = nullptr;
////
////public:
////	my_unique_ptr() : ptr(nullptr) {}
////
////	my_unique_ptr(T* ptr) : ptr(ptr) {}
////
////
////	T* operator->() // deferencing arrow operator
////	{
////		return ptr;
////	}
////
////	T& operator*()
////	{
////		return *ptr;
////	}
////
////	~my_unique_ptr() // destructor
////	{
////		__cleanup__();
////	}
////
////	//my_unique_ptr(const my_unique_ptr& obj) = delete; // copy constructor is deleted
////	//my_unique_ptr& operator=(const my_unique_ptr& obj) = delete; // copy assignment is deleted
////
////	//my_unique_ptr(my_unique_ptr&& dyingObj) // move constructor
////	//{
////	//	// Transfer ownership of the memory pointed by dyingObj to this object
////	//	this->ptr = dyingObj.ptr;
////	//	dyingObj.ptr = nullptr;
////	//}
////
////	//void operator=(my_unique_ptr&& dyingObj) // move assignment
////	//{
////	//	__cleanup__(); // cleanup any existing data
////	//	// Transfer ownership of the memory pointed by dyingObj to this object
////	//	this->ptr = dyingObj.ptr;
////	//	dyingObj.ptr = nullptr;
////	//}
////
////private:
////	void __cleanup__()
////	{
////		if (ptr != nullptr)
////			delete ptr;
////
////		ptr = nullptr;
////	}
////};
//
//int main()
//{
//	Simple* simple = new Simple(10);
//	simple->print();
//	delete simple;
//	
//	/*int a = 10;
//	if(a==10)
//	{
//		return 0;
//	}
//	delete simple;*/
//	
//	//unique_ptr<Simple> uSimple = std::make_unique<Simple>(11);
//	//uSimple->print();
//
//	//click to std::make_unique
//	//int a = 10;
//	//if (a == 10)
//	//	return 0;
//
//	//unique_ptr<Simple> anoverSimple = uSimple;
//	
//	//unique_ptr<Simple> anoverSimple = std::move(uSimple);
//	//if (uSimple)
//	//	uSimple->print();
//	//else
//	//	cout << "uSimple is nullptr" << endl;
//	//anoverSimple->print();
//
//	//function(uSimple);
//
//	//function(std::move(uSimple));
//	//if (uSimple)
//	//	uSimple->print();
//	//else
//	//	cout << "uSimple is nullptr" << endl;
//
//	//function2(uSimple);
//	//if (uSimple)
//	//	uSimple->print();
//	//else
//	//	cout << "uSimple is nullptr" << endl;
//
//
//	//my_unique_ptr<Simple> uSimple = my_unique_ptr<Simple>(new Simple(5));
//	//uSimple->print();
//	//my_unique_ptr<int> val = my_unique_ptr<int>(new int(16));
//	//cout << *val;
//	//*val = 18;
//
//	
//	//my_unique_ptr<Simple> uSimpleDublicate = uSimple;
//	//my_unique_ptr<Simple> uSimpleDublicate(uSimple);
//	
//	//my_unique_ptr<Simple> anoverSimple = std::move(uSimple);
//	//my_unique_ptr<Simple> anoverSimple(std::move(uSimple));
//
//	//!-> rewrite class Hand;
//	//std::vector<Card*> m_cards;
//
//  //https://www.geeksforgeeks.org/pimpl-idiom-in-c-with-examples/
//	return 0;
//}