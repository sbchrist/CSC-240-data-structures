#ifndef HEAPTYPE_H
#define HEAPTYPE_H
template <class ItemType>
void swap(ItemType& one, ItemType& two);

// Assumes ItemType is either a built-in simple type or a class
// with overloaded relational operators.
template<class ItemType>
struct HeapType
{
  void ReheapDown(int root, int bottom);
  // Function: Compares and swaps items
  // Pre: list is initialed
  // Post: Heap property is resorted.
  void ReheapUp(int root, int bottom);
  // Function: Compares and swaps items
  // Pre: list is initialed
  // Post: Heap property is resorted.
  void HeapSort(int numValues);
  // Function: calls reheapup and reheapdown and properly returns the index value of the root and its children nodes
  // Pre: list is initilized and not empty
  // Post: properly sorted list 
  void ReheapDown(ItemType elements[], int root, int bottom);
  ItemType* elements; //external pointer to list of elements
};

template <class ItemType>
void Swap(ItemType& one, ItemType& two)
{
  ItemType temp;
  temp = one;
  one = two;
  two = temp;
}

template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
// Post: Heap property is restored.
{
  int parent;

  if (bottom > root)
  {
    parent = (bottom-1) / 2;
    if (elements[parent] < elements[bottom])
    {
      Swap(elements[parent], elements[bottom]);
      ReheapUp(root, parent);
    }
  }
}
template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
// Post: Heap property is restored.
{
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root*2+1;
  rightChild = root*2+2;
  if (leftChild <= bottom)
  {
    if (leftChild == bottom)
      maxChild = leftChild;
    else
    {
      if (elements[leftChild] <= elements[rightChild])
        maxChild = rightChild;
      else
        maxChild = leftChild;
    }
    if (elements[root] < elements[maxChild])
    {
      Swap(elements[root], elements[maxChild]);
      ReheapDown(maxChild, bottom);
    }
  }
}

template<class ItemType>
void HeapType<ItemType>::HeapSort(int numValues)
// Pre:  Struct HeapType is available.
// Post: The elements in the array values are sorted by key.
{
  int index;

  for (index = numValues/2 - 1; index >= 0; index--)
    ReheapDown(elements, index, numValues-1);

  for (index = numValues-1; index >=1; index--)
  {
    Swap(elements[0], elements[index]);
    ReheapDown(elements, 0, index-1);
  }
}

template<class ItemType>
void HeapType<ItemType>::ReheapDown(ItemType elements[], int root, int bottom)
// Post: Heap property is restored.
{
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root*2+1;
  rightChild = root*2+2;
  if (leftChild <= bottom)
  {
    if (leftChild == bottom)
      maxChild = leftChild;
    else
    {
      if (elements[leftChild] <= elements[rightChild])
        maxChild = rightChild;
      else
        maxChild = leftChild;
    }
    if (elements[root] < elements[maxChild])
    {
      Swap(elements[root], elements[maxChild]);
      ReheapDown(elements, maxChild, bottom);
    }
  }
}

#endif
