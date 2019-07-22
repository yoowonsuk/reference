#include "AVLRebalance.h"
#include <stdlib.h>

int GetHeight(BTreeNode * bst) // not level but height+1
{
  int left, right;

  if(bst == NULL)
    return 0;

  left = GetHeight(GetLeftSubTree(bst));
  right = GetHeight(GetRightSubTree(bst));

  if(left > right)
    return left + 1;
  return right + 1;
}

int GetHeightDiff(BTreeNode * bst)
{
  int left, right;
  
  if(bst == NULL)
    return 0;

  left = GetHeight(GetLeftSubTree(bst));
  right = GetHeight(GetRightSubTree(bst));

  return left - right;
}

BTreeNode * RotateLL(BTreeNode * pRoot)
{
  BTreeNode * pnode = pRoot;
  BTreeNode * cnode = GetLeftSubTree(pnode);

  ChangeLeftSubTree(pnode, GetRightSubTree(cnode));
  ChangeRightSubTree(cnode, pnode);

  return cnode;
}

BTreeNode * RotateRR(BTreeNode * pRoot)
{
  BTreeNode * pnode = pRoot;
  BTreeNode * cnode = GetRightSubTree(pnode);

  ChangeRightSubTree(pnode, GetLeftSubTree(cnode));
  ChangeLeftSubTree(cnode, pnode);

  return cnode;
}

BTreeNode * RotateLR(BTreeNode * pRoot)
{
  BTreeNode * pnode = pRoot;
  BTreeNode * cnode = GetLeftSubTree(pnode);

  ChangeLeftSubTree(pnode, RotateRR(cnode));
  return  RotateLL(pnode);
}

BTreeNode * RotateRL(BTreeNode * pRoot)
{
  BTreeNode * pnode = pRoot;
  BTreeNode * cnode = GetRightSubTree(pnode);

  ChangeRightSubTree(pnode, RotateLL(cnode));
  return RotateRR(pnode);
}

BTreeNode * Rebalance(BTreeNode ** pRoot)
{
  int hedif = GetHeightDiff(*pRoot);

  if(hedif>1)
    if(GetHeight(GetLeftSubTree(*pRoot)) > 1)
      *pRoot = RotateLL(*pRoot);
    else
      *pRoot = RotateLR(*pRoot);
  else if(hedif<-1)
    if(GetHeight(GetRightSubTree(*pRoot)) > -1)
      *pRoot = RotateRR(*pRoot);
    else
      *pRoot = RotateRL(*pRoot);

  return *pRoot;
}

