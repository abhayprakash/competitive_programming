/**
minHeap can be(should be) implemented by using stl priotity queue as following:

priority_queue<int, vector<int>, greater<int> > minHeap;
-> push(*)
-> pop()
-> top()

For own implementation i am writing this code
**/

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class minHeap{
    vector<T> m_a;
public:
    minHeap()
    {
        m_a.push_back(-1); // sentinel - my heap starts from index 1
    }

    bool isEmpty()
    {
        return (m_a.size() == 1);
    }

    void push(T n)
    {
        m_a.push_back(n);
        int current = m_a.size() -1;

        while(current > 1)
        {
            if(m_a[current] < m_a[current / 2])
            {
                T temp = m_a[current];
                m_a[current] = m_a[current / 2];
                m_a[current / 2] = temp;

                current /= 2;
            }
            else
                return;
        }
        //*/
    }

    T pop()
    {
        T toret = m_a[1];
        int last_i = m_a.size() - 1;
        m_a[1] = m_a[last_i];
        m_a.erase(m_a.begin() + last_i);
        m_heapify(1);

        return toret;
    }

    T top()
    {
        return m_a[1];
    }

private:
    void m_heapify(int index)
    {
        int left = 2*index;
        int right = 2*index + 1;
        int smallest_i = index;
        if(left < m_a.size() && m_a[left] < m_a[smallest_i])
            smallest_i = left;
        if(right < m_a.size() && m_a[right] < m_a[smallest_i])
            smallest_i = right;
        if(smallest_i !=  index)
        {
            T temp = m_a[smallest_i];
            m_a[smallest_i] = m_a[index];
            m_a[index] = temp;

            m_heapify(smallest_i);
        }
    }

    void m_buildHeap()
    {
        for(int i = (m_a.size()-1)/2; i > 0; i--)
            m_heapify(i);
    }
};

int main()
{
    minHeap<int> myHeap;
    myHeap.push(25);
    myHeap.push(5);
    myHeap.push(45);
    myHeap.push(50);
    myHeap.push(75);
    myHeap.push(10);
    while(!myHeap.isEmpty())
        cout<<myHeap.pop()<<endl;
//*/
}
