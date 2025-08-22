/*
#include <iostream>
#include <algorithm>
using namespace std;
                        //     2       1           10
bool binarySearch(int A[], int low, int high, int searchKey)
{
    // A[] = { 1, 4, 45, 6, 10, -8 };

    while (low <= high) { // 
        int m = low + (high - low) / 2; // 

        // Check if searchKey is present at mid
        if (A[m] == searchKey) // 
            return true;

        // If searchKey greater, ignore left half
        if (A[m] < searchKey)
            low = m + 1; // 

        // If searchKey is smaller, ignore right half
        else
            high = m - 1; // 
    }

    // if we reach here, then element was
    // not present
    return false;
}

bool checkTwoSum(int A[], int arr_size, int sum)
{

    /* Sort the elements 
    //sort(A, A + arr_size);

    // Traversing all element in an array search for
    // searchKey
    for (int i = 0; i < arr_size - 1; i++) { // i = 0 , 1

        int searchKey = sum - A[i]; //  10
        // calling binarySearch function
        if (binarySearch(A, i + 1, arr_size - 1, searchKey)
            == true) {
            return true;
        }
    }
    return false;
}

/* Driver program to test above function 
int main()
{
    int A[] = { 1, 4, 45, 6, 10, -8 };
    int n = 14;
    int arr_size = sizeof(A) / sizeof(A[0]);

    // Function calling
    if (checkTwoSum(A, arr_size, n))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
*/










// programm number 5 to C++ ------------------------------------
/*
#include <iostream>
using namespace std;


class BankAccount {
public:
    void set_Data (string account_number ,int the_balance)
    {
        if(account_number.size()!=5 && the_balance <= 0)
        {
            cout << "Invalid All Data" << endl;
        }

        else if(account_number.size()!=5)
        {
            cout << "Invalid Account Number => " << account_number  << endl;
        }

        else if(the_balance <= 0)
        {
            cout << "Invalid the_balance => " << the_balance << endl;
        }
        
        this -> account_number = account_number;
        this -> the_balance = the_balance;
        
        this -> chick = true;
    }

    int get_money(int withdrawn)
    {
        if(chick == true)
        {
            cout << "Error ";
            return 0;
        }

        if(this -> the_balance - withdrawn >= 0)
        {
            cout << "Has Been Withdrawn -> " << withdrawn << endl;
            cout << "Your current Balance is : " <<  the_balance << " - "<< withdrawn << " => ";
            return the_balance - withdrawn;
        }

        else
        {
            cout << "Your Balance Is Not Enough => " ;
            return  the_balance ;
        }
    }

private:
        string account_number ="";
        int the_balance = 0;
        bool chick = false;

};

int main(){
    BankAccount ba;
        ba.set_Data("1234" , 1000);
        cout << ba.get_money(1000) << endl;
}
*/







// programm number 4 to C++ ------------------------------------
/*
#include <iostream>
using namespace std;

class Car{
public:
    void set_company(string company)
    {
        this -> company = company;
    }

    void set_model(string model)
    {
        this ->model = model;
    }

    void set_year(int year)
    {
        this-> year = year;
    }

    string get_company()
    {
    return company;
    }

    string get_model()
    {
    return model;
    }

    int get_year()
    {
    return year;
    }



private:
    string company;
    string model;
    int year;


};

int main(){
Car c;
    c.set_company("Cairo_Motoar");
    c.set_model("Shahin");
    c.set_year(2030);

    cout <<" company Is :=> " << c.get_company() << endl;
    cout << " model Is :=> " << c.get_model() << endl;
    cout << " year Is :=> " << c.get_year()<< endl;

}
*/





// programm number 3 to C++ ------------------------------------
/*
#include <iostream>
using namespace std;


class Person{
public:
    void set_name(string name)
    {
        this -> name = name;
    }

    void set_age(int age)
    {
        this-> age = age;
    }

    void set_contry(string contry)
    {
        this ->contry = contry;
    }

    string get_name()
    {
    return name;
    }

    int get_age()
    {
    return age;
    }

    string get_contry()
    {
    return contry;
    }

private:
    string name;
    int age;
    string contry;


};

int main(){
Person p;
    p.set_name("Ahmed");
    p.set_age(18);
    p.set_contry("Cairo");

    cout <<"Your Name Is :=> " << p.get_name() << endl;
    cout << "Your age Is :=> " << p.get_age() << endl;
    cout << "Your contry Is :=> " << p.get_contry() << endl;

}
*/






// programm number 2 to C++ ------------------------------------
/*
#include <iostream>
using namespace std;

class Rectangle{
public:
  Rectangle(float height , float the_offer){
    this -> height = height;
    this -> the_offer = the_offer;
  }

     float get_rectangle_area()
     {
        return (height * the_offer);
     }

     float get_perimeter_of_the_rectangle()
     {
        return 2 * (height + the_offer) ;
     }

private:
    float height ;
    float the_offer ;

};

int main(){
Rectangle r(7 ,3);
cout << " rectangle_area is : "  << r.get_rectangle_area() << endl;
cout << " perimeter_of_the_rectangle is : " << r.get_perimeter_of_the_rectangle() << endl;
}
*/




// programm number 1 to C++ ------------------------------------
/*
#include <iostream>
using namespace std;

class Circle{
    public:

    Circle(float radius)
    {
        this-> radius= radius;
    }

    float get_circle_aria()
    {
        return pi*(radius*radius);
    }

    float get_surroundings_ofa_cicle()
    {
        return pi*2*radius;
    }

    private:

    const float pi =3.14;
    float radius;


};

int main(){
Circle c(6);
cout <<" circle_aria is : "<< c.get_circle_aria()<< endl;
cout << " surroundings_ofa_cicle is : " << c.get_surroundings_ofa_cicle()<< endl;
}
*/
