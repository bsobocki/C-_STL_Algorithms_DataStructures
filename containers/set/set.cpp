#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;
/*
template <typename T, class Iterable> 
set<T> convert_to_set(Iterable & it){
    return set<T>(std::make_move_iterator(it.begin()), std::make_move_iterator(it.end()))
}

std::vector<int> deleteNth(std::vector<int> arr, int n)
{  
  std::map<int,int> map;
  std::vector<int> vec;
  for(auto i=arr.begin(); i!=arr.end(); i++){
    if (map.find(*i) != map.end()) {
      map[*i] ++;
      if (map[*i] <= n ) 
        vec.push_back(*i);
    }
    else {  
      vec.push_back(*i);
      map.insert(*i,0);
    }
  }
  return vec;
}*/

#include<string>
#include <algorithm>

bool valid_square(unsigned int board[9][9], int number){
  unsigned int temp[9] = {0};
  int start = number*3, end = start+3;
  for (int i=start; i<end; i++)
    for (int j=start; j<end; j++) 
      temp[ board[i][j]-1 ]++;
  for (int i=0; i<9; i++) if (temp[i] != 1) return false;
  return true;
}

bool valid_row(unsigned int board[9][9], int number){
  unsigned int temp[9] = {0};
  for (int i=0; i<9; i++) {
    if (board[i][number] <= 0 || board[i][number] >= 10 ) return false;
    temp[ board[number][i]-1 ] ++;
  }
  for (int i=0; i<9; i++) if (temp[i] != 1) return false;
  return true;
}

bool valid_column(unsigned int board[9][9], int number){
  unsigned int temp[9] = {0};
  for (int i=0; i<9; i++) {
    if (board[i][number] <= 0 || board[i][number] >= 10 ) return false;
    temp[ board[i][number]-1 ] ++;
  }
  for (int i=0; i<9; i++) if (temp[i] != 1) return false;
  return true;
}

bool validSolution(unsigned int board[9][9]){
  for(int i=0; i<9; i++)
    if (!valid_column(board,i) || !valid_row(board,i)) return false;
  for(int i=0;i<3;i++) if (!valid_square(board, i)) return false;
  return true;
}

unsigned int example1[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2}, 
                             {6, 7, 2, 1, 9, 5, 3, 4, 8},
                             {0, 9, 8, 3, 4, 2, 5, 6, 7},
                             {8, 5, 9, 7, 6, 1, 4, 2, 3},
                             {4, 2, 6, 8, 5, 3, 7, 9, 1},
                             {7, 1, 3, 9, 2, 4, 8, 5, 6},
                             {9, 6, 1, 5, 3, 7, 2, 8, 4},
                             {2, 8, 7, 4, 1, 9, 6, 3, 5},
                             {3, 4, 5, 2, 8, 6, 1, 7, 9}}; 

int main(){
   cout<<validSolution(example1);
}