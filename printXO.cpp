#include <iostream>
#include <string>
#include <cassert>


std::string printXO(const int countX, const int countO)
{
   std::string output = "";
   if(countX < 0 || countO < 0)
    {
        std::cout << "elements should be higher than zero" << std::endl;
        return "no solution";
    }
    
    auto nX = countX, nO = countO;
    while(nX + nO >0 )
    {
        bool WriteX = false;
        size_t len = output.length();

        if(len >= 3 && (output.at(len-2) == output.at(len-1)))
        {
            if (output.at(len-1) == 'O')
                WriteX = true;
            else if(output.at(len-1) == 'O' && output.at(len-2) == 'X')
                WriteX = true;
            else if(output.at(len-1) == 'X' && output.at(len-2) == 'X' && output.at(len-3) == 'O')
                WriteX = true;
            else if(output.at(len-1) == 'X' && output.at(len-2) == 'X' && output.at(len-3) == 'X' )
                WriteX = false;
            else if(output.at(len-1) == '0' && output.at(len-2) == '0' && output.at(len-3) == '0' )
                WriteX = true;
        }
        else
        {
            if(nX>=nO)
                WriteX = true;
            else
                WriteX = false;
            
        }
        if (WriteX && nX > 0)
        {
            nX--;
            output.append("X");
        } 
        else if(!WriteX && nO > 0) 
        {
            nO--;
            output.append("O");
        }
        else
        {
            std::cout << "solutions does not exist" << std::endl;
            return "no solution";
        }
    }
    
    
    for(auto &elem : output)
    {
        std::cout << elem;
    }
    std::cout << std::endl;
    
    // for test function
    return output;
}

void test()
{
    assert(printXO(9,3) =="XXXOXXXOXXXO" && "should be XXXOXXXOXXXO");
    assert(printXO(9,1) =="no solution" && "solutions does not exist");
    assert(printXO(10,5) =="XXXOXXXOXOXOXOX" && "should be XXXOXXXOXOXOXOX");
    assert(printXO(3,5) =="OOOXOXOX" && "should be OOOXOXOX");
    assert(printXO(10,13) =="OOOXOOXOXOXOXOXOXOXOXOX" && "should be OOOXOOXOXOXOXOXOXOXOXOX");
    assert(printXO(6,1) =="XXXOXXX" && "should be XXXOXXX");
    assert(printXO(5,11) =="OOOXOOXOOXOOXOOX" && "should be OOOXOOXOOXOOXOOX");
    
}

int main(){

test();

return 0;
}
