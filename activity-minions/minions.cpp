#include <iostream>
#include <thread>

void f (int a) {
  std::cout<<"Hello! I am minion "<<a<<". \n";
} 

void writeoverlordmessage() {
  std::cout<<"Hello Minions! I am the Overlord.\n";
}
int main (int argc, char** argv) {
  if (argc < 2) {
    std::cerr<<"usage: "<<argv[0]<<" <nbminions>\n";
    return -1;
  }
  //Your code goes here
  for (int i = 0; i < atoi(argv[1]); i++) {
    std::thread minion_thread(f, (i+1));

    
    minion_thread.join();
  }

  std::thread overlord_thread(writeoverlordmessage);
  overlord_thread.join();
  return 0;
}
