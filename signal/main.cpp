#include <signal.h>
#include <iostream>

int main() {
  sigset_t sset;
  sigemptyset(&sset);
  sigaddset(&sset, SIGTERM);
  signal(SIGINT, SIG_IGN);
  sigprocmask(SIG_BLOCK, &sset, NULL);
  int sig;
  sigwait(&sset, &sig);
  std::cout << "SIGTERM was received!!" << std::endl;
}
