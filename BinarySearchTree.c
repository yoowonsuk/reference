#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

void BSTMakeAndInit(BTreeNode ** pRoot)
{
  *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
  return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
  BTreeNode * pnode = NULL;
  BTreeNode * cnode = *pRoot;
  BTreeNode * nnode = MakeBTreeNode();
  
  while(cnode)
  {
    if(data == GetData(cnode))
      return; // For Key Redundancy

    pnode = cnode;

    if(GetData(cnode) > data)
      cnode = GetLeftSubTree(cnode);
    else
      cnode = GetRightSubTree(cnode);
  }


  SetData(nnode, data);

  if(pnode)
    if(GetData(pnode) > data)
      ChangeLeftSubTree(pnode, nnode);
    else
      ChangeRightSubTree(pnode, nnode);
  else
    *pRoot = nnode; // For Inserting into root node

  Rebalance(pRoot);
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
  BTreeNode * cnode = bst;

  while(cnode)
   if(GetData(bst) == target)
      return cnode;
    else if(GetData(cnode) > target)
      cnode = GetLeftSubTree(cnode);
    else
      cnode = GetRightSubTree(cnode);

  return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
  BTreeNode * pVRoot = MakeBTreeNode();
  BTreeNode * pnode = pVRoot;
  BTreeNode * cnode = *pRoot;
  BTreeNode * dnode = NULL;

  ChangeRightSubTree(pVRoot, *pRoot);

  while(GetData(cnode) != target && cnode != NULL)
  {
    pnode = cnode;

    if(GetData(cnode) > target)
      cnode = GetLeftSubTree(cnode);
    else
      cnode = GetRightSubTree(cnode);
  }

  if(cnode == NULL)
    return NULL;
  dnode = cnode;

  if(GetRightSubTree(cnode) == NULL && GetLeftSubTree(cnode) == NULL)
    if(GetRightSubTree(pnode) == cnode)
      RemoveRightSubTree(pnode);
    else
      RemoveLeftSubTree(pnode);

  else if(GetRightSubTree(cnode) == NULL || GetLeftSubTree(cnode) == NULL)
  {
    if(GetRightSubTree(cnode) != NULL)
      cnode = GetRightSubTree(cnode);
    else
      cnode = GetLeftSubTree(cnode);

    if(GetRightSubTree(pnode) == dnode)
      ChangeRightSubTree(pnode, cnode);
    else
      ChangeLeftSubTree(pnode, cnode);
  }

  else
  {
    BTreeNode * mpnode = cnode;
    BTreeNode * mnode = GetRightSubTree(cnode);
    BTData rdata;

    while(GetLeftSubTree(mnode) != NULL)
    {
      mpnode = mnode;
      mnode = GetLeftSubTree(mnode);
    }
    
    rdata = GetData(cnode);
    SetData(cnode, GetData(mnode));
    SetData(mnode, rdata);
    dnode = mnode;

    if(GetRightSubTree(mpnode) == mnode)
      ChangeRightSubTree(mpnode, GetRightSubTree(mnode));
    else
      ChangeLeftSubTree(mpnode, GetRightSubTree(mnode));
  }

  if(*pRoot != GetRightSubTree(pVRoot))
    *pRoot = GetRightSubTree(pVRoot);
  
  free(pVRoot);
  Rebalance(pRoot);
  return dnode;
}

void ShowIntData(int data)
{
  printf("%d ", data);
}

void BSTShowAll(BTreeNode * bst)
{
  InorderTraverse(bst, ShowIntData);
}

