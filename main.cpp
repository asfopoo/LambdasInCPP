#include <iostream>

using namespace std;

int main()
{
    //lambda function
    //[capture list](parameter list) -> return_type {function body}
    auto someFunction = [](){
      cout << "Hello World!" << endl;
    };

    someFunction();


    //anonomous lanbda immediately invoked
    [](){
          cout << "Hello World!" << endl;
        }();


    //defina a lambda with parameters
    [](int a, int b){
        cout << "The sum of a and b is: " << a + b << endl;
    }(7,3);

    //lambda that returns an int
    [](int a, int b)->int{
        return a+b;
    }(7,3);


    //lambda inside output statement
    cout << "The sum is: " << [](int a, int b)->int{
        return a+b;
    }(7,3) << endl;

    //capture lists
    int a = 7;
    int b = 3;

   [a, b](){
        cout << a + b << endl;
    }();

    //capturing by value
    int c = 42;
    auto myFunc = [c](){
        cout << "The lambda value of c is: " << c << endl;
    };

    for(int i = 1; i < 5; i++){
        cout << "The for loop value of c is: " << c << endl;
        myFunc();
        c = c + 1;
    }

    //output -> 42 42 43 42 44 42 45 42
    //by value creates a copy of c

    //////

    //capturing by reference
    auto myFuncByReference = [&c](){
        cout << "The lambda value of c is: " << c << endl;
    };

    for(int i = 1; i < 5; i++){
        cout << "The for loop value of c is: " << c << endl;
        myFuncByReference();
        c = c + 1;
    }

    //output -> 42 42 43 43 44 44 45 45
    //by reference passes the address

    //////

    //capture any variable in the current scope by value
    int x = 1;
    int y = 10;
    auto myFuncAll = [=](){
        //can use x y and c !!!!! (by value)
        cout << "The lambda value of c is: " << c << endl;
        cout << x + y << endl;
    };

    for(int i = 1; i < 5; i++){
        cout << "The for loop value of c is: " << c << endl;
        myFuncAll();
        c = c + 1;
    }

    /////////


    //Or the same by reference
    auto myFuncAllRef = [&](){
        //can use x y and c !!!!! (by value)
        cout << "The lambda value of c is: " << c << endl;
        cout << x + y << endl;
    };

    for(int i = 1; i < 5; i++){
        cout << "The for loop value of c is: " << c << endl;
        myFuncAllRef();
        c = c + 1;
    }





    return 0;
}
