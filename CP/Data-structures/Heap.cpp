#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class PriorityQueue
{
public:
  PriorityQueue() = default;
  void push(const T& value);
  T top() const;
  void pop();

private:
  size_t size;
  std::vector<T> heap;
};

template <typename T>
PriorityQueue<T>::PriorityQueue()
    : size(0)
    , heap(vector<T>(1))
{
}

template <typename T>
void PriorityQueue<T>::push(const T& value)
{
  size++;
  heap.push_back(value);
  size_t idx = size;
  while (idx > 1)
  {
    if (heap[idx / 2] > heap[idx])
      swap(heap[idx / 2], heap[idx]);
    idx /= 2;
  }
}

template <typename T>
T PriorityQueue<T>::top() const
{
  if (size == 0)
    return static_cast<T>(INT32_MIN);
  return heap[1];
}

template <typename T>
void PriorityQueue<T>::pop()
{
  if (size > 0)
  {
    v[1] = v[size];
    size--;
    int idx = 1;
    while (2 * idx <= size)
    {
      if (2 * idx + 1 <= size)
      {
        if (heap[idx] > min(heap[2 * idx], heap[2 * idx + 1]))
        {
          heap[idx] = min(heap[2 * idx], heap[2 * idx + 1]);
          if (heap[2 * idx] < heap[2 * idx + 1])
            idx = 2 * idx;
          else
            idx = 2 * idx + 1;
        }
        
      }
      else if (heap[idx] > heap[2 * idx])
    }
  }
}