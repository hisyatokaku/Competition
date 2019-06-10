#include <iostream>
using namespace std;

int main(void){
  int N;
  cin >> N;

  int i,j ;
  int D[N][N];
    
  for (i = 0; i < N; i++){
    for (j = 0; j < N; j++){
      cin >> D[i][j];
    }
  }
  
  int Q;
  cin >> Q;
  
  int P[Q];
  for (i = 0; i < Q; i++){
    cin >> P[i];
  }
  
  return 0;
  
}
