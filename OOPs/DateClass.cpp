#include <iostream>

// OOPS IN C++
// : Default Access Specifier is 'private'
class Date{

    public:

    Date (){
        d = m = y = 0;
    }

    Date (int dd, int mm, int yy){
        d = dd;
        m = mm;
        y = yy;
    }

    ~Date(){
        printf ("This is destructor");
    }

    void init(int dd, int mm, int yy){
        d = dd;
        m = mm;
        y = yy;
    }

    void display(){
        printf("%d-%d-%d\n", d, m, y);
    }

    void displayDate();

    private:

    int d, m, y;
};

// Defining Member outside class. (The member should be declared inside the class)
void Date::displayDate(){
    printf("The date is %d-%d-%d\n", d, m, y);
}

// Function which takes object of a class
void initDate(Date &d, int dd, int m, int y){
    d.init(dd, m, y);
}

int main(){
    Date dDefault;
    dDefault.display();
    // delete dDefault;
    // dDefault.init(25,6,2020);

    // Date d = new Date (25,6,2020); // ERROR
    Date d {25,6,2020}; // Class object with constructor -- Colloquial Style
    // Date d(25,6,2020); // Class object with constructor -- Colloquial Style
    // Date d = {25,6,2020}; // Class object with constructor -- Verbose Style
    // Date d = Date {25,6,2020}; // Class object with constructor -- Verbose Style
    d.display();

    Date *dPointer = new Date();
    dPointer->display();
    delete dPointer;

    Date newyear;
    initDate(newyear, 1, 1, 2021);
    newyear.displayDate();
    return 0;
}