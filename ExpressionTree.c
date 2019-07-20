#include "ListBaseStack.h"
#include "BinaryTree2.h"
#include "ExpressionTree.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

BTreeNode * MakeExpTree(char exp[])
{
  Stack stack;
  int i;
  BTreeNode * pnode;

  StackInit(&stack);

  for(i=0; i<strlen(exp); i++)
  {
      pnode = MakeBTreeNode();

      if(isdigit(exp[i]))
        SetData(pnode, exp[i]-'0');
      else
      {
        MakeRightSubTree(pnode, SPop(&stack));
        MakeLeftSubTree(pnode, SPop(&stack));
        SetData(pnode, exp[i]);
      }
      SPush(&stack, pnode);
  }

  return SPop(&stack);
}

void ShowNodeData(int data)
{
	if(0<=data && data<=9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt)
{
  if(bt->left != NULL)
  {
    putchar('(');
    ShowInfixTypeExp(bt->left);
    ShowNodeData(GetData(bt));
    ShowInfixTypeExp(bt->right);
    putchar(')');
  }
  else
    ShowNodeData(GetData(bt));

//	InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode * bt)
{
	PostorderTraverse(bt, ShowNodeData);
}

int EvaluateExpTree(BTreeNode * bt)
{
	int op1, op2;

	if(GetLeftSubTree(bt)==NULL)
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch(GetData(bt))
	{
	case '+':
		return op1+op2;
	case '-':
		return op1-op2;
	case '*':
		return op1*op2;
	case '/':
		return op1/op2;
	}

	return 0;
}
