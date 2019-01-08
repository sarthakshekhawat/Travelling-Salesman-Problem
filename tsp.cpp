/*  ARTIFICIAL INTELLIGENCE 
 *  Program to know approximate solution and path for Travelling Salesman Problem.
*/
#include <bits/stdc++.h>
#include "functions.h"
using namespace std;

int main(int argc, char const *argv[]) {
  string s;
  int n;
  int a, b;
  int temp;
  unsigned long long int count=0;
  float cmp,prob,T = 999999999999999;
  float tmax = T;
  float FACt = 0.999;
  unsigned long long int limit = 999999;


  time_t start, end;
  double elap;
  start = time(NULL);
  bool terminate = true;

  cin >> s >> n;
  vector< pair<float, float> > coordinates; //coordinates of the city
  vector <vector <float> > matrix2(n); 
  float x, y;
  for (int i = 0; i < n; i++) {
    scanf("%f %f",&x,&y);
    coordinates.push_back(make_pair(x,y));
  }

  vector <int> possiblePath(n+1,0);
  vector <int> effectivePath(n+1,0);
  vector <int> computedPath(n+1,0);
  for(int i=1;i<n;i++)
  {
      possiblePath[i]=i;
      effectivePath[i]=i;
      computedPath[i]=i;
  }
  float matrix_temp;

  float ccost,pcost,ecost;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    {
      scanf("%f",&matrix_temp);
      matrix2[i].push_back(matrix_temp);
    }
    matrix = matrix2;
  srand(time(NULL));
  while (terminate) {
    end=time(NULL);
    elap = difftime(end, start);
    if(elap>=300.0) //300 seconds limit
      terminate = false;
    pcost=cost(possiblePath); //cost of possiblePath
    ecost=cost(effectivePath); // cost of effectivePath

    computedPath = compute(possiblePath);
    ccost = cost(computedPath);

    cmp = (float)(rand() / (float)RAND_MAX);
    prob = (float)(1/(1 + exp((ccost - pcost)/T))); //probability
    if(prob>cmp)
      possiblePath = computedPath;

    pcost = cost(possiblePath);

    if(pcost<ecost){
      effectivePath = possiblePath;
      //cout << pcost << endl;
      viewPath(effectivePath);
      count=0;
    }
    else
      count++;
        T *=FACt;

    if(count>limit)
    {
      T = tmax;
      FACt = (float)(1+FACt)/2;
      limit =  2*limit;
      count = 0;
    }
  }
  return 0;
}