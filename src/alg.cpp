// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  vector<Node*> level = vector<Node*>(tree.enter);
  int len = tree.enter.size();
  int N = n, s = 0, add = 0;
  std::vector<int> path(len);
  std::vector<char> out(0);
  if (n > factorial(len)*len) return out;
  for (int i = 0; i < len; i++) {
    add = factorial(len - i);
    s = 0;
    for (int j = 0; j < len - i; j++) {
      s = s + add;
      if (s >= N) {
        path[i] = j;
        N = N - add * j;
        break;
      }
    }
  }
  for (int k = 0; k < len; k++) {
    out.push_back(level[path[k]]->c);
    level = level[path[k]]->v;
  }
  return out;
}
