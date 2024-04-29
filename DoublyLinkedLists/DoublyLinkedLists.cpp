#include <iostream>
#include "DList.h" // Include the header file

int main()
{
    // Create an instance of DList with integers
    DList<int> myList;

    // Push elements to the front
    myList.Push_Front(10);
    myList.Push_Front(20);
    myList.Push_Front(30);

    // Push elements to the back
    myList.push_back(40);
    myList.push_back(50);
    myList.push_back(60);

    // Display the elements in the list
    std::cout << "Elements in the list:\n";
    for (int i = 0; i < myList.GetCount(); ++i)
    {
        std::cout << myList[i] << " ";
    }
    std::cout << std::endl;

    // Clear the list
    myList.Clear();
    std::cout << "After clearing the list, count: " << myList.GetCount() << std::endl;

    // Destructor will be called when the object goes out of scope
    // or we can manually call it
    myList.push_back(100); // Adding elements again
    myList.push_back(200);
    std::cout << "Elements in the list after adding again:\n";
    for (int i = 0; i < myList.GetCount(); ++i)
    {
        std::cout << myList[i] << " ";
    }
    std::cout << std::endl;

    // Manually call destructor
    myList.~DList();
    std::cout << "After calling the destructor, count: " << myList.GetCount() << std::endl;

    return 0;
}
