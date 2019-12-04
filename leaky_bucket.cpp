#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, const char *argv[])
{
    cout << "Enter size of buffer: ";
    int bufferSize;
    cin >> bufferSize;
    cout << "Enter output rate/grant interval: ";
    int grantRate;
    cin >> grantRate;
    cout << "Enter simulation time in seconds: ";
    int simTime;
    cin >> simTime;
    int choice;
    int dataSize;
    int bufferFilled = 0;
    int grantTime = 1;
    for (int i = 0; i < simTime; i++)
    {
        cout << "\nTime: " << i + 1 << " s\n";
        int nPackets = rand() % 5;
        cout << nPackets << " Packets Generated\n";
        if (nPackets > bufferSize - bufferFilled)
        {
            if (bufferSize != bufferFilled)
                cout << ((nPackets) - (bufferSize - bufferFilled)) << " Packets dropped, insufficient space available in buffer\n";
            else
                cout << "Packets dropped, insufficient space available in buffer\n";

            bufferFilled = bufferSize;
        }
        else
        {
            cout << "Packets added to buffer" << endl;
            bufferFilled += nPackets;
        }
        if (bufferFilled != 0)
        {
            if (grantTime == 0)
            {
                cout << "1 Packet Sent\n";
                cout << "Queue Size: " << --bufferFilled << endl;
            }
            else
                cout << "No packet Sent due to lack of grant\n";
        }
        else
        {
            cout << "No data to send, buffer empty" << endl;
        }
        grantTime = (grantTime + 1) % grantRate;
    }
    return 0;
}