#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif

  
int main (int argc, char* argv[]) {

  if (argc < 6) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<<std::endl;
    return -1;
  }

  int functionid = atoi(argv[1]);
  float a = atof(argv[2]);
  float b = atof(argv[3]);
  int n = atoi(argv[4]);
  int intensity = atoi(argv[5]);
  float x = 0.0;

  auto start = std::chrono::system_clock::now();

  if (functionid == 1) {
    for (int i; i < n; i++) {
      x += f1((a+(i+.5)*((b-a)/n)), intensity);
    }
    x = x * ((b-a)/n);
     cout <<  x << endl;
  }
  else if (functionid == 2){
    for (int i; i < n; i++) {
      x += f2((a+(i+.5)*((b-a)/n)), intensity);
    }
    x = x * ((b-a)/n);
     cout <<  x << endl;
  }
  else if (functionid == 3){
    for (int i; i < n; i++) {
      x += f3((a+(i+.5)*((b-a)/n)), intensity);
    }
    x = x * ((b-a)/n);
     cout <<  x << endl;
  }
  else if (functionid == 4){
    for (int i; i < n; i++) {
      x += f4((a+(i+.5)*((b-a)/n)), intensity);
    }
    x = x * ((b-a)/n);
     cout <<  x << endl;
  }

  auto end = std::chrono::system_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

  std::cerr<<duration<<std::endl;

  return 0;
}
