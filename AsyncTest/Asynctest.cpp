#include <iostream>
#include <conio.h> // For _kbhit and _getch
#include <future>
#include <thread>


// Function to be executed asynchronously
int add(int a, int b) {
    int c = rand() % a + b;
    return c;
}

void CheckSpace()
{
    while (true)
    {
        // Check if a key is pressed
        if (_kbhit())
        {
            // Check if the pressed key is spacebar
            if (_getch() == 32)
            { // ASCII value of spacebar
                std::cout << "Space pressed" << std::endl;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void ThreadFunction()
{
    std::future<int> result;
    for (int i = 0; i < 10; i++)
    {
        result = std::async(std::launch::async, add, 10, 20);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        int sum = result.get();
        std::cout << "Sum: " << sum << std::endl;
    }
}

int main()
{

    // Do other work while add function is running asynchronously
    std::thread tPlayerControl(CheckSpace);
    std::thread t1(ThreadFunction);
    std::thread t2(ThreadFunction);
    //std::thread t2(ThreadFunction);
    // Retrieve the result from the future object

    // Output the result
    t1.join();
    t2.join();
    tPlayerControl.join();

    return 0;
}
