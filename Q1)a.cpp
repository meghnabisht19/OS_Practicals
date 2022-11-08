#include <iostream>
#include <unistd.h>

using namespace std;

void sameProgramSameCode()
{
  pid_t pidFork;
  pidFork = fork();
  if(pidFork < 0)
    cout << "\nError in fork...";
  else
    cout << "\nProcess ID : " <<  getpid() << "\nParent Process ID : " << getppid() << endl;
  return;
}

int main()
{
  sameProgramSameCode();
}