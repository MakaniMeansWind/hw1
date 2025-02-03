/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

using namespace std;

int main(int argc, char* argv[])
/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ -g -Wall split.cpp split_test.cpp -o split_test
*/

#include <iostream>
#include "split.h"
using namespace std;

int main(int argc, char* argv[])
{
  // Test One - Standard Ordered List

  cout << "Test One" << endl;

  Node e(9, NULL);  
  Node d(8, &e);
  Node c(7, &d);
  Node b(6, &c);
  Node a(5, &b);

  Node* HeadOdds = NULL;
  Node* HeadEvens = NULL;
  Node* Start = &a;

  split(Start, HeadOdds, HeadEvens);

  Node* ScannerOdd = HeadOdds;
  Node* ScannerEven = HeadEvens;

  if(HeadOdds != NULL)
  {

    cout << "HeadOdds is " << ScannerOdd->value << endl;

  } 

  else
  {

    cout << "No odd header, no odds list" << endl;

  }

  if(HeadEvens != NULL)
  {

    cout << "HeadEvens is " << ScannerEven->value << endl;

  }

  else
  {

    cout << "No even header, no evens list" << endl;
    
  }

  cout << endl;

  cout << "Odd list is (from least to greatest): " << endl;
  printList(ScannerOdd);
  
  cout << "Even list is (from least to greatest): " << endl;
  printList(ScannerEven);

  cout << endl;

  // Test Two - Empty List

  cout << "Test Two" << endl;

  Start = NULL;
  HeadEvens = NULL;
  HeadOdds = NULL;

  split(Start, HeadEvens, HeadOdds);

  if(HeadOdds != NULL)
  {

    cout << "HeadOdds is " << ScannerOdd->value << endl;

  } 

  else
  {

    cout << "No odd header, no odds list" << endl;

  }

  if(HeadEvens != NULL)
  {

    cout << "HeadEvens is " << ScannerEven->value << endl;

  }

  else
  {

    cout << "No even header, no evens list" << endl;

  }

  cout << endl;

  // Test Three - All Evens

  cout << "Test Three" << endl;

  Node j(8, NULL);
  Node i(6, &j);
  Node h(4, &i);
  Node g(2, &h);
  Node f(0, &g);

  HeadOdds = NULL;
  HeadEvens = NULL;
  Start = &f;

  split(Start, HeadOdds, HeadEvens);

  ScannerOdd = HeadOdds;
  ScannerEven = HeadEvens;

  if(HeadOdds != NULL)
  {

    cout << "HeadOdds is " << ScannerOdd->value << endl;

  } 

  else
  {

    cout << "No odd header, no odds list" << endl;

  }

  if(HeadEvens != NULL)
  {

    cout << "HeadEvens is " << ScannerEven->value << endl;

  }

  else
  {

    cout << "No even header, no evens list" << endl;

  }

  cout << endl;

  cout << "Odd list is (from least to greatest): " << endl;
  printList(ScannerOdd);
  
  cout << "Even list is (from least to greatest): " << endl;
  printList(ScannerEven);

  cout << endl;

  // Test Four - All Odds

  cout << "Test Four" << endl;

  Node Five(9, NULL);
  Node Four(7, &Five);
  Node Three(5, &Four);
  Node Two(3, &Three);
  Node One(1, &Two);

  HeadOdds = NULL;
  HeadEvens = NULL;
  Start = &One;

  split(Start, HeadOdds, HeadEvens);

  ScannerOdd = HeadOdds;
  ScannerEven = HeadEvens;

  if(HeadOdds != NULL)
  {

    cout << "HeadOdds is " << ScannerOdd->value << endl;

  } 

  else
  {

    cout << "No odd header, no odds list" << endl;

  }

  if(HeadEvens != NULL)
  {

    cout << "HeadEvens is " << ScannerEven->value << endl;

  }

  else
  {

    cout << "No even header, no evens list" << endl;

  }

  cout << endl;

  cout << "Odd list is (from least to greatest): " << endl;
  printList(ScannerOdd);
  
  cout << "Even list is (from least to greatest): " << endl;
  printList(ScannerEven);

  cout << endl;

  // Test Five - Single Node

  cout << "Test Five" << endl;

  Node Single(1, NULL);

  HeadOdds = NULL;
  HeadEvens = NULL;
  Start = &Single;

  split(Start, HeadOdds, HeadEvens);

  ScannerOdd = HeadOdds;
  ScannerEven = HeadEvens;

  if(HeadOdds != NULL)
  {

    cout << "HeadOdds is " << ScannerOdd->value << endl;

  } 

  else
  {

    cout << "No odd header, no odds list" << endl;

  }

  if(HeadEvens != NULL)
  {

    cout << "HeadEvens is " << ScannerEven->value << endl;

  }

  else
  {

    cout << "No even header, no evens list" << endl;

  }

  cout << endl;

  cout << "Odd list is (from least to greatest): " << endl;
  printList(ScannerOdd);
  
  cout << "Even list is (from least to greatest): " << endl;
  printList(ScannerEven);

  cout << endl;

  // Test Six - All Duplicates

  cout << "Test Six" << endl;

  Node Ten(2, NULL);
  Node Nine(2, &Ten);
  Node Eight(2, &Nine);
  Node Seven(2, &Eight);
  Node Six(2, &Seven);

  HeadOdds = NULL;
  HeadEvens = NULL;
  Start = &Six;

  split(Start, HeadOdds, HeadEvens);

  ScannerOdd = HeadOdds;
  ScannerEven = HeadEvens;

  if(HeadOdds != NULL)
  {

    cout << "HeadOdds is " << ScannerOdd->value << endl;

  } 

  else
  {

    cout << "No odd header, no odds list" << endl;

  }

  if(HeadEvens != NULL)
  {

    cout << "HeadEvens is " << ScannerEven->value << endl;

  }

  else
  {

    cout << "No even header, no evens list" << endl;

  }

  cout << endl;

  cout << "Odd list is (from least to greatest): " << endl;
  printList(ScannerOdd);
  
  cout << "Even list is (from least to greatest): " << endl;
  printList(ScannerEven);

  cout << endl;

  

  return 0;
}
