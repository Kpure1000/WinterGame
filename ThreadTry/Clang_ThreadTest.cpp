#include<iostream>
#include<thread>
using namespace std;

void fun1(int& n)
{
    static int a;
    for(int i=0;i<10;i++)
    {
        cout<<"Thread "<<n<<" on"<<endl;
        
        cout<<"fun1 run "<<a<<" times."<<endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void fun2(int& n)
{
    static int a;
    for(int i=0;i<10;i++)
    {
        //cout<<"Thread 02 on"<<endl;
        n++;
        a++;
        cout<<"            fun 2 Run "<<a<<" Times."<<endl;
        this_thread::sleep_for(chrono::milliseconds(300));
    }
}

class AA
{
public:
    int x,y;
public:
    AA():x(0),y(0){}
    AA(int const& X, int  const& Y):x(X),y(Y){}
    ~AA(){}
};

void fun3(AA& sq, AA sp)
{
    cout<<sp.x<<", "<<sp.y<<"   "<<sq.x<<", "<<sq.y<<endl;
}

int main_()
{
    int n = 0;
    AA m(2,3);
    AA o(3,4);
    thread t1;
    thread t3(fun2, ref(n));
    thread t2(fun1, ref(n));
    thread t4(move(t3));
    thread t5(fun3, ref(o), m);
    n+=2;
    t2.join();
    t5.join();
    t4.join();
    cout<<"Fine value n is "<<n<<endl;
    return 0;
}
int main()
{
    main_();
}
