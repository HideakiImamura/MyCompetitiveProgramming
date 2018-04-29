cmake_minimum_required(VERSION 3.3)
project(AtCoder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Tak_and_Hotels.cpp Beautiful_Strings.cpp Tak_and_Cards.cpp ABC044/ABC_044_C2.cpp AGC004/AGC_004_A.cpp AGC004/AGC_004_B.cpp AGC004/AGC_004_C.cpp AGC004/AGC_004_D.cpp AGC004/AGC_004_E.cpp ARC060/ARC_060_C.cpp ARC060/ARC_060_D.cpp ABC052/ABC_052_A.cpp.cpp ABC052/ABC_052_B.cpp ABC052/ABC_052_C.cpp ABC052/ABC_052_D.cpp ARC067/ARC_067_E.cpp ABC060_ARC073/ABC_060_A.cpp ABC060_ARC073/ABC_060_B.cpp ABC060_ARC073/b2.cpp ABC060_ARC073/c.cpp ABC060_ARC073/d.cpp ABC060_ARC073/e.cpp CF2017_preA/A.cpp CF2017_preA/B.cpp CF2017_preA/C.cpp ABC083/a.cpp ABC083/b.cpp ABC083/c.cpp ABC085/a.cpp ABC085/b.cpp ABC085/c.cpp ABC085/d.cpp ABC044/c.cpp ABC044/d.cpp ABC044/d_ans.cpp ABC083/d.cpp ARC090/c.cpp ARC090/d.cpp ARC090/e.cpp "ARC090/eYoshino.cpp" ABC088/a.cpp ABC088/b.cpp ABC088/c.cpp ABC088/d.cpp ARC089/c.cpp ARC089/d.cpp ARC089/d_sigma.cpp ARC090/f.cpp ARC089/e.cpp)
add_executable(AtCoder ${SOURCE_FILES})