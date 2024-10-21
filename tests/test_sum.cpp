#include "gtest/gtest.h"
#include "14_sum.h"
#include <vector>
#include <numeric>

using namespace homework;

TEST(SumVector, Int){
    std::vector<int> vint = {1,2,3,4,5};
    auto sum_ints = sum_elements(vint, 0);
    auto sum_ints_ref = std::accumulate(vint.begin(),vint.end(),0);
    ASSERT_EQ(sum_ints,sum_ints_ref);
    }
TEST(SumVector, Double){
    std::vector<double> vdouble = {1.1,2.2,3.3,4.4,5.5};
    auto sum_doubles = sum_elements(vdouble, 0.0);
    auto sum_doubles_ref = std::accumulate(vdouble.begin(),vdouble.end(),0.0);
    ASSERT_NEAR(sum_doubles,sum_doubles_ref,1e-10);
}

// std::string() passes an empty string instance while "" passes an array of const char[1]
// "" wouldn't work because sum elements expects an empty string instance 
TEST(SumVector, String){
    std::vector<std::string> vstring = {"hello","world"};
    auto sum_string = sum_elements(vstring, std::string()); 
    ASSERT_EQ(sum_string,"helloworld");
}


#include <list>
TEST(SumSequence, List){
    std::list<int> lint = {1,2,3,4,5};
    auto sum_ints = sum_elements(lint, 0);
    auto sum_ints_ref = std::accumulate(lint.begin(),lint.end(),0);
    ASSERT_EQ(sum_ints,sum_ints_ref);
}
#include <array>
TEST(SumSequence, Array){
    std::array<int,5> aint = {1,2,3,4,5};
    auto sum_ints = sum_elements(aint, 0);
    auto sum_ints_ref = std::accumulate(aint.begin(),aint.end(),0);
    ASSERT_EQ(sum_ints,sum_ints_ref);
}


TEST(SumVector, CustomType){
    struct MyType{
        int i;
        double d;

        // overloading += operator of MyType struct so it works with sum_elements function
        MyType& operator+=(const MyType& other){
            this->i += other.i;
            this->d += other.d;
            return *this;
        }

        // overloading == operator of MyType struct so it works with ASSERT_EQ
        bool operator==(const MyType& other) const{ // has to be passed as const because gtest implementation of ASSERT_Q passes values as const
            return this->i == other.i && this->d == other.d;
        }
    };

    std::vector<MyType> vmt = {{1,1.1},{2,2.2},{3,3.3}};
    auto sum_mts = sum_elements(vmt, MyType{0,0.0});
    ASSERT_EQ(sum_mts,(MyType{6,6.6}));
}

#include <tuple>
TEST(Tuple, make){
    auto t = homework::make_tuple(1,2.2,"hello");
    ASSERT_EQ(std::get<0>(t),1);
    ASSERT_NEAR(std::get<1>(t),2.2,1e-10);
    ASSERT_EQ(std::get<2>(t),"hello");
}
TEST(Tuple, make2){
    auto t = homework::make_tuple("word", (std::vector<int>{1,2,3}));
    ASSERT_EQ(std::get<0>(t),"word");
    ASSERT_EQ(std::get<1>(t), (std::vector<int>{1,2,3}));
}