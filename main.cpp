#include <iostream>
#include <string>
#include <vector>
#include <map>

enum class Bills
{
    BILL_25 = 25,
    BILL_50 = 50,
    BILL_100 = 100
};

bool exchange(std::map<Bills, uint64_t>& theatreCash, int personCash)
{
    auto cash = static_cast<Bills>(personCash);
    ++theatreCash[cash];

    switch(cash)
    {
        case Bills::BILL_25:
            return true;

        case Bills::BILL_50:
            if (theatreCash[Bills::BILL_25])
            {
                --theatreCash[Bills::BILL_25];
                return true;
            }
            return false;

        case Bills::BILL_100:
            if (theatreCash[Bills::BILL_50] and theatreCash[Bills::BILL_25])
            {
                --theatreCash[Bills::BILL_50];
                --theatreCash[Bills::BILL_25];
                return true;
            }
            else if (theatreCash[Bills::BILL_25] >= 3)
            {
                theatreCash[Bills::BILL_25] -= 3;
                return true;
            }
            return false;
    }
}

std::string tickets (const std::vector<int>& peopleInLine) {

    std::map<Bills, uint64_t> theatreCash;
    for (auto person : peopleInLine)
    {
        if (not exchange(theatreCash, person))
            return {"NO"};
    }
    return {"YES"};
}

int main() {
    std::vector<int> line {25, 25, 50, 50, 25, 100};
    std::vector<int> line2 {100, 25, 50, 100};
    std::vector<int> line3 {25, 25, 50, 100};
    std::vector<int> line4 {25, 25, 25, 100};


    std::cout << tickets(line) << std::endl;
    std::cout << tickets(line2) << std::endl;
    std::cout << tickets(line3) << std::endl;
    std::cout << tickets(line4) << std::endl;


    return 0;
}