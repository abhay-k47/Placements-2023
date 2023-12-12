#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * Given that the search space is sorted in ascending order.
 * finding the minimum value in the search space for which a certain condition satisfies
 *      1. figure out what that condition should be that we need to satisfy
 *      2. figure out the search space
 *
 */
class BinarySearch
{
public:
  bool binarySearchIterative(int searchSpace[], int n, int target)
  {
    int left = 0;
    int right = n - 1;

    /**
     * @brief it is very important to put <= and not just <
     * otherwise your program will give wrong answer if the target
     * happens to be the last element in the search space
     * Take example of searchSpace = [1, 2, 3] and target = 3
     * and see what would happen.
     * right would be initialized as index 2 and left as 0 giving mid = 1
     * searchSpace[1] = 2 which is < target value 3
     * so right remains same but left becomes  mid + 1 = 1 + 1 = 2
     * now, mid = left + (right - left) / 2 = 2 + (2 - 2) / 2 = 2
     * searchSpace[2] = 3 = target value. Returns true.
     * So here the search would terminate when left = 2 and right = 2.
     *
     */
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (searchSpace[mid] == target)
      {
        return true;
      }
      else if (searchSpace[mid] > target)
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    return false;
  }

  bool binarySearchRecursive(int searchSpace[], int n, int target)
  {
    sort(searchSpace, searchSpace + n); /** do this only if it is not guaranteed that searchSpace is already sorted */
    return binarySearchRecursiveHelper(searchSpace, target, 0, n - 1);
  }

  bool condition(int mid)
  {
    return true;
  }

  int binarySearch(int min_searchSpace, int max_searchSpace)
  {
    int left = min_searchSpace;
    int right = max_searchSpace;

    /** Loop invariant: right is the value that satisfies condition */

    while (left < right)
    {
      int mid = left + ((right - left) / 2);
      if (condition(mid))
      {
        right = mid;
      }
      else
      {
        left = mid + 1;
      }
    }
    return left;
  }

private:
  bool binarySearchRecursiveHelper(int searchSpace[], int target, int left, int right)
  {
    if (left > right)
    {
      return false;
    }
    int mid = left + (right - left) / 2;
    if (searchSpace[mid] == target)
    {
      return true;
    }
    else if (searchSpace[mid] < target)
    {
      return binarySearchRecursiveHelper(searchSpace, target, mid + 1, right);
    }
    else
    {
      return binarySearchRecursiveHelper(searchSpace, target, left, mid - 1);
    }
  }
};

// while (lo <= hi)
// {
//   int mid = lo + (hi - lo) / 2;
//   if (check())
//   {
//     hi = mid - 1;
//     // ans = mid;
//   }
//   else
//   {
//     lo = mid + 1;
//   }
// }

typedef long long ll;
ll findmin(ll lo, ll hi, function<bool(ll)> check)
{
  ll ans = INT_MAX;  // indicates no feasible solution in [l,r]
  while (lo <= hi)
  {
    ll mid = lo + (hi - lo) / 2;
    //   cout << lo << " " << hi << " " << mid << endl;
    if (check(mid))
      ans = mid, hi = mid - 1;
    else
      lo = mid + 1;
  }
  return ans;
}

ll findmax(ll lo, ll hi, function<bool(ll)> check)
{
  ll ans = INT_MIN;  // indicates no feasible solution in [l,r]
  while (lo <= hi)
  {
    ll mid = lo + (hi - lo) / 2;
    //   cout << lo << " " << hi << " " << mid << endl;
    if (check(mid))
      ans = mid, lo = mid + 1;
    else
      hi = mid - 1;
  }
  return ans;
}
