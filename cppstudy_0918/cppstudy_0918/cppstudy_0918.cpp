#include <iostream>

int main()
{
    int valueMin = 100;
    int valueMax = 210;

    int userInfo;

    std::cout << "키를 입력하세요" << std::endl;
    std::cin >> userInfo;

    if (valueMin < userInfo && userInfo < valueMax)
    {
        std::cout << "탑승하세요" << std::endl;
    }

    else if(valueMin > userInfo)
    {
        std::cout << "키가 작아서 탑승이 불가합니다" << std::endl;
    }
    else
    {
        std::cout << "키가 커서 탑승이 불가합니다" << std::endl;
    }

}


// 프로그래밍은 무조건 영어
// 소괄호 ()
// 중괄호 {}
// 대괄호[]
// 꺽쇠괄호 <>
