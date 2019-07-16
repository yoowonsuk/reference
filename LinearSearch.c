int LSearch(int arr[], int len, int target)
{
  int i;

  for(i=0; i<len; i++)
    if(arr[i] == target)
      return i;
  return -1;
}
