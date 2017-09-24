#include <iostream>
#include <stdio.h>
#include<map>

#define MIN_PID 300
#define MAX_PID 5000

//define map type so can access it more easily
typedef std::map<int, int> intMap;
//instantiate myMap for global access
intMap myMap;
//int for the last assigned ID for global access
int nextPid = 300;


//create empty map. return 1 if successful, -1 if failed
int allocateMap()
{
    //create map
    intMap myMap = *new intMap{};
    //if created a new map - by default is empty so can check if it was created
    if(myMap.empty())
        return 1;
    
    //if wasn't empty then wasn't created & return -1
    return -1;
};

//allocate pid within the range (min & max). Cannot be duplicated
int allocatePid()
{
    int pid;
    
    //if enter at last pid, start over from min pid
    if(nextPid > MAX_PID)
    {
        nextPid = 300;
    }
    
    //while in the range of pid's to assign
    while(nextPid <= MAX_PID && nextPid >= MIN_PID)
    {
        //if the next pid is not assigned & is less than max: assign that pid, add to map, & increment lastPid
        if(myMap.count(nextPid) == 0 && nextPid <= MAX_PID)
        {
            pid = nextPid;
            myMap.insert({pid, 1});
            nextPid ++;
            return pid;
        }
        //else just increment pid to continue
        nextPid ++;
        
        //if allocated last pid allowed, start again
        if(nextPid > MAX_PID)
            nextPid = 300;
    
    }
    
    //if reach here than already assigned all pid's and none left
    return -1;
};

//remove specified pid
void releasePid(int pid)
{
    //if it exists in the map than delete
    if(myMap.count(pid) != 0)
    {
        myMap.erase(pid);
    }
    
    else
        std::cout<<"pid "<< pid << " has not been assigned. \n";
    
    
    return;
};

int main(int argc, char *argv[])
{
    
    
    int ret = allocateMap();
    
    std::cout<<"****** PART I *******\n";
    /*debug - test if created map*/
    std::cout<<"ret is "<<ret<<"\n";
    
    std::cout<<"****** PART II *******\n";
    /* test allocate pid*/
    nextPid = 4990;
    for(int i = 0; i<20; i++)
    {
        std::cout<<"nextPid before allocate is "<<nextPid<<"\n";
        int pid = allocatePid();
        std::cout<<"nextPid after allocate is "<<nextPid<<"\n";
        std::cout<<"pid is "<<pid<<"\n";
    }
    
    std::cout<<"****** PART III *******\n";
    nextPid = 4990;
    /* test allocate pid*/
    for(int i = 0; i<10; i++)
    {
        
        std::cout<<"nextPid before allocate is "<<nextPid<<"\n";
        int pid = allocatePid();
        std::cout<<"nextPid after allocate is "<<nextPid<<"\n";
        std::cout<<"pid is "<<pid<<"\n";
    }
    
    std::cout<<"****** PART IV *******\n";
    /* test release pid*/
    releasePid(300);
    releasePid(4000);
    releasePid(4995);
    releasePid(4996);
    releasePid(4001);
    
    nextPid = 4990;
    for(int i = 0; i<10; i++)
    {
        std::cout<<"nextPid before allocate is "<<nextPid<<"\n";
        int pid = allocatePid();
        std::cout<<"nextPid after allocate is "<<nextPid<<"\n";
        std::cout<<"pid is "<<pid<<"\n";
    }
}

