/*
 * Message queue example using threads and STL-queue
 *
 */

#include <iostream>
#include <string>    // messages
#include <queue>
#include <cstdlib>
#include <unistd.h>    // usleep
#include <thread>
#include <mutex>


// mutex for guarding messages
std::mutex msgmutex;

std::queue<std::string> msgq;



void msgreceiver()
{
long qsize;
std::string nextmsg;

  while(true){
    if(msgq.empty()){
      usleep(10000); // sleep 0.01 sec before trying again
      continue;
    }

    // we end up here because there was something in the msg queue
    msgmutex.lock();
    qsize=msgq.size();
    if(qsize > 5) std::cout << "Queue size: " << qsize << std::endl;
    nextmsg=msgq.front(); // get next message in queue
    msgq.pop(); // remove it from the queue
    msgmutex.unlock();

    std::cout << "Processing value " << nextmsg << std::endl;
    usleep(1000000);
  } // while
} // msgreceiver()



void msgtransmitter()
{
std::string nextmsg;

  while(true){
    std::cin >> nextmsg;
    msgmutex.lock();
    msgq.push(nextmsg); // push message onto the queue
    msgmutex.unlock();
  } // while
} // msgtransmitter()



int main(int argc, char **argv)
{

  std::thread thread_1(msgreceiver);
  std::thread thread_2(msgtransmitter);

  thread_1.join();
  thread_2.join();

} // main()
