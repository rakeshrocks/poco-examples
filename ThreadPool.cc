# compile using below step
#g++ -std=c++0x poco.cc –lPocoFoundation -lPocoNet  -lPocoUtil

#include "Poco/Runnable.h"
#include "Poco/ThreadPool.h"
#include <iostream>

using namespace std;

class Worker:public Poco::Runnable{
        public:
                Worker(int n):_id(n){}
                virtual void run() {
                        cout << "RAKESH in work"<< _id << endl;
                }
        private:
                int _id;
};

int main(int argc, char **argv)
{
        Worker work1(1);
        Worker work2(2);

        Poco::ThreadPool threadpool;

        threadpool.start(work1);
        threadpool.start(work2);

        threadpool.joinAll();

        return 0;
}

