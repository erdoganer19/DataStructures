//Name:Ertug Erdogan
//Number:150190714
#include <vector>


class Agent{
    private:
        int waitingtime;
    public:
        bool full;
        void FullIt();
        void EmptyIt();
        Agent();
        int getwaitingtime();
        void setwaitingtime(int);
        void ReduceWaitingtime();
};


