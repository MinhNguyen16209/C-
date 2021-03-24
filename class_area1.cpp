#include <iostream>
class BaseMath
{
private:
    bool isEvenNumber(int num)
    {
        bool result = false;
        if (num%2 == 0)
        {
            result = true;
        }
        return result;
    }
public:
    int factorial(int n)
    {
        int result = 1;
        for (int i=1;i<=n;i++)
        {
            result *= i;
        }
        return result;
    }
};

class AdvancedMath : public BaseMath
{
public:
    double estimateEulerNumber(int numLoops)
    {
        double result = 1.0;
        for (int i=1;i<=numLoops;i++)
        {
            result += 1.0/factorial(i);
        }
        return result;
    }
};

int main()
{
    BaseMath bm;
    printf("Factorial(4) is %d\n", bm.factorial(4));
    AdvancedMath am;
    printf("Factorial(4) is %d\n", am.factorial(4));
    printf("estimateEulerNumber(8) is %f", am.estimateEulerNumber(8));
    return 0;
}
