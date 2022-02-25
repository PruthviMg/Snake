#include <iostream>
#include <unordered_map>
#include <vector>

struct Data
{
    std::vector<int> value;
};

std::unordered_map<std::string, Data> m_umapData;
bool flag;
std::string m_current;

std::pair<bool, Data &> pairGetCurrentDataConfigStatus(int &data)
{
    if (data % 2 == 0)
    {
        m_current = "even";

        if (m_umapData.find(m_current) == m_umapData.end())
        {
            flag = true;
            m_umapData[m_current].value.push_back(data);
        }

        else
        {
            flag = false;
            m_umapData[m_current].value.push_back(data);
        }
    }

    else
    {
        m_current = "odd";

        if (data != 5)
        {
            if (m_umapData.find(m_current) == m_umapData.end())
            {
                flag = true;
                m_umapData[m_current].value.push_back(data);
            }

            else
            {
                flag = false;
                m_umapData[m_current].value.push_back(data);
            }
        }
    }

    return {flag, m_umapData[m_current]};
}

class simple
{
private:
    std::vector<int> &m_vec;
    std::unordered_map<std::string, int> mapval;

public:
    simple(std::vector<int> &vec) : m_vec(vec) {}
    // void push(std::vector<int> &vector)
    // {
    //     m_vec = vector;
    // }

    int &iFetch()
    {
        return mapval["Hi"];
    }

    void add(std::string s, int &p)
    {
        if (mapval.find(s) == mapval.end())
        {
            mapval[s] = p;
            std::cout << "mapval[s] " << &mapval[s] << std::endl;
            auto z = iFetch();
            std::cout << "z " << z << std::endl;
            m_vec.push_back(z);
        }

        else
        {
            std::cout << "mapval[s] else " << &mapval[s] << std::endl;

            mapval[s] = p;
        }
        for (auto itr = mapval.begin(); itr != mapval.end(); ++itr)
        {
            std::cout << '\t' << itr->first << '\t' << itr->second
                      << '\n';
        }
    }

    void print()
    {
        std::cout << "Inside class" << std::endl;

        for (auto i : m_vec)
        {
            std::cout << i << ",";
        }
        std::cout << std::endl;
    }
};

// class data
// {
// private:
//     int &x;

// public:
//     data(int &i) : x(i)
//     {
//         x++;
//         std::cout << x << std::endl;
//     }
// };

int main()
{
    // int val = 5;
    // data d(val);
    // std::cout << val << std::endl;

    std::vector<int> v = {1, 2, 3, 4};
    simple s(v);
    // s.push(v);
    int p = 12;
    s.add("Hi", p);
    p = 33;
    s.add("Hi", p);

    std::cout << "Inside Main" << std::endl;

    for (auto i : v)
    {
        std::cout << i << ",";
    }
    std::cout << std::endl;
    s.print();

    // std::vector<Data> data;

    // for (int i = 0; i < 10; i++)
    // {
    //     auto res = pairGetCurrentDataConfigStatus(i);

    //     if (res.first)
    //     {
    //         data.push_back(res.second);
    //     }
    // }

    // for (auto itr = m_umapData.begin(); itr != m_umapData.end(); itr++)
    // {
    //     std::cout << itr->first << " ";
    //     for (auto j = itr->second.value.begin(); j != itr->second.value.end(); j++)
    //     {
    //         std::cout << *j << ",";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}