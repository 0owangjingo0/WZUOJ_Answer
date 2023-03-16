#include <bits/stdc++.h>

using namespace std;
typedef char ElementType;
typedef struct Node {
  ElementType data;
  struct Node *lchild;
  struct Node *rchild;
} BTNode, *BTree;

int getDepth(BTree rt) {
  if (rt == NULL)return 0;
  return max(getDepth(rt->lchild), getDepth(rt->rchild)) + 1;
}

void leafNode(BTree rt) {
  if (rt->lchild == NULL && rt->rchild == NULL)
    putchar(rt->data);
  if (rt->lchild != NULL)
    leafNode(rt->lchild);
  if (rt->rchild != NULL)
    leafNode(rt->rchild);
}

int getNum(BTree rt) {
  if (rt == NULL)return 0;
  return getNum(rt->lchild) + getNum(rt->rchild) + 1;
}

void preOrderExt(BTree bt) {
  if (bt == NULL)
    putchar('.');
  else {
    putchar(bt->data);
    preOrderExt(bt->lchild);
    preOrderExt(bt->rchild);
  }
}

char M[110][110];
char s[1000];
int idx;

BTNode *preOrderCreate() {
  BTNode *node = (BTNode *) malloc(sizeof(BTNode));
  if (s[idx] == '.') {
    node = NULL;
    ++idx;
  } else {
    node->data = s[idx++];
    node->lchild = preOrderCreate();
    node->rchild = preOrderCreate();
  }
  return node;
}

void inOrder(BTree bt) {
  if (!bt)return;
  inOrder(bt->lchild);
  printf("%c", bt->data);
  inOrder(bt->rchild);
}

void treeOut1(BTree bt, int n) {
  if (bt == NULL)return;
  treeOut1(bt->rchild, n + 1);
  for (int i = 0; i < n; ++i)
    putchar('-');
  putchar(bt->data);
  putchar('\n');

  treeOut1(bt->lchild, n + 1);
}

int c;

void treeOut2(BTree bt, int n) {
  if (bt == NULL)return;
  treeOut2(bt->lchild, n + 1);
  M[n][c++] = bt->data;
  treeOut2(bt->rchild, n + 1);
}

string myIntToString(int x) {
  string res;
  while (x){
    res += x%10+'0';
    x/=10;
  }
  std::reverse(res.begin(), res.end());
  return res;
}

string outWithNode(BTree bt) {
  if (bt == NULL)return "";
  string res;
  if (bt->lchild == NULL && bt->rchild == NULL) {
    res += bt->data;
    res += "[1]";
    return res;
  }

  res += bt->data;
  res += '[';
  res+= myIntToString(getNum(bt));
  res += "](";
  res += outWithNode(bt->lchild);
  res += ',';
  res += outWithNode(bt->rchild);
  res += ')';
  return res;
}

int main() {
  gets(s);
  BTree tree = preOrderCreate();
  cout << outWithNode(tree) << endl;
  return 0;
}
