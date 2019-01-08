#include <bits/stdc++.h>
using namespace std;	

vector <vector <float> > matrix; // distance of cities from each cities

/*Functions Defination*/
//Finds the path's cost 
float cost(vector <int> path){
  float cost=0;
  for (int i = 1; i < path.size(); i++)
     cost += matrix[path[i]][path[i-1]];
  return cost;
}

//computes the neighbour path
vector <int> compute(vector <int> path){
int a,b,temp;
a=rand()%(path.size()-1);
if(a==0)
  a++;
b=rand()%(path.size()-1);
if(b==0)
  b++;
if(a>b){
  temp=b;
  b=a;
  a=temp;
}
  int i=0;
  while (a+i<b-i){
    temp = path[a+i];
    path[a+i] = path[b-i];
    path[b-i] = temp;
    i++;
  }
  return path;
}


//Shows the Path
void viewPath(vector <int> path){
  for (int i = 0; i < path.size()-1; i++)
    printf("%d ",path[i]);
  printf("\n");
}