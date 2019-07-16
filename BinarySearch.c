int BSearch(int arr[], int len, int target)
{
  int first = 0;
  int last = len - 1;
  int mid;
  
  while(first<=last)
  {
    mid = (first+last)/2;
    if(arr[mid]==target)
      return mid;
  
    if(arr[mid] > target)
      last = mid -1;
    else
      first = mid + 1;
  }
  return -1;
}
