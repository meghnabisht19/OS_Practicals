#include <iostream>
#include <unistd.h>

using namespace std;

void sameProgramDiffCode()
{
  pid_t pidFork;
  pidFork = fork();
  if(pidFork < 0)
    cout << "\nError in fork...";
  else if(pidFork == 0)
    cout << "\nChild executed\nProcess ID : " <<  getpid() << "\nParent Process ID : " << getppid() << endl;
  else
    cout << "\nParent executed\nProcess ID : " << getpid() << "\nParent Process ID : " << getppid() << endl;
  return;
}

int main()
{
  sameProgramDiffCode();
}