#include<iostream>
#include<thread>
using namespace std;

void fun1(int& n)
{
    for(int i=0;i<10;i++)
    {
        cout<<"Thread "<<n<<" on"<<endl;
        this_thread::sleep_for(chrono::milliseconds(20));
    }
}

void fun2(int& n)
{
    for(int i=0;i<10;i++)
    {
        //cout<<"Thread 02 on"<<endl;
        n++;
        this_thread::sleep_for(chrono::milliseconds(20));
    }
}

int main_()
{
    int n = 0;
    thread t1;
    thread t3(fun2, ref(n));
    thread t2(fun1, ref(n));
    thread t4(move(t3));
    n+=2;
    t2.join();
    
    t4.join();
    cout<<"Fine value n is "<<n<<endl;
    return 0;
}
int main()
{
    main_();
}
